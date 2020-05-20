/*
  ==============================================================================

    WaveVoicePulse.h
    Created: 19 May 2020 11:39:16am
    Author:  alexe

  ==============================================================================
*/

#pragma once
#include "WaveTable.h"
template <typename t>
class WaveVoicePulse : public Wavetable<t>
{
public:
    WaveVoicePulse(size_t size = 48000) : Wavetable(size) {

    }


    void CreateTable(size_t size) override {
        m_audioBufferSize = size;
        m_audioBuffer = std::vector<t>(size);
        t angleDelta =0.0f;
        t currentAngle = 0.0f;
        auto cyclesPerSample = 1.0f / (t)m_audioBufferSize;
        angleDelta = cyclesPerSample * 2.0 * MathConstants<double>::pi;
        for (int i = 0; i < size; i++)
        {
            t SinSample = std::sin(currentAngle);
            currentAngle += angleDelta;
             m_audioBuffer.at(i) = (Signum( SinSample) * 0.3);
        }
    }

private:
    t Signum(t value) {
        return (t(0) < value) - (value < t(0));
        return (t(0) < value) - (value < t(0));
    }
};
