#ifndef TkSeedingLayers_SeedingHit_H
#define TkSeedingLayers_SeedingHit_H

#include <boost/shared_ptr.hpp>

namespace edm { class EventSetup; }
class TrackingRecHit;

namespace ctfseeding {

class SeedingHit {
public:
  SeedingHit(const TrackingRecHit * hit ,  const edm::EventSetup& iSetup);

  float phi() const;
  float rOrZ() const;
  float r() const;
  float z() const;

  // to be skipped
  const TrackingRecHit * RecHit() const;

  operator const TrackingRecHit* () const;

private:
  class SeedingHitImpl;
  boost::shared_ptr<SeedingHitImpl> theImpl;
};

}

#endif 
