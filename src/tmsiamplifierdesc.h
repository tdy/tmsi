/**
 * @brief Tmsi Amplifier Driver
 * @author Macias@OpenBCI
 * @date 13 październik 2010, 13:14
 * Modified on 11 Jan 2013 by Alberto Valero
 * Distributed under GPL license
 */

#ifndef TmsiAmplifierDesc_H_
#define TmsiAmplifierDesc_H_
#include "amplifierdescription.h"
#include "tmsichannels.h"
class TmsiAmplifier;
class TmsiAmplifierDesc:public AmplifierDescription{
	vector<Channel *> digi_channels;
public:
	TmsiAmplifierDesc(tms_input_device_t &dev,TmsiAmplifier *amp);
	inline vector<Channel *> get_digi_channels(){
		return digi_channels;
	}
};

#endif /* TmsiAmplifierDesc_H_ */
