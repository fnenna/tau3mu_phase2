from CRABClient.UserUtilities import config, getUsername
config = config()

config.General.requestName = '140X_mcPhase2_DsTau3Mu_MINIAOD_NoPU_onlyGEMpos_complete'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = '/lustrehome/felicenenna/tau3mu/CMSSW_14_0_17/src/MC_generation/DsTau3Mu/python/DsTau3Mu_step3_MiniAOD_NoPU.py'
#config.Data.inputDataset  = '/DsTau3Mu_pythia8_Phase2_14TeV_PU200/fnenna-140X_mcPhase2_DsTau3Mu_14TeV_NoPU_GEN-SIM-DIGI-RAW-3e6308c9f2e1b5f7149b10726641c719/USER'
#config.Data.inputDataset  = '/DsTau3Mu_pythia8_Phase2_14TeV_PU200/fnenna-140X_mcPhase2_DsTau3Mu_14TeV_NoPU_onlyGEMpos_GEN-SIM-DIGI-RAW-3ccceeb55cf8ddde9a3cc74f34b8d2db/USER'
#config.Data.inputDataset  = '/DsTau3Mu_pythia8_Phase2_14TeV_PU200/fnenna-140X_mcPhase2_DsTau3Mu_14TeV_NoPU_onlyGEMneg_GEN-SIM-DIGI-RAW_v2-ed3bd3bc8b93ae7e4e3f5bc45750773e/USER'
config.Data.inputDataset  = '/DsTau3Mu_pythia8_Phase2_14TeV_PU200/fnenna-140X_mcPhase2_DsTau3Mu_14TeV_NoPU_onlyGEMpos_GEN-SIM-DIGI-RAW_v3-47404e36d9561b7baf702233d8410848/USER'
#config.Data.inputDataset  = '/DsTau3Mu_pythia8_Phase2_14TeV_PU200/fnenna-140X_mcPhase2_DsTau3Mu_14TeV_NoPU_onlyGEMneg_GEN-SIM-DIGI-RAW-a72cf629561b1358e32d96feadcc5759/USER'
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
config.Data.outputDatasetTag = '140X_mcPhase2_DsTau3Mu_MINIAOD_NoPU_onlyGEMpos_complete'

config.Site.storageSite = 'T2_IT_Bari'
config.JobType.allowUndistributedCMSSW = True
config.Site.ignoreGlobalBlacklist  = True