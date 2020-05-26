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

#include "ADSRPage.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ADSRPage::ADSRPage ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    m_amp_attack.reset (new Slider ("amp attack"));
    addAndMakeVisible (m_amp_attack.get());
    m_amp_attack->setRange (0.1, 1, 0);
    m_amp_attack->setSliderStyle (Slider::RotaryVerticalDrag);
    m_amp_attack->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    m_amp_attack->setColour (Slider::thumbColourId, Colour (0xff0a2463));
    m_amp_attack->addListener (this);

    m_amp_attack->setBounds (150, 40, 150, 150);

    m_filter_attack.reset (new Slider ("filter attack"));
    addAndMakeVisible (m_filter_attack.get());
    m_filter_attack->setRange (0, 10, 0);
    m_filter_attack->setSliderStyle (Slider::RotaryVerticalDrag);
    m_filter_attack->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    m_filter_attack->setColour (Slider::thumbColourId, Colour (0xff247ba0));
    m_filter_attack->addListener (this);

    m_filter_attack->setBounds (150, 226, 150, 150);

    m_amp_decay.reset (new Slider ("amp decay"));
    addAndMakeVisible (m_amp_decay.get());
    m_amp_decay->setRange (0.1, 1, 0);
    m_amp_decay->setSliderStyle (Slider::RotaryVerticalDrag);
    m_amp_decay->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    m_amp_decay->setColour (Slider::thumbColourId, Colour (0xff0a2463));
    m_amp_decay->addListener (this);

    m_amp_decay->setBounds (304, 40, 150, 150);

    m_amp_sustain.reset (new Slider ("amp sustain"));
    addAndMakeVisible (m_amp_sustain.get());
    m_amp_sustain->setRange (0.1, 1, 0);
    m_amp_sustain->setSliderStyle (Slider::RotaryVerticalDrag);
    m_amp_sustain->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    m_amp_sustain->setColour (Slider::thumbColourId, Colour (0xff0a2463));
    m_amp_sustain->addListener (this);

    m_amp_sustain->setBounds (456, 40, 150, 150);

    m_amp_release.reset (new Slider ("amp release"));
    addAndMakeVisible (m_amp_release.get());
    m_amp_release->setRange (0.1, 1, 0);
    m_amp_release->setSliderStyle (Slider::RotaryVerticalDrag);
    m_amp_release->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    m_amp_release->setColour (Slider::thumbColourId, Colour (0xff0a2463));
    m_amp_release->addListener (this);

    m_amp_release->setBounds (608, 40, 150, 150);

    m_filter_decay.reset (new Slider ("filter decay"));
    addAndMakeVisible (m_filter_decay.get());
    m_filter_decay->setRange (0, 10, 0);
    m_filter_decay->setSliderStyle (Slider::RotaryVerticalDrag);
    m_filter_decay->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    m_filter_decay->setColour (Slider::thumbColourId, Colour (0xff247ba0));
    m_filter_decay->addListener (this);

    m_filter_decay->setBounds (304, 226, 150, 150);

    m_filter_sustain.reset (new Slider ("filter sustain"));
    addAndMakeVisible (m_filter_sustain.get());
    m_filter_sustain->setRange (0, 10, 0);
    m_filter_sustain->setSliderStyle (Slider::RotaryVerticalDrag);
    m_filter_sustain->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    m_filter_sustain->setColour (Slider::thumbColourId, Colour (0xff247ba0));
    m_filter_sustain->addListener (this);

    m_filter_sustain->setBounds (456, 226, 150, 150);

    m_filter_release.reset (new Slider ("filter release"));
    addAndMakeVisible (m_filter_release.get());
    m_filter_release->setRange (0, 10, 0);
    m_filter_release->setSliderStyle (Slider::RotaryVerticalDrag);
    m_filter_release->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    m_filter_release->setColour (Slider::thumbColourId, Colour (0xff247ba0));
    m_filter_release->addListener (this);

    m_filter_release->setBounds (608, 226, 150, 150);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (640, 480);


    //[Constructor] You can add your own custom stuff here..
    m_amp_attack->onValueChange = [this]() {
        ampPerams.attack = m_amp_attack->getValue();
    };
    m_amp_decay->onValueChange = [this]() {
        ampPerams.decay = m_amp_decay->getValue();
    };
    m_amp_sustain->onValueChange = [this]() {
        ampPerams.sustain = m_amp_sustain->getValue();
    };
    m_amp_release->onValueChange = [this]() {
        ampPerams.release = m_amp_release->getValue();
    };
    m_filter_attack->onValueChange = [this]() {
        filterPerams.attack = m_filter_attack->getValue();
    };
    m_filter_decay->onValueChange = [this]() {
        filterPerams.decay = m_filter_decay->getValue();
    };
    m_filter_sustain->onValueChange = [this]() {
        filterPerams.sustain = m_filter_sustain->getValue();
    };
    m_filter_release->onValueChange = [this]() {
        filterPerams.release = m_filter_release->getValue();
    };


    //[/Constructor]
}

ADSRPage::~ADSRPage()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_amp_attack = nullptr;
    m_filter_attack = nullptr;
    m_amp_decay = nullptr;
    m_amp_sustain = nullptr;
    m_amp_release = nullptr;
    m_filter_decay = nullptr;
    m_filter_sustain = nullptr;
    m_filter_release = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ADSRPage::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff605f5e));

    {
        int x = -20, y = 100, width = 200, height = 30;
        String text (TRANS("Amplifer"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = -20, y = 284, width = 200, height = 30;
        String text (TRANS("Filter"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 124, y = 188, width = 200, height = 30;
        String text (TRANS("Attack"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 276, y = 188, width = 200, height = 30;
        String text (TRANS("Decay"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 428, y = 188, width = 200, height = 30;
        String text (TRANS("Sustain"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 580, y = 188, width = 200, height = 30;
        String text (TRANS("Release"));
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

void ADSRPage::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ADSRPage::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_amp_attack.get())
    {
        //[UserSliderCode_m_amp_attack] -- add your slider handling code here..
        //[/UserSliderCode_m_amp_attack]
    }
    else if (sliderThatWasMoved == m_filter_attack.get())
    {
        //[UserSliderCode_m_filter_attack] -- add your slider handling code here..
        //[/UserSliderCode_m_filter_attack]
    }
    else if (sliderThatWasMoved == m_amp_decay.get())
    {
        //[UserSliderCode_m_amp_decay] -- add your slider handling code here..
        //[/UserSliderCode_m_amp_decay]
    }
    else if (sliderThatWasMoved == m_amp_sustain.get())
    {
        //[UserSliderCode_m_amp_sustain] -- add your slider handling code here..
        //[/UserSliderCode_m_amp_sustain]
    }
    else if (sliderThatWasMoved == m_amp_release.get())
    {
        //[UserSliderCode_m_amp_release] -- add your slider handling code here..
        //[/UserSliderCode_m_amp_release]
    }
    else if (sliderThatWasMoved == m_filter_decay.get())
    {
        //[UserSliderCode_m_filter_decay] -- add your slider handling code here..
        //[/UserSliderCode_m_filter_decay]
    }
    else if (sliderThatWasMoved == m_filter_sustain.get())
    {
        //[UserSliderCode_m_filter_sustain] -- add your slider handling code here..
        //[/UserSliderCode_m_filter_sustain]
    }
    else if (sliderThatWasMoved == m_filter_release.get())
    {
        //[UserSliderCode_m_filter_release] -- add your slider handling code here..
        //[/UserSliderCode_m_filter_release]
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

<JUCER_COMPONENT documentType="Component" className="ADSRPage" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="640" initialHeight="480">
  <BACKGROUND backgroundColour="ff605f5e">
    <TEXT pos="-20 100 200 30" fill="solid: ffffffff" hasStroke="0" text="Amplifer"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="-20 284 200 30" fill="solid: ffffffff" hasStroke="0" text="Filter"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="124 188 200 30" fill="solid: ffffffff" hasStroke="0" text="Attack"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="276 188 200 30" fill="solid: ffffffff" hasStroke="0" text="Decay"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="428 188 200 30" fill="solid: ffffffff" hasStroke="0" text="Sustain"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="580 188 200 30" fill="solid: ffffffff" hasStroke="0" text="Release"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <SLIDER name="amp attack" id="7306013f1a2ec368" memberName="m_amp_attack"
          virtualName="" explicitFocusOrder="0" pos="150 40 150 150" thumbcol="ff0a2463"
          min="0.1" max="1.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="filter attack" id="4d9f80155e221640" memberName="m_filter_attack"
          virtualName="" explicitFocusOrder="0" pos="150 226 150 150" thumbcol="ff247ba0"
          min="0.0" max="10.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="amp decay" id="62644c62a89e36b6" memberName="m_amp_decay"
          virtualName="" explicitFocusOrder="0" pos="304 40 150 150" thumbcol="ff0a2463"
          min="0.1" max="1.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="amp sustain" id="ad1376cd40f50de8" memberName="m_amp_sustain"
          virtualName="" explicitFocusOrder="0" pos="456 40 150 150" thumbcol="ff0a2463"
          min="0.1" max="1.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="amp release" id="3e0ae671e637be31" memberName="m_amp_release"
          virtualName="" explicitFocusOrder="0" pos="608 40 150 150" thumbcol="ff0a2463"
          min="0.1" max="1.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="filter decay" id="1bbee7e041d90af5" memberName="m_filter_decay"
          virtualName="" explicitFocusOrder="0" pos="304 226 150 150" thumbcol="ff247ba0"
          min="0.0" max="10.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="filter sustain" id="998e43782a4d2232" memberName="m_filter_sustain"
          virtualName="" explicitFocusOrder="0" pos="456 226 150 150" thumbcol="ff247ba0"
          min="0.0" max="10.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="filter release" id="34dd07c52577a11c" memberName="m_filter_release"
          virtualName="" explicitFocusOrder="0" pos="608 226 150 150" thumbcol="ff247ba0"
          min="0.0" max="10.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

