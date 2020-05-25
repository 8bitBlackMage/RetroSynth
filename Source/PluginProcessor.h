/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Synthesizer/SynthSource.h"
//==============================================================================
/**
*/
class RetroSynthAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    RetroSynthAudioProcessor();
    ~RetroSynthAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    MidiKeyboardState m_keystate;

    ADSR::Parameters* m_FilterPerameters = nullptr;
    ADSR::Parameters* m_AmpPerameters = nullptr;
    int* m_FilterMode = nullptr;


    double* m_VCF1_Cutoff = nullptr;
    double* m_VCF1_Res = nullptr;
    int* m_Filter1Type = nullptr;
    double* m_VCF2_Cutoff = nullptr;
    double* m_VCF2_Res = nullptr;
    int* m_Filter2Type = nullptr;
    double* m_FilterEnvelope = nullptr;

    double* m_OSC1_Volume = nullptr;
    double* m_OSC1_Detune = nullptr;
    int* m_Waveform1Index = nullptr;
    double* m_OSC2_Volume = nullptr;
    double* m_OSC2_Detune = nullptr;;
    int* m_Waveform2Index = nullptr;





private:
    //==============================================================================
   RetroSynthAudioSource m_synth;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RetroSynthAudioProcessor)
};
