/*
  ==============================================================================

    Voice.h
    Created: 12 Dec 2023 11:30:12am
    Author:  rjbal

  ==============================================================================
*/

#pragma once
#include "Oscillator.h"
#include "Envelope.h"

struct Voice
{
    int note;
    Oscillator osc1;
    Oscillator osc2;
    float saw;
    Envelope env;
    float period;

    void reset()
    {
        note = 0;
        osc1.reset();
        osc2.reset();
        saw = 0.0f;

        env.reset();
    }

    float render(float input)
    {
        float sample1 = osc1.nextSample();
        float sample2 = osc2.nextSample();
        saw = saw * 0.997f + sample1 - sample2;

        float output = saw + input;
        float envelope = env.nextValue();

        return output * envelope;
    }

    void release()
    {
        env.release();
    }

};
