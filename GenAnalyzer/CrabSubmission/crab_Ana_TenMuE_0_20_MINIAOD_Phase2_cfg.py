from CRABClient.UserUtilities import config, getUsername
config = config()

config.General.requestName = '140X_mcRun4_TenMuE_0_20_GEN_ANA'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = '/lustrehome/felicenenna/tau3mu/CMSSW_14_0_17/src/GenAnalyser/GenAnalyzer/python/genAnalyser_cff.py'
config.Data.userInputFiles = ['/store/user/fnenna/TenMuE_0_20_Phase2/140X_mcRun4_TenMuE_0_20_GEN-SIM/250126_155601/0000/TenMuE_0_20_GEN_SIM_0.root',
                              '/store/user/fnenna/TenMuE_0_20_Phase2/140X_mcRun4_TenMuE_0_20_GEN-SIM/250126_155601/0000/TenMuE_0_20_GEN_SIM_1.root',
                              '/store/user/fnenna/TenMuE_0_20_Phase2/140X_mcRun4_TenMuE_0_20_GEN-SIM/250126_155601/0000/TenMuE_0_20_GEN_SIM_2.root',
                              '/store/user/fnenna/TenMuE_0_20_Phase2/140X_mcRun4_TenMuE_0_20_GEN-SIM/250126_155601/0000/TenMuE_0_20_GEN_SIM_3.root',
                              '/store/user/fnenna/TenMuE_0_20_Phase2/140X_mcRun4_TenMuE_0_20_GEN-SIM/250126_155601/0000/TenMuE_0_20_GEN_SIM_4.root',
                              '/store/user/fnenna/TenMuE_0_20_Phase2/140X_mcRun4_TenMuE_0_20_GEN-SIM/250126_155601/0000/TenMuE_0_20_GEN_SIM_5.root',
                              '/store/user/fnenna/TenMuE_0_20_Phase2/140X_mcRun4_TenMuE_0_20_GEN-SIM/250126_155601/0000/TenMuE_0_20_GEN_SIM_6.root',
                              '/store/user/fnenna/TenMuE_0_20_Phase2/140X_mcRun4_TenMuE_0_20_GEN-SIM/250126_155601/0000/TenMuE_0_20_GEN_SIM_7.root',
                              '/store/user/fnenna/TenMuE_0_20_Phase2/140X_mcRun4_TenMuE_0_20_GEN-SIM/250126_155601/0000/TenMuE_0_20_GEN_SIM_8.root',
                              '/store/user/fnenna/TenMuE_0_20_Phase2/140X_mcRun4_TenMuE_0_20_GEN-SIM/250126_155601/0000/TenMuE_0_20_GEN_SIM_9.root']
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 1
config.JobType.numCores = 1
config.JobType.maxMemoryMB = 5000
config.Data.publication = False
config.Data.outputPrimaryDataset = 'TenMuE_0_20_Phase2'
config.Data.outputDatasetTag = "140X_mcRun4_TenMuE_0_20_GEN_ANA"

config.Site.storageSite = 'T2_IT_Bari'
config.JobType.allowUndistributedCMSSW = True
config.Site.ignoreGlobalBlacklist  = True