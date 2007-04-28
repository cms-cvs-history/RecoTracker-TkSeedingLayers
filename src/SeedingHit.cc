#include "RecoTracker/TkSeedingLayers/interface/SeedingHit.h"

#include "DataFormats/GeometryVector/interface/LocalPoint.h"
#include "DataFormats/GeometryVector/interface/GlobalPoint.h"
#include "TrackingTools/DetLayers/interface/DetLayer.h"
#include "DataFormats/TrackingRecHit/interface/TrackingRecHit.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "Geometry/TrackerGeometryBuilder/interface/TrackerGeometry.h"
#include "Geometry/Records/interface/TrackerDigiGeometryRecord.h"
#include "DataFormats/SiPixelDetId/interface/PixelSubdetector.h"
#include "DataFormats/SiStripDetId/interface/StripSubdetector.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "RecoTracker/TkSeedingLayers/interface/SeedingLayer.h"
#include "TrackingTools/TransientTrackingRecHit/interface/TransientTrackingRecHit.h"

using namespace ctfseeding;

class SeedingHit::SeedingHitImpl {
public:
  SeedingHitImpl(const TrackingRecHit * hit ,  const edm::EventSetup& es) 
    : theRecHit(hit)
  {
    edm::ESHandle<TrackerGeometry> tracker;
    es.get<TrackerDigiGeometryRecord>().get(tracker);
    GlobalPoint gp = tracker->idToDet(
        hit->geographicalId())->surface().toGlobal(hit->localPosition());
    thePhi = gp.phi();
    theR = gp.perp();
    theZ = gp.z();
    unsigned int subid=hit->geographicalId().subdetId();
    theRZ = (   subid == PixelSubdetector::PixelBarrel
             || subid == StripSubdetector::TIB
             || subid == StripSubdetector::TOB) ? theZ : theR;
  }
  float phi() const {return thePhi;}
  float rOrZ() const { return theRZ; }
  float r() const {return theR; }
  float z() const {return theZ; }

  const TrackingRecHit * trackingRecHit() const { return theRecHit; }

private:
//  SeedingLayer theLayer;
  TransientTrackingRecHit::ConstRecHitPointer theTransientRecHit;
  const TrackingRecHit *theRecHit;
  float thePhi;
  float theR, theZ;
  bool theBarrel;
  bool hasTransientHit;
  float theRZ;
};



SeedingHit::SeedingHit(const TrackingRecHit * hit ,  const edm::EventSetup& es)
{
  SeedingHitImpl * h = new SeedingHitImpl(hit,es);
  theImpl = boost::shared_ptr<SeedingHitImpl>(h);
}

float SeedingHit::phi() const { return theImpl->phi(); }
float SeedingHit::rOrZ() const { return theImpl->rOrZ(); }
float SeedingHit::r() const { return theImpl->r(); }
float SeedingHit::z() const { return theImpl->z(); }

SeedingHit::operator const TrackingRecHit* () const {
  return  theImpl->trackingRecHit();
}

const TrackingRecHit * SeedingHit::RecHit() const { 
  return theImpl->trackingRecHit(); 
}


