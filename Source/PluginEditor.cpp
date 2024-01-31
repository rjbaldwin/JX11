
#include "PluginProcessor.h"
#include "PluginEditor.h"



JX11AudioProcessorEditor::JX11AudioProcessorEditor (JX11AudioProcessor& p)
    : AudioProcessorEditor (&p), 
      audioProcessor (p)
{
    outputLevelKnob.label = "Level";
    addAndMakeVisible(outputLevelKnob);

    filterResoKnob.label = "Reso";
    addAndMakeVisible(filterResoKnob);

    oscTuneKnob.label = "Osc Tune";
    addAndMakeVisible(oscTuneKnob);

    oscFineTuneKnob.label = "Osc Fine Tune";
    addAndMakeVisible(oscFineTuneKnob);

    oscMixKnob.label = "Osc Mix";
    addAndMakeVisible(oscMixKnob);

    glideModeKnob.label = "Glide Mode";
    addAndMakeVisible(glideModeKnob);

    polyModeButton.setButtonText("Poly");
    polyModeButton.setClickingTogglesState(true);
    addAndMakeVisible(polyModeButton);

    glideRateKnob.label = "Glide Rate";
    addAndMakeVisible(glideRateKnob);

    glideBendKnob.label = "Glide Bend";
    addAndMakeVisible(glideBendKnob);

    filterFreqKnob.label = "Filter Freq";
    addAndMakeVisible(filterFreqKnob);

    filterEnvKnob.label = "Filter Env";
    addAndMakeVisible(filterEnvKnob);

    filterLFOKnob.label = "Filter LFO";
    addAndMakeVisible(filterLFOKnob);


    juce::LookAndFeel::setDefaultLookAndFeel(&globalLNF);
    
    setSize (800, 800);
}

JX11AudioProcessorEditor::~JX11AudioProcessorEditor()
{

}

//==============================================================================
void JX11AudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

  
    
}

void JX11AudioProcessorEditor::resized()
{
    juce::Rectangle r(20, 20, 80, 100);
    outputLevelKnob.setBounds(r);

    

    r = r.withX(r.getRight() + 20);
    oscTuneKnob.setBounds(r);

    r = r.withX(r.getRight() + 20);
    oscFineTuneKnob.setBounds(r);

    r = r.withX(r.getRight() + 20);
    oscMixKnob.setBounds(r);


    polyModeButton.setSize(80,30);
    polyModeButton.setCentrePosition(r.withX(r.getRight()).getCentre());


    // Add a new knob below the existing ones
    r = r.withY(r.getBottom() + 20).withX(20); // Adjust y-coordinate and reset x-coordinate
    glideModeKnob.setBounds(r);

    r = r.withX(r.getRight() + 20);
    glideRateKnob.setBounds(r);

    r = r.withX(r.getRight() + 20);
    glideBendKnob.setBounds(r);

    r = r.withX(r.getRight() + 20);
    filterFreqKnob.setBounds(r);

    // Add a new knob below the existing ones
    r = r.withY(r.getBottom() + 20).withX(20); // Adjust y-coordinate and reset x-coordinate
    filterResoKnob.setBounds(r);

    r = r.withX(r.getRight() + 20);
    filterEnvKnob.setBounds(r);

    r = r.withX(r.getRight() + 20);
    filterLFOKnob.setBounds(r);


    
}
