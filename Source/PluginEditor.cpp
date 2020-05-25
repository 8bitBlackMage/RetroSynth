/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "Frontend/ADSRPage.h"
#include "frontend/FilterPage.h"
#include "Frontend/OSCPage.h"

//==============================================================================
RetroSynthAudioProcessorEditor::RetroSynthAudioProcessorEditor (RetroSynthAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), m_keyboardComponent(processor.m_keystate, MidiKeyboardComponent::Orientation::horizontalKeyboard)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    addAndMakeVisible(m_Controls);
    addAndMakeVisible(m_keyboardComponent);
    setSize (1024, 768);

    p.m_FilterPerameters = &dynamic_cast<ADSRPage*>(m_Controls.getTabbedComponent()->getTabContentComponent(2))->filterPerams;
    p.m_AmpPerameters = &dynamic_cast<ADSRPage*>(m_Controls.getTabbedComponent()->getTabContentComponent(2))->ampPerams;
    p.m_FilterMode = &dynamic_cast<FilterPage*>(m_Controls.getTabbedComponent()->getTabContentComponent(1))->FilterMode;
    
    p.m_VCF1_Cutoff = &dynamic_cast<FilterPage*>(m_Controls.getTabbedComponent()->getTabContentComponent(1))->GetFilterControl1()->VCF_Cutoff;
    p.m_VCF1_Res = &dynamic_cast<FilterPage*>(m_Controls.getTabbedComponent()->getTabContentComponent(1))->GetFilterControl1()->VCF_Res;
    p.m_Filter1Type = &dynamic_cast<FilterPage*>(m_Controls.getTabbedComponent()->getTabContentComponent(1))->GetFilterControl1()->FilterType;

    p.m_VCF2_Cutoff = &dynamic_cast<FilterPage*>(m_Controls.getTabbedComponent()->getTabContentComponent(1))->GetFilterControl2()->VCF_Cutoff;
    p.m_VCF2_Res = &dynamic_cast<FilterPage*>(m_Controls.getTabbedComponent()->getTabContentComponent(1))->GetFilterControl2()->VCF_Res;
    p.m_Filter2Type = &dynamic_cast<FilterPage*>(m_Controls.getTabbedComponent()->getTabContentComponent(1))->GetFilterControl2()->FilterType;

    p.m_FilterEnvelope = &dynamic_cast<FilterPage*>(m_Controls.getTabbedComponent()->getTabContentComponent(2))->EnvelopeAmount;

    p.m_OSC1_FrequencyMod = &dynamic_cast<OSCPage*>(m_Controls.getTabbedComponent()->getTabContentComponent(0))->getOSCcontrol1()->OSC_FrequencyMod;
    p.m_OSC1_Detune = &dynamic_cast<OSCPage*>(m_Controls.getTabbedComponent()->getTabContentComponent(0))->getOSCcontrol1()->OSC_Detune;
    p.m_Waveform1Index = &dynamic_cast<OSCPage*>(m_Controls.getTabbedComponent()->getTabContentComponent(0))->getOSCcontrol1()->WaveformIndex;

    p.m_OSC2_FrequencyMod = &dynamic_cast<OSCPage*>(m_Controls.getTabbedComponent()->getTabContentComponent(0))->getOSCcontrol2()->OSC_FrequencyMod;
    p.m_OSC2_Detune = &dynamic_cast<OSCPage*>(m_Controls.getTabbedComponent()->getTabContentComponent(0))->getOSCcontrol2()->OSC_Detune;
    p.m_Waveform2Index = &dynamic_cast<OSCPage*>(m_Controls.getTabbedComponent()->getTabContentComponent(0))->getOSCcontrol2()->WaveformIndex;
    p.m_OSC2_Vol = &dynamic_cast<OSCPage*>(m_Controls.getTabbedComponent()->getTabContentComponent(0))->m_OSCMixerValue;

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
    m_Controls.setBounds(getBounds());
    m_keyboardComponent.setBounds(getBounds().removeFromBottom(150));
}
