from CRABClient.UserUtilities import config, getUsername
config = config()

#config.General.requestName = '140X_mcPhase2_DsTau3Mu_GEN_ANAv3_allEtas_PU200_Gen'
config.General.requestName = '140X_mcPhase2_DsTau3Mu_miniaod_genInfo_PU200_onlyGEMneg_withChi'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'

config.JobType.psetName = '/lustrehome/felicenenna/tau3mu/CMSSW_14_0_17/src/GenAnalyser/GenAnalyzer/python/genAnalyser_cff.py'
#config.Data.inputDataset = "/DsTau3Mu_pythia8_Phase2_14TeV_PU200/fnenna-140X_mcPhase2_DsTau3Mu_MINIAOD_NoPU-6ae100ee14b53fd6015588c05a477e7b/USER"
#config.Data.inputDataset = '/DsTau3Mu_pythia8_Phase2_14TeV_PU200/fnenna-140X_mcPhase2_DsTau3Mu_MINIAOD_NoPU_onlyGEMneg-6ae100ee14b53fd6015588c05a477e7b/USER'
#config.Data.inputDataset = '/DsTau3Mu_pythia8_Phase2_14TeV_PU200/fnenna-140X_mcPhase2_14TeV_DsTau3Mu_onlyGEMneg_GEN-SIM-fb65f432edcfe3909e36927b0b2b18cb/USER'
#config.Data.inputDataset = '/DsTau3Mu_pythia8_Phase2_14TeV_PU200/fnenna-140X_mcPhase2_14TeV_DsTau3Mu_onlyGEMneg_GEN-SIM_v3-784cb3da897a3436213ab346162fdf0e/USER'
#config.Data.inputDataset = '/DsTau3Mu_pythia8_Phase2_14TeV_PU200/fnenna-140X_mcPhase2_DsTau3Mu_MINIAOD_NoPU_onlyGEMneg_v2-6ae100ee14b53fd6015588c05a477e7b/USER'
#config.Data.inputDataset = '/DsTau3Mu_pythia8_Phase2_14TeV_PU200/fnenna-140X_mcPhase2_DsTau3Mu_PU200_onlyGEMneg_MINIAOD_v3-6ae100ee14b53fd6015588c05a477e7b/USER'
#config.Data.inputDataset = '/DsTau3Mu_pythia8_Phase2_14TeV_PU200/fnenna-140X_mcPhase2_14TeV_DsTau3Mu_onlyGEMneg_GEN-SIM_v3-784cb3da897a3436213ab346162fdf0e/USER'
#config.Data.inputDataset = '/DsTau3Mu_pythia8_Phase2_14TeV_PU200/fnenna-140X_mcPhase2_14TeV_DsTau3Mu_allEtas_GEN-SIM_v2-784cb3da897a3436213ab346162fdf0e/USER'
##config.Data.inputDataset = '/DsTau3Mu_pythia8_Phase2_14TeV_PU200/fnenna-140X_mcPhase2_DsTau3Mu_MINIAOD_NoPU_onlyGEMpos_complete-6ae100ee14b53fd6015588c05a477e7b/USER'
config.Data.outputPrimaryDataset = "DsTau3Mu_Phase2_PUstudies_gemsegm_PU200_GEMNeg"
#config.Data.userInputFiles = open('/lustrehome/felicenenna/tau3mu/CMSSW_14_0_17/src/GenAnalyser/GenAnalyzer/python/lista_root_files.txt').readlines()
config.Data.userInputFiles = open('/lustrehome/felicenenna/tau3mu/CMSSW_14_0_17/src/MC_generation/DsTau3Mu/CrabSubmission/file_list.txt').readlines()
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
config.Data.outputDatasetTag = "140X_mcPhase2_DsTau3Mu_miniaod_genInfo_PU200_onlyGEMneg_withChi"
config.JobType.allowUndistributedCMSSW = True 
config.Site.storageSite = 'T2_IT_Bari'
config.Site.ignoreGlobalBlacklist  = True

