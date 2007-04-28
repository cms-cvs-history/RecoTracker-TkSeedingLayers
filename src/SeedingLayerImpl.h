#ifndef TkSeedingLayerImpls_SeedingLayerImpl_H
#define TkSeedingLayerImpls_SeedingLayerImpl_H

#include <string>
#include <vector>
#include "RecoTracker/TkSeedingLayers/interface/SeedingHit.h"

class DetLayer;
class TransientTrackingRecHitBuilder;

namespace edm { class Event; class EventSetup; }
namespace ctfseeding {class HitExtractor; }


namespace ctfseeding {

class SeedingLayerImpl {
public:
  SeedingLayerImpl( const DetLayer* layer,
                const std::string & name,
                const std::string & hitBuilder,
                const HitExtractor * hitExtractor);

  ~SeedingLayerImpl();

  std::string name() const { return theName; }
  std::vector<SeedingHit> hits(const edm::Event& ev, const edm::EventSetup& es) const;

  const DetLayer*  detLayer() const { return theLayer; }
  const TransientTrackingRecHitBuilder * hitBuilder(const edm::EventSetup& es) const;
 
private:
  SeedingLayerImpl(const SeedingLayerImpl &);
private:
  const DetLayer* theLayer;
  std::string theName;
  std::string theTTRHBuilderName;
  const HitExtractor * theHitExtractor;
  mutable const TransientTrackingRecHitBuilder *theTTRHBuilder;
};
}
#endif
