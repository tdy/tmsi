/**
 * @brief tmsi test program
 *
 * TMSi Porti7 amplifier test with fusbi usb
 * Requires Fusbi Kernel Module Installed
 *
 * @author Alberto Valero
 * @date 11 Jan 2012
 */

#include "TmsiAmplifier.h"
#include "cpp_amplifiers/base/test_amplifier.h"

int main(int argc,char** argv){
    TmsiAmplifier amp;
    try {
        test_driver(argc,argv,&amp);
    } catch (exception& e) {
        cerr << "Exception: "<<e.what();
    }
}
