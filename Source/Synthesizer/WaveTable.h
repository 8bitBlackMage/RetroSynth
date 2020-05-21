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
    ~Wavetable(){}
    t getSample(double position)
    {
        while (position >= m_audioBufferSize)
        {
            position -= m_audioBufferSize;
        }

        
        float intIndex, remain;
        remain = modf(position, &intIndex);
        t y1(intIndex -1), y2(intIndex), y3(intIndex +1), y4(intIndex +2);
        size_t size = m_audioBuffer.size() - 1;
        while (y1 > size) y1 -= size;
        while (y1 < 0) y1 += size;

        while (y2 > size) y2 -= size;
        while (y2 < 0) y2 += size;

        while (y3 > size) y3 -= size;
        while (y3 < 0) y3 += size;

        while (y4 > size) y4 -= size;
        while (y4 < 0) y4 += size;




        return CubicInterpolate(m_audioBuffer[y1], m_audioBuffer[y2], m_audioBuffer[y3], m_audioBuffer[y4],remain);
       // return m_audioBuffer[position];
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

private:
    t CubicInterpolate(
        t y0, t y1,
        t y2, t y3,
        t mu)
    {
        t a0, a1, a2, a3, mu2;

        mu2 = mu * mu;
        a0 = y3 - y2 - y0 + y1;
        a1 = y0 - y1 - a0;
        a2 = y2 - y0;
        a3 = y1;

        return(a0 * mu * mu2 + a1 * mu2 + a2 * mu + a3);
    }
};

