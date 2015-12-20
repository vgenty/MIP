/**
 * \file ThroughGoingFilter.h
 *
 * \ingroup meep 
 * 
 * \brief Class def header for a class ThroughGoingFilter
 *
 * @author vic
 */

/** \addtogroup MichelElectron

    @{*/

#ifndef LARLITE_THROUGHGOINGFILTER_H
#define LARLITE_THROUGHGOINGFILTER_H

#include "Analysis/ana_base.h"
#include "DataFormat/mctrack.h"

//stolen from kas

namespace larlite {
  /**
     \class ThroughGoingFilter
     User custom analysis class made by SHELL_USER_NAME
   */
  class ThroughGoingFilter : public ana_base{
  
  public:

    /// Default constructor
    ThroughGoingFilter();

    /// Default destructor
    virtual ~ThroughGoingFilter(){}

    
    virtual bool initialize();
    virtual bool analyze(storage_manager* storage);
    virtual bool finalize();

    Int_t get_num_filtered() { return _kept_events; }

    void Stopping(bool on) { _stopping = on; }

    void Filter(bool on) { _filter = on; }

    void Pure(bool on) { _pure = on; }

    double GetEndEnergy() { return _E; }

    bool Passes() { return _pass; }

    
    
  protected:
    
    bool _stopping;

    bool _filter;
    
    bool _pass;
    
    int _kept_events;
    int _total_events;

    double _E;

    // boolean for a pure sample: i.e. ignore muons 
    // with end energy > 10 and < 100 MeV
    bool _pure;

  private:

    bool outside(const larlite::mcstep& step);

  };
}
#endif

