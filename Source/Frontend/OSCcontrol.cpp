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

    m_OSC_Volume.reset (new Slider ("OSC Volume"));
    addAndMakeVisible (m_OSC_Volume.get());
    m_OSC_Volume->setRange (0, 1, 0);
    m_OSC_Volume->setSliderStyle (Slider::RotaryVerticalDrag);
    m_OSC_Volume->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    m_OSC_Volume->setColour (Slider::thumbColourId, Colour (0xff164f71));

    m_OSC_Volume->setBounds (40, 10, 75, 75);

    m_OSC_Detune.reset (new Slider ("OSC Detune"));
    addAndMakeVisible (m_OSC_Detune.get());
    m_OSC_Detune->setRange (0, 1, 0);
    m_OSC_Detune->setSliderStyle (Slider::RotaryVerticalDrag);
    m_OSC_Detune->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    m_OSC_Detune->setColour (Slider::thumbColourId, Colour (0xff164f71));

    m_OSC_Detune->setBounds (152, 10, 75, 75);

    m_WaveForm_selctor.reset (new ComboBox ("Waveform Selector"));
    addAndMakeVisible (m_WaveForm_selctor.get());
    m_WaveForm_selctor->setEditableText (false);
    m_WaveForm_selctor->setJustificationType (Justification::centredLeft);
    m_WaveForm_selctor->setTextWhenNothingSelected (String());
    m_WaveForm_selctor->setTextWhenNoChoicesAvailable (TRANS("OSC off"));
    m_WaveForm_selctor->addItem (TRANS("Sine"), 1);
    m_WaveForm_selctor->addItem (TRANS("Square"), 2);
    m_WaveForm_selctor->addItem (TRANS("Triangle"), 3);
    m_WaveForm_selctor->addItem (TRANS("NES Triangle"), 4);
    m_WaveForm_selctor->addListener (this);

    m_WaveForm_selctor->setBounds (256, 40, 150, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (640, 150);


    //[Constructor] You can add your own custom stuff here..
    m_OSC_Volume->onValueChange = [this]() {
        OSC_Volume = m_OSC_Volume->getValue();
    };
    m_OSC_Detune->onValueChange = [this]() {
        OSC_Detune = m_OSC_Detune->getValue();
    };
    m_WaveForm_selctor->onChange = [this]() {
        WaveformIndex = m_WaveForm_selctor->getSelectedItemIndex();
    };





    //[/Constructor]
}

OSCcontrol::~OSCcontrol()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_OSC_Volume = nullptr;
    m_OSC_Detune = nullptr;
    m_WaveForm_selctor = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void OSCcontrol::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff605f5e));

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

    if (comboBoxThatHasChanged == m_WaveForm_selctor.get())
    {
        //[UserComboBoxCode_m_WaveForm_selctor] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_WaveForm_selctor]
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
  <BACKGROUND backgroundColour="ff605f5e">
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
  <SLIDER name="OSC Volume" id="27c5e9cffffc8a85" memberName="m_OSC_Volume"
          virtualName="" explicitFocusOrder="0" pos="40 10 75 75" thumbcol="ff164f71"
          min="0.0" max="1.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="OSC Detune" id="580d060b041dc1b9" memberName="m_OSC_Detune"
          virtualName="" explicitFocusOrder="0" pos="152 10 75 75" thumbcol="ff164f71"
          min="0.0" max="1.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <COMBOBOX name="Waveform Selector" id="171c38ddab1a8569" memberName="m_WaveForm_selctor"
            virtualName="" explicitFocusOrder="0" pos="256 40 150 24" editable="0"
            layout="33" items="Sine&#10;Square&#10;Triangle&#10;NES Triangle"
            textWhenNonSelected="" textWhenNoItems="OSC off"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

