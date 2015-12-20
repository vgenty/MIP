#ifndef LARLITE_MCFLASHER_CXX
#define LARLITE_MCFLASHER_CXX

#include "MCFlasher.h"

namespace larlite {

  bool MCFlasher::initialize() {
    //_tree->Branch("_dS","std::vector<double>",&_dS);
    //_outtree->Branch("_X")
    
    return true;
  }
  
  bool MCFlasher::analyze(storage_manager* storage) {
    //this even should have atleast single throughgoing muon which means may be a flash.
  
    //auto ev_mctrack = storage->get_data<event_mctrack>("mcreco");
    auto ev_flash   = storage->get_data<event_opflash>("opflashSat");
    auto ev_mctrack = storage->get_data<event_mctrack>("mcreco");

    _opflash = ev_flash;
    _mctrack = ev_mctrack; 
    
    return true;
  }

  bool MCFlasher::finalize() {
  
    return true;
  }


}
#endif
