/*
  ==============================================================================

    Phasor.h
    Created: 16 May 2020 12:22:32pm
    Author:  alexe

  ==============================================================================
*/

#pragma once


class RetroSynthPhasor {
public: 
    RetroSynthPhasor(double samplerate = 44100, double frequency = 440);
    void setSampleRate(double samplerate);
    void setFrequency(double frequency);
    void tick();
    double getPhase();
    double getFreq();

private:
    double m_frequency;
    double m_sampleRate;
    double m_phaseInc;
    double m_phase;
};