#ifndef Timer_H_
#define Timer_H_
#ifndef _WIN32

#include <sys/time.h>
#include <cstdlib>
#include <stdio.h>

class Timer
{
public:
	Timer(bool start = false);
	void Start(bool bReset = false);   // Start from current value or optionally from 0
	void Stop();                       // Stop timing. Use Start afterwards to continue.
	bool IsRunning();                  // Returns FALSE if stopped.
	const double Elapsed();            // Returns elapsed time in seconds
	const double Elapsedms();          // Returns elapsed time in milliseconds 
	const double Elapsedus();          // Returns elapsed time in microseconds
private:
	struct timeval Tps, Tpf;
	struct timezone Tzp;
	double elapsed_us;
	bool is_stopped;
};

inline bool Timer :: IsRunning()       { return !is_stopped;           }              
inline const double Timer::Elapsedms() { return (Elapsedus()/1000);    }
inline const double Timer::Elapsed()   { return (Elapsedus()/1000000); }


#endif //_WIN32
#endif //Timer_H

