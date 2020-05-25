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
#include "OSCPage.h"
#include "FilterPage.h"
#include "ADSRPage.h"
//[/Headers]

#include "MainPage.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...

//[/MiscUserDefs]

//==============================================================================
MainPage::MainPage ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    tabbedComponent.reset (new TabbedComponent (TabbedButtonBar::TabsAtTop));
    addAndMakeVisible (tabbedComponent.get());
    tabbedComponent->setTabBarDepth (36);
    tabbedComponent->addTab (TRANS("Oscilator"), Colours::lightgrey, new OSCPage(), true);
    tabbedComponent->addTab (TRANS("Filter"), Colours::lightgrey, new FilterPage(), true);
    tabbedComponent->addTab (TRANS("ADSR"), Colours::lightgrey, new ADSRPage(), true);
    tabbedComponent->setCurrentTabIndex (0);

    tabbedComponent->setBounds (0, 0, 1024, 480);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (1024, 768);


    //[Constructor] You can add your own custom stuff here..

    //[/Constructor]
}

MainPage::~MainPage()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    tabbedComponent = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainPage::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff605f5e));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainPage::resized()
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

<JUCER_COMPONENT documentType="Component" className="MainPage" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="1024" initialHeight="768">
  <BACKGROUND backgroundColour="ff605f5e"/>
  <TABBEDCOMPONENT name="new tabbed component" id="406aa28d76829b57" memberName="tabbedComponent"
                   virtualName="" explicitFocusOrder="0" pos="0 0 1024 480" orientation="top"
                   tabBarDepth="36" initialTab="0">
    <TAB name="Oscilator" colour="ffd3d3d3" useJucerComp="0" contentClassName="OSCPage"
         constructorParams="" jucerComponentFile=""/>
    <TAB name="Filter" colour="ffd3d3d3" useJucerComp="0" contentClassName="FilterPage"
         constructorParams="" jucerComponentFile=""/>
    <TAB name="ADSR" colour="ffd3d3d3" useJucerComp="0" contentClassName="ADSRPage"
         constructorParams="" jucerComponentFile=""/>
  </TABBEDCOMPONENT>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

