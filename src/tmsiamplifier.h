/**
 * @brief Tmsi Amplifier Driver
 * @date 11 Jan 2013
 * @author Albero Valero
 * Distributed under LGPL license
 *
 * Initial version taken from OpenBCI framework
 */

#ifndef TMSIAMPLIFIER_H
#define	TMSIAMPLIFIER_H
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>

#include "nexus.h"
#include "amplifier.h"
#include "tmsiamplifierdesc.h"
#include "amplifierdescription.h"

#define BLUETOOTH_AMPLIFIER 1
#define USB_AMPLIFIER 2
#define IP_AMPLIFIER 3
#define MESSAGE_SIZE 1024*1024
#define CHAN_TYPE_DIG 4
#define KEEP_ALIVE_RATE 1 //seconds between every keep_alive message
#define MAX_ERRORS 10
#define MAX_ERRORS 10
using namespace std;
#undef debug
#ifdef AMP_DEBUG
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define in_debug(...) __VA_ARGS__;
#else
#define debug(...) ;
#define in_debug(...) ;
#endif


/**
 * @brief The TmsiAmplifier class API
 * API for TMSi Amplifier.
 * Supports Fusbi USB, bluetooth, and IP connection
 * @author Macias@OpenBCI (modified by Alberto Valero)
 */
class TmsiAmplifier : public Amplifier {

public:
    /**
     * @brief Default TmsiAmplifier Constructor
     */
    TmsiAmplifier();

    virtual ~TmsiAmplifier();


private:
    int fd; //!< Devide descriptor
    int read_fd; //!< File Descriptor for reading
    int dump_fd; //!< File descriptor for writting (saving data)

    tms_frontendinfo_t fei;
    tms_vldelta_info_t vli;
    tms_input_device_t dev;
    tms_acknowledge_t ack;
    tms_rtc_t rtc;
    tms_channel_data_t *channel_data;
    uint8_t msg[MESSAGE_SIZE];
    int br; //actual msg length;
    int channel_data_index;
    int sample_rate_div;
    int keep_alive;
    int read_errors;
    uint mode;

protected:
    virtual double get_expected_sample_time();

public:
    uint get_digi(uint index);

    /**
     * @brief get_sample_int
     * @param index channel index
     * @return sample of index channel
     */
    inline int get_sample_int(uint index){
    	return channel_data[index].data[channel_data_index].isample;
    }

    uint get_base_sample_rate(){
    	return fei.basesamplerate;
    }

    double next_samples(bool synchronize=true);

    /**
     * @brief number_of_channels
     * @return Number of channels of the amplifier
     */
    int number_of_channels() {
        return fei.nrofswchannels;
    }

    uint set_sampling_rate(uint sample_rate);

    void set_sampling_rate_div(uint sampling_rate_div);

    int get_sampling_rate_div() {
        return sample_rate_div;
    }

    void start_sampling();

    void stop_sampling(bool disconnecting=false);

    int refreshInfo();

    boost::program_options::options_description get_options();

    void init(boost::program_options::variables_map &vm);

    void connect_device(uint type,const string &address);

    int get_available_data();

private:

    int connect_usb(const string & address);
    int connect_bluetooth(const string &address);
    int connect_ip(const string &address);
    void read_from(const string &file);
    void dump_to(const string &file);
    int send_request(int type);
    bool update_info(int type);
    bool _refreshInfo(int type);
    tms_channel_data_t* alloc_channel_data(bool vldelta);

    void free_channel_data(tms_channel_data_t * &channel_data);

    void refreshFrontEndInfo();

    void refreshIDData();
    void refreshVLDeltaInfo();
    int _print_message(FILE *, uint8_t * msg, int br);

    int print_message(FILE * f);

    int rcv_message(uint8_t *, int n);
    int fetch_iddata();
    void receive();
    const char * get_type_name(int type);
    void disconnect_mobita();
};

class DummyTmsiAmplifier: public Amplifier{
public:
	DummyTmsiAmplifier():Amplifier(){
		set_description(new DummyAmpDesc(this));
	}
};
#endif	/* TMSIAMPLIFIER_H */

