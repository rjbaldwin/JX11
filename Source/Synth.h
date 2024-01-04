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
    float tune;

    static constexpr int MAX_VOICES = 16;
    int numVoices;

private:
    float sampleRate;
    //Voice voice;
    std::array<Voice, MAX_VOICES> voices;

    void noteOn(int note, int velocity);
    void noteOff(int note);
    void startVoice(int v, int note, int velocity);
    NoiseGenerator noiseGen;

    float calcPeriod(int note) const;
    float pitchBend;


};