/*
  ==============================================================================

    SynthSound.h
    Created: 15 May 2020 2:41:29pm
    Author:  alexe

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
struct RetroSynthSound : SynthesiserSound 
{
public: 
    RetroSynthSound(){}

    bool appliesToNote(int) override { return true; }
    bool appliesToChannel(int) override { return true; }
};