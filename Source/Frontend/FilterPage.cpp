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

#include "FilterPage.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
FilterPage::FilterPage ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    m_FilterControl1.reset (new FilterControl());
    addAndMakeVisible (m_FilterControl1.get());
    m_FilterControl1->setName ("Filter Control 1 ");

    m_FilterControl1->setBounds (8, 24, 640, 150);

    m_FilterControl2.reset (new FilterControl());
    addAndMakeVisible (m_FilterControl2.get());
    m_FilterControl2->setName ("Filter Control 2");

    m_FilterControl2->setBounds (8, 192, 640, 150);

    m_FilterMode.reset (new ComboBox ("Filter Mode"));
    addAndMakeVisible (m_FilterMode.get());
    m_FilterMode->setEditableText (false);
    m_FilterMode->setJustificationType (Justification::centredLeft);
    m_FilterMode->setTextWhenNothingSelected (String());
    m_FilterMode->setTextWhenNoChoicesAvailable (String());
    m_FilterMode->addItem (TRANS("Serial"), 1);
    m_FilterMode->addItem (TRANS("parallel"), 2);
    m_FilterMode->addListener (this);

    m_FilterMode->setBounds (664, 88, 150, 24);

    m_Envelope_Amount.reset (new Slider ("Envelope Amount"));
    addAndMakeVisible (m_Envelope_Amount.get());
    m_Envelope_Amount->setRange (0, 10, 0);
    m_Envelope_Amount->setSliderStyle (Slider::RotaryVerticalDrag);
    m_Envelope_Amount->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    m_Envelope_Amount->setColour (Slider::thumbColourId, Colour (0xfffb3640));
    m_Envelope_Amount->addListener (this);

    m_Envelope_Amount->setBounds (697, 212, 75, 75);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (640, 480);


    //[Constructor] You can add your own custom stuff here..

    m_FilterMode->onChange = [this]
    {
        FilterMode = m_FilterMode->getSelectedId();
    };
    m_Envelope_Amount->onValueChange = [this]
    {
        EnvelopeAmount = m_Envelope_Amount->getValue();
    };
    //[/Constructor]
}

FilterPage::~FilterPage()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_FilterControl1 = nullptr;
    m_FilterControl2 = nullptr;
    m_FilterMode = nullptr;
    m_Envelope_Amount = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void FilterPage::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff605f5e));

    {
        int x = 636, y = 124, width = 200, height = 30;
        String text (TRANS("Filter Configuration"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 636, y = 292, width = 200, height = 30;
        String text (TRANS("Envelope amount"));
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

void FilterPage::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void FilterPage::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == m_FilterMode.get())
    {
        //[UserComboBoxCode_m_FilterMode] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_FilterMode]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void FilterPage::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_Envelope_Amount.get())
    {
        //[UserSliderCode_m_Envelope_Amount] -- add your slider handling code here..
        //[/UserSliderCode_m_Envelope_Amount]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="FilterPage" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="640" initialHeight="480">
  <BACKGROUND backgroundColour="ff605f5e">
    <TEXT pos="636 124 200 30" fill="solid: ffffffff" hasStroke="0" text="Filter Configuration"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="636 292 200 30" fill="solid: ffffffff" hasStroke="0" text="Envelope amount"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <GENERICCOMPONENT name="Filter Control 1 " id="b7530f29acbbacbd" memberName="m_FilterControl1"
                    virtualName="" explicitFocusOrder="0" pos="8 24 640 150" class="FilterControl"
                    params=""/>
  <GENERICCOMPONENT name="Filter Control 2" id="1e476266eadc7c33" memberName="m_FilterControl2"
                    virtualName="" explicitFocusOrder="0" pos="8 192 640 150" class="FilterControl"
                    params=""/>
  <COMBOBOX name="Filter Mode" id="217075eea1cef814" memberName="m_FilterMode"
            virtualName="" explicitFocusOrder="0" pos="664 88 150 24" editable="0"
            layout="33" items="Serial&#10;parallel" textWhenNonSelected=""
            textWhenNoItems=""/>
  <SLIDER name="Envelope Amount" id="8668bccd0423e080" memberName="m_Envelope_Amount"
          virtualName="" explicitFocusOrder="0" pos="697 212 75 75" thumbcol="fffb3640"
          min="0.0" max="10.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

