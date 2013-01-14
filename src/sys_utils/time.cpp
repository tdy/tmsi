#include "time.h"
#include <sys/timeb.h>

#ifdef HAVE_CLOCK_GETTIME
#ifdef CLOCK_HIGHRES
#define SAMPLED_CLOCK CLOCK_HIGHRES
#else
#define SAMPLED_CLOCK CLOCK_REALTIME
#endif

void MRTime::tic() {

    if (clock_gettime(SAMPLED_CLOCK, &tv))
        tv.tv_sec = tv.tv_nsec = -1;
}

double MRTime::toc() {
    struct timespec tv2;

    if (clock_gettime(SAMPLED_CLOCK, &tv2))
        tv2.tv_sec = tv2.tv_nsec = -1;

    double  sec = static_cast<double>(tv2.tv_sec - tv.tv_sec);
    double nsec = static_cast<double>(tv2.tv_nsec - tv.tv_nsec);

    return (sec + 1.0e-9 * nsec);
}

#else

#ifdef HAVE_GETTIMEOFDAY

void BBTime::tic() {
    gettimeofday(&tv, 0L);
}

double BBTime::toc() {

    tictoc tv2;

    gettimeofday(&tv2, 0L);
    double  sec = static_cast<double>(tv2.tv_sec - tv.tv_sec);
    double usec = static_cast<double>(tv2.tv_usec - tv.tv_usec);

    return (sec + 1.0e-6 * usec);
}

#else
// Fall back to C/C++ low resolution time function.

void MRTime::precistic() {
    time(&tv);
}

double MRTime::precistoc() {
    tictoc tv2;
    time(&tv2);
    return difftime(tv2, tv);
}
#endif
#endif
