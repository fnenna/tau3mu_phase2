#include <TFile.h>
#include <TTree.h>
#include <iostream>
#include <TMath.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TEfficiency.h>
#include <TStyle.h>
#include <TColor.h>
#include <TChain.h>
#include <TProfile2D.h>


int main() {
    gStyle->SetOptStat(0);
    // Open the ROOT file
    //TFile *file = TFile::Open("/lustrehome/felicenenna/tau3mu/CMSSW_14_0_17/src/Utilities/Phase2_analysis/Ntuple_Phase2_DsTau3Mu_onlyGEMneg_v2.root", "READ");
    //std::cout <<"/lustrehome/felicenenna/tau3mu/CMSSW_14_0_17/src/Utilities/Phase2_analysis/Ntuple_Phase2_DsTau3Mu_onlyGEMneg_v2.root"<<std::endl;
    //if (!file || !file->IsOpen()) {
    //    std::cerr << "Error: Could not open file!" << std::endl;
    //    return 0;
    //}
    TChain *tree = new TChain("TreeMaker/ntuple");
    //tree->Add("/lustre/cms/store/user/fnenna/DsTau3Mu_Phase2_PUstudies_gemsegm_v3/140X_mcPhase2_DsTau3Mu_miniaod_gemsegm_v3/250531_150652/0000/TreeMC_GEMsegm_*.root");
    tree->Add("/lustre/cms/store/user/fnenna/DsTau3Mu_pythia8_Phase2_14TeV_PU200/140X_mcPhase2_DsTau3Mu_miniaod_genInfo_NoPU_onlyGEMpos_withChi/250611_131702/0000/TreeMC_GEMsegmPU50_*.root");
    //tree->Add("/lustre/cms/store/user/fnenna/DsTau3Mu_Phase2_PUstudies_gemsegm_PU200_GEMNeg/140X_mcPhase2_DsTau3Mu_miniaod_genInfo_PU200_onlyGEMneg_withChi/250611_135629/0000/TreeMC_GEMsegmPU50_*.root");
    //tree->Add("/lustre/cms/store/user/fnenna/DsTau3Mu_pythia8_Phase2_14TeV_PU200/140X_mcPhase2_DsTau3Mu_miniaod_genInfo_NoPU_onlyGEMpos/250607_131344/0000/*.root");
    
    //PU200 with ntuplizer
    /*
    tree->Add("/lustre/cms/store/user/fnenna/DsTau3Mu_Phase2_PUstudies_PU200_ntuples/SkimTau3mu_MC_Phase2_DsTau3Mu_new_Mini_PU200_GEMneg_ntuple/250605_135323/0000/*.root");
    tree->Add("/lustre/cms/store/user/fnenna/DsTau3Mu_Phase2_PUstudies_PU200_ntuples/SkimTau3mu_MC_Phase2_DsTau3Mu_new_Mini_PU200_GEMneg_ntuple/250605_135323/0001/*.root");
    tree->Add("/lustre/cms/store/user/fnenna/DsTau3Mu_Phase2_PUstudies_PU200_ntuples/SkimTau3mu_MC_Phase2_DsTau3Mu_new_Mini_PU200_GEMneg_ntuple/250605_135323/0002/*.root");
    tree->Add("/lustre/cms/store/user/fnenna/DsTau3Mu_Phase2_PUstudies_PU200_ntuples/SkimTau3mu_MC_Phase2_DsTau3Mu_new_Mini_PU200_GEMneg_ntuple/250605_135323/0003/*.root");
    tree->Add("/lustre/cms/store/user/fnenna/DsTau3Mu_Phase2_PUstudies_PU200_ntuples/SkimTau3mu_MC_Phase2_DsTau3Mu_new_Mini_PU200_GEMneg_ntuple/250605_135323/0004/*.root");
    tree->Add("/lustre/cms/store/user/fnenna/DsTau3Mu_Phase2_PUstudies_PU200_ntuples/SkimTau3mu_MC_Phase2_DsTau3Mu_new_Mini_PU200_GEMneg_ntuple/250605_135323/0005/*.root");
    tree->Add("/lustre/cms/store/user/fnenna/DsTau3Mu_Phase2_PUstudies_PU200_ntuples/SkimTau3mu_MC_Phase2_DsTau3Mu_new_Mini_PU200_GEMneg_ntuple/250605_135323/0006/*.root");
    tree->Add("/lustre/cms/store/user/fnenna/DsTau3Mu_Phase2_PUstudies_PU200_ntuples/SkimTau3mu_MC_Phase2_DsTau3Mu_new_Mini_PU200_GEMneg_ntuple/250605_135323/0007/*.root");
    tree->Add("/lustre/cms/store/user/fnenna/DsTau3Mu_Phase2_PUstudies_PU200_ntuples/SkimTau3mu_MC_Phase2_DsTau3Mu_new_Mini_PU200_GEMneg_ntuple/250605_135323/0008/*.root");
    tree->Add("/lustre/cms/store/user/fnenna/DsTau3Mu_Phase2_PUstudies_PU200_ntuples/SkimTau3mu_MC_Phase2_DsTau3Mu_new_Mini_PU200_GEMneg_ntuple/250605_135323/0009/*.root");
    */

    // Retrieve the TTree from the file
    //TTree *tree = dynamic_cast<TTree*>(file->Get("TreeMakerBkg/ntuple"));
    if (!tree) {
        std::cerr << "Error: Could not find tree!" << std::endl;
        //file->Close();
        return 0;
    }


    // Define pointers to std::vector
    std::vector<double>* GenParticle_Pt = nullptr;
    std::vector<double>* GenParticle_Eta = nullptr;
    std::vector<double>* GenParticle_Phi = nullptr;
    std::vector<float>* MuonPt = nullptr;
    std::vector<float>* MuonEta = nullptr;
    std::vector<float>* MuonPhi = nullptr;
    std::vector<double>  *Muon_isTrackerMuon = nullptr;
    std::vector<double>  *Muon_isPF = nullptr;
    std::vector<double> *Muon_isGlobal = nullptr;
    std::vector<double> *Muon_isGEM = nullptr;
    std::vector<UInt_t>* GenParticle_PdgId = nullptr;
    std::vector<UInt_t>* GenParticle_MotherPdgId = nullptr;
    std::vector<std::vector<int>>* GEMSegment_nRechits = nullptr;
    std::vector<std::vector<float>>* GEMSegment_chi2 = nullptr;
    //UInt_t* evt = nullptr;
    tree->SetBranchAddress("GenParticle_Pt", &GenParticle_Pt);
    tree->SetBranchAddress("GenParticle_Eta", &GenParticle_Eta);
    tree->SetBranchAddress("GenParticle_PdgId", &GenParticle_PdgId);
    tree->SetBranchAddress("GenParticle_MotherPdgId", &GenParticle_MotherPdgId);
    tree->SetBranchAddress("GenParticle_Phi", &GenParticle_Phi);
    tree->SetBranchAddress("MuonPt", &MuonPt);
    tree->SetBranchAddress("MuonEta", &MuonEta);
    tree->SetBranchAddress("MuonPhi", &MuonPhi);
    tree->SetBranchAddress("Muon_isTrackerMuon", &Muon_isTrackerMuon);
    tree->SetBranchAddress("Muon_isPF", &Muon_isPF);
    tree->SetBranchAddress("Muon_isGlobal", &Muon_isGlobal);
    tree->SetBranchAddress("Muon_isGEM", &Muon_isGEM);
    tree->SetBranchAddress("GEMSegment_nRechits", &GEMSegment_nRechits);
    tree->SetBranchAddress("GEMSegment_chi2", &GEMSegment_chi2);
    //tree->SetBranchAddress("evt", &evt);

    // Create histograms for gen and reco pT
    TH1F* histGenPt = new TH1F("histGenPt", "Generated Particle pT", 100, 0, 10);
    TH1F* histMatchGenPt = new TH1F("histMatchGenPt", "Matching Reconstructed Particle pT", 100, 0, 10);
    // Create histograms for gen and reco pT
    TH1F* histGenEta = new TH1F("histGenEta", "Generated Particle eta", 200, 1.7, 3.);
    TH1F* histMatchGenEta = new TH1F("histMatchGenEta", "Matching Reconstructed Particle eta", 200, 1.7, 3.);
    TH1F* histMatchGenEta_Trk = new TH1F("histMatchGenEta_Trk", "Matching Track Reconstructed Particle eta", 200, 1.7, 3.);
    TH1F* histMatchGenEta_PF = new TH1F("histMatchGenEta_PF", "Matching PF Reconstructed Particle eta", 200, 1.7, 3.);
    TH1F* histMatchGenEta_Glb = new TH1F("histMatchGenEta_Glb", "Matching Global Reconstructed Particle eta", 200, 1.7, 3.);
    TH1F* histMatchGenEta_GEM = new TH1F("histMatchGenEta_GEM", "Matching GEM Reconstructed Particle eta", 200, 1.7, 3.);
    TH1F* histEta_Trk = new TH1F("histEta_Trk", "Tracker Reconstructed Particle eta", 200, 1.7, 3.);
    TH1F* histEta_GEM = new TH1F("histEta_GEM", "GEM Reconstructed Particle eta", 200, 1.7, 3.);
    TH2F* hist2DEtaPt_Trk = new TH2F("hist2DEtaPt", "2D Reconstructed Particle eta vs pt", 200, 1.7, 3., 100, 0, 10);
    TH1F* hist_NMatching = new TH1F("histNRechits", "Number of Hits of the matching segment", 6, 0.5, 6.5);
    TProfile2D* h2d_avg_nrechits = new TProfile2D("h2d_avg_nrechits", "Avg GEMSegment_nRechits;|#eta|;p_{T}",200, 1.7, 3., 100, 0, 10);  // Adjust binning as needed
    TH1F* hist_segmentChi2 = new TH1F("hist_segmentChi2", "Chi2 of the segments", 300, 0., 100.);
    TH1F* hist_segmentChi2All = new TH1F("hist_segmentChi2All", "Chi2 of the segments", 300, 0., 100.);
    TH2F* hist_segmentChi2VSnHits = new TH2F("hist_2DsegmentChi2", "Chi2 of the segments", 300, 0., 100., 3, 3.5, 6.5);

    int nbinsEta = 100;
    int nbinsPt = 100;
    double Etalow = 1.7, Etahigh = 3;
    double ptlow = 0, pthigh = 10;

    TH2F* h_denominator = new TH2F("h_denominator", "Denominator;|#eta|;p_{T}", nbinsEta, Etalow, Etahigh, nbinsPt, ptlow, pthigh);
    TH2F* h_numerator = new TH2F("h_numerator", "Numerator;|#eta|;p_{T}", nbinsEta, Etalow, Etahigh, nbinsPt, ptlow, pthigh);


    float total_gen_particles=0;
    float matching_gen_particles=0;
    // Loop over each event
    Long64_t nEntries = tree->GetEntries();
    bool matching = false;
    for (Long64_t i = 0; i < nEntries; ++i) {
        tree->GetEntry(i);
        matching = false;
        if (GenParticle_Eta->size()>0){
            //loop sulle gen particle
            for(Int_t i_gen=0; i_gen<GenParticle_Eta->size(); i_gen++){
                bool fill = true;
                //per ogni gen particle vogliamo calcolare il dR minimo, cioè la distanza geometrica dalla reco particle più vicina
                double dR_min = 10000.;
                double dptmin = 10000.;
                int index_gen_match;
                int index_reco_match;
                if (fabs(GenParticle_PdgId->at(i_gen))!=13 || fabs(GenParticle_MotherPdgId->at(i_gen))!=15) continue;
                total_gen_particles++;
                histGenPt->Fill(GenParticle_Pt->at(i_gen));
                histGenEta->Fill(fabs(GenParticle_Eta->at(i_gen)));
                h_denominator->Fill(fabs(GenParticle_Eta->at(i_gen)), GenParticle_Pt->at(i_gen));
                //loop sulle reco particle
                for(Int_t i_reco=0; i_reco<MuonEta->size(); i_reco++){
                    for(uint i_seg0=0; i_seg0<GEMSegment_nRechits->at(i_reco).size(); i_seg0++){
                    if (i_gen==0){
                        hist_segmentChi2All->Fill(GEMSegment_chi2->at(i_reco).at(i_seg0));
                    }
                }
                    std::cout << MuonEta->size() << std::endl;
                    //calcoliamo dR tra reco e gen
                    double dR = TMath::Sqrt((GenParticle_Eta->at(i_gen)-MuonEta->at(i_reco))*(GenParticle_Eta->at(i_gen)-MuonEta->at(i_reco)) + (GenParticle_Phi->at(i_gen)-MuonPhi->at(i_reco))*(GenParticle_Phi->at(i_gen)-MuonPhi->at(i_reco)));
                    double dpt = (GenParticle_Pt->at(i_gen)-MuonPt->at(i_reco))/GenParticle_Pt->at(i_gen);
                    if (Muon_isTrackerMuon->at(i_reco)==1&&fill){
                        histEta_Trk->Fill(MuonEta->at(i_reco));
                        hist2DEtaPt_Trk->Fill(MuonEta->at(i_reco), MuonPt->at(i_reco));
                    }
                    if (Muon_isGEM->at(i_reco)==1&&fill){
                        histEta_GEM->Fill(MuonEta->at(i_reco));
                    }
                    if (dR<dR_min){//&&dpt<dptmin){
                    //if (dR<0.3){  // && fabs(dpt)<0.1){
                        dR_min = dR;
                        dptmin = dpt;
                        matching = true;
                        index_gen_match = i_gen;
                        index_reco_match = i_reco;
                    }
            }
            fill = false;
            if (matching&&dR_min<0.1){//&&dptmin<0.5){ 
                histMatchGenPt->Fill(GenParticle_Pt->at(index_gen_match));
                histMatchGenEta->Fill(fabs(GenParticle_Eta->at(index_gen_match)));
                h_numerator->Fill(fabs(GenParticle_Eta->at(index_gen_match)), GenParticle_Pt->at(index_gen_match));
                matching_gen_particles++;
                Int_t i_seg = 0;
                Int_t n_seg = GEMSegment_nRechits->at(index_reco_match).size();
                float avg_n_rechits = 0;
                for(i_seg=0; i_seg<GEMSegment_nRechits->at(index_reco_match).size(); i_seg++){
                    hist_NMatching->Fill(GEMSegment_nRechits->at(index_reco_match).at(i_seg));
                    avg_n_rechits = avg_n_rechits + GEMSegment_nRechits->at(index_reco_match).at(i_seg)/n_seg;
                    hist_segmentChi2->Fill(GEMSegment_chi2->at(index_reco_match).at(i_seg));
                    hist_segmentChi2VSnHits->Fill(GEMSegment_chi2->at(index_reco_match).at(i_seg), GEMSegment_nRechits->at(index_reco_match).at(i_seg));
                }
                h2d_avg_nrechits->Fill(fabs(GenParticle_Eta->at(index_gen_match)), GenParticle_Pt->at(index_gen_match), avg_n_rechits);
                //if the gen muon matches with a trackerMuon
                if (Muon_isTrackerMuon->at(index_reco_match)==1){
                    histMatchGenEta_Trk->Fill(fabs(GenParticle_Eta->at(index_gen_match)));
                }
                if (Muon_isPF->at(index_reco_match)==1){
                    histMatchGenEta_PF->Fill(fabs(GenParticle_Eta->at(index_gen_match)));
                }
                if (Muon_isGlobal->at(index_reco_match)==1){
                    histMatchGenEta_Glb->Fill(fabs(GenParticle_Eta->at(index_gen_match)));
                }
                if (Muon_isGEM->at(index_reco_match)==1){
                    histMatchGenEta_GEM->Fill(fabs(GenParticle_Eta->at(index_gen_match)));
                }
            }
        }
        }
    }

    TCanvas* canvas_chi2 = new TCanvas("canvas_chi2", "chi2 Distributions", 800, 600);
    // Draw the generated pT histogram
    hist_segmentChi2->SetLineColor(kRed); // Set line color to red
    hist_segmentChi2All->SetLineColor(kBlue);
    hist_segmentChi2->SetLineWidth(2);     // Set line width
    hist_segmentChi2All->SetLineWidth(2);     // Set line width
    hist_segmentChi2All->Draw("HIST");
    hist_segmentChi2->Draw("SAME");
    canvas_chi2->SaveAs("chi2_distribution_noPU.png");

    TCanvas* canvas_chi2_2D = new TCanvas("canvas_chi2_2D", "chi2 Distributions", 800, 600);
    // Draw the generated pT histogram
    hist_segmentChi2VSnHits->Draw("COLZ");
    canvas_chi2_2D->SaveAs("2Dchi2_distribution_noPU.png");

    TCanvas* canvas = new TCanvas("canvas", "pT Distributions", 800, 600);
    // Draw the generated pT histogram
    histGenPt->SetLineColor(kRed); // Set line color to red
    histGenPt->SetLineWidth(2);     // Set line width
    histGenPt->Draw("HIST");

    // Draw the reconstructed pT histogram on the same canvas
    histMatchGenPt->SetLineColor(kBlue); // Set line color to blue
    histMatchGenPt->SetLineWidth(2);     // Set line width
    histMatchGenPt->Draw("HIST SAME");
    // Create a legend
    TLegend* legend = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend->AddEntry(histGenPt, "Gen pT", "l");
    legend->AddEntry(histMatchGenPt, "Reco-Matching Gen pT", "l");
    legend->Draw();
    // Update the canvas to reflect the changes
    canvas->Update();
    canvas->SaveAs("pt_distributions_v2__fineEta.png");
    std::cout<<"Total # of generated muons (from tau): "<<total_gen_particles<<std::endl;
    std::cout<<"# of matching muons (from tau): "<<matching_gen_particles<<std::endl;
    float efficiency=matching_gen_particles/total_gen_particles;
    std::cout<<"Reconstruction efficiency: "<<efficiency<<std::endl;
    TCanvas* canvas_rechits = new TCanvas("canvas_rechits", "n_rechits", 800, 600);
    hist_NMatching->SetLineColor(kRed); // Set line color to red
    hist_NMatching->SetLineWidth(2);     // Set line width
    hist_NMatching->Draw();
    canvas_rechits->SaveAs("n_rechits_fineEta.png");

    TCanvas* canvas_rechits2D = new TCanvas("canvas_rechits2D", "canvas_rechits2D", 800, 600);
    gStyle->SetOptStat(0);
    h2d_avg_nrechits->GetZaxis()->SetRangeUser(5, 6);
    h2d_avg_nrechits->Draw("COLZ");  // "COLZ" shows colored boxes with Z-axis as color
    
    canvas_rechits2D->SaveAs("2D_n_rechits_fineEta.png");

    TCanvas* canvas2 = new TCanvas("canvas2", "efficiency", 800, 600);
    // Create a TEfficiency object
    TEfficiency* eff = new TEfficiency(*histMatchGenPt, *histGenPt);

    // Set efficiency histogram properties
    eff->SetTitle("Reconstruction Efficiency;pT (GeV);Efficiency");
    eff->SetLineColor(kBlue);

    // Draw the efficiency plot
    eff->Draw("AP");
    // Enable grid lines on the current pad
    gPad->SetGrid();
    canvas2->Update();
    canvas2->SaveAs("reco_efficiency_v2__fineEta.png");
    TCanvas* canvas3 = new TCanvas("canvas", "eta Distributions", 800, 600);
    canvas3->cd();
    // Draw the generated pT histogram
    histGenEta->SetLineColor(kRed); // Set line color to red
    histGenEta->SetLineWidth(2);     // Set line width
    //histGenEta->Draw("HIST");

    // Draw the reconstructed pT histogram on the same canvas
    histMatchGenEta->SetLineColor(kBlue); // Set line color to blue
    histMatchGenEta->SetLineWidth(2);     // Set line width
    //histMatchGenEta->Draw("HIST SAME");
    // Draw the reconstructed pT histogram on the same canvas
    histEta_Trk->SetLineColor(kBlue); // Set line color to blue
    histEta_Trk->SetLineWidth(2);     // Set line width
    histEta_Trk->SetFillColor(kBlue);
    histEta_Trk->SetFillColorAlpha(kBlue, 0.4);
    histEta_Trk->SetFillStyle(1001);
    histEta_Trk->Draw();
    // Draw the reconstructed pT histogram on the same canvas
    histEta_GEM->SetLineColor(kRed); // Set line color to blue
    histEta_GEM->SetLineWidth(2);     // Set line width
    histEta_GEM->SetFillColor(kRed);
    histEta_GEM->SetFillColorAlpha(kRed, 0.4);
    histEta_GEM->SetFillStyle(1001);
    histEta_GEM->Draw("SAME");
    // Create a legend
    TLegend* legend1 = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend1->AddEntry(histEta_Trk, "Trk muons", "f");
    legend1->AddEntry(histEta_GEM, "GEM muons", "f");
    legend1->Draw();
    // Update the canvas to reflect the changes
    canvas3->Update();
    canvas3->SaveAs("eta_distributions_v2__fineEta.png");
    TCanvas* canvas4 = new TCanvas("canvas4", "efficiency", 800, 600);
    // Create a TEfficiency object
    TEfficiency* eff1 = new TEfficiency(*histMatchGenEta, *histGenEta);

    // Set efficiency histogram properties
    eff1->SetTitle("Reconstruction Efficiency;eta ;Efficiency");
    eff1->SetLineColor(kBlue);
    eff1->SetMarkerStyle(21);
    eff1->SetMarkerColor(kBlue);

    // Draw the efficiency plot
    eff1->Draw("AP");
    TEfficiency* eff_trk = new TEfficiency(*histMatchGenEta_Trk, *histGenEta);
    eff_trk->SetLineColor(kRed);
    eff_trk->SetMarkerStyle(22);
    eff_trk->SetMarkerColor(kRed);
    eff_trk->Draw("SAME");
    TEfficiency* eff_pf = new TEfficiency(*histMatchGenEta_PF, *histGenEta);
    eff_pf->SetLineColor(kGreen);
    eff_pf->SetMarkerStyle(20);
    eff_pf->SetMarkerColor(kGreen);
    eff_pf->Draw("SAME");
    TEfficiency* eff_glb = new TEfficiency(*histMatchGenEta_Glb, *histGenEta);
    eff_glb->SetLineColor(kMagenta+1);
    eff_glb->SetMarkerStyle(20);
    eff_glb->SetMarkerColor(kMagenta+1);
    eff_glb->Draw("SAME");
    TEfficiency* eff_gem = new TEfficiency(*histMatchGenEta_GEM, *histGenEta);
    eff_gem->SetLineColor(kCyan);
    eff_gem->SetMarkerStyle(20);
    eff_gem->SetMarkerColor(kCyan);
    eff_gem->Draw("SAME");
    // Enable grid lines on the current pad
    gPad->SetGrid();
    TLegend* legend2 = new TLegend(0.12, 0.20, 0.27, 0.35);
    legend2->AddEntry(eff1, "Reconstructed", "lep");
    legend2->AddEntry(eff_trk, "Tracker Muons", "lep");
    legend2->AddEntry(eff_pf, "PF Muons", "lep");
    legend2->AddEntry(eff_glb, "Global Muons", "lep");
    legend2->AddEntry(eff_gem, "GEM Muons", "lep");
    legend2->Draw();
    canvas4->Update();
    canvas4->SaveAs("reco_efficiency_eta_v2__fineEta.png");
    // Close the file
    TCanvas* canvas5 = new TCanvas("canvas5", "2d histo", 800, 600);
    canvas5->cd();
    hist2DEtaPt_Trk->Draw("COLZ");
    canvas5 ->SaveAs("2d_histo_etaVsPt__fineEta.png");
    //file->Close();
    // Create efficiency histogram
    TH2F* h_efficiency = (TH2F*)h_numerator->Clone("h_efficiency");
    h_efficiency->SetTitle("Efficiency Map;|#eta|;p_{T}");
    h_efficiency->Divide(h_numerator, h_denominator, 1.0, 1.0, "B"); // "B" for binomial errors

    // Draw efficiency map
    TCanvas* c = new TCanvas("c", "Efficiency Map", 800, 600);
    h_efficiency->Draw("COLZ");
    c->SaveAs("efficiency_map__fineEta.png");
    return 1;
}
