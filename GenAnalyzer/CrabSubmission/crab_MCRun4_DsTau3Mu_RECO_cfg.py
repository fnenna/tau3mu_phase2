from CRABClient.UserUtilities import config, getUsername
config = config()

config.General.requestName = '140X_mcPhase2_DsTau3Mu_RECO_ANAv3_onlyGEMneg_PU200'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = False

config.JobType.pluginName = 'Analysis'

config.JobType.psetName = '/lustrehome/felicenenna/tau3mu/CMSSW_14_0_17/src/GenAnalyser/GenAnalyzer/python/genAnalyser_RECO_cff.py'
#config.Data.inputDataset = "/DSTau3Mu_14TeV_Pythia8/jschulte-Phase2Spring24DIGIRECOMiniAOD-PU200_140X_mcRun4_realistic_v4_v2-fab0e0c98a2058a3b66af3f42aa300fa/USER"
config.Data.inputDataset = '/DsTau3Mu_pythia8_Phase2_14TeV_PU200/fnenna-140X_mcPhase2_DsTau3Mu_PU200_onlyGEMneg_RECO_v3-d24c5882cf93662fdafa5eb703fd711d/USER'
'''
config.Data.userInputFiles = ['/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_RECO_RECOSIM_PAT_VALIDATION_DQM/250129_211502/0000/step3_DsTau3Mu_RECO_1.root',
                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_RECO_RECOSIM_PAT_VALIDATION_DQM/250129_211502/0000/step3_DsTau3Mu_RECO_2.root',
                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_RECO_RECOSIM_PAT_VALIDATION_DQM/250129_211502/0000/step3_DsTau3Mu_RECO_3.root',
                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_RECO_RECOSIM_PAT_VALIDATION_DQM/250129_211502/0000/step3_DsTau3Mu_RECO_4.root',
                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_RECO_RECOSIM_PAT_VALIDATION_DQM/250129_211502/0000/step3_DsTau3Mu_RECO_5.root',
                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_RECO_RECOSIM_PAT_VALIDATION_DQM/250129_211502/0000/step3_DsTau3Mu_RECO_6.root',
                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_RECO_RECOSIM_PAT_VALIDATION_DQM/250129_211502/0000/step3_DsTau3Mu_RECO_7.root',
                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_RECO_RECOSIM_PAT_VALIDATION_DQM/250129_211502/0000/step3_DsTau3Mu_RECO_8.root',
                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_RECO_RECOSIM_PAT_VALIDATION_DQM/250129_211502/0000/step3_DsTau3Mu_RECO_9.root',
                              '/store/user/fnenna/DsTau3Mu_privateFnenna_Phase2/140X_mcRun4_DsTau3Mu_RECO_RECOSIM_PAT_VALIDATION_DQM/250129_211502/0000/step3_DsTau3Mu_RECO_10.root']
'''
config.Data.inputDBS = 'phys03'
#config.Data.splitting = 'LumiBased'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 10
config.JobType.numCores = 1
config.JobType.maxMemoryMB = 5000
config.Data.publication = False
#config.Data.outputPrimaryDataset = '140X_mcPhase2_DsTau3Mu_RECO_ANAv3_onlyGEMneg_PU200'
#config.Data.publication = True
config.Data.outputDatasetTag = "140X_mcPhase2_DsTau3Mu_RECO_ANAv3_onlyGEMneg_PU200"
config.JobType.allowUndistributedCMSSW = True 
config.Site.storageSite = 'T2_IT_Bari'
config.Site.ignoreGlobalBlacklist  = True

