/*
  ==============================================================================

    BiquadFilter.h
    Created: 20 May 2020 3:56:18pm
    Author:  alexe

  ==============================================================================
*/

#include "DelayUnit.h"
#include "JuceHeader.h"
#include <cmath>
#include <vector>

template <typename t>
class Biquad 
{
public:
	Biquad(t cutoff = 20000, t res = 10, t samplerate = 44100, t dbgain = 1.0) :M_Cutoff(cutoff), M_Res(res), M_samplerate(samplerate), M_DBGain(dbgain)
	{
		Calculate_intermediates(M_Cutoff, M_Res, M_samplerate, M_DBGain);

	}
	void resetsamplerate(int samplerate)
	{
		M_samplerate = samplerate;
		Calculate_intermediates(M_Cutoff, M_Res, M_samplerate, M_DBGain);
	}
	void ChangeFreq(t CutoffFreq) {
		M_Cutoff = CutoffFreq;
		Calculate_intermediates(M_Cutoff, M_Res, M_samplerate, M_DBGain);
	}
	void changeRes(t Res) {
		M_Res = Res;
		Calculate_intermediates(M_Cutoff, M_Res, M_samplerate, M_DBGain);
	}
	void changeGain(t gain) {
		M_DBGain = gain;
		Calculate_intermediates(M_Cutoff, M_Res, M_samplerate, M_DBGain);
	}
	t process_samples(t sample) {
		float processed = ((b[0] * sample) + (b[1] * xi1) + (b[2] * xi2) - (a[1] * yi1) - (a[2] * yi2)) * a[0];
		xi2 = xi1;
		xi1 = sample;
		yi2 = yi1;
		yi1 = processed;
		
		return processed;
	}

	t getCuttof() {
		return M_Cutoff;
	}
	t getRes() {
		return M_Res;
	}
	virtual void changeVal() = 0;
private:
	t A;
	int M_samplerate;
	t M_Cutoff;
	t M_Res;
	t M_DBGain;
	void Calculate_intermediates(t Cutoff, t Res, t SampleRate, t DbGain)
	{
		A = pow(10, DbGain / 20);
		omega = juce::MathConstants<t>::twoPi * (Cutoff / SampleRate);
		alpha = sin(omega) / (2 * Res);
	}
protected:
	t xi1 = 0;
	t xi2 = 0;
	t yi1 = 0;
	t yi2 = 0;

	t a[3];
	t b[3];
	t alpha = 0;
	t omega = 0;
};

template <typename t>
class LowPass : public Biquad<t>
{
public:

    using Biquad<t>::a; 
    using Biquad<t>::b; 
    using Biquad<t>::alpha;
    using Biquad<t>::omega;
    using Biquad<t>::xi1; 
    using Biquad<t>::xi2; 
    using Biquad<t>::yi1; 
    using Biquad<t>::yi2; 
 

	LowPass(t cutoff, t res, t samplerate, t dbgain) :Biquad<t>(cutoff, res, samplerate, dbgain) {

		b[0] = (1 - cos(omega)) / 2;
		b[1] = 1 - cos(omega);
		b[2] = (1 - cos(omega)) / 2;

		a[0] = 1 / (1 + alpha);
		a[1] = -2 * cos(omega);
		a[2] = 1 - alpha;
	}
	void changeVal() override{
		b[0] = (1 - cos(omega)) / 2;
		b[1] = 1 - cos(omega);
		b[2] = (1 - cos(omega)) / 2;

		a[0] = 1 / (1 + alpha);
		a[1] = -2 * cos(omega);
		a[2] = 1 - alpha;
		xi1 = 0;
		xi2 = 0;
		yi1 = 0;
		yi2 = 0;
	}

};

template <typename t>
class HighPass : public Biquad<t>
{
public:

    using Biquad<t>::a; 
    using Biquad<t>::b; 
    using Biquad<t>::alpha;
    using Biquad<t>::omega;
    using Biquad<t>::xi1; 
    using Biquad<t>::xi2; 
    using Biquad<t>::yi1; 
    using Biquad<t>::yi2; 


	HighPass() {}
	HighPass(t cutoff, t res, t samplerate, t dbgain) :Biquad<t>(cutoff, res, samplerate, dbgain) {
		b[0] = (1 + cos(omega)) / 2;
		b[1] = -(1 + cos(omega));
		b[2] = (1 + cos(omega)) / 2;

		a[0] = 1 / (1 + alpha);
		a[1] = 2 * cos(omega);
		a[2] = 1 - alpha;
	}
	void changeVal() override {
		b[0] = (1 + cos(omega)) / 2;
		b[1] = -(1 + cos(omega));
		b[2] = (1 + cos(omega)) / 2;

		a[0] = 1 / (1 + alpha);
		a[1] = 2 * cos(omega);
		a[2] = 1 - alpha;
		xi1 = 0;
		xi2 = 0;
		yi1 = 0;
		yi2 = 0;

	}



};