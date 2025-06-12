// -*- C++ -*-
//
// Package:    GenAnalyser/GenAnalyzer_onlyGen
// Class:      GenAnalyzer_onlyGen
//
/**\class GenAnalyzer_onlyGen GenAnalyzer_onlyGen.cc GenAnalyser/GenAnalyzer_onlyGen/plugins/GenAnalyzer_onlyGen.cc

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


#include "TrackingTools/TransientTrack/interface/TransientTrackBuilder.h"
#include "TrackingTools/Records/interface/TransientTrackRecord.h"

#include "Geometry/DTGeometry/interface/DTGeometry.h"

//


// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<>
// This will improve performance in multithreaded jobs.

//using reco::TrackCollection;

class GenAnalyzer_onlyGen : public edm::one::EDAnalyzer<edm::one::SharedResources> {
public:
  explicit GenAnalyzer_onlyGen(const edm::ParameterSet&);
  ~GenAnalyzer_onlyGen() override;

  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

private:
  void beginJob() override;
  void analyze(const edm::Event&, const edm::EventSetup&) override;
  void endJob() override;

  // ----------member data ---------------------------
  //edm::EDGetTokenT<TrackCollection> tracksToken_;  //used to select what tracks to read from configuration file
  edm::EDGetTokenT<edm::View<reco::GenParticle> > genParticles_;
  edm::EDGetTokenT<edm::View<pat::Muon> > muons_;
  //edm::EDGetTokenT<edm::View<reco::Muon> > muons_;
  //edm::ESGetToken<TransientTrackBuilder, TransientTrackRecord> theTransientTrackBuilder_;


  //tree
  TTree*      tree_;
  edm::Service<TFileService> fs;
  
  std::vector<int> GenParticle_PdgId, GenParticle_MotherPdgId, GenParticle_GrandMotherPdgId;
  std::vector<int> N_of_hits_GE11, N_of_hits_GE21, N_of_hits_ME0;
  std::vector<double> GenParticle_P, GenParticle_Pt, GenParticle_Eta,    GenParticle_Phi, GenParticle_vx, GenParticle_vy, GenParticle_vz;
  std::vector<float>  MuonPt, MuonEta, MuonPhi;
  std::vector<double> MuonEnergy,  MuonCharge;
  std::vector<double>  Muon_vx,  Muon_vy,  Muon_vz;
  std::vector<double>  Muon_isGlobal,  Muon_isTracker,  Muon_isSoft, Muon_isMVA, Muon_isMVASoft,  Muon_isLoose, Muon_isMedium, Muon_isTight,  Muon_isPF, Muon_isGEM,  Muon_isME0,  Muon_isRPCMuon,  Muon_isStandAloneMuon,  Muon_isTrackerMuon,  Muon_isCaloMuon,  Muon_isQualityValid,  Muon_isTimeValid,  Muon_isIsolationValid,  Muon_numberOfMatchedStations,  Muon_numberOfMatches;
  std::vector<double>  Muon_timeAtIpInOut,Muon_timeAtIpInOutErr;
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
GenAnalyzer_onlyGen::GenAnalyzer_onlyGen(const edm::ParameterSet& iConfig){
  genParticles_ = consumes<edm::View<reco::GenParticle>  > (iConfig.getParameter<edm::InputTag>("genParticleLabel"));
  //muons_ = consumes<edm::View<reco::Muon>  > (iConfig.getParameter<edm::InputTag>("muonLabel"));
  //muons_ = consumes<edm::View<pat::Muon>  > (iConfig.getParameter<edm::InputTag>("muonLabel"));
  //theTransientTrackBuilder_ = esConsumes<TransientTrackBuilder, TransientTrackRecord>(edm::ESInputTag("", "TransientTrackBuilder"));

  //muons_ = consumes<edm::View<reco::Muon>  > (iConfig.getParameter<edm::InputTag>("muonLabel"));
}

GenAnalyzer_onlyGen::~GenAnalyzer_onlyGen() {
  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)
  //
  // please remove this method altogether if it would be left empty
}

//
// member functions
//

// ------------ method called for each event  ------------
void GenAnalyzer_onlyGen::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup) {
  using namespace edm;

  edm::Handle< edm::View<reco::GenParticle> > genParticles;
  iEvent.getByToken(genParticles_, genParticles);


  uint j=0;
  uint ngenP=genParticles->size();
  std::vector<int> genPidx;
  
  //          cout<<"****************GenLevel Info Begin********************"<<endl;
  for(edm::View<reco::GenParticle>::const_iterator gp=genParticles->begin(); gp!=genParticles->end(), j<ngenP; ++gp , ++j){

    // se la particella è un muone       
    if(fabs(gp->pdgId())==13){
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
  }

// ------------ method called once each job just before starting event loop  ------------
void GenAnalyzer_onlyGen::beginJob() {
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
  tree_->Branch("N_of_hits_GE11", &N_of_hits_GE11);
  tree_->Branch("N_of_hits_GE21", &N_of_hits_GE21);
  tree_->Branch("N_of_hits_ME0", &N_of_hits_ME0);

}

// ------------ method called once each job just after ending the event loop  ------------
void GenAnalyzer_onlyGen::endJob() {
  tree_->GetDirectory()->cd();
  tree_->Write();
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void GenAnalyzer_onlyGen::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
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

//define this as a plug-in
DEFINE_FWK_MODULE(GenAnalyzer_onlyGen);
