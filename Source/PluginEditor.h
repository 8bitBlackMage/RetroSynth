/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Frontend/MainPage.h"


//==============================================================================
/**
*/
class RetroSynthAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    RetroSynthAudioProcessorEditor (RetroSynthAudioProcessor&);
    ~RetroSynthAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    RetroSynthAudioProcessor& processor;
    ADSR::Parameters* m_FilterPerameters;
    ADSR::Parameters* m_AmpPerameters;
    int* m_FilterMode;


    double* m_VCF1_Cutoff;
    double* m_VCF1_Res;
    int* m_Filter1Type;
    double* m_VCF2_Cutoff;
    double* m_VCF2_Res;
    int* m_Filter2Type;
    double* m_FilterEnvelope;

    double* m_OSC1_Volume;
    double* m_OSC1_Detune;
    int* m_Waveform1Index;
    double* m_OSC2_Volume;
    double* m_OSC2_Detune;
    int* m_Waveform2Index;


    MainPage m_Controls;
    MidiKeyboardComponent m_keyboardComponent;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RetroSynthAudioProcessorEditor)
};
