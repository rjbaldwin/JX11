/*
  ==============================================================================

    Utils.h
    Created: 12 Dec 2023 1:21:10pm
    Author:  rjbal

  ==============================================================================
*/

#pragma once
#include<cmath>
#include<JuceHeader.h>

inline void protectYourEars(float* buffer, int sampleCount)
{
    if (buffer == nullptr) { return; }
    bool firstWarning = true;
    for (int i = 0; i < sampleCount; ++i)
    {
        float x = buffer[i];
        bool silence = false;
        if (std::isnan(x))
        {
            DBG("!!! WARNING: nan detected in audio buffer, silencing !!!");
            silence = true;
        }
        else if (std::isinf(x))
        {
            DBG("!!! WARNING: inf detected in audio buffer, silencing !!!");
            silence = true;
        }
        else if (x < -2.0f || x>2.0f)
        {
            // screaming feedback
            DBG("!!! WARNING: sample out of range, silencing !!!");
            silence = true;
        }
        else if (x < -1.0f)
        {
            if (firstWarning)
            {
                DBG("!!! WARNING: Sample out of range, clamping !!!");
                firstWarning = false;
            }
            buffer[i] = -1.0f;
        }
        else if(x > 1.0f)
        {
            if (firstWarning)
            {
                DBG("!!! WARNING: Sample out of range, clamping !!!");
                firstWarning = false;
            }
            buffer[i] = 1.0f;
        }
        if (silence)
        {
            memset(buffer, 0, sampleCount * sizeof(float));
            return;
        }
      
    }


}