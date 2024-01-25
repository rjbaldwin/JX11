
#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"




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

    juce::Slider outputLevelKnob;
    SliderAttachment outputLevelAttachment{ audioProcessor.apvts, ParameterID::outputLevel.getParamID(), outputLevelKnob };

   

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JX11AudioProcessorEditor)
};
