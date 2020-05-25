/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
RetroSynthAudioProcessor::RetroSynthAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
     )                
#endif
   ,m_synth(m_keystate, 2)
{
}

RetroSynthAudioProcessor::~RetroSynthAudioProcessor()
{
}

//==============================================================================
const String RetroSynthAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool RetroSynthAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool RetroSynthAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool RetroSynthAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double RetroSynthAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int RetroSynthAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int RetroSynthAudioProcessor::getCurrentProgram()
{
    return 0;
}

void RetroSynthAudioProcessor::setCurrentProgram (int index)
{
}

const String RetroSynthAudioProcessor::getProgramName (int index)
{
    return {};
}

void RetroSynthAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void RetroSynthAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    m_synth.prepareToPlay(samplesPerBlock,sampleRate);
}

void RetroSynthAudioProcessor::releaseResources()
{
    m_synth.releaseResources();
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool RetroSynthAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void RetroSynthAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    AudioSourceChannelInfo bufferWrapper(&buffer, 0, buffer.getNumSamples());

    m_synth.HandleADSRValues(m_AmpPerameters, m_FilterPerameters);
    m_synth.HandleFilterValues(0, m_VCF1_Cutoff, m_VCF1_Res, m_Filter1Type);
    m_synth.HandleFilterValues(1, m_VCF2_Cutoff, m_VCF2_Res, m_Filter2Type);
    m_synth.HandleOSCValues(1, m_OSC1_Detune, m_OSC1_FrequencyMod, m_Waveform1Index,m_OSC2_Vol );
    m_synth.HandleOSCValues(2, m_OSC2_Detune, m_OSC2_FrequencyMod, m_Waveform2Index, m_OSC2_Vol);
    m_synth.getNextAudioBlock(bufferWrapper);
}

//==============================================================================
bool RetroSynthAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* RetroSynthAudioProcessor::createEditor()
{
    return new RetroSynthAudioProcessorEditor (*this);
}

//==============================================================================
void RetroSynthAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void RetroSynthAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new RetroSynthAudioProcessor();
}
