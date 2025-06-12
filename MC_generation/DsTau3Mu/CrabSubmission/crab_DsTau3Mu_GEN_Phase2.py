from CRABClient.UserUtilities import config, getUsername
config = config()

#config.General.requestName = '140X_mcPhase2_14TeV_DsTau3Mu_onlyGEMpos_GEN-SIM_v3'
config.General.requestName = '140X_mcPhase2_14TeV_DsTau3Mu_allEtas_GEN-SIM_v3'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'PrivateMC'
config.JobType.psetName = '/lustrehome/felicenenna/tau3mu/CMSSW_14_0_17/src/MC_generation/DsTau3Mu/python/DsTau3Mu_pythia8_cfi_GEN_SIM.py'
config.Data.outputPrimaryDataset = 'DsTau3Mu_pythia8_Phase2_14TeV_PU200'
config.Data.splitting   = 'EventBased'
config.Data.unitsPerJob = 100000
NJOBS = 10000
config.Data.totalUnits = config.Data.unitsPerJob * NJOBS
#config.JobType.numCores = 1
config.JobType.maxMemoryMB = 3500
config.Data.publication = True
config.Data.outputDatasetTag = '140X_mcPhase2_14TeV_DsTau3Mu_allEtas_GEN-SIM_v3'

config.Site.storageSite = 'T2_IT_Bari'
config.JobType.allowUndistributedCMSSW = True
config.Site.ignoreGlobalBlacklist  = True
config.Site.blacklist = ["T2_CH_CERN"]