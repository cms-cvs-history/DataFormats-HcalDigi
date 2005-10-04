#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/Handle.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "DataFormats/HcalDigi/interface/HcalDigiCollections.h"
#include "FWCore/Framework/interface/Selector.h"
#include <iostream>

using namespace std;


/** \class HcalDigiDump
      
$Date: 2005/10/04 13:37:35 $
$Revision: 1.3 $
\author J. Mans - Minnesota
*/
class HcalDigiDump : public edm::EDAnalyzer {
public:
  explicit HcalDigiDump(edm::ParameterSet const& conf);
  virtual void analyze(edm::Event const& e, edm::EventSetup const& c);
};


HcalDigiDump::HcalDigiDump(edm::ParameterSet const& conf) {
}

void HcalDigiDump::analyze(edm::Event const& e, edm::EventSetup const& c) {
  std::vector<edm::Handle<HBHEDigiCollection> > hbhe;
  std::vector<edm::Handle<HODigiCollection> > ho;
  std::vector<edm::Handle<HFDigiCollection> > hf;
  
  try {
    e.getManyByType(hbhe);
    //      cout << "Selected " << hbhe.size() << endl;
    std::vector<edm::Handle<HBHEDigiCollection> >::iterator i;
    for (i=hbhe.begin(); i!=hbhe.end(); i++) {
      const HBHEDigiCollection& c=*(*i);
      
      for (HBHEDigiCollection::const_iterator j=c.begin(); j!=c.end(); j++)
	cout << *j << std::endl;
    }
  } catch (...) {
    cout << "No HB/HE Digis." << endl;
  }
  
  try {
    e.getManyByType(hf);
    //      cout << "Selected " << hf.size() << endl;
    std::vector<edm::Handle<HFDigiCollection> >::iterator i;
    for (i=hf.begin(); i!=hf.end(); i++) {
      const HFDigiCollection& c=*(*i);
      
      for (HFDigiCollection::const_iterator j=c.begin(); j!=c.end(); j++)
	cout << *j << std::endl;
    }
  } catch (...) {
    cout << "No HF Digis." << endl;
  }
  
  try {
    e.getManyByType(ho);
    //      cout << "Selected " << ho.size() << endl;
    std::vector<edm::Handle<HODigiCollection> >::iterator i;
    for (i=ho.begin(); i!=ho.end(); i++) {
      const HODigiCollection& c=*(*i);
      
      for (HODigiCollection::const_iterator j=c.begin(); j!=c.end(); j++)
	cout << *j << std::endl;

    }
  } catch (...) {
    cout << "No HO Digis." << endl;
  }
  
  cout << endl;    
}

#include "PluginManager/ModuleDef.h"
#include "FWCore/Framework/interface/MakerMacros.h"

DEFINE_SEAL_MODULE();
DEFINE_ANOTHER_FWK_MODULE(HcalDigiDump)

