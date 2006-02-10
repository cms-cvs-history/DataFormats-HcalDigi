#ifndef DIGIHCAL_HcalCalibDATAFRAME_H
#define DIGIHCAL_HcalCalibDATAFRAME_H

#include "DataFormats/HcalDetId/interface/HcalCalibDetId.h"
#include "DataFormats/HcalDetId/interface/HcalElectronicsId.h"
#include "DataFormats/HcalDigi/interface/HcalQIESample.h"
#include <vector>
#include <ostream>

/** \class HcalCalibDataFrame
       
Precision readout digi for HcalCalib

*/
class HcalCalibDataFrame {
public:
  typedef HcalCalibDetId key_type; ///< For the sorted collection

  HcalCalibDataFrame(); // for persistence
  explicit HcalCalibDataFrame(const HcalCalibDetId& id);
  
  const HcalCalibDetId& id() const { return id_; }
  const HcalElectronicsId& elecId() const { return electronicsId_; }
  
  /// total number of samples in the digi
  int size() const { return size_; }
  /// number of samples before the sample from the triggered beam crossing (according to the hardware)
  int presamples() const { return hcalPresamples_; }
  
  /// access a sample
  const HcalQIESample& operator[](int i) const { return data_[i]; }
  /// access a sample
  const HcalQIESample& sample(int i) const { return data_[i]; }
  
  /// validate appropriate DV and ER bits as well as capid rotation for the specified samples (default is all)
  bool validate(int firstSample=0, int nSamples=100) const;
  
  void setSize(int size);
  void setPresamples(int ps);
  void setSample(int i, const HcalQIESample& sam) { data_[i]=sam; }
  void setReadoutIds(const HcalElectronicsId& eid);
  
  static const int MAXSAMPLES = 10;
private:
  HcalCalibDetId id_;
  HcalElectronicsId electronicsId_; 
  int size_;
  int hcalPresamples_;
  HcalQIESample data_[MAXSAMPLES];
};

std::ostream& operator<<(std::ostream&, const HcalCalibDataFrame&);

#endif