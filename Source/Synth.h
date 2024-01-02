/*
  ==============================================================================

    Synth.h
    Created: 12 Dec 2023 11:31:05am
    Author:  rjbal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Voice.h"
#include "NoiseGenerator.h"

class Synth
{
public:
    Synth();

    void allocateResources(double sampleRate_, int samplesPerBlock);
    void deallocateResources();
    void reset();
    void render(float** outputBuffers, int sampleCount);
    void midiMessage(uint8_t data0, uint8_t data1, uint8_t data2);

    float noiseMix;
    float envAttack;
    float envDecay;
    float envSustain;
    float envRelease;
    float oscMix;
    float detune;

private:
    float sampleRate;
    Voice voice;

    void noteOn(int note, int velocity);
    void noteOff(int note);
    NoiseGenerator noiseGen;
};