/*
  ===================================================================
  Project Name: Semester Project
  Author: Victor A. Percival
  Date: 05/03/21
  Filename: Processor.cpp
  ===================================================================
*/


#include <iostream>
#include "Processor.h"
  
int bufferLength = 0;
int buffer[];

float Processor::findAmplitude(float peakAmplitude)
{
	for(size_t idx(0); idx < bufferLength; ++idx)
	{
		peakAmplitude = std::max(peakAmplitude, std::fabs(buffer[idx]));
	}

	if(0.0f >= peakAmplitude)
	{
		std::cout << "The audio signal is silent." << std::endl;
		return;
	}
	return newAmplitude;
}

const float Processor::multiplier(float newAmplitude / float peakAmplitude)
{
	for(size_t idx(0); idx < bufferLength; ++idx)
	{
		buffer[idx] *= newMultiplier;
	}
}