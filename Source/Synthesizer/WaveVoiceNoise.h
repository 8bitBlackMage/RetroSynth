/*
  ==============================================================================

    WaveVoiceNoise.h
    Created: 20 May 2020 10:36:16am
    Author:  alexe

  ==============================================================================
*/

#pragma once
#include "WaveTable.h"
#include "JuceHeader.h"
template <typename t>
class WaveVoiceNoise : public Wavetable<t> {

public:
    WaveVoiceNoise(size_t size) : Wavetable(size) {}
    void CreateTable(size_t size) override {
        m_audioBufferSize = size;
        m_audioBuffer = std::vector<t>(size);
        Random random;

        for (int i = 0; i < size; i++)
        {
            m_audioBuffer.at(i) = (t)random.nextDouble();
        }
       

    }
};