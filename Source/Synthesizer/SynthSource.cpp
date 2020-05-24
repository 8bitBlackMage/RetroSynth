/*
  ==============================================================================

    SynthSource.cpp
    Created: 15 May 2020 2:22:39pm
    Author:  alexe

  ==============================================================================
*/

#include "SynthSource.h"
#include "SynthSound.h"

RetroSynthAudioSource::RetroSynthAudioSource(MidiKeyboardState& keystate):m_keystate(keystate), m_WaveTable_NesTri(44100), m_WaveTable_Pulse(44100),m_Wavetable_sine(44100),m_WaveTable_Tri(44100)
{
    for (int i = 0; i < 1; i++)
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
    m_Wavetable_sine.CreateTable(SampleRate);
    m_synth.setCurrentPlaybackSampleRate(SampleRate);
    for (int i = 0; i < 1; i++) {
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
