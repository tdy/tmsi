/**
 * @brief Tmsi Amplifier Driver
 * @author Macias@OpenBCI
 * @date 13 październik 2010, 13:14
 * Modified on 11 Jan 2013 by Alberto Valero
 * Distributed under GPL license
 */

#include "tmsichannels.h"
#include "tmsiamplifier.h"
#include "tmsiamplifierdesc.h"
string TmsiChannel::get_type(){
	return get_main_type()+" "+get_subtype();
}
int TmsiChannel::get_raw_sample(){
	return ((TmsiAmplifier*)amplifier)->get_sample_int(index);
}
int DigiChannel::get_raw_sample(){
	return ((TmsiAmplifier*)amplifier)->get_digi(index);
}
int SpecialChannel::get_raw_sample(){
		vector<Channel *> digi_chan=((TmsiAmplifierDesc*)amplifier->get_description())->get_digi_channels();
		uint res=0;
		uint tmp;
		for (uint i=0;i<digi_chan.size();i++){
			res=(res<<1);
			tmp=digi_chan[i]->get_raw_sample();
			if (tmp&mask)
				res|=1;
		}
		return res;
	}

SpecialChannel::SpecialChannel(string name,uint mask,TmsiAmplifierDesc *desc):GeneratedChannel(name,desc->get_driver()){
		this->bit_length=desc->get_digi_channels().size();
		this->mask=mask;
		}
