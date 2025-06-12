from CRABClient.UserUtilities import config, getUsername
config = config()

config.General.requestName = '140X_mcRun4_TenMuE_0_20_newMINIAOD_ANA'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = '/lustrehome/felicenenna/tau3mu/CMSSW_14_0_17/src/GenAnalyser/GenAnalyzer/python/genAnalyser_cff.py'
config.Data.userInputFiles = ['/store/user/fnenna/TenMuE_0_20_Phase2_newPAT/140X_mcRun4_TenMuE_0_20_RECO_RECOSIM_newPAT_VALIDATION_DQM/250127_180625/0000/step3_inMINIAODSIM_newEta_1.root',
                              '/store/user/fnenna/TenMuE_0_20_Phase2_newPAT/140X_mcRun4_TenMuE_0_20_RECO_RECOSIM_newPAT_VALIDATION_DQM/250127_180625/0000/step3_inMINIAODSIM_newEta_2.root',
                              '/store/user/fnenna/TenMuE_0_20_Phase2_newPAT/140X_mcRun4_TenMuE_0_20_RECO_RECOSIM_newPAT_VALIDATION_DQM/250127_180625/0000/step3_inMINIAODSIM_newEta_3.root',
                              '/store/user/fnenna/TenMuE_0_20_Phase2_newPAT/140X_mcRun4_TenMuE_0_20_RECO_RECOSIM_newPAT_VALIDATION_DQM/250127_180625/0000/step3_inMINIAODSIM_newEta_4.root',
                              '/store/user/fnenna/TenMuE_0_20_Phase2_newPAT/140X_mcRun4_TenMuE_0_20_RECO_RECOSIM_newPAT_VALIDATION_DQM/250127_180625/0000/step3_inMINIAODSIM_newEta_5.root',
                              '/store/user/fnenna/TenMuE_0_20_Phase2_newPAT/140X_mcRun4_TenMuE_0_20_RECO_RECOSIM_newPAT_VALIDATION_DQM/250127_180625/0000/step3_inMINIAODSIM_newEta_6.root',
                              '/store/user/fnenna/TenMuE_0_20_Phase2_newPAT/140X_mcRun4_TenMuE_0_20_RECO_RECOSIM_newPAT_VALIDATION_DQM/250127_180625/0000/step3_inMINIAODSIM_newEta_7.root',
                              '/store/user/fnenna/TenMuE_0_20_Phase2_newPAT/140X_mcRun4_TenMuE_0_20_RECO_RECOSIM_newPAT_VALIDATION_DQM/250127_180625/0000/step3_inMINIAODSIM_newEta_8.root',
                              '/store/user/fnenna/TenMuE_0_20_Phase2_newPAT/140X_mcRun4_TenMuE_0_20_RECO_RECOSIM_newPAT_VALIDATION_DQM/250127_180625/0000/step3_inMINIAODSIM_newEta_9.root',
                              '/store/user/fnenna/TenMuE_0_20_Phase2_newPAT/140X_mcRun4_TenMuE_0_20_RECO_RECOSIM_newPAT_VALIDATION_DQM/250127_180625/0000/step3_inMINIAODSIM_newEta_10.root']
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 1
config.JobType.numCores = 1
config.JobType.maxMemoryMB = 5000
config.Data.publication = False
config.Data.outputPrimaryDataset = 'TenMuE_0_20_Phase2_newPAT'
config.Data.outputDatasetTag = "140X_mcRun4_TenMuE_0_20_newMINIAOD_ANA"

config.Site.storageSite = 'T2_IT_Bari'
config.JobType.allowUndistributedCMSSW = True
config.Site.ignoreGlobalBlacklist  = True