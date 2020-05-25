/*
  ==============================================================================

    SynthSource.cpp
    Created: 15 May 2020 2:22:39pm
    Author:  alexe

  ==============================================================================
*/

#include "SynthSource.h"
#include "SynthSound.h"

RetroSynthAudioSource::RetroSynthAudioSource(MidiKeyboardState& keystate, int voiceNumber):m_keystate(keystate), m_voicenumber(voiceNumber),m_WaveTable_NesTri(44100), m_WaveTable_Pulse(44100),m_WaveTable_sine(44100),m_WaveTable_Tri(44100)
{
    for (int i = 0; i < m_voicenumber; i++)
    {
        m_synth.addVoice(new RetroSynthVoice(&m_WaveTable_Pulse, 44100));
        m_synth.addSound(new RetroSynthSound());
    }
}

void RetroSynthAudioSource::prepareToPlay(int, double SampleRate)
{
    m_WaveTable_NesTri.CreateTable(SampleRate);
    m_WaveTable_Pulse.CreateTable(SampleRate);
    m_WaveTable_Tri.CreateTable(SampleRate);
    m_WaveTable_sine.CreateTable(SampleRate);
    m_synth.setCurrentPlaybackSampleRate(SampleRate);
    for (int i = 0; i < m_voicenumber; i++) {
        m_synth.getVoice(i)->setCurrentPlaybackSampleRate(SampleRate);
    }
    
}

void RetroSynthAudioSource::releaseResources()
{

}

void RetroSynthAudioSource::getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill)
{
    bufferToFill.clearActiveBufferRegion();
    MidiBuffer incomingMidi;
    m_keystate.processNextMidiBuffer(incomingMidi, bufferToFill.startSample, bufferToFill.numSamples, true);
    m_synth.renderNextBlock(*bufferToFill.buffer, incomingMidi, bufferToFill.startSample, bufferToFill.numSamples);

}

void RetroSynthAudioSource::HandleFilterValues(int FilterNumber, float* Cutoff, float* Res, int* FilterType)
{
    if (Cutoff != nullptr && Res != nullptr && FilterType != nullptr)
    {
        for (int i = 0; i < m_synth.getNumVoices(); i++) {
            RetroSynthVoice* Voice = dynamic_cast<RetroSynthVoice*>(m_synth.getVoice(i));
            if (FilterNumber == 0) {
                Voice->m_FilterA->ChangeFreq(*Cutoff);
                Voice->m_FilterA->changeRes(*Res);
                Voice->m_FilterA->changeVal();
                if (*FilterType == 1 && m_FilterAtype != 1)
                {
                    delete(Voice->m_FilterA);
                    Voice->m_FilterA =   new LowPass<float>(*Cutoff, *Res, Voice->getSampleRate(), 0.3);
                    m_FilterAtype = *FilterType;
                }
                if (*FilterType == 2 && m_FilterBtype != 2)
                {
                    delete(Voice->m_FilterA);
                    Voice->m_FilterA =  new HighPass<float>(*Cutoff, *Res, Voice->getSampleRate(), 0.3);
                        m_FilterAtype = *FilterType;
                }
            }
            if (FilterNumber == 1) {
                Voice->m_FilterB->ChangeFreq(*Cutoff);
                Voice->m_FilterB->changeRes(*Res);
                Voice->m_FilterB->changeVal();
                if (*FilterType == 1 && m_FilterBtype != 1)
                {
                    delete(Voice->m_FilterB);
                    Voice->m_FilterB =   new LowPass<float>(*Cutoff, *Res, Voice->getSampleRate(), 0.3);
                    m_FilterBtype = *FilterType;
                }
                if (*FilterType == 2 && m_FilterBtype != 2)
                {
                    delete(Voice->m_FilterB);
                    Voice->m_FilterB =   new HighPass<float>(*Cutoff, *Res, Voice->getSampleRate(), 0.3);
                    m_FilterBtype = *FilterType;
                }
            }
            Voice = nullptr;
        }
    }
}

void RetroSynthAudioSource::HandleOSCValues(int OSCNumber, float* detune, float* Volume, int* voiceType)
{
    if (detune != nullptr && Volume != nullptr && voiceType != nullptr)
    {
        for (int i = 0; i < m_synth.getNumVoices(); i++)
        {
            RetroSynthVoice* Voice = dynamic_cast<RetroSynthVoice*>(m_synth.getVoice(i));

            if (OSCNumber == 1) {
                Voice->m_PhasorA.setFrequency( (Voice->m_PhasorA.getFreq() + *detune));
                Voice->DetuneA = *detune;
            }



        }
    }
}

void RetroSynthAudioSource::HandleADSRValues(ADSR::Parameters *ampEnvelope, ADSR::Parameters *filterEnvelope)
{
    if (ampEnvelope != nullptr && filterEnvelope != nullptr) {
        for (int i = 0; i < m_synth.getNumVoices(); i++)
        {

            RetroSynthVoice* Voice = dynamic_cast<RetroSynthVoice*>(m_synth.getVoice(i));
            Voice->m_Envelope.setParameters(*ampEnvelope);
            Voice = nullptr;
        }
    }
}
