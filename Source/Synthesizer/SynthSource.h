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
    RetroSynthAudioSource(MidiKeyboardState& keystate, int voiceNumber );
    void prepareToPlay(int /*SamplesPerBlockExpected*/, double SampleRate) override;
    void releaseResources() override;
    void getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill) override;
    void HandleFilterValues(int FilterNumber, float* Cutoff,float* Res, int* FilterType);
    void HandleOSCValues(int OSCNumber, float* detune, float* Volume, int* voiceType);
    void HandleADSRValues(ADSR::Parameters* ampEnvelope, ADSR::Parameters* filterEnvelope);
private:
    int m_voicenumber;
    MidiKeyboardState& m_keystate;
    Synthesiser m_synth;
    WaveVoicePulse<float> m_WaveTable_Pulse;
    WaveVoiceNesTri<float>m_WaveTable_NesTri;
    WaveVoiceTri<float>m_WaveTable_Tri;
    WaveVoiceSine<float>m_WaveTable_sine;

    int m_FilterAtype;
    int m_FilterBtype;
};