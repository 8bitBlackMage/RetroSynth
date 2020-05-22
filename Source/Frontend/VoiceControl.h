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
#include "OSCcontrol.h"
#include <JuceHeader.h>
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class VoiceControl  : public Component
{
public:
    //==============================================================================
    VoiceControl ();
    ~VoiceControl() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    OSCcontrol* getOSCcontrol1() {
        return m_OSCControl1.get();
    }
    OSCcontrol* getOSCcontrol2() {
        return m_OSCcontrol2.get();
    }
    double getMixSliderValue()
    {
        return m_OSCMixerValue;
    }
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    double m_OSCMixerValue;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<OSCcontrol> m_OSCControl1;
    std::unique_ptr<OSCcontrol> m_OSCcontrol2;
    std::unique_ptr<Slider> m_OSCMixer;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VoiceControl)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

