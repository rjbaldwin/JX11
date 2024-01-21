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
    void controlChange(uint8_t data1, uint8_t data2);

    float noiseMix;
    float envAttack;
    float envDecay;
    float envSustain;
    float envRelease;
    float oscMix;
    float detune;
    float tune;
    float volumeTrim;
    static constexpr int MAX_VOICES{ 16 };
    int numVoices;
    juce::LinearSmoothedValue<float> outputLevelSmoother;
    float velocitySensitivity;
    bool ignoreVelocity;
    const int LFO_MAX{ 32 };
    float lfoInc;
    float vibrato;
    float pwmDepth;

    int glideMode;
    float glideRate;
    float glideBend;
    float filterKeyTracking;
    float filterQ;

private:
    void noteOn(int note, int velocity);
    void noteOff(int note);
    void startVoice(int v, int note, int velocity);
    float calcPeriod(int v, int note) const;
    int findFreeVoice() const;
    bool sustainPedalPressed {false};
    void restartMonoVoice(int note, int velocity);
    void shiftQueuedNotes();
    int nextQueuedNote();
    void updateLFO();
    bool isPlayingLegatoStyle() const;

    inline void updatePeriod(Voice& voice)
    {
        voice.osc1.period = voice.period * pitchBend;
        voice.osc2.period = voice.osc1.period * detune;
    }


    float sampleRate;
    std::array<Voice, MAX_VOICES> voices;
    NoiseGenerator noiseGen;
    float pitchBend;
    int lfoStep;
    float lfo;
    float modWheel;
    int lastNote;
    float resonanceCtl;

    

    


};