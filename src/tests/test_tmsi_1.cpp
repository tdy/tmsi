/**
 * @brief Tmsi Amplifier Driver
 * @date 11 Jan 2013
 * @author Albero Valero
 * Distributed under LGPL license
 */


#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/program_options.hpp>

#include <stdlib.h>
#define __STDC_LIMIT_MACROS
#include <stdint.h>
#include <iostream>

#include "tmsi/tmsiamplifier.h"
#include "sys_utils/time.h"

using namespace boost::posix_time;
using namespace std;
namespace po=boost::program_options;

int test_driver(int argc, char ** argv, Amplifier *amp);

int main(int argc,char** argv){

    TmsiAmplifier amp; //!< Amplifier driver

    try{
        test_driver(argc,argv, &amp);
        return 0;
    }
    catch (char const* msg){
        cerr<< "Amplifier exception: "<<msg<<"\n";
    }

    catch (exception * ex){
        cerr << "Amplifier exception: "<<ex->what()<<"\n";
    }

    return -1;

}


/*
 * Simple C++ Test Suite
 */
int test_driver(int argc, char ** argv, Amplifier *amp){
    int length;
    int saw;
    double time_diff;

//    Channel * ampSaw, *driverSaw;

    po::options_description options("Program Options");

    options.add_options()
            ("length,l",po::value<int>(&length)->default_value(5),"Length of the test in seconds")
            ("help,h","Show help")
            ("start","Start sampling")
            ("saw",po::value<int>(&saw)->default_value(0),"Set expected Saw difference. If set driver will monitor samples lost")
            ("time",po::value<double>(&time_diff)->default_value(0.0),"Monitor time difference. Display error, when difference between expected timestamps is bigger then give value");

    options.add(amp->get_options());
    cout << options <<"\n";

    po::variables_map vm;
    po::store(po::parse_command_line(argc,argv,options),vm);
    po::notify(vm);
    amp->init(vm);

    int sample_rate = amp->get_sampling_rate();

    //ampSaw=amp->get_description()->find_channel("Saw");
    //driverSaw=amp->get_description()->find_channel("Driver_Saw");

    //channels comma separated
    amp->set_active_channels_string("1"); //ExG2
    vector<Channel *> channels = amp->get_active_channels();
    int last_saw=-1;

    dout << "Found " << channels.size() << " active channels" << dendl;

    amp->start_sampling();

    double start_time=amp->get_sample_timestamp();

    cout.precision(3);
    while(true){
        channels[0]->get_sample();
        channels[0]->get_raw_sample();
    }

    amp->stop_sampling();
    return 0;

}
