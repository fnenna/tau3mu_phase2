from CRABClient.UserUtilities import config, getUsername
config = config()

config.General.requestName = '140X_mcPhase2_14TeV_NuGun_GEN-SIM-DIGI-RAW_PU140_v2'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'NuGunE10_GEN_SIM_DIGI_RAW_PU140_cfg.py'
#config.Data.inputDataset = '/NuGunE10_Phase2_PUstudies/fnenna-140X_mcPhase2_14TeV_NuGun_GEN-39e7e1484ad385ff91596d0972ca93cb/USER'
config.Data.inputDataset = "/NuGunE10_Phase2_PUstudies/fnenna-140X_mcPhase2_14TeV_NuGun_GEN_v2-39e7e1484ad385ff91596d0972ca93cb/USER"
#config.Data.inputDataset = "/NuGunE10_Phase2_PUstudies/fnenna-140X_mcPhase2_14TeV_NuGun_MINIAOD_gemsegm-6ae100ee14b53fd6015588c05a477e7b/USER"
config.Data.inputDBS = 'phys03'
config.Data.splitting = 'EventAwareLumiBased'
config.Data.totalUnits = 50000
config.Data.unitsPerJob = 1
config.JobType.maxMemoryMB = 8000
config.JobType.numCores=4
config.Data.publication = True
config.Data.outputDatasetTag = '140X_mcPhase2_14TeV_NuGun_GEN-SIM-DIGI-RAW_PU140_v2'

config.Site.storageSite = 'T2_IT_Bari'
config.JobType.allowUndistributedCMSSW = True
config.Site.ignoreGlobalBlacklist  = True