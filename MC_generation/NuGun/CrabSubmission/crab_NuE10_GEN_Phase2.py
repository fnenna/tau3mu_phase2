from CRABClient.UserUtilities import config, getUsername
config = config()

#config.General.requestName = '140X_mcPhase2_14TeV_DsTau3Mu_onlyGEMpos_GEN-SIM_v3'
config.General.requestName = '140X_mcPhase2_14TeV_NuGun_GEN_v2'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'PrivateMC'
config.JobType.psetName = 'SingleNuE10_cfi_GEN_SIM.py'
config.Data.outputPrimaryDataset = 'NuGunE10_Phase2_PUstudies'
config.Data.splitting   = 'EventBased'
config.Data.unitsPerJob = 500
NJOBS = 1000
config.Data.totalUnits = config.Data.unitsPerJob * NJOBS
#config.JobType.numCores = 1
config.JobType.maxMemoryMB = 2500
config.Data.publication = True
config.Data.outputDatasetTag = '140X_mcPhase2_14TeV_NuGun_GEN_v2'

config.Site.storageSite = 'T2_IT_Bari'
config.JobType.allowUndistributedCMSSW = True
config.Site.ignoreGlobalBlacklist  = True
#config.Site.blacklist = ["T2_CH_CERN"]