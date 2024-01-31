
#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "RotaryKnob.h"
#include "LookAndFeel.h"

class JX11AudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    JX11AudioProcessorEditor (JX11AudioProcessor&);
    ~JX11AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JX11AudioProcessor& audioProcessor;

    using AVPTS = juce::AudioProcessorValueTreeState;
    using SliderAttachment = AVPTS::SliderAttachment;

    RotaryKnob outputLevelKnob;
    SliderAttachment outputLevelAttachment{ audioProcessor.apvts, ParameterID::outputLevel.getParamID(), outputLevelKnob.slider };

    RotaryKnob filterResoKnob;
    SliderAttachment filterResoAttachment{ audioProcessor.apvts, ParameterID::filterReso.getParamID(), filterResoKnob.slider };

    RotaryKnob oscTuneKnob;
    SliderAttachment oscTuneAttachment{ audioProcessor.apvts, ParameterID::oscTune.getParamID(), oscTuneKnob.slider };

    RotaryKnob oscFineTuneKnob;
    SliderAttachment oscFineTuneAttachment{ audioProcessor.apvts, ParameterID::oscFine.getParamID(), oscFineTuneKnob.slider };

    RotaryKnob oscMixKnob;
    SliderAttachment oscMixAttachment{ audioProcessor.apvts, ParameterID::oscMix.getParamID(), oscMixKnob.slider };

    RotaryKnob glideModeKnob;
    SliderAttachment glideModeAttachment{ audioProcessor.apvts, ParameterID::glideMode.getParamID(), glideModeKnob.slider };

    using ButtonAttachment = AVPTS::ButtonAttachment;
    juce::TextButton polyModeButton;
    ButtonAttachment polyModeAttachment{ audioProcessor.apvts, ParameterID::polyMode.getParamID(), polyModeButton };

    RotaryKnob glideRateKnob;
    SliderAttachment glideRateAttachment{ audioProcessor.apvts, ParameterID::glideRate.getParamID(), glideRateKnob.slider };

    RotaryKnob glideBendKnob;
    SliderAttachment glideBendAttachment{ audioProcessor.apvts, ParameterID::glideBend.getParamID(), glideBendKnob.slider };

    RotaryKnob filterFreqKnob;
    SliderAttachment filterFreqAttachment{ audioProcessor.apvts, ParameterID::filterFreq.getParamID(), filterFreqKnob.slider };

    RotaryKnob filterEnvKnob;
    SliderAttachment filterEnvAttachment{ audioProcessor.apvts, ParameterID::filterEnv.getParamID(), filterEnvKnob.slider };

    RotaryKnob filterLFOKnob;
    SliderAttachment filterLFOAttachment{ audioProcessor.apvts, ParameterID::filterLFO.getParamID(), filterLFOKnob.slider };

    LookAndFeel globalLNF;
   

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JX11AudioProcessorEditor)
};
