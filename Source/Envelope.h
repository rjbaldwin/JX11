/*
  ==============================================================================

    Envelope.h
    Created: 21 Dec 2023 11:53:11am
    Author:  rjbal

  ==============================================================================
*/

#pragma once

const float SILENCE = 0.0001f;

class Envelope
{
public:
    float nextValue()
    {
        level *= multiplier;
        return level;
    }

    float level;
    float multiplier;

};
