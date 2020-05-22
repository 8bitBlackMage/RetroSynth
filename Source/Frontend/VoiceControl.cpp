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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "VoiceControl.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
VoiceControl::VoiceControl ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    m_OSCControl1.reset (new OSCcontrol());
    addAndMakeVisible (m_OSCControl1.get());
    m_OSCControl1->setName ("OSC Controller 1");

    m_OSCControl1->setBounds (8, 24, 640, 150);

    m_OSCcontrol2.reset (new OSCcontrol());
    addAndMakeVisible (m_OSCcontrol2.get());
    m_OSCcontrol2->setName ("OSC Control 2");

    m_OSCcontrol2->setBounds (8, 192, 640, 150);

    m_OSCMixer.reset (new Slider ("new slider"));
    addAndMakeVisible (m_OSCMixer.get());
    m_OSCMixer->setRange (0, 10, 0);
    m_OSCMixer->setSliderStyle (Slider::RotaryVerticalDrag);
    m_OSCMixer->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);

    m_OSCMixer->setBounds (680, 104, 150, 150);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (640, 480);


    //[Constructor] You can add your own custom stuff here..
    m_OSCMixer->onValueChange = [this]() {m_OSCMixerValue = m_OSCMixer->getValue(); };

    //[/Constructor]
}

VoiceControl::~VoiceControl()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_OSCControl1 = nullptr;
    m_OSCcontrol2 = nullptr;
    m_OSCMixer = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void VoiceControl::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff505050));

    {
        int x = 660, y = 252, width = 200, height = 30;
        String text (TRANS("OSC Mixer"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void VoiceControl::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="VoiceControl" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="640" initialHeight="480">
  <BACKGROUND backgroundColour="ff505050">
    <TEXT pos="660 252 200 30" fill="solid: ffffffff" hasStroke="0" text="OSC Mixer"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <GENERICCOMPONENT name="OSC Controller 1" id="3d2802861ac69e42" memberName="m_OSCControl1"
                    virtualName="" explicitFocusOrder="0" pos="8 24 640 150" class="OSCcontrol"
                    params=""/>
  <GENERICCOMPONENT name="OSC Control 2" id="173f459860a2f5a2" memberName="m_OSCcontrol2"
                    virtualName="" explicitFocusOrder="0" pos="8 192 640 150" class="OSCcontrol"
                    params=""/>
  <SLIDER name="new slider" id="e6e4e8161ac40fd1" memberName="m_OSCMixer"
          virtualName="" explicitFocusOrder="0" pos="680 104 150 150" min="0.0"
          max="10.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

