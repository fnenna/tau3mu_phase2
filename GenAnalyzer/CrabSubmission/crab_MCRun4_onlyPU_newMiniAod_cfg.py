from CRABClient.UserUtilities import config, getUsername
config = config()

config.General.requestName = '140X_mcPhase2_onlyPU_GenAna_v2'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = '/lustrehome/felicenenna/tau3mu/CMSSW_14_0_17/src/GenAnalyser/GenAnalyzer/python/genAnalyser_cff.py'
config.Data.inputDataset = '/MinBias_TuneCP5_14TeV-pythia8/fnenna-140X_mcPhase2_14TeV_onlyPU_MINIAOD_v3-6ae100ee14b53fd6015588c05a477e7b/USER'
#config.Data.userInputFiles = ['/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_RECO_RECOSIM_PAT_VALIDATION_DQM/250201_084650/0000/step3_DsTau3Mu_inMINIAODSIM_1.root',
#                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_RECO_RECOSIM_PAT_VALIDATION_DQM/250201_084650/0000/step3_DsTau3Mu_inMINIAODSIM_2.root',
#                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_RECO_RECOSIM_PAT_VALIDATION_DQM/250201_084650/0000/step3_DsTau3Mu_inMINIAODSIM_3.root',
#                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_RECO_RECOSIM_PAT_VALIDATION_DQM/250201_084650/0000/step3_DsTau3Mu_inMINIAODSIM_4.root',
#                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_RECO_RECOSIM_PAT_VALIDATION_DQM/250201_084650/0000/step3_DsTau3Mu_inMINIAODSIM_5.root',
#                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_RECO_RECOSIM_PAT_VALIDATION_DQM/250201_084650/0000/step3_DsTau3Mu_inMINIAODSIM_6.root',
#                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_RECO_RECOSIM_PAT_VALIDATION_DQM/250201_084650/0000/step3_DsTau3Mu_inMINIAODSIM_7.root',
#                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_RECO_RECOSIM_PAT_VALIDATION_DQM/250201_084650/0000/step3_DsTau3Mu_inMINIAODSIM_8.root',
#                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_RECO_RECOSIM_PAT_VALIDATION_DQM/250201_084650/0000/step3_DsTau3Mu_inMINIAODSIM_9.root',
#                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_RECO_RECOSIM_PAT_VALIDATION_DQM/250201_084650/0000/step3_DsTau3Mu_inMINIAODSIM_10.root']

config.Data.inputDBS = 'phys03'
#config.Data.splitting = 'LumiBased'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 10
config.Data.publication = True
#config.Data.outputPrimaryDataset = 'DsTau3Mu_privateFnenna_Phase2'
config.Data.outputDatasetTag = "140X_mcPhase2_onlyPU_GenAna_v2"
config.JobType.allowUndistributedCMSSW = True 
config.Site.storageSite = 'T2_IT_Bari'
config.Site.ignoreGlobalBlacklist  = True

