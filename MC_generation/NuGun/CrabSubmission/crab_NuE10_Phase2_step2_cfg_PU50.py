from CRABClient.UserUtilities import config, getUsername
config = config()

config.General.requestName = '140X_mcPhase2_14TeV_NuGun_MINIAOD_PU50_v2'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'NuGunE10_step3_MiniAOD_PU50.py'
#config.Data.outputPrimaryDataset = "NuGunE10_Phase2_PUstudies_140"
#config.Data.userInputFiles = open('/lustrehome/felicenenna/tau3mu/CMSSW_14_0_17/src/MC_generation/NuGun/CrabSubmission/paths_BX0.txt').readlines()
#config.JobType.psetName = 'NuGunE10_step3_MiniAOD_PU200.py'
#config.Data.inputDataset  = '/NuGunE10_Phase2_PUstudies/fnenna-140X_mcPhase2_14TeV_NuGun_GEN-SIM-DIGI-RAW_PU50-c52b8d7ba8f78245041831e03d76270a/USER'
config.Data.inputDataset  = '/NuGunE10_Phase2_PUstudies/fnenna-140X_mcPhase2_14TeV_NuGun_GEN-SIM-DIGI-RAW_PU50_v2-824ac2c26a76361b5c19b1924120035b/USER'
config.Data.inputDBS = 'phys03'
#config.Data.splitting = 'EventAwareLumiBased'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 1
config.JobType.numCores = 4
config.JobType.maxMemoryMB = 8000
config.Data.publication = True
config.Data.outputDatasetTag = '140X_mcPhase2_14TeV_NuGun_MINIAOD_50_v2'

config.Site.storageSite = 'T2_IT_Bari'
config.JobType.allowUndistributedCMSSW = True
config.Site.ignoreGlobalBlacklist  = True