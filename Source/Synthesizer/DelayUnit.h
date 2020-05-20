/*
  ==============================================================================

    DelayUnit.h
    Created: 20 May 2020 3:56:10pm
    Author:  alexe

  ==============================================================================
*/

#pragma once
#include <vector>
#include <cmath>

typedef std::vector<float> DelayBuffer;

class DelayUnit
{
    DelayBuffer m_buffer;
    int m_writePos, m_maxDelay;

    double CubicInterpolate(
        double y0, double y1,
        double y2, double y3,
        double mu)
    {
        //thanks Paul Bourke
        double a0, a1, a2, a3, mu2;

        mu2 = mu * mu;
        a0 = y3 - y2 - y0 + y1;
        a1 = y0 - y1 - a0;
        a2 = y2 - y0;
        a3 = y1;

        return(a0 * mu * mu2 + a1 * mu2 + a2 * mu + a3);
    }


public:
    ///Basic Delay Unit constructor with a default size of 128 samples
    DelayUnit(int maximumDelay = 128) :
        //Initialises values in the order of declaration
        m_writePos(0),
        m_maxDelay(maximumDelay)
    {
        //m_buffer.resize(maximumDelay);
       
        for (int i = 0; i < maximumDelay; i++) {
            m_buffer.push_back(0);
        }

    };
    ///Advance the write position and check that it is in bounds
    void tick()
    {
        ++m_writePos;

        while (m_writePos >= m_maxDelay) m_writePos -= m_maxDelay;
        while (m_writePos < 0) m_writePos += m_maxDelay;
    }

    ///Returns a delayed signal/value at a given Sample Time
    float getDelay(float delayTime)
    {
        float delayInt, delayRemain;
        delayRemain = modf(delayTime, &delayInt);
        float y1(delayInt - 1), y2(delayInt), y3(delayInt + 1), y4(delayInt + 2);

        while (y1 > m_maxDelay) y1 -= m_maxDelay;
        while (y1 < 0) y1 += m_maxDelay;

        while (y2 > m_maxDelay) y2 -= m_maxDelay;
        while (y2 < 0) y2 += m_maxDelay;

        while (y3 > m_maxDelay) y3 -= m_maxDelay;
        while (y3 < 0) y3 += m_maxDelay;

        while (y4 > m_maxDelay) y4 -= m_maxDelay;
        while (y4 < 0) y4 += m_maxDelay;

        return CubicInterpolate(y1, y2, y3, y4, delayRemain);
    }

    ///Writes sample to buffer. Clips audio to range -1 to 1.
    void writeDelay(float sample, bool clip = true, bool replace = true)
    {

        if (clip) //Allows clipping functionality to be turned off
        {
            if (sample > 1) sample = 1;
            if (sample < -1) sample = -1;
        }
        if (replace)
        {
            m_buffer[m_writePos] = sample;
        }
        else
        {
            m_buffer[m_writePos] += sample;

            if (clip) //Allows clipping functionality to be turned off
            {
                if (m_buffer[m_writePos] > 1) m_buffer[m_writePos] = 1;
                if (m_buffer[m_writePos] < -1) m_buffer[m_writePos] = -1;
            }
        }
        tick();

    }


    ///Clears the buffer when delay is resumed after a pause.
    void clear()
    {
        //  m_buffer.clear();
        for (int n = 0; n < m_buffer.size(); ++n) {
            m_buffer[n] = 0;
        }
    }
};
