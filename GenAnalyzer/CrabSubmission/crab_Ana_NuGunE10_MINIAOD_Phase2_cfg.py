from CRABClient.UserUtilities import config, getUsername
config = config()

config.General.requestName = '140X_mcPhase2_NuGunPU200_MiniaodAna_PU50_v2'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = '/lustrehome/felicenenna/tau3mu/CMSSW_14_0_17/src/GenAnalyser/GenAnalyzer/python/genAnalyser_cff.py'
#config.Data.outputPrimaryDataset = "NuGunE10_Phase2_PUstudies_gemsegm"
#config.Data.userInputFiles = open('/lustrehome/felicenenna/tau3mu/CMSSW_14_0_17/src/GenAnalyser/GenAnalyzer/CrabSubmission/output_match_v1.txt').readlines()
#config.Data.inputDataset = "/NuGunE10_Phase2_PUstudies/fnenna-140X_mcPhase2_14TeV_NuGun_MINIAOD_gemsegm-6ae100ee14b53fd6015588c05a477e7b/USER"
#config.Data.inputDataset = '/NuGunE10_Phase2_PUstudies_gemsegm/fnenna-140X_mcPhase2_14TeV_NuGun_MINIAOD_newConfigFile-ece9576153624786c5b578bc33ac1c32/USER'
#config.Data.inputDataset = '/NuGunE10_Phase2_PUstudies_BX0/fnenna-140X_mcPhase2_14TeV_NuGun_MINIAOD_BX0-ece9576153624786c5b578bc33ac1c32/USER'
#config.Data.inputDataset = '/NuGunE10_Phase2_PUstudies/fnenna-140X_mcPhase2_14TeV_NuGun_MINIAOD_140-ece9576153624786c5b578bc33ac1c32/USER'
#config.Data.inputDataset = '/NuGunE10_Phase2_PUstudies/fnenna-140X_mcPhase2_14TeV_NuGun_MINIAOD_50-ece9576153624786c5b578bc33ac1c32/USER'
#config.Data.inputDataset = '/NuGunE10_Phase2_PUstudies/fnenna-140X_mcPhase2_14TeV_NuGun_MINIAOD_PU1-ece9576153624786c5b578bc33ac1c32/USER'
#config.Data.inputDataset = '/NuGunE10_Phase2_PUstudies/fnenna-140X_mcPhase2_14TeV_NuGun_GEN-SIM-DIGI-RAW_PU140_v2-5be23de5000af8de5ba2a8b4110a4815/USER'
config.Data.inputDataset = '/NuGunE10_Phase2_PUstudies/fnenna-140X_mcPhase2_14TeV_NuGun_MINIAOD_50_v2-ece9576153624786c5b578bc33ac1c32/USER'
config.Data.inputDBS = 'phys03'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 5
config.Data.publication = True
config.Data.outputDatasetTag = "140X_mcPhase2_NuGunPU200_MiniaodAna_PU50_v2"
config.JobType.allowUndistributedCMSSW = True 
config.Site.storageSite = 'T2_IT_Bari'
config.Site.ignoreGlobalBlacklist  = True
