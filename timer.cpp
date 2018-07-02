#ifndef _WIN32
#include "Timer.h"

Timer:: Timer(bool start) 
{
	is_stopped = true;
	Stop();
	elapsed_us = 0;
}

void Timer :: Start(bool Reset)   // Start from current value or optionally from 0
{
	if (!is_stopped) return;
	
	if (Reset) elapsed_us = 0;
		
	is_stopped = false;
	gettimeofday(&Tps,NULL);
}

void Timer:: Stop()
{ 
	if (is_stopped) return;
	   
	gettimeofday(&Tpf, NULL);
	elapsed_us = elapsed_us + Elapsedus();
	is_stopped = true;
}

const double Timer:: Elapsedus()	// Returns elapsed time in microseconds   
{
	if (is_stopped)	
		return elapsed_us;
	else
		gettimeofday(&Tpf, NULL);

	return double ( (Tpf.tv_sec - Tps.tv_sec)*1000000 + (Tpf.tv_usec-Tps.tv_usec) + elapsed_us);
} 

#endif
