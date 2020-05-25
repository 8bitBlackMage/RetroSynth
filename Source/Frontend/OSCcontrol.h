/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.7

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class OSCcontrol  : public Component,
                    public ComboBox::Listener
{
public:
    //==============================================================================
    OSCcontrol ();
    ~OSCcontrol() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    float OSC_FrequencyMod;
    float OSC_Detune;
    int WaveformIndex;
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Slider> m_OSC_Freq;
    std::unique_ptr<Slider> m_OSC_Detune;
    std::unique_ptr<ComboBox> m_WaveForm_selctor;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OSCcontrol)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

