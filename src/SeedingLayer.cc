#include "RecoTracker/TkSeedingLayers/interface/SeedingLayer.h"
#include "SeedingLayerImpl.h"

using namespace ctfseeding;

SeedingLayer::SeedingLayer( const DetLayer* layer, const std::string & name,
    const std::string & hitBuilder, const HitExtractor * hitExtractor)
{
  SeedingLayerImpl * l = new SeedingLayerImpl(layer,name,hitBuilder,hitExtractor);
  theImpl = boost::shared_ptr<SeedingLayerImpl> (l);
}

std::string SeedingLayer::name() const
{
  return theImpl->name();
}

const DetLayer*  SeedingLayer::detLayer() const
{
  return theImpl->detLayer();
}

const TransientTrackingRecHitBuilder * SeedingLayer::hitBuilder(const edm::EventSetup& es) const 
{
  return theImpl->hitBuilder(es);
}

std::vector<SeedingHit> SeedingLayer::hits(const edm::Event& ev, const edm::EventSetup& es) const
{
  return  theImpl->hits(ev,es);
}


