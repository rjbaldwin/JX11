/*
  ==============================================================================

    Voice.h
    Created: 12 Dec 2023 11:30:12am
    Author:  rjbal

  ==============================================================================
*/

#pragma once

struct Voice
{
    int note;
    int velocity;

    void reset()
    {
        note = 0;
        velocity = 0;
    }
};
