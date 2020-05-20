/*
  ==============================================================================

    WaveVoiceSine.h
    Created: 20 May 2020 10:35:40am
    Author:  alexe

  ==============================================================================
*/

#pragma once
#include "WaveTable.h"
template <typename t>
class WaveVoiceSine : public Wavetable<t>
{
public:
    WaveVoiceSine(size_t size = 48000) : Wavetable(size) {

    }


    void CreateTable(size_t size) override {
        m_audioBufferSize = size;
        m_audioBuffer = std::vector<t>(size);
        t angleDelta = 0.0f;
        t currentAngle = 0.0f;
        auto cyclesPerSample = 1.0f / (t)m_audioBufferSize;
        angleDelta = cyclesPerSample * 2.0 * MathConstants<double>::pi;
        for (int i = 0; i < size; i++)
        {
            t SinSample = std::sin(currentAngle);
            currentAngle += angleDelta;
            m_audioBuffer.at(i) = (SinSample);
        }
    }

private:

};