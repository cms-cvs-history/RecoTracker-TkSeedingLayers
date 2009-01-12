import FWCore.ParameterSet.Config as cms

### standard configuration of *strip* layer pairs to be used 
### to reconstruct tracks without using additional pixel-with tracking steps. 


pixellesslayerpairs = cms.ESProducer("PixelLessLayerPairsESProducer",
    layerList = cms.vstring(
        'TIB1+TIB2','TIB1+TIB3','TIB2+TIB3',
        'TIB1+TID1_pos', 'TIB1+TID1_neg',
        'TIB2+TID1_pos', 'TIB2+TID1_neg',
        'TIB1+TID2_pos', 'TIB1+TID2_neg',
        'TID1_pos+TID2_pos', 
        'TID2_pos+TID3_pos', 
        'TID3_pos+TEC2_pos', 
        'TEC1_pos+TEC2_pos', 
        'TEC2_pos+TEC3_pos', 
        'TID1_neg+TID2_neg', 
        'TID2_neg+TID3_neg', 
        'TID3_neg+TEC2_neg', 
        'TEC1_neg+TEC2_neg',
        'TEC2_neg+TEC3_neg'),
    TID1 = cms.PSet(
        useSimpleRphiHitsCleaner = cms.untracked.bool(True),
        minRing = cms.int32(1),
        matchedRecHits = cms.InputTag("siStripMatchedRecHits","matchedRecHit"),
        useRingSlector = cms.untracked.bool(True),
        TTRHBuilder = cms.string('WithTrackAngle'),
        rphiRecHits = cms.InputTag("siStripMatchedRecHits","rphiRecHit"),
        maxRing = cms.int32(3)
    ),
    TID2 = cms.PSet(
        useSimpleRphiHitsCleaner = cms.untracked.bool(True),
        minRing = cms.int32(1),
        matchedRecHits = cms.InputTag("siStripMatchedRecHits","matchedRecHit"),
        useRingSlector = cms.untracked.bool(True),
        TTRHBuilder = cms.string('WithTrackAngle'),
        rphiRecHits = cms.InputTag("siStripMatchedRecHits","rphiRecHit"),
        maxRing = cms.int32(3)
    ),
    TID3 = cms.PSet(
        useSimpleRphiHitsCleaner = cms.untracked.bool(True),        
        minRing = cms.int32(1),
        matchedRecHits = cms.InputTag("siStripMatchedRecHits","matchedRecHit"),
        useRingSlector = cms.untracked.bool(True),
        TTRHBuilder = cms.string('WithTrackAngle'),
        maxRing = cms.int32(2)
    ),
    ComponentName = cms.string('PixelLessLayerPairs'),
    TEC = cms.PSet(
        matchedRecHits = cms.InputTag("siStripMatchedRecHits","matchedRecHit"),
        useRingSlector = cms.untracked.bool(True),
        TTRHBuilder = cms.string('WithTrackAngle'),
        minRing = cms.int32(1),
        maxRing = cms.int32(2)
    ),

    TIB1 = cms.PSet(
        TTRHBuilder = cms.string('WithTrackAngle'),
        matchedRecHits = cms.InputTag("siStripMatchedRecHits","matchedRecHit"),
        useSimpleRphiHitsCleaner = cms.untracked.bool(False),
    ),
    TIB2 = cms.PSet(
        TTRHBuilder = cms.string('WithTrackAngle'),
        matchedRecHits = cms.InputTag("siStripMatchedRecHits","matchedRecHit"),
        useSimpleRphiHitsCleaner = cms.untracked.bool(False),
    ),
    TIB3 = cms.PSet(
        TTRHBuilder = cms.string('WithTrackAngle'),
        useSimpleRphiHitsCleaner = cms.untracked.bool(False),
        rphiRecHits = cms.InputTag("siStripMatchedRecHits","rphiRecHit"),
    )
)

