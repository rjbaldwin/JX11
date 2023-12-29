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
        level = multiplier * (level - target) + target;
        return level;
    }

    void reset()
    {
        level = 0.0f;
        target = 0.0f;
        multiplier = 0.0f;
    }

    void release()
    {
        target = 0.0f;
        multiplier = releaseMultiplier;
    }

    inline bool isActive() const
    {
        return level > SILENCE;
    }

    float level;
    float multiplier;
    float target;

    float attackMultiplier;
    float decayMultiplier;
    float sustainLevel;
    float releaseMultiplier;


};
