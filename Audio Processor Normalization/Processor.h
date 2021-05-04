/*
  ===================================================================
  Project Name: Semester Project
  Author: Victor A. Percival
  Date: 05/03/21
  Filename: Processor.h
  ===================================================================
*/


#ifndef CLASS_PROCESSOR_H
#define CLASS_PROCESSOR_H

class Processor
{
private:
	/**
	* These values will be used to assist in the calculation of
	* normalization.
	*/
	float peakAmplitude;
	float newAmplitude;
	float newMultiplier;
public:
	Processor(void);
	~Processor(void);

	/**
	 * These functions are used to find the peak amplitude and 
	 * normalize the audio of the audio file.
	 */
	float findAmplitude(float peakAmplitude);
	const float multiplier(float newAmplitude / float peakAmplitude);
};

#endif //CLASS_PROCESSOR_H