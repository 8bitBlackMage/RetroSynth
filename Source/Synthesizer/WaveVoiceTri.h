/*
  ==============================================================================

    WaveVoiceTri.h
    Created: 20 May 2020 10:35:52am
    Author:  alexe

  ==============================================================================
*/

#pragma once
#include "WaveTable.h"

template <typename t>
class WaveVoiceTri : public Wavetable<t> {
public:
    WaveVoiceTri(size_t size): Wavetable<t>(size) {

    }

    void CreateTable(size_t size) override
    {
        Wavetable<t>::m_audioBufferSize = size;
        Wavetable<t>::m_audioBuffer = std::vector<t>(size);
        t incriment =  1.0f / size;
        t sample = 0.0f;
        for (int i = 0; i < size; i++)
        {
            Wavetable<t>::m_audioBuffer.at(i) = ((sample *2.0f) - 0.5f);
            if (i < size * 0.5f)
            {
                sample += incriment;
            }
            else
            {
                sample -= incriment;
            }
        }
    }
};