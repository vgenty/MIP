/**
 * \file MCFlasher.h
 *
 * \ingroup meep
 * 
 * \brief Class def header for a class MCFlasher
 *
 * @author vgenty
 */

/** \addtogroup meep

    @{*/

#ifndef LARLITE_MCFLASHER_H
#define LARLITE_MCFLASHER_H

#include "Analysis/ana_base.h"

#include "DataFormat/mctrack.h"
#include "DataFormat/opflash.h"

namespace larlite {

  class MCFlasher : public ana_base{
  
  public:

    /// Default constructor
    MCFlasher() : _outtree(nullptr), _opflash(nullptr), _mctrack(nullptr) { _name="MCFlasher"; _fout=0;}

    /// Default destructor
    virtual ~MCFlasher(){}


    virtual bool initialize();
    virtual bool analyze(storage_manager* storage);
    virtual bool finalize();



    larlite::event_opflash* getflashes() { return _opflash; }
    larlite::event_mctrack* gettracks()  { return _mctrack; }
      
  protected:

  private:
    TTree * _outtree;
    larlite::event_opflash* _opflash;
    larlite::event_mctrack* _mctrack;

  };
}
#endif

//**************************************************************************
// 
// For Analysis framework documentation, read Manual.pdf here:
//
// http://microboone-docdb.fnal.gov:8080/cgi-bin/ShowDocument?docid=3183
//
//**************************************************************************

/** @} */ // end of doxygen group 
