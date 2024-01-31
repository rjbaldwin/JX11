
#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "RotaryKnob.h"

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

    using ButtonAttachment = AVPTS::ButtonAttachment;
    juce::TextButton polyModeButton;
    ButtonAttachment polyModeAttachment{ audioProcessor.apvts, ParameterID::polyMode.getParamID(), polyModeButton };

   

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JX11AudioProcessorEditor)
};
