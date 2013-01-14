/**
 * @brief Tmsi Amplifier Driver
 * @date 11 Jan 2013
 * @author Albero Valero
 * Distributed under LGPL license
 *
 * Initial version taken from OpenBCI framework (http://git.braintech.pl/openbci.git)
 */

#ifndef LOGGER_H
#define	LOGGER_H
#include <ctime>
#include <iostream>
#include <stdarg.h>
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::posix_time;

using namespace std;
class Logger{
public:
    int sampling;
    int number_of_samples;
    ptime start_time,last_pack_time;
    const char * name;
    Logger(int p_sampling, const char * p_name);
    void restart();
    void next_sample();
    char * header(char * buffer);
    void info(const char * string,...);
    ostream & info();
};


#endif	/* LOGGER_H */

