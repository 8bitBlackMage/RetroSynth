/*
  ==============================================================================

    WaveTable.h
    Created: 16 May 2020 12:19:24pm
    Author:  alexe

  ==============================================================================
*/

#pragma once
#include <vector>
template <typename t>
class Wavetable {
public:
    Wavetable(size_t Size): m_audioBufferSize(Size)
    {
        CreateTable(m_audioBufferSize);
    }
    ~Wavetable()
    {
    }




    t getSample(size_t position)
    {
        while (position >= m_audioBufferSize)
        {
            position -= m_audioBufferSize;
        }

        return m_audioBuffer[position];
    }
    void pushSample(t Sample, size_t position)
    {
        while (position >= m_audioBufferSize)
        {
            position -= m_audioBufferSize;
        }
        m_audioBuffer[position] = Sample;
    }
    virtual void CreateTable(size_t TableSize)
    {

    }

    size_t getSize()
    {
        return m_audioBuffer.size();
    }

protected:
    size_t m_audioBufferSize;
    std::vector<t> m_audioBuffer;
};

