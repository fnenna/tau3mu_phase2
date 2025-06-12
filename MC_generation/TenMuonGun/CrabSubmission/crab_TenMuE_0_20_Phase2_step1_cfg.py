from CRABClient.UserUtilities import config, getUsername
config = config()

config.General.requestName = '140X_mcRun4_TenMuE_0_20_GEN-SIM-DIGI-RAW'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'step2_DIGI_L1TrackTrigger_L1_DIGI2RAW_HLT.py'
config.Data.userInputFiles = ['/store/user/fnenna/TenMuE_0_20_Phase2/140X_mcRun4_TenMuE_0_20_GEN-SIM/250126_155601/0000/TenMuE_0_20_GEN_SIM_1.root',
                              '/store/user/fnenna/TenMuE_0_20_Phase2/140X_mcRun4_TenMuE_0_20_GEN-SIM/250126_155601/0000/TenMuE_0_20_GEN_SIM_2.root',
                              '/store/user/fnenna/TenMuE_0_20_Phase2/140X_mcRun4_TenMuE_0_20_GEN-SIM/250126_155601/0000/TenMuE_0_20_GEN_SIM_3.root',
                              '/store/user/fnenna/TenMuE_0_20_Phase2/140X_mcRun4_TenMuE_0_20_GEN-SIM/250126_155601/0000/TenMuE_0_20_GEN_SIM_4.root',
                              '/store/user/fnenna/TenMuE_0_20_Phase2/140X_mcRun4_TenMuE_0_20_GEN-SIM/250126_155601/0000/TenMuE_0_20_GEN_SIM_5.root',
                              '/store/user/fnenna/TenMuE_0_20_Phase2/140X_mcRun4_TenMuE_0_20_GEN-SIM/250126_155601/0000/TenMuE_0_20_GEN_SIM_6.root',
                              '/store/user/fnenna/TenMuE_0_20_Phase2/140X_mcRun4_TenMuE_0_20_GEN-SIM/250126_155601/0000/TenMuE_0_20_GEN_SIM_7.root',
                              '/store/user/fnenna/TenMuE_0_20_Phase2/140X_mcRun4_TenMuE_0_20_GEN-SIM/250126_155601/0000/TenMuE_0_20_GEN_SIM_8.root',
                              '/store/user/fnenna/TenMuE_0_20_Phase2/140X_mcRun4_TenMuE_0_20_GEN-SIM/250126_155601/0000/TenMuE_0_20_GEN_SIM_9.root',
                              '/store/user/fnenna/TenMuE_0_20_Phase2/140X_mcRun4_TenMuE_0_20_GEN-SIM/250126_155601/0000/TenMuE_0_20_GEN_SIM_10.root']
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 1
config.JobType.numCores = 1
config.JobType.maxMemoryMB = 4000
config.Data.publication = False
config.Data.outputDatasetTag = '140X_mcRun4_TenMuE_0_200_GEN-SIM-DIGI-RAW'

config.Site.storageSite = 'T2_IT_Bari'
config.JobType.allowUndistributedCMSSW = True
config.Site.ignoreGlobalBlacklist  = True