/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
RetroSynthAudioProcessorEditor::RetroSynthAudioProcessorEditor (RetroSynthAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), m_keyboardComponent(processor.m_keystate, MidiKeyboardComponent::Orientation::horizontalKeyboard)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    addAndMakeVisible(m_OSCcontrol);
    addAndMakeVisible(m_keyboardComponent);
    setSize (1024, 768);
}

RetroSynthAudioProcessorEditor::~RetroSynthAudioProcessorEditor()
{
}

//==============================================================================
void RetroSynthAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    
}

void RetroSynthAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    m_OSCcontrol.setBounds(getBounds());
    m_keyboardComponent.setBounds(getBounds().removeFromBottom(150));
}
