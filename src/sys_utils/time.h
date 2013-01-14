#pragma once

#include <iostream>
#include "config.h"


#ifdef HAVE_CLOCK_GETTIME
		#include <time.h>
		typedef struct timespec tictoc;
	#else
		#ifdef HAVE_GETTIMEOFDAY
			#include <sys/time.h>
			typedef struct timeval tictoc;
		#else
			#include <ctime>
			typedef time_t tictoc;
		#endif
	#endif






using namespace std;

class BBTime
{
    friend ostream& operator<<(ostream& os, const BBTime& t);

public:
    BBTime(void){}
    ~BBTime(void){}	
    void   tic();   /* start timing. */
    double toc();   /* stop  timing. */

private:
	tictoc tv;
	
};
