import FWCore.ParameterSet.Config as cms

process = cms.Process('Tau3MuSkim')

import copy

process.load("FWCore.MessageService.MessageLogger_cfi")
process.load("TrackingTools/TransientTrack/TransientTrackBuilder_cfi")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.load("TrackingTools.TransientTrack.TransientTrackBuilder_cfi")
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('Configuration/Geometry/GeometryExtended2026D110Reco_cff')
process.load('Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
#process.load("TrackingTools.TransientTrack.TransientTrackBuilder_cfi")


process.GlobalTag.globaltag = '140X_mcRun4_realistic_v6' #Run4MC 
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        #'/store/user/fnenna/NuGunE10_Phase2_PUstudies/140X_mcPhase2_14TeV_NuGun_MINIAOD/250415_183629/0000/step3_NuGunE10_inMINIAODSIM_529.root'
        #'file:/lustrehome/felicenenna/tau3mu/CMSSW_14_0_17/src/MC_generation/DsTau3Mu/python/step3_DsTau3Mu_inMINIAODSIM.root'
        #'file:/lustrehome/felicenenna/step3_NuGunE10_inMINIAODSIM.root'
        #'file:/lustre/cms/store/user/fnenna/NuGunE10_Phase2_PUstudies/140X_mcPhase2_14TeV_NuGun_MINIAOD_gemsegm/250524_110223/0000/step3_NuGunE10_inMINIAODSIM_882.root'
        #'file:/lustrehome/felicenenna/tau3mu/CMSSW_14_0_17/src/MC_generation/DsTau3Mu/step3_DsTau3Mu_inMINIAODSIM.root'
        #'file:/lustrehome/felicenenna/tau3mu/CMSSW_14_0_17/src/MC_generation/NuGun/CrabSubmission/step3_NuGunE10_inMINIAODSIM.root'
        'file:/lustrehome/felicenenna/tau3mu/CMSSW_14_0_17/src/MC_generation/NuGun/CrabSubmission/step3_NuGunE10_inMINIAODSIM_PU50.root'

        #MC Run2024
        #'root://xrootd-cms.infn.it/store/mc/Phase2Spring24DIGIRECOMiniAOD/MinBias_TuneCP5_14TeV-pythia8/GEN-SIM-DIGI-RAW-MINIAOD/PU200ALCA_140X_mcRun4_realistic_v4-v2/120000/004dd3c5-29c9-4283-95f3-baf57220dce2.root',
        #'file:/lustrehome/felicenenna/tau3mu/CMSSW_14_0_17/src/GenAnalyser/004f52f5-5cac-4a87-ab4d-ac7fcea30858.root'
        #"file:/lustrehome/felicenenna/tau3mu/CMSSW_14_0_17/src/GenAnalyser/00078112-8503-4587-8dca-8fecf38d35fb.root" 
        #"file:/lustrehome/felicenenna/tau3mu/CMSSW_14_0_17/src/Utilities/run_the_matrix/29621.0_TenMuE_0_200+2026D110/step3_newEta.root"
        #"file:/lustre/cms/store/user/fnenna/DsTau3Mu_pythia8_Phase2_14TeV_PU200/140X_mcPhase2_DsTau3Mu_MINIAOD_NoPU_onlyGEMneg/250225_100923/0000/step3_DsTau3Mu_inMINIAODSIM_540.root"
        #"file:/lustre/cms/store/user/fnenna/DsTau3Mu_pythia8_Phase2_14TeV_PU200/140X_mcPhase2_14TeV_DsTau3Mu_onlyGEMneg_GEN-SIM_v2/250303_150857/0000/DsTau3Mu_GEN-SIM_Phase2_2.root"
        #'/store/mc/Phase2Spring24GS/MinBias_TuneCP5_14TeV-pythia8/GEN-SIM/140X_mcRun4_realistic_v4-v1/2520000/029209dc-ba63-4f0f-a74a-ec922dc01663.root'
        #"file:/lustre/cms/store/user/fnenna/DsTau3Mu_pythia8_Phase2_14TeV_PU200/140X_mcPhase2_14TeV_DsTau3Mu_onlyGEMneg_GEN-SIM_v3/250304_215930/0000/DsTau3Mu_GEN-SIM_Phase2_1.root"
        #"file:/lustrehome/felicenenna/tau3mu/CMSSW_14_0_17/src/Utilities/run_the_matrix/29621.0_TenMuE_0_200+2026D110/step3_inMINIAODSIM_newEta.root"
        #"/store/user/jschulte/DSTau3Mu_14TeV_Pythia8/jschulte-Phase2Spring24DIGIRECOMiniAOD-PU200_140X_mcRun4_realistic_v4_MiniAODTest_v1-515bee752741ef71814a39d75a17d442/241210_191536/0000/XTau3Mu_GEN_SIM_DIGI_RAW_MINIAOD_1.root",
        #MC DsTau3Mu 2023
        #'root://xrootd-cms.infn.it//"'root://xrootd-cms.infn.it//""/store/mc/Run3Summer22MiniAODv4/DsToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/2540000/5ef6393b-32c8-41c5-8a3f-af1b6529a9c9.root",",',
        #'root://xrootd-cms.infn.it//""/store/mc/Run3Summer22MiniAODv4/DsToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/2540000/b7fa0de1-fd0e-4094-a5ec-ceece64db4af.root",",',
        #'root://xrootd-cms.infn.it//""/store/mc/Run3Summer22MiniAODv4/DsToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/30000/5ab61b39-05bc-41c9-889e-357c65922f03.root",",',
        #'root://xrootd-cms.infn.it//""/store/mc/Run3Summer22MiniAODv4/DsToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/30000/8d67b4cd-f759-4b41-ae3e-179c72e98367.root",",',
        #'root://xrootd-cms.infn.it//""/store/mc/Run3Summer22MiniAODv4/DsToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/30000/daa8ab3e-6cfc-4a96-a3ac-e4d677815a3f.root",",',

       #MC WTau3mu
#'root://xrootd-cms.infn.it//""/store/mc/Run3Summer22MiniAODv4/WToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/2520000/e8fd601a-a377-4e20-a3a6-ee316975fbe8.root",",',
#'root://xrootd-cms.infn.it//""/store/mc/Run3Summer22MiniAODv4/WToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/30000/0420aba2-5de3-490b-83b5-0c7e12666615.root",",',
#'root://xrootd-cms.infn.it//""/store/mc/Run3Summer22MiniAODv4/WToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/30000/297b4d68-465f-4b0d-b1b2-434beba9a05b.root",",',
#'root://xrootd-cms.infn.it//""/store/mc/Run3Summer22MiniAODv4/WToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/30000/37f2df9e-e23f-4d1c-8b30-bc2d2d824deb.root",",',
#'root://xrootd-cms.infn.it//""/store/mc/Run3Summer22MiniAODv4/WToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/30000/7088360f-8483-4229-8d57-ec816b6ead4a.root",",',
#'root://xrootd-cms.infn.it//""/store/mc/Run3Summer22MiniAODv4/WToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/30000/76a34b30-5294-4f19-9805-4f2831a9beda.root",",',
#'root://xrootd-cms.infn.it//""/store/mc/Run3Summer22MiniAODv4/WToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/40000/8512727a-9222-4c1a-be50-36572c6698c3.root",",',
#'root://xrootd-cms.infn.it//""/store/mc/Run3Summer22MiniAODv4/WToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/40000/a6175f49-f3a8-4ca1-a4f6-af6622252adf.root",",',
#'root://xrootd-cms.infn.it//""/store/mc/Run3Summer22MiniAODv4/WToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/40000/f45163c1-632b-403f-8553-51e6908b36dc.root",",',
#'root://xrootd-cms.infn.it//""/store/mc/Run3Summer22MiniAODv4/WToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/50000/2fd1e51e-6aae-40fb-a26f-4d53b2c4cad9.root",",',
#'root://xrootd-cms.infn.it//""/store/mc/Run3Summer22MiniAODv4/WToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/50000/63c1a09f-c527-46e1-9d3e-f72369b2a542.root",",',
#'root://xrootd-cms.infn.it//""/store/mc/Run3Summer22MiniAODv4/WToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/50000/d04bad90-cf47-4947-a464-728119f33e43.root",",',
#'root://xrootd-cms.infn.it//""/store/mc/Run3Summer22MiniAODv4/WToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/50000/da7fcca8-5064-41a8-9e63-f6cde6abf10f.root",",',
    ),
            #eventsToProcess = cms.untracked.VEventRange('320012:56448719')
)


process.TFileService = cms.Service("TFileService",
                                   fileName = cms.string("TreeMC_GEMsegmPU50.root"))

#process.TreeMaker = cms.EDAnalyzer("GenAnalyzer_onlyGen",
#                                    genParticleLabel=cms.InputTag("genParticles")
#)
                           

#process.TreeMaker = cms.EDAnalyzer("GenAnalyzer_onlyReco",
process.TreeMaker = cms.EDAnalyzer("GenAnalyzer_segments",
#process.TreeMaker = cms.EDAnalyzer("GenAnalyzer_onlyGen",
                                      #genParticleLabel=cms.InputTag("genParticles"),
                                      recomuonLabel=cms.InputTag("muons"),
                                      muonLabel=cms.InputTag("slimmedMuons"),
                                      genParticleLabel=cms.InputTag("prunedGenParticles"),
                                      TracksLabel = cms.InputTag("packedPFCandidates"),
                                      GEMSegmentCollectionLabel = cms.InputTag("gemSegments"),
                                      CSCSegmentCollectionLabel = cms.InputTag("cscSegments")
)


process.Tau3MuSkim = cms.Path( process.TreeMaker )
