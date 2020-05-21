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

#include "OSCcontrol.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
OSCcontrol::OSCcontrol ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    m_OSC1_Volume.reset (new Slider ("OSC1_Volume"));
    addAndMakeVisible (m_OSC1_Volume.get());
    m_OSC1_Volume->setRange (0, 1, 0);
    m_OSC1_Volume->setSliderStyle (Slider::RotaryVerticalDrag);
    m_OSC1_Volume->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);

    m_OSC1_Volume->setBounds (40, 10, 75, 75);

    m_OSC1_Volume2.reset (new Slider ("OSC1_Volume"));
    addAndMakeVisible (m_OSC1_Volume2.get());
    m_OSC1_Volume2->setRange (0, 1, 0);
    m_OSC1_Volume2->setSliderStyle (Slider::RotaryVerticalDrag);
    m_OSC1_Volume2->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);

    m_OSC1_Volume2->setBounds (152, 10, 75, 75);

    comboBox.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBox.get());
    comboBox->setEditableText (false);
    comboBox->setJustificationType (Justification::centredLeft);
    comboBox->setTextWhenNothingSelected (String());
    comboBox->setTextWhenNoChoicesAvailable (TRANS("OSC off"));
    comboBox->addItem (TRANS("Sine"), 1);
    comboBox->addItem (TRANS("Square"), 2);
    comboBox->addItem (TRANS("Triangle"), 3);
    comboBox->addItem (TRANS("NES Triangle"), 4);
    comboBox->addListener (this);

    comboBox->setBounds (256, 40, 150, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (640, 150);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

OSCcontrol::~OSCcontrol()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_OSC1_Volume = nullptr;
    m_OSC1_Volume2 = nullptr;
    comboBox = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void OSCcontrol::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff505050));

    {
        int x = -20, y = 84, width = 200, height = 30;
        String text (TRANS("OSC Volume"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 92, y = 84, width = 200, height = 30;
        String text (TRANS("OSC Detune"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 228, y = 84, width = 200, height = 30;
        String text (TRANS("OSC WaveForm"));
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

void OSCcontrol::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void OSCcontrol::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBox.get())
    {
        //[UserComboBoxCode_comboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="OSCcontrol" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="640" initialHeight="150">
  <BACKGROUND backgroundColour="ff505050">
    <TEXT pos="-20 84 200 30" fill="solid: ffffffff" hasStroke="0" text="OSC Volume"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="92 84 200 30" fill="solid: ffffffff" hasStroke="0" text="OSC Detune"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="228 84 200 30" fill="solid: ffffffff" hasStroke="0" text="OSC WaveForm"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <SLIDER name="OSC1_Volume" id="27c5e9cffffc8a85" memberName="m_OSC1_Volume"
          virtualName="" explicitFocusOrder="0" pos="40 10 75 75" min="0.0"
          max="1.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="OSC1_Volume" id="580d060b041dc1b9" memberName="m_OSC1_Volume2"
          virtualName="" explicitFocusOrder="0" pos="152 10 75 75" min="0.0"
          max="1.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <COMBOBOX name="new combo box" id="171c38ddab1a8569" memberName="comboBox"
            virtualName="" explicitFocusOrder="0" pos="256 40 150 24" editable="0"
            layout="33" items="Sine&#10;Square&#10;Triangle&#10;NES Triangle"
            textWhenNonSelected="" textWhenNoItems="OSC off"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

