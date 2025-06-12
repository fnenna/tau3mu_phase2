from CRABClient.UserUtilities import config, getUsername
config = config()

config.General.requestName = '140X_mcRun4_TenMuE_0_20_RECO_RECOSIM_PAT_VALIDATION_DQM'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'step3_RAW2DIGI_RECO_RECOSIM_PAT_VALIDATION_DQM.py'
config.Data.userInputFiles = ['/store/user/fnenna/CRAB_UserFiles/140X_mcRun4_TenMuE_0_200_GEN-SIM-DIGI-RAW/250124_193122/0000/step2_newEta_1.root',
                              '/store/user/fnenna/CRAB_UserFiles/140X_mcRun4_TenMuE_0_200_GEN-SIM-DIGI-RAW/250124_193122/0000/step2_newEta_2.root',
                              '/store/user/fnenna/CRAB_UserFiles/140X_mcRun4_TenMuE_0_200_GEN-SIM-DIGI-RAW/250124_193122/0000/step2_newEta_3.root',
                              '/store/user/fnenna/CRAB_UserFiles/140X_mcRun4_TenMuE_0_200_GEN-SIM-DIGI-RAW/250124_193122/0000/step2_newEta_4.root',
                              '/store/user/fnenna/CRAB_UserFiles/140X_mcRun4_TenMuE_0_200_GEN-SIM-DIGI-RAW/250124_193122/0000/step2_newEta_5.root',
                              '/store/user/fnenna/CRAB_UserFiles/140X_mcRun4_TenMuE_0_200_GEN-SIM-DIGI-RAW/250124_193122/0000/step2_newEta_6.root',
                              '/store/user/fnenna/CRAB_UserFiles/140X_mcRun4_TenMuE_0_200_GEN-SIM-DIGI-RAW/250124_193122/0000/step2_newEta_7.root',
                              '/store/user/fnenna/CRAB_UserFiles/140X_mcRun4_TenMuE_0_200_GEN-SIM-DIGI-RAW/250124_193122/0000/step2_newEta_8.root',
                              '/store/user/fnenna/CRAB_UserFiles/140X_mcRun4_TenMuE_0_200_GEN-SIM-DIGI-RAW/250124_193122/0000/step2_newEta_9.root',
                              '/store/user/fnenna/CRAB_UserFiles/140X_mcRun4_TenMuE_0_200_GEN-SIM-DIGI-RAW/250124_193122/0000/step2_newEta_10.root']
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 1
config.JobType.numCores = 1
config.JobType.maxMemoryMB = 5000
config.Data.publication = False
config.Data.outputPrimaryDataset = 'TenMuE_0_20_Phase2'
config.Data.outputDatasetTag = '140X_mcRun4_TenMuE_0_20_RECO_RECOSIM_PAT_VALIDATION_DQM'

config.Site.storageSite = 'T2_IT_Bari'
config.JobType.allowUndistributedCMSSW = True
config.Site.ignoreGlobalBlacklist  = True