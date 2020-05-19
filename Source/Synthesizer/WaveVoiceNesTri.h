/*
  ==============================================================================

    WaveVoiceNesTri.h
    Created: 16 May 2020 2:58:28pm
    Author:  alexe

  ==============================================================================
*/

#pragma once
#include "WaveTable.h"


template<typename t>
class  WaveVoiceNesTri : public Wavetable<t> {
public:
    WaveVoiceNesTri(size_t size = 44100):Wavetable<t>(size) {}
    void CreateTable(size_t size) override
    {
        m_audioBufferSize = size;
        m_audioBuffer = std::vector<t>(size);
        //Nes Triangle wave is a 32 step 4 bit wave due to being produced by a shift register
        double StepSize = size / 32;
        t incriment = 1.0f / 16.0f;
        t Sample = 0.0f;
        for (size_t i = 0; i < 32; i++) {
            for (size_t Inc2 = 0; Inc2 < StepSize; Inc2++)
            {
             //   DBG(Inc2 + i);
                m_audioBuffer.at(Inc2 + (i*StepSize)) = (((Sample * 2.0f) - 1.0f)* 0.6f);
            }

            if (i <= 15) {
                Sample += incriment;
            }
            else
            {
                Sample -= incriment;
            }
        

        }
    }
    
    ~WaveVoiceNesTri()
    {

    }
};