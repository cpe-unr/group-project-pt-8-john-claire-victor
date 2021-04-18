#ifndef CLASS_PROCESSOR_H
#define CLASS_PROCESSOR_H

class Processor
{
private:
	float peakAmplitude;
	float newAmplitude;
	float newMultiplier;
public:
	Processor(void);
	~Processor(void);

	float findAmplitude(float peakAmplitude);
	const float multiplier(float newAmplitude / float peakAmplitude);
};

#endif //CLASS_PROCESSOR_H