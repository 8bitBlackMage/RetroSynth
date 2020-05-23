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

#include "FilterControl.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
FilterControl::FilterControl ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    m_VCF_Cutoff.reset (new Slider ("VCF Cutoff"));
    addAndMakeVisible (m_VCF_Cutoff.get());
    m_VCF_Cutoff->setRange (0, 10, 0);
    m_VCF_Cutoff->setSliderStyle (Slider::RotaryVerticalDrag);
    m_VCF_Cutoff->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    m_VCF_Cutoff->addListener (this);

    m_VCF_Cutoff->setBounds (40, 10, 75, 75);

    m_VCF_Res.reset (new Slider ("VCF Resonance"));
    addAndMakeVisible (m_VCF_Res.get());
    m_VCF_Res->setRange (0, 10, 0);
    m_VCF_Res->setSliderStyle (Slider::RotaryVerticalDrag);
    m_VCF_Res->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    m_VCF_Res->addListener (this);

    m_VCF_Res->setBounds (152, 10, 75, 75);

    comboBox.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBox.get());
    comboBox->setEditableText (false);
    comboBox->setJustificationType (Justification::centredLeft);
    comboBox->setTextWhenNothingSelected (String());
    comboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox->addItem (TRANS("Lowpass"), 1);
    comboBox->addItem (TRANS("Highpass"), 2);
    comboBox->addItem (TRANS("Bandpass"), 3);
    comboBox->addListener (this);

    comboBox->setBounds (256, 40, 150, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (640, 150);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

FilterControl::~FilterControl()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_VCF_Cutoff = nullptr;
    m_VCF_Res = nullptr;
    comboBox = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void FilterControl::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff505050));

    {
        int x = -20, y = 84, width = 200, height = 30;
        String text (TRANS("Cutoff"));
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
        String text (TRANS("Resonance"));
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
        String text (TRANS("Filter Type"));
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

void FilterControl::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void FilterControl::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_VCF_Cutoff.get())
    {
        //[UserSliderCode_m_VCF_Cutoff] -- add your slider handling code here..
        //[/UserSliderCode_m_VCF_Cutoff]
    }
    else if (sliderThatWasMoved == m_VCF_Res.get())
    {
        //[UserSliderCode_m_VCF_Res] -- add your slider handling code here..
        //[/UserSliderCode_m_VCF_Res]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void FilterControl::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
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

<JUCER_COMPONENT documentType="Component" className="FilterControl" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="640" initialHeight="150">
  <BACKGROUND backgroundColour="ff505050">
    <TEXT pos="-20 84 200 30" fill="solid: ffffffff" hasStroke="0" text="Cutoff"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="92 84 200 30" fill="solid: ffffffff" hasStroke="0" text="Resonance"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="228 84 200 30" fill="solid: ffffffff" hasStroke="0" text="Filter Type"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <SLIDER name="VCF Cutoff" id="1be29174ea790e31" memberName="m_VCF_Cutoff"
          virtualName="" explicitFocusOrder="0" pos="40 10 75 75" min="0.0"
          max="10.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="VCF Resonance" id="6dcbc1d4b225705f" memberName="m_VCF_Res"
          virtualName="" explicitFocusOrder="0" pos="152 10 75 75" min="0.0"
          max="10.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <COMBOBOX name="new combo box" id="afaceff72b2c552c" memberName="comboBox"
            virtualName="" explicitFocusOrder="0" pos="256 40 150 24" editable="0"
            layout="33" items="Lowpass&#10;Highpass&#10;Bandpass" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

