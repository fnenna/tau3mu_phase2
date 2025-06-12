from CRABClient.UserUtilities import config, getUsername
config = config()

config.General.requestName = '140X_mcPhase2_DsTau3Mu_PU200_onlyGEMneg_RECO_v3'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'DsTau3Mu_step3_RECO_PU200.py'
#config.Data.inputDataset  = '/DsTau3Mu_pythia8_Phase2_14TeV_PU200/fnenna-140X_mcPhase2_DsTau3Mu_14TeV_PU200_GEN-SIM-DIGI-RAW-8b1164da9ded5d1c783f6a6abfe38469/USER'
config.Data.inputDataset  = '/DsTau3Mu_pythia8_Phase2_14TeV_PU200/fnenna-140X_mcPhase2_DsTau3Mu_14TeV_PU200_onlyGEMneg_GEN-SIM-DIGI-RAW_v3-862c29d9b9cead1e8905b3c11f5de07c/USER'
#config.Data.userInputFiles = ['/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_GEN-SIM-DIGI-RAW/250131_142451/0000/step2_DsTau3Mu_DIGI_1.root',
#                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_GEN-SIM-DIGI-RAW/250131_142451/0000/step2_DsTau3Mu_DIGI_2.root',
#                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_GEN-SIM-DIGI-RAW/250131_142451/0000/step2_DsTau3Mu_DIGI_3.root',
#                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_GEN-SIM-DIGI-RAW/250131_142451/0000/step2_DsTau3Mu_DIGI_4.root',
#                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_GEN-SIM-DIGI-RAW/250131_142451/0000/step2_DsTau3Mu_DIGI_5.root',
#                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_GEN-SIM-DIGI-RAW/250131_142451/0000/step2_DsTau3Mu_DIGI_6.root',
#                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_GEN-SIM-DIGI-RAW/250131_142451/0000/step2_DsTau3Mu_DIGI_7.root',
#                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_GEN-SIM-DIGI-RAW/250131_142451/0000/step2_DsTau3Mu_DIGI_8.root',
#                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_GEN-SIM-DIGI-RAW/250131_142451/0000/step2_DsTau3Mu_DIGI_9.root',
#                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_GEN-SIM-DIGI-RAW/250131_142451/0000/step2_DsTau3Mu_DIGI_10.root']
config.Data.inputDBS = 'phys03'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 1
config.JobType.numCores = 4
config.JobType.maxMemoryMB = 8000
config.Data.publication = True
#config.Data.outputPrimaryDataset = 'DsTau3Mu_privateFnenna_Phase2'
config.Data.outputDatasetTag = '140X_mcPhase2_DsTau3Mu_PU200_onlyGEMneg_RECO_v3'

config.Site.storageSite = 'T2_IT_Bari'
config.JobType.allowUndistributedCMSSW = True
config.Site.ignoreGlobalBlacklist  = True