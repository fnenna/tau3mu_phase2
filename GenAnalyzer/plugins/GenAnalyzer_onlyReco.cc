// -*- C++ -*-
//
// Package:    GenAnalyser/GenAnalyzer
// Class:      GenAnalyzer
//
/**\class GenAnalyzer GenAnalyzer.cc GenAnalyser/GenAnalyzer/plugins/GenAnalyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Federica Maria Simone
//         Created:  Thu, 28 Mar 2024 08:07:39 GMT
//
//

// system include files
#include <memory>
#include <algorithm>
// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/EDGetToken.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include <DataFormats/MuonReco/interface/MuonFwd.h>
#include <DataFormats/MuonReco/interface/Muon.h>
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Tau.h"
#include "DataFormats/PatCandidates/interface/Photon.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/MET.h"
//#include "DataFormats/PatCandidates/interface/PackedCandidate.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/PatCandidates/interface/PackedGenParticle.h"
#include "FWCore/Framework/interface/ConsumesCollector.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "TFile.h"
#include "TH1.h"
#include "TrackingTools/TransientTrack/interface/TransientTrack.h"
#include "TrackingTools/TransientTrack/interface/TransientTrackBuilder.h"
#include "TrackingTools/Records/interface/TransientTrackRecord.h"
#include "TH2.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "RecoVertex/KalmanVertexFit/interface/KalmanVertexFitter.h"
#include "RecoVertex/VertexPrimitives/interface/TransientVertex.h"
#include "RecoBTag/SecondaryVertex/interface/SecondaryVertex.h"
#include "RecoVertex/AdaptiveVertexFit/interface/AdaptiveVertexFitter.h"


#include "RecoVertex/KinematicFit/interface/KinematicParticleVertexFitter.h"
#include "RecoVertex/KinematicFitPrimitives/interface/KinematicParticleFactoryFromTransientTrack.h"
#include "RecoVertex/KinematicFit/interface/MassKinematicConstraint.h"
#include "RecoVertex/KinematicFit/interface/KinematicParticleFitter.h"
#include "RecoVertex/KinematicFitPrimitives/interface/MultiTrackKinematicConstraint.h"
#include "RecoVertex/KinematicFit/interface/KinematicConstrainedVertexFitter.h"
#include "RecoVertex/KinematicFit/interface/TwoTrackMassKinematicConstraint.h"
#include "RecoVertex/KinematicFitPrimitives/interface/KinematicParticle.h"
#include "RecoVertex/KinematicFitPrimitives/interface/RefCountedKinematicParticle.h"
#include "RecoVertex/KinematicFitPrimitives/interface/TransientTrackKinematicParticle.h"
#include "RecoVertex/KinematicFitPrimitives/interface/KinematicTree.h"


#include "RecoVertex/KinematicFit/interface/KinematicParticleVertexFitter.h"
#include "RecoVertex/KinematicFit/interface/KinematicParticleFitter.h"
#include "RecoVertex/KinematicFit/interface/MassKinematicConstraint.h"
#include "RecoVertex/KinematicFitPrimitives/interface/KinematicParticle.h"
#include "RecoVertex/KinematicFitPrimitives/interface/RefCountedKinematicParticle.h"
#include "RecoVertex/KinematicFitPrimitives/interface/TransientTrackKinematicParticle.h"
#include "RecoVertex/KinematicFitPrimitives/interface/TransientTrackKinematicParticle.h"
#include "RecoVertex/KinematicFitPrimitives/interface/KinematicParticleFactoryFromTransientTrack.h"
#include "RecoVertex/AdaptiveVertexFit/interface/AdaptiveVertexFitter.h"


#include "TrackingTools/Records/interface/TrackingComponentsRecord.h"

#include "TrackingTools/TransientTrack/interface/TransientTrackFromFTSFactory.h"
#include "TrackingTools/TransientTrack/interface/TransientTrack.h"
#include "TrackingTools/PatternTools/interface/ClosestApproachInRPhi.h"

#include "DataFormats/Candidate/interface/VertexCompositeCandidateFwd.h"
#include "DataFormats/Candidate/interface/CompositeCandidate.h"

#include "RecoVertex/VertexPrimitives/interface/ConvertToFromReco.h"
#include "DataFormats/TrackReco/interface/TrackBase.h"
#include "RecoVertex/VertexTools/interface/VertexDistance3D.h"
#include "SimDataFormats/Vertex/interface/SimVertex.h"
#include "SimDataFormats/Vertex/interface/SimVertexContainer.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "FWCore/Common/interface/TriggerResultsByName.h"

#include "DataFormats/HLTReco/interface/TriggerEvent.h"
#include "PhysicsTools/PatUtils/interface/TriggerHelper.h"
#include "DataFormats/PatCandidates/interface/TriggerEvent.h"
#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"
#include "DataFormats/PatCandidates/interface/TriggerFilter.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"
#include "TrackingTools/IPTools/interface/IPTools.h"


#include "CondFormats/L1TObjects/interface/L1GtTriggerMenu.h"
#include "CondFormats/DataRecord/interface/L1GtTriggerMenuRcd.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerReadoutRecord.h"
#include "DataFormats/HLTReco/interface/TriggerEvent.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/L1TGlobal/interface/GlobalAlgBlk.h"
#include "L1Trigger/L1TGlobal/interface/L1TGlobalUtil.h"
#include "DataFormats/L1Trigger/interface/Muon.h"
#include "CondFormats/DataRecord/interface/L1TUtmTriggerMenuRcd.h"
#include "CondFormats/L1TObjects/interface/L1TUtmTriggerMenu.h"
#include "CondFormats/DataRecord/interface/L1TGlobalPrescalesVetosRcd.h"
#include "CondFormats/L1TObjects/interface/L1TGlobalPrescalesVetos.h"
#include "DataFormats/PatCandidates/interface/TriggerObjectStandAlone.h"
#include "DataFormats/PatCandidates/interface/PackedTriggerPrescales.h"
#include "DataFormats/TrackReco/interface/TrackToTrackMap.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"

#include "DataFormats/MuonDetId/interface/ME0DetId.h"
#include "DataFormats/MuonDetId/interface/MuonSubdetId.h"
#include "DataFormats/MuonDetId/interface/GEMDetId.h"
#include "Geometry/Records/interface/MuonGeometryRecord.h"
#include "FWCore/Framework/interface/ESHandle.h"


#include "TrackingTools/IPTools/interface/IPTools.h"
#include "TrackingTools/Records/interface/TransientTrackRecord.h"
#include "TrackingTools/TransientTrack/interface/TransientTrack.h"
#include "TrackingTools/TransientTrack/interface/TransientTrackBuilder.h"


#include "Geometry/DTGeometry/interface/DTGeometry.h"
#include "Geometry/GEMGeometry/interface/GEMGeometry.h"
#include "Geometry/CSCGeometry/interface/CSCGeometry.h"
#include "Geometry/Records/interface/MuonGeometryRecord.h"

#include "FWCore/Utilities/interface/typelookup.h"
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"



//
// class declaration

namespace nano_mu {

  template <class T, class R, edm::Transition TR = edm::Transition::Event>
  class ESTokenHandle {
  public:
    /// Constructor
    ESTokenHandle(edm::ConsumesCollector&& collector, const std::string& label = "")
        : m_token{collector.template esConsumes<TR>(edm::ESInputTag{"", label})} {}

    ///Get Handle from ES
    void getFromES(const edm::EventSetup& environment) { m_handle = environment.getHandle(m_token); }

    /// Check validity
    bool isValid() { return m_handle.isValid(); }

    /// Return handle
    T const* operator->() { return m_handle.product(); }

  private:
    edm::ESGetToken<T, R> m_token;
    edm::ESHandle<T> m_handle;
  };
}  // namespace nano_mu

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<>
// This will improve performance in multithreaded jobs.

//using pat::PackedCandidateCollection;

class GenAnalyzer_onlyReco : public edm::one::EDAnalyzer<edm::one::SharedResources> {
public:
  explicit GenAnalyzer_onlyReco(const edm::ParameterSet&);
  ~GenAnalyzer_onlyReco() override;

  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

private:
  void beginJob() override;
  void analyze(const edm::Event&, const edm::EventSetup&) override;
  void endJob() override;

  // ----------member data ---------------------------
  //edm::EDGetTokenT<TrackCollection> tracksToken_;  //used to select what tracks to read from configuration file
  //edm::EDGetTokenT<edm::View<reco::Muon> > muons_;
  edm::EDGetTokenT<edm::View<reco::GenParticle> > genParticles_;
  edm::EDGetTokenT<edm::View<pat::Muon> > muons_;
  edm::EDGetTokenT<edm::View<pat::PackedCandidate> > tracks_;
  edm::ESGetToken<TransientTrackBuilder, TransientTrackRecord> theTransientTrackBuilder_;
  edm::EDGetTokenT<GEMSegmentCollection> gemSegmentsToken;
  edm::ESGetToken<GEMGeometry, MuonGeometryRecord> GEMGeom_Token;
  edm::EDGetTokenT<CSCSegmentCollection> cscSegmentsToken;
  edm::ESGetToken<CSCGeometry, MuonGeometryRecord> CSCGeom_Token;
  edm::EDGetTokenT<std::vector<PileupSummaryInfo> > pileupToken;




  //tree
  TTree*      tree_;
  edm::Service<TFileService> fs;
  
  std::vector<int> GenParticle_PdgId, GenParticle_MotherPdgId, GenParticle_GrandMotherPdgId;
  std::vector<int> N_of_hits_GE11, N_of_hits_GE21, N_of_hits_ME0;
  std::vector<double> GenParticle_P, GenParticle_Pt, GenParticle_Eta,    GenParticle_Phi, GenParticle_vx, GenParticle_vy, GenParticle_vz;
  std::vector<float>  MuonPt, MuonEta, MuonPhi;
  std::vector<int> GEMSegment_Station, GEMSegment_nRechits, CSCSegment_Station, CSCSegment_Ring;
  std::vector<float> GEMSegment_Eta, GEMSegment_Phi, GEMSegment_BX;
  std::vector<float> CSCSegment_Eta, CSCSegment_Phi, CSCSegment_Time;
  std::vector<float>  MuTrkPt, MuTrkEta, MuTrkPhi;
  std::vector<float>  TrkPt, TrkEta, TrkPhi, TrkPuppi;
  std::vector<double> MuonEnergy,  MuonCharge;
  std::vector<double>  Muon_vx,  Muon_vy,  Muon_vz;
  std::vector<double>  Muon_isGlobal,  Muon_isTracker,  Muon_isSoft, Muon_isMVA, Muon_isMVASoft,  Muon_isLoose, Muon_isMedium, Muon_isTight,  Muon_isPF, Muon_isGEM,  Muon_isME0,  Muon_isRPCMuon,  Muon_isStandAloneMuon,  Muon_isTrackerMuon,  Muon_isCaloMuon,  Muon_isQualityValid,  Muon_isTimeValid,  Muon_isIsolationValid,  Muon_numberOfMatchedStations,  Muon_numberOfMatches;
  std::vector<double>  Muon_timeAtIpInOut,Muon_timeAtIpInOutErr;
  std::vector<int>  Muon_GEMHits,Muon_GEMSegments, Muon_GEMStation;

  //std::vector<int>  Muon_simPdgId, Muon_simMotherPdgId, Muon_simFlavour,  Muon_simType, Muon_simBX, Muon_simTpEvent, Muon_simMatchQuality;

};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
GenAnalyzer_onlyReco::GenAnalyzer_onlyReco(const edm::ParameterSet& iConfig){
  genParticles_ = consumes<edm::View<reco::GenParticle>  > (iConfig.getParameter<edm::InputTag>("genParticleLabel"));
  muons_ = consumes<edm::View<pat::Muon>  > (iConfig.getParameter<edm::InputTag>("muonLabel"));
  tracks_ = consumes<edm::View<pat::PackedCandidate> > (iConfig.getParameter<edm::InputTag>("TracksLabel"));
  theTransientTrackBuilder_ = esConsumes<TransientTrackBuilder, TransientTrackRecord>(edm::ESInputTag("", "TransientTrackBuilder"));
  gemSegmentsToken = consumes<GEMSegmentCollection>(edm::InputTag("gemSegments"));
  GEMGeom_Token = esConsumes<GEMGeometry, MuonGeometryRecord>();
  cscSegmentsToken = consumes<CSCSegmentCollection>(edm::InputTag("cscSegments"));
  CSCGeom_Token = esConsumes<CSCGeometry, MuonGeometryRecord>();
  pileupToken = consumes<std::vector<PileupSummaryInfo>>(edm::InputTag("addPileupInfo"));
}

GenAnalyzer_onlyReco::~GenAnalyzer_onlyReco() {
  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)
  //
  // please remove this method altogether if it would be left empty
}

//
// member functions
//

// ------------ method called for each event  ------------
void GenAnalyzer_onlyReco::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup) {
  using namespace edm;
  //edm::Handle< edm::View<reco::Muon> > muons;
  edm::Handle< edm::View<reco::GenParticle> > genParticles;
  edm::Handle< edm::View<pat::Muon> > muons;
  edm::Handle< edm::View<pat::PackedCandidate> > tracks;
  edm::ESHandle<TransientTrackBuilder> theTransientTrackBuilder = iSetup.getHandle(theTransientTrackBuilder_); 
  edm::Handle<GEMSegmentCollection> gemSegments;
  edm::Handle<CSCSegmentCollection> cscSegments;

  iEvent.getByToken(genParticles_, genParticles);
  iEvent.getByToken(muons_, muons);
  iEvent.getByToken(tracks_, tracks);
  iEvent.getByToken(gemSegmentsToken, gemSegments);
  edm::ESHandle<GEMGeometry> GEMGeom = iSetup.getHandle(GEMGeom_Token);
  iEvent.getByToken(cscSegmentsToken, cscSegments);
  edm::ESHandle<CSCGeometry> CSCGeom = iSetup.getHandle(CSCGeom_Token);
  

  uint j=0;
  uint ngenP=genParticles->size();
  std::vector<int> genPidx;
  for(edm::View<reco::GenParticle>::const_iterator gp=genParticles->begin(); gp!=genParticles->end(), j<ngenP; ++gp , ++j){
    // se la particella è un muone       
    if(fabs(gp->pdgId())){
      std::cout << "The particle is a muon"<< std::endl;
        GenParticle_PdgId.push_back(gp->pdgId());
        GenParticle_P.push_back(gp->p());
        GenParticle_Pt.push_back(gp->pt());
        GenParticle_Eta.push_back(gp->eta());
        GenParticle_Phi.push_back(gp->phi());
        GenParticle_vx.push_back(gp->vx());
        GenParticle_vy.push_back(gp->vy());
        GenParticle_vz.push_back(gp->vz());
        if (gp->numberOfMothers()) {
            GenParticle_MotherPdgId.push_back(gp->mother(0)->pdgId());
            if(gp->mother(0)->mother(0)) {
                GenParticle_GrandMotherPdgId.push_back(gp->mother(0)->mother(0)->pdgId());
            }else{
                GenParticle_GrandMotherPdgId.push_back(-99);
            }
        }else{
            GenParticle_MotherPdgId.push_back(-99);
        }
    }
  }

  uint i_gemseg=0;
  for(GEMSegmentCollection::const_iterator gem_segment=gemSegments->begin(); gem_segment!=gemSegments->end(), i_gemseg<gemSegments->size(); ++gem_segment, ++i_gemseg){  
    std::cout << "the segment is recorded by station: " <<gem_segment->gemDetId().station() << std::endl;
    std::cout << "the segment is recorded by eta: " <<gem_segment->gemDetId().roll() << std::endl;
    std::cout << "the n of rechits recorded is: " <<gem_segment->nRecHits() << std::endl;
    std::cout << "the n of rechits recorded is: " <<gem_segment->parameters() << std::endl;
    GEMDetId id = gem_segment->gemDetId();
    AlgebraicVector params = gem_segment->parameters();
    float time_BX = gem_segment->bunchX();
    auto roll = GEMGeom->etaPartition(id);
    //GEMSegment_Eta.push_back(params[2]);
    float eta;
    float pl;
    for (auto const* hit : gem_segment->recHits()) {
      const GEMRecHit* gemHit = dynamic_cast<const GEMRecHit*>(hit);
      if (gemHit) {
        GEMDetId id_hit = gemHit->gemId();
        auto roll = GEMGeom->etaPartition(id_hit);
        int layer = id_hit.layer();
        if (layer==3){
        std::cout << "the hit is recorded by layer: " << id_hit.layer() << std::endl;
        std::cout << "rechit local position x: " << hit->localPosition().x() << std::endl;
        eta = (roll->toGlobal(gemHit->localPosition())).eta();
        pl = (roll->toGlobal(gemHit->localPosition())).barePhi();
        std::cout << "rechit global position eta: " << eta << std::endl;
        std::cout << "rechit global position phi: " << pl << std::endl;
        GEMSegment_Station.push_back(id.station());
        GEMSegment_nRechits.push_back(gem_segment->nRecHits());
        GEMSegment_Eta.push_back(eta);
        GEMSegment_Phi.push_back(pl);
        GEMSegment_BX.push_back(time_BX);
        }
    }
  }  
}

uint i_cscseg = 0;
for(CSCSegmentCollection::const_iterator csc_segment=cscSegments->begin(); csc_segment!=cscSegments->end(), i_cscseg<cscSegments->size(); ++csc_segment, ++i_cscseg){  
  CSCDetId id = csc_segment->cscDetId();
  std::cout << "the segment is recorded by station: " << id << std::endl;
  //GEMSegment_Eta.push_back(params[2]);
  float eta;
  float pl;
  float time = csc_segment->time();
  for (auto const* hit : csc_segment->recHits()) {
    const CSCRecHit2D* cscHit = dynamic_cast<const CSCRecHit2D*>(hit);
    if (cscHit) {
      CSCDetId id_hit = cscHit->cscDetId();
      int layer = id_hit.layer();
      int station = id_hit.station();
      int ring = id_hit.ring();
      const CSCChamber* cscchamber = CSCGeom->chamber(id);
      if (layer==3){
      std::cout << "the hit is recorded by layer: " << id_hit.layer() << std::endl;
      std::cout << "rechit local position x: " << hit->localPosition().x() << std::endl;
      eta = (cscchamber->toGlobal(cscHit->localPosition())).eta();
      pl = (cscchamber->toGlobal(cscHit->localPosition())).barePhi();
      std::cout << "rechit global position eta: " << eta << std::endl;
      std::cout << "rechit global position phi: " << pl << std::endl;
      CSCSegment_Ring.push_back(ring);
      CSCSegment_Station.push_back(station);
      CSCSegment_Eta.push_back(eta);
      CSCSegment_Phi.push_back(pl);
      CSCSegment_Time.push_back(time);
      }
    }
  }
}

  
  uint k=0;
  for(edm::View<pat::Muon>::const_iterator mu=muons->begin(); mu!=muons->end(), k<muons->size(); ++mu, ++k){    
    //Basic Kinematics
    bool is_gem = false;
    MuonPt.push_back(mu->pt());
    MuonEta.push_back(mu->eta());
    MuonPhi.push_back(mu->phi());
    MuonEnergy.push_back(mu->energy());
    MuonCharge.push_back(mu->charge());
    
    //Muon_simPdgId.push_back(mu->simPdgId());
    //Muon_simMotherPdgId.push_back(mu->simMotherPdgId());
    //Muon_simFlavour.push_back(mu->simFlavour());
    //Muon_simType.push_back(mu->simType());
    //Muon_simBX.push_back(mu->simBX());

    //Vtx position
    Muon_vx.push_back(mu->vx());
    Muon_vy.push_back(mu->vy());
    Muon_vz.push_back(mu->vz());
    
    //MuonID
    Muon_isGlobal.push_back(mu->isGlobalMuon());
    //Muon_isSoft.push_back(mu->isSoftMuon(PV));
    //Muon_isMVA.push_back(mu->mvaIDValue());
    //Muon_isMVASoft.push_back(mu->softMvaValue());
    //Muon_isLoose.push_back(mu->isLooseMuon());
    //Muon_isMedium.push_back(mu->isMediumMuon());
    //Muon_isTight.push_back(mu->isTightMuon(PV));
    Muon_isPF.push_back(mu->isPFMuon());
    Muon_isME0.push_back(mu->isME0Muon());
    Muon_isGEM.push_back(mu->isGEMMuon());
    Muon_isRPCMuon.push_back(mu->isRPCMuon());
    Muon_isStandAloneMuon.push_back(mu->isStandAloneMuon());
    Muon_isTrackerMuon.push_back(mu->isTrackerMuon());
    Muon_isCaloMuon.push_back(mu->isCaloMuon());
    Muon_isQualityValid.push_back(mu->isQualityValid());
    Muon_isTimeValid.push_back(mu->isTimeValid());
    Muon_isIsolationValid.push_back(mu->isIsolationValid());
    Muon_numberOfMatchedStations.push_back(mu->numberOfMatchedStations());
    //Muon_numberOfMatches.push_back(mu->numberOfMatches(reco::Muon::SegmentArbitration));
    reco::TrackRef trk;
    trk = mu->innerTrack();
      if (trk.isNonnull() && trk.isAvailable()) {
        const reco::TransientTrack transientTrack = theTransientTrackBuilder->build(trk);
        reco::Track Track = transientTrack.track();
        MuTrkPt.push_back(Track.pt());
        MuTrkEta.push_back(Track.eta());
        MuTrkPhi.push_back(Track.phi());
    } else {
        edm::LogWarning("BadTrackRef") << "Muon has null or invalid innerTrack ref.";
        MuTrkPt.push_back(-999);
        MuTrkEta.push_back(-999);
        MuTrkPhi.push_back(-999);
    }
  }

  for(edm::View<pat::PackedCandidate>::const_iterator trk=tracks->begin(); trk!=tracks->end(), k<tracks->size(); ++trk, ++k){    
    //Basic Kinematics
    TrkPt.push_back(trk->pt());
    TrkEta.push_back(trk->eta());
    TrkPhi.push_back(trk->phi());
    TrkPuppi.push_back(trk->puppiWeight());


  }
  // PILE-UP INFORMATION
  // Get pileup information from the pile-up information module
  std::vector<float> ntupleData;
  edm::Handle<std::vector<PileupSummaryInfo> > puInfo;
  if (iEvent.getByToken(pileupToken, puInfo)){
    const unsigned nBx = puInfo->size();
    ntupleData.push_back(static_cast<float>(nBx));

    double sumpt_Lo = 0.0, sumpt_Hi = 0.0;
    int totalNpu = 0;

    int npu_by_Bx[3] = {0,};
    double sumpt_Lo_by_Bx[3] = {0.0,}, sumpt_Hi_by_Bx[3] = {0.0,};

    std::cout << "\n**** Pileup info begin" << std::endl;

    for (unsigned ibx = 0; ibx < nBx; ++ibx) {
      const PileupSummaryInfo& pileupinfo((*puInfo)[ibx]);

      const int bx = pileupinfo.getBunchCrossing();
      if (bx==0){
        const int npu = pileupinfo.getPU_NumInteractions();
        const std::vector<float>& zpos = pileupinfo.getPU_zpositions();    
        const std::vector<float>& lopt = pileupinfo.getPU_sumpT_lowpT();    
        const std::vector<float>& hipt = pileupinfo.getPU_sumpT_highpT();
        const double losum = std::accumulate(lopt.begin(), lopt.end(), 0.0);
        const double hisum = std::accumulate(hipt.begin(), hipt.end(), 0.0);
        /*
        if (losum >= crazyEnergyCut)
          isCrazy = true;
        if (hisum >= crazyEnergyCut)
          isCrazy = true;
        */

        totalNpu += npu;
        sumpt_Lo += losum;
        sumpt_Hi += hisum;

        const unsigned idx = bx < 0 ? 0U : (bx == 0 ? 1U : 2U);
        npu_by_Bx[idx] += npu;
        sumpt_Lo_by_Bx[idx] += losum;
        sumpt_Hi_by_Bx[idx] += hisum;

        std::cout << "ibx " << ibx << " bx " << bx << " npu " << npu << " losum " << losum << " hisum " << hisum << std::endl;
    }
  }

    std::cout << "**** Pileup info end\n" << std::endl;

}




  tree_->Fill();

  GenParticle_PdgId.clear();
  GenParticle_Pt.clear();
  GenParticle_P.clear();
  GenParticle_Eta.clear();
  GenParticle_Phi.clear();
  GenParticle_MotherPdgId.clear();
  GenParticle_GrandMotherPdgId.clear();
  GenParticle_vx.clear();
  GenParticle_vy.clear();
  GenParticle_vz.clear();

  GEMSegment_Station.clear();
  GEMSegment_nRechits.clear();
  GEMSegment_Eta.clear();
  GEMSegment_BX.clear();
  GEMSegment_Phi.clear();

  CSCSegment_Station.clear();
  CSCSegment_Eta.clear();
  CSCSegment_Ring.clear();
  CSCSegment_Phi.clear();
  CSCSegment_Time.clear();

  MuonPt.clear();
  MuonEta.clear();
  MuonPhi.clear();
  MuonEnergy.clear();
  MuonCharge.clear();
  
  //Muon_simPdgId.clear();
  //Muon_simMotherPdgId.clear();
  //Muon_simFlavour.clear();
  //Muon_simType.clear();
  //Muon_simBX.clear();
    
  /////Vtx position
  Muon_vx.clear();
  Muon_vy.clear();
  Muon_vz.clear();
  
  /////MuonID
  Muon_isGlobal.clear();
  Muon_isSoft.clear();
  //Muon_isMVA.clear();
  //Muon_isMVASoft.clear();
  //Muon_isLoose.clear();
  //Muon_isMedium.clear();
  Muon_isTight.clear();
  Muon_isPF.clear();
  Muon_isME0.clear();
  Muon_isGEM.clear();
  Muon_isRPCMuon.clear();
  Muon_isStandAloneMuon.clear();
  Muon_isTrackerMuon.clear();
  Muon_isCaloMuon.clear();
  Muon_isQualityValid.clear();
  Muon_isTimeValid.clear();
  Muon_isIsolationValid.clear();
  Muon_numberOfMatchedStations.clear();
  Muon_numberOfMatches.clear();
  /////MuonTime
  Muon_timeAtIpInOut.clear();
  Muon_timeAtIpInOutErr.clear();
  Muon_GEMSegments.clear();
  Muon_GEMHits.clear();
  Muon_GEMStation.clear();
  N_of_hits_GE11.clear();
  N_of_hits_GE21.clear();
  N_of_hits_ME0.clear();

  MuTrkPt.clear();
  MuTrkEta.clear();
  MuTrkPhi.clear();

  TrkPt.clear();
  TrkEta.clear();
  TrkPhi.clear();
  TrkPuppi.clear();

}


// ------------ method called once each job just before starting event loop  ------------
void GenAnalyzer_onlyReco::beginJob() {
  // please remove this method if not needed
  tree_ = fs->make<TTree>("ntuple","LFVTau ntuple");

  tree_->Branch("GenParticle_PdgId", &GenParticle_PdgId);
  tree_->Branch("GenParticle_Pt", &GenParticle_Pt);
  tree_->Branch("GenParticle_P",  &GenParticle_P);
  tree_->Branch("GenParticle_Eta", &GenParticle_Eta);
  tree_->Branch("GenParticle_Phi", &GenParticle_Phi);
  tree_->Branch("GenParticle_MotherPdgId", &GenParticle_MotherPdgId);
  tree_->Branch("GenParticle_GrandMotherPdgId", &GenParticle_GrandMotherPdgId);
  tree_->Branch("GenParticle_vx", &GenParticle_vx);
  tree_->Branch("GenParticle_vy", &GenParticle_vy);
  tree_->Branch("GenParticle_vz", &GenParticle_vz);

  tree_->Branch("GEMSegment_Station",&GEMSegment_Station);
  tree_->Branch("GEMSegment_nRechits",&GEMSegment_nRechits);
  tree_->Branch("GEMSegment_Eta",&GEMSegment_Eta);
  tree_->Branch("GEMSegment_Phi",&GEMSegment_Phi);
  tree_->Branch("GEMSegment_BX",&GEMSegment_BX);

  tree_->Branch("CSCSegment_Station",&CSCSegment_Station);
  tree_->Branch("CSCSegment_Eta",&CSCSegment_Eta);
  tree_->Branch("CSCSegment_Phi",&CSCSegment_Phi);
  tree_->Branch("CSCSegment_Ring",&CSCSegment_Ring);
  tree_->Branch("CSCSegment_Time",&CSCSegment_Time);

  tree_->Branch("MuonPt",&MuonPt);
  tree_->Branch("MuonEta",&MuonEta);
  tree_->Branch("MuonPhi",&MuonPhi);
  tree_->Branch("MuonEnergy", &MuonEnergy);
  tree_->Branch("MuonCharge", &MuonCharge);

  //tree_->Branch("Muon_simPdgId", &Muon_simPdgId);
  //tree_->Branch("Muon_simMotherPdgId", &Muon_simMotherPdgId);
  //tree_->Branch("Muon_simFlavour", &Muon_simFlavour);
  //tree_->Branch("Muon_simType", &Muon_simType);
  //tree_->Branch("Muon_simBX", &Muon_simBX);

  /////Vtx position
  tree_->Branch("Muon_vx", &Muon_vx);
  tree_->Branch("Muon_vy", &Muon_vy);
  tree_->Branch("Muon_vz", &Muon_vz);
  
  /////MuonID
  tree_->Branch("Muon_isGlobal", &Muon_isGlobal);
  tree_->Branch("Muon_isSoft", &Muon_isSoft);
  //tree_->Branch("Muon_isMVA", &Muon_isMVA);
  //tree_->Branch("Muon_isMVASoft", &Muon_isMVASoft);
  //tree_->Branch("Muon_isLoose", &Muon_isLoose);
  //tree_->Branch("Muon_isMedium", &Muon_isMedium);
  tree_->Branch("Muon_isTight", &Muon_isTight);
  tree_->Branch("Muon_isPF", &Muon_isPF);
  tree_->Branch("Muon_isME0", &Muon_isME0);
  tree_->Branch("Muon_isGEM", &Muon_isGEM);
  tree_->Branch("Muon_isRPCMuon", &Muon_isRPCMuon);
  tree_->Branch("Muon_isStandAloneMuon", &Muon_isStandAloneMuon);
  tree_->Branch("Muon_isTrackerMuon", &Muon_isTrackerMuon);
  tree_->Branch("Muon_isCaloMuon", &Muon_isCaloMuon);
  tree_->Branch("Muon_isQualityValid", &Muon_isQualityValid);
  tree_->Branch("Muon_isTimeValid", &Muon_isTimeValid);
  tree_->Branch("Muon_isIsolationValid", &Muon_isIsolationValid);
  tree_->Branch("Muon_numberOfMatchedStations", &Muon_numberOfMatchedStations);
  tree_->Branch("Muon_numberOfMatches", &Muon_numberOfMatches);
  
  tree_->Branch("Muon_timeAtIpInOut",&Muon_timeAtIpInOut);
  tree_->Branch("Muon_timeAtIpInOutErr",&Muon_timeAtIpInOutErr);
  tree_->Branch("Muon_GEMHits",&Muon_GEMHits);
  tree_->Branch("Muon_GEMSegments",&Muon_GEMSegments);
  tree_->Branch("Muon_GEMStation",&Muon_GEMStation);
  tree_->Branch("N_of_hits_GE11", &N_of_hits_GE11);
  tree_->Branch("N_of_hits_GE21", &N_of_hits_GE21);
  tree_->Branch("N_of_hits_ME0", &N_of_hits_ME0);

  tree_->Branch("MuTrkPt",&MuTrkPt);
  tree_->Branch("MuTrkEta",&MuTrkEta);
  tree_->Branch("MuTrkPhi",&MuTrkPhi);

  tree_->Branch("TrkPt",&TrkPt);
  tree_->Branch("TrkEta",&TrkEta);
  tree_->Branch("TrkPhi",&TrkPhi);
  tree_->Branch("TrkPuppi",&TrkPuppi);

}

// ------------ method called once each job just after ending the event loop  ------------
void GenAnalyzer_onlyReco::endJob() {
  tree_->GetDirectory()->cd();
  tree_->Write();
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void GenAnalyzer_onlyReco::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);

  //Specify that only 'tracks' is allowed
  //To use, remove the default given above and uncomment below
  //ParameterSetDescription desc;
  //desc.addUntracked<edm::InputTag>("tracks","ctfWithMaterialTracks");
  //descriptions.addWithDefaultLabel(desc);
}

//TYPELOOKUP_DATA_REG(GEMGeometry);
//TYPELOOKUP_DATA_REG(CSCGeometry);
//define this as a plug-in
DEFINE_FWK_MODULE(GenAnalyzer_onlyReco);
