/*
  ==============================================================================

    Voice.h
    Created: 12 Dec 2023 11:30:12am
    Author:  rjbal

  ==============================================================================
*/

#pragma once
#include"Oscillator.h"

struct Voice
{
    int note;
    Oscillator osc;

    void reset()
    {
        note = 0;
        osc.reset();
    }

    float render()
    {
        return osc.nextSample();
    }
};
