from CRABClient.UserUtilities import config, getUsername
config = config()

config.General.requestName = '140X_mcRun4_TenMuE_0_200_GEN-SIM'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'PrivateMC'
config.JobType.psetName = 'TenMuE_0_200_pythia8_cfi_GEN_SIM.py'
config.Data.outputPrimaryDataset = 'TenMuE_0_200_Phase2'
config.Data.splitting = 'EventBased'
config.JobType.eventsPerLumi = 200
config.Data.unitsPerJob = 500
NJOBS = 10
config.Data.totalUnits = config.Data.unitsPerJob * NJOBS
config.JobType.numCores = 1
config.JobType.maxMemoryMB = 4000
config.Data.publication = False
config.Data.outputDatasetTag = '140X_mcRun4_TenMuE_0_200_GEN-SIM'

config.Site.storageSite = 'T2_IT_Bari'
config.JobType.allowUndistributedCMSSW = True
config.Site.ignoreGlobalBlacklist  = True