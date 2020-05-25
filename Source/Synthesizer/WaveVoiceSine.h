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
    WaveVoiceSine(size_t size = 48000) : Wavetable<t>(size) {

    }


    void CreateTable(size_t size) override {
        Wavetable<t>::m_audioBufferSize = size;
        Wavetable<t>:: m_audioBuffer = std::vector<t>(size);
        t angleDelta = 0.0f;
        t currentAngle = 0.0f;
        auto cyclesPerSample = 1.0f / (t)Wavetable<t>::m_audioBufferSize;
        angleDelta = cyclesPerSample * 2.0 * MathConstants<double>::pi;
        for (int i = 0; i < size; i++)
        {
            t SinSample = std::sin(currentAngle);
            currentAngle += angleDelta;
            Wavetable<t>::m_audioBuffer.at(i) = (SinSample);
        }
    }

private:

};