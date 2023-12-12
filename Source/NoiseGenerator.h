/*
  ==============================================================================

    NoiseGenerator.h
    Created: 12 Dec 2023 12:39:34pm
    Author:  rjbal

  ==============================================================================
*/

#pragma once

class NoiseGenerator
{
public:
    void reset()
    {
        noiseSeed = 22222;
    }

    float nextValue()
    {
        // Generate the next integer pseudorandom number
        noiseSeed = noiseSeed * 196314165 + 907633515;

        // convert to a signed value
        int temp = int(noiseSeed >> 7) - 16777216;

        // Convert to a floating-point value between -1.0 and 1.0.
        return float(temp) / 16777216.0f;
    }

private:
    unsigned int noiseSeed;
};