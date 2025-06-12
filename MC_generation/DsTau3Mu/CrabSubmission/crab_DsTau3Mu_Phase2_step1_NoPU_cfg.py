from CRABClient.UserUtilities import config, getUsername
config = config()

config.General.requestName = '140X_mcPhase2_DsTau3Mu_14TeV_NoPU_onlyGEMpos_GEN-SIM-DIGI-RAW_v3'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'DsTau3Mu_step2_DIGI_L1TrackTrigger_L1_DIGI2RAW_HLT.py'
#config.Data.inputDataset = '/DsTau3Mu_pythia8_Phase2/fnenna-140X_mcPhase2_DsTau3Mu_GEN-SIM-868ca7f36322e2a66e82d6277eace596/USER'
#config.Data.inputDataset = '/DsTau3Mu_pythia8_Phase2_14TeV_PU200/fnenna-140X_mcPhase2_14TeV_DsTau3Mu_GEN-SIM-fb65f432edcfe3909e36927b0b2b18cb/USER'
#config.Data.inputDataset = '/DsTau3Mu_pythia8_Phase2_14TeV_PU200/fnenna-140X_mcPhase2_14TeV_DsTau3Mu_onlyGEMneg_GEN-SIM-fb65f432edcfe3909e36927b0b2b18cb/USER'
#config.Data.inputDataset = '/DsTau3Mu_pythia8_Phase2_14TeV_PU200/fnenna-140X_mcPhase2_14TeV_DsTau3Mu_onlyGEMneg_GEN-SIM_v3-784cb3da897a3436213ab346162fdf0e/USER'
config.Data.inputDataset = '/DsTau3Mu_pythia8_Phase2_14TeV_PU200/fnenna-140X_mcPhase2_14TeV_DsTau3Mu_onlyGEMpos_GEN-SIM_v3-784cb3da897a3436213ab346162fdf0e/USER'
#config.Data.inputDataset = '/DsTau3Mu_pythia8_Phase2_14TeV_PU200/fnenna-140X_mcPhase2_14TeV_DsTau3Mu_onlyGEMpos_GEN-SIM-fb65f432edcfe3909e36927b0b2b18cb/USER'
'''
config.Data.userInputFiles = ['/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_GEN-SIM/250131_121950/0000/DsTau3Mu_GEN-SIM_Phase2_1.root',
                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_GEN-SIM/250131_121950/0000/DsTau3Mu_GEN-SIM_Phase2_2.root',
                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_GEN-SIM/250131_121950/0000/DsTau3Mu_GEN-SIM_Phase2_3.root',
                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_GEN-SIM/250131_121950/0000/DsTau3Mu_GEN-SIM_Phase2_4.root',
                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_GEN-SIM/250131_121950/0000/DsTau3Mu_GEN-SIM_Phase2_5.root',
                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_GEN-SIM/250131_121950/0000/DsTau3Mu_GEN-SIM_Phase2_6.root',
                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_GEN-SIM/250131_121950/0000/DsTau3Mu_GEN-SIM_Phase2_7.root',
                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_GEN-SIM/250131_121950/0000/DsTau3Mu_GEN-SIM_Phase2_8.root',
                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_GEN-SIM/250131_121950/0000/DsTau3Mu_GEN-SIM_Phase2_9.root',
                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_GEN-SIM/250131_121950/0000/DsTau3Mu_GEN-SIM_Phase2_10.root']
'''
config.Data.inputDBS = 'phys03'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 10
config.JobType.maxMemoryMB = 3500
config.JobType.numCores=1
config.Data.publication = True
#config.Data.outputPrimaryDataset = 'DsTau3Mu_privateFnenna_Phase2'
config.Data.outputDatasetTag = '140X_mcPhase2_DsTau3Mu_14TeV_NoPU_onlyGEMpos_GEN-SIM-DIGI-RAW_v3'

config.Site.storageSite = 'T2_IT_Bari'
config.JobType.allowUndistributedCMSSW = True
config.Site.ignoreGlobalBlacklist  = True