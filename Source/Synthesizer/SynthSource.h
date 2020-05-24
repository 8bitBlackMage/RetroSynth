/*
  ==============================================================================

    SynthSource.h
    Created: 15 May 2020 2:22:39pm
    Author:  alexe

  ==============================================================================
*/
#include "JuceHeader.h"
#include"WaveVoiceNesTri.h"
#include "WaveVoiceTri.h"
#include "WaveVoicePulse.h"
#include "WaveVoiceSine.h"
#include "WaveVoiceNoise.h"
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
    WaveVoicePulse<float> m_WaveTable_Pulse;
    WaveVoiceNesTri<float>m_WaveTable_NesTri;
    WaveVoiceTri<float>m_WaveTable_Tri;
    WaveVoiceSine<float>m_Wavetable_sine;
};