/*
  ==============================================================================

    SynthSource.h
    Created: 15 May 2020 2:22:39pm
    Author:  alexe

  ==============================================================================
*/
#include "JuceHeader.h"
#include"WaveVoiceNesTri.h"
#include "SynthVoice.h"
#pragma once

class RetroSynthAudioSource : public AudioSource {
public:
    RetroSynthAudioSource(MidiKeyboardState& keystate);
    void prepareToPlay(int /*SamplesPerBlockExpected*/, double SampleRate) override;
    void releaseResources() override;
    void getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill) override;
    
private:
    MidiKeyboardState& m_keystate;
    Synthesiser m_synth;
    WaveVoiceNesTri<float> m_WaveTable;
};