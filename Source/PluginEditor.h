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



    MainPage m_Controls;
    MidiKeyboardComponent m_keyboardComponent;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RetroSynthAudioProcessorEditor)
};
