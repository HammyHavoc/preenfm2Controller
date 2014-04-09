/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "PanelEngine.h"
#include "PanelModulation.h"
//[/Headers]

#include "MainTabs.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainTabs::MainTabs ()
{
    addAndMakeVisible (tabbedComponent = new TabbedComponent (TabbedButtonBar::TabsAtTop));
    tabbedComponent->setTabBarDepth (30);
    tabbedComponent->addTab (TRANS("ENGINE"), Colour (0xffa8c8e4), new PanelEngine(), true);
    tabbedComponent->addTab (TRANS("MODULATIORS"), Colour (0xffcff0e5), new PanelModulation(), true);
    tabbedComponent->addTab (TRANS("ARPEGIATOR"), Colour (0xffe4d2d2), 0, false);
    tabbedComponent->setCurrentTabIndex (1);

    addAndMakeVisible (midiInCombo = new ComboBox ("midi input combo"));
    midiInCombo->setEditableText (false);
    midiInCombo->setJustificationType (Justification::centredLeft);
    midiInCombo->setTextWhenNothingSelected (TRANS("-- select --"));
    midiInCombo->setTextWhenNoChoicesAvailable (TRANS("-- no choice --"));
    midiInCombo->addListener (this);

    addAndMakeVisible (midiInputLabel = new Label ("midi input label",
                                                   TRANS("0")));
    midiInputLabel->setFont (Font (15.00f, Font::plain));
    midiInputLabel->setJustificationType (Justification::centredLeft);
    midiInputLabel->setEditable (false, false, false);
    midiInputLabel->setColour (Label::textColourId, Colours::blue);
    midiInputLabel->setColour (TextEditor::textColourId, Colours::black);
    midiInputLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (midiOutCombo = new ComboBox ("midi output combo"));
    midiOutCombo->setEditableText (false);
    midiOutCombo->setJustificationType (Justification::centredLeft);
    midiOutCombo->setTextWhenNothingSelected (TRANS("-- select --"));
    midiOutCombo->setTextWhenNoChoicesAvailable (TRANS("-- no choice --"));
    midiOutCombo->addListener (this);

    addAndMakeVisible (midiInLabel = new Label ("midi in label",
                                                TRANS("Midi input")));
    midiInLabel->setFont (Font (15.00f, Font::plain));
    midiInLabel->setJustificationType (Justification::centredLeft);
    midiInLabel->setEditable (false, false, false);
    midiInLabel->setColour (TextEditor::textColourId, Colours::black);
    midiInLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (midiOutLabel = new Label ("midi out label",
                                                 TRANS("Midi output")));
    midiOutLabel->setFont (Font (15.00f, Font::plain));
    midiOutLabel->setJustificationType (Justification::centredLeft);
    midiOutLabel->setEditable (false, false, false);
    midiOutLabel->setColour (TextEditor::textColourId, Colours::black);
    midiOutLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (midiInputLabel2 = new Label ("midi input label",
                                                    TRANS("0")));
    midiInputLabel2->setFont (Font (15.00f, Font::plain));
    midiInputLabel2->setJustificationType (Justification::centredLeft);
    midiInputLabel2->setEditable (false, false, false);
    midiInputLabel2->setColour (Label::textColourId, Colours::blue);
    midiInputLabel2->setColour (TextEditor::textColourId, Colours::black);
    midiInputLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (700, 600);


    //[Constructor] You can add your own custom stuff here..
	panelEngine = ((PanelEngine*)tabbedComponent->getTabContentComponent(0));
	panelModulation = ((PanelModulation*)tabbedComponent->getTabContentComponent(1));

    midiInCombo->addItemList(MidiInput::getDevices(), 1);
    midiOutCombo->addItemList(MidiOutput::getDevices(), 1);
    midiInput = nullptr;
    midiOutput = nullptr;
    //[/Constructor]
}

MainTabs::~MainTabs()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	if (midiInput != nullptr) {
		midiInput->stop();
		delete(midiInput);
		midiInput = nullptr;
	}
    //[/Destructor_pre]

    tabbedComponent = nullptr;
    midiInCombo = nullptr;
    midiInputLabel = nullptr;
    midiOutCombo = nullptr;
    midiInLabel = nullptr;
    midiOutLabel = nullptr;
    midiInputLabel2 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainTabs::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::aliceblue);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainTabs::resized()
{
    tabbedComponent->setBounds (10, 24, getWidth() - 20, getHeight() - 34);
    midiInCombo->setBounds (464, 8, 150, 24);
    midiInputLabel->setBounds (464, 32, 72, 16);
    midiOutCombo->setBounds (728, 8, 150, 24);
    midiInLabel->setBounds (392, 8, 80, 24);
    midiOutLabel->setBounds (640, 8, 80, 24);
    midiInputLabel2->setBounds (560, 32, 72, 16);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MainTabs::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == midiInCombo)
    {
        //[UserComboBoxCode_midiInCombo] -- add your combo box handling code here..
    	if (midiInput != nullptr) {
    		midiInput->stop();
    		delete(midiInput);
    	}
    	midiInput = MidiInput::openDevice(midiInCombo->getSelectedItemIndex(), this);
    	if (midiInput != nullptr) {
    		midiInput->start();
    	}
        //[/UserComboBoxCode_midiInCombo]
    }
    else if (comboBoxThatHasChanged == midiOutCombo)
    {
        //[UserComboBoxCode_midiOutCombo] -- add your combo box handling code here..
    	if (midiOutput != nullptr) {
    		delete(midiOutput);
    	}
    	midiOutput = MidiOutput::openDevice(midiOutCombo->getSelectedItemIndex());
    	panelEngine->setMidiOutput(midiOutput);
    	panelModulation->setMidiOutput(midiOutput);
        //[/UserComboBoxCode_midiOutCombo]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void 	MainTabs::handleIncomingMidiMessage (MidiInput *source, const MidiMessage &message) {
	if (message.isController()) {
		switch (message.getControllerNumber()) {
		case 99:
			currentNrpn.paramMSB = message.getControllerValue();
			break;
		case 98:
			currentNrpn.paramLSB = message.getControllerValue();
			break;
		case 6:
			currentNrpn.valueMSB = message.getControllerValue();
			break;
		case 38:
		{
			currentNrpn.valueLSB = message.getControllerValue();
			int param = (int)(currentNrpn.paramMSB << 7) + currentNrpn.paramLSB;
			int value = (int)(currentNrpn.valueMSB << 7) + currentNrpn.valueLSB;

			const MessageManagerLock mmLock;
			midiInputLabel->setText(String(param), sendNotification);
			midiInputLabel2->setText(String(value), sendNotification);
			panelEngine->handleIncomingNrpn(param, value);
			panelModulation->handleIncomingNrpn(param, value);
			break;
		}
		}
	}
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainTabs" componentName=""
                 parentClasses="public Component, public MidiInputCallback" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="700" initialHeight="600">
  <BACKGROUND backgroundColour="fff0f8ff"/>
  <TABBEDCOMPONENT name="new tabbed component" id="f175981f6c34a740" memberName="tabbedComponent"
                   virtualName="TabbedComponent" explicitFocusOrder="0" pos="10 24 20M 34M"
                   orientation="top" tabBarDepth="30" initialTab="1">
    <TAB name="ENGINE" colour="ffa8c8e4" useJucerComp="0" contentClassName="PanelEngine"
         constructorParams="" jucerComponentFile=""/>
    <TAB name="MODULATIORS" colour="ffcff0e5" useJucerComp="0" contentClassName="PanelModulation"
         constructorParams="" jucerComponentFile=""/>
    <TAB name="ARPEGIATOR" colour="ffe4d2d2" useJucerComp="0" contentClassName=""
         constructorParams="" jucerComponentFile=""/>
  </TABBEDCOMPONENT>
  <COMBOBOX name="midi input combo" id="8e92a0bc65751bf0" memberName="midiInCombo"
            virtualName="" explicitFocusOrder="0" pos="464 8 150 24" editable="0"
            layout="33" items="" textWhenNonSelected="-- select --" textWhenNoItems="-- no choice --"/>
  <LABEL name="midi input label" id="f77b232960a175fb" memberName="midiInputLabel"
         virtualName="" explicitFocusOrder="0" pos="464 32 72 16" textCol="ff0000ff"
         edTextCol="ff000000" edBkgCol="0" labelText="0" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="midi output combo" id="9d89a1cd0c9574f3" memberName="midiOutCombo"
            virtualName="" explicitFocusOrder="0" pos="728 8 150 24" editable="0"
            layout="33" items="" textWhenNonSelected="-- select --" textWhenNoItems="-- no choice --"/>
  <LABEL name="midi in label" id="686cd0868f5c506b" memberName="midiInLabel"
         virtualName="" explicitFocusOrder="0" pos="392 8 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Midi input" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="midi out label" id="487ff4211688a9c3" memberName="midiOutLabel"
         virtualName="" explicitFocusOrder="0" pos="640 8 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Midi output" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="midi input label" id="f5bde9938974ba9f" memberName="midiInputLabel2"
         virtualName="" explicitFocusOrder="0" pos="560 32 72 16" textCol="ff0000ff"
         edTextCol="ff000000" edBkgCol="0" labelText="0" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]