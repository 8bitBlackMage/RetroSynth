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
#include "FilterControl.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class FilterPage  : public Component,
                    public ComboBox::Listener,
                    public Slider::Listener
{
public:
    //==============================================================================
    FilterPage ();
    ~FilterPage() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    FilterControl* GetFilterControl1()
    {
        return m_FilterControl1.get();
    }
    FilterControl* GetFilterControl2()
    {
        return m_FilterControl2.get();
    }
    int FilterMode;
    double EnvelopeAmount;
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<FilterControl> m_FilterControl1;
    std::unique_ptr<FilterControl> m_FilterControl2;
    std::unique_ptr<ComboBox> m_FilterMode;
    std::unique_ptr<Slider> m_Envelope_Amount;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilterPage)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

