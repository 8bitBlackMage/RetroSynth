/*
  ==============================================================================

    SynthVoice.h
    Created: 15 May 2020 2:46:06pm
    Author:  alexe

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
#include "Phasor.h"
#include "BiquadFilter.h"
#include "WaveTable.h"


class RetroSynthVoice : public SynthesiserVoice
{
public:
    RetroSynthVoice(Wavetable<float>* wavetable, double samplerate);
    bool canPlaySound(SynthesiserSound*) override;
    void startNote(int MidiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition) override;
    void stopNote(float Veclocity, bool AllowTailOff) override;
    void setCurrentPlaybackSampleRate(double samplerate) override;
    void pitchWheelMoved(int newValue) override;
    void controllerMoved(int controller, int newvalue) override;
    void renderNextBlock(AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override;

    RetroSynthPhasor m_PhasorA;
    RetroSynthPhasor m_PhasorB;
    Wavetable<float>* m_WavetableA;
    Wavetable<float>* m_WavetableB;
    ADSR m_Envelope;
    Biquad<float> *m_FilterA;
    Biquad<float> *m_FilterB;
    float VolumeA;
    float VolumeB;

    float DetuneA;
    float DetuneB;
    float FreqModA;
    float FreqModB;


    float OSCB_Blend;
private:

};