/*
  ==============================================================================

    SynthVoice.cpp
    Created: 15 May 2020 2:46:06pm
    Author:  alexe

  ==============================================================================
*/

#include "SynthVoice.h"
#include "SynthSound.h"



RetroSynthVoice::RetroSynthVoice(WaveVoiceNesTri<float>* wavetable, double sampleRate): m_Phasor(sampleRate)
{
    m_Wavetable = wavetable;
}

bool RetroSynthVoice::canPlaySound(SynthesiserSound* sound)
{
    return dynamic_cast<RetroSynthSound*>(sound) != nullptr;
}

void RetroSynthVoice::startNote(int MidiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition)
{
    auto cyclesPerSecond = MidiMessage::getMidiNoteInHertz(MidiNoteNumber);
    
    m_Phasor.setFrequency(cyclesPerSecond);
    m_Envelope.noteOn();
}

void RetroSynthVoice::stopNote(float Veclocity, bool AllowTailOff)
{
    m_Envelope.noteOff();
}

void RetroSynthVoice::setCurrentPlaybackSampleRate(double samplerate)
{
    m_Phasor.setSampleRate(samplerate);
}

void RetroSynthVoice::pitchWheelMoved(int newValue)
{
}

void RetroSynthVoice::controllerMoved(int controller, int newvalue)
{
}

void RetroSynthVoice::renderNextBlock(AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
    
    float* left = outputBuffer.getWritePointer(0);
    float* right = outputBuffer.getWritePointer(1);
    for (int i = 0; i < numSamples; i++)
    {
        float sample = m_Wavetable->getSample( (m_Phasor.getPhase() * m_Wavetable->getSize())  *m_Envelope.getNextSample()
       );
        m_Phasor.tick();
        left[i] += sample;
        right[i] += sample;
    }
  


}
