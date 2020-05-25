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
class ADSRPage  : public Component,
                  public Slider::Listener,
                  public ComboBox::Listener
{
public:
    //==============================================================================
    ADSRPage ();
    ~ADSRPage() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    ADSR::Parameters ampPerams;
    ADSR::Parameters filterPerams;
    int numberOfVoices;
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Slider> m_amp_attack;
    std::unique_ptr<Slider> m_filter_attack;
    std::unique_ptr<ComboBox> m_Number_of_Voices;
    std::unique_ptr<Slider> m_amp_decay;
    std::unique_ptr<Slider> m_amp_sustain;
    std::unique_ptr<Slider> m_amp_release;
    std::unique_ptr<Slider> m_filter_decay;
    std::unique_ptr<Slider> m_filter_sustain;
    std::unique_ptr<Slider> m_filter_release;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ADSRPage)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

