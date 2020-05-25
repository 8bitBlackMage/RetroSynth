/*
  ==============================================================================

    Phasor.cpp
    Created: 16 May 2020 12:22:32pm
    Author:  alexe

  ==============================================================================
*/

#include "Phasor.h"
#include <assert.h>
RetroSynthPhasor::RetroSynthPhasor(double samplerate, double frequency):
    m_sampleRate(samplerate),
    m_frequency(frequency), 
    m_phase(0.0),
    m_phaseInc(m_frequency / m_sampleRate)
{
}

void RetroSynthPhasor::setSampleRate(double samplerate)
{
    m_sampleRate = samplerate;

    m_phaseInc = m_frequency / m_sampleRate;
}

void RetroSynthPhasor::setFrequency(double frequency)
{
    if (frequency > 0.0) {
        m_frequency = frequency;
        
        m_phaseInc = m_frequency / m_sampleRate;
    }
}

void RetroSynthPhasor::tick()
{
    m_phase += m_phaseInc;

    while (m_phase >= 1)
    {
        m_phase -= 1;
    }
}

double RetroSynthPhasor::getPhase()
{
    return m_phase;
}

double RetroSynthPhasor::getFreq()
{
    return m_frequency;
}
