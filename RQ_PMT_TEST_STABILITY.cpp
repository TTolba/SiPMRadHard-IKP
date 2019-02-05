{
    TCanvas *c1 = new TCanvas("c1","c1",600,500);
    gStyle->SetOptStat(0);
    
    
    double QTot_PMT_Run2[18] = {3430,3435,3462,3452,3462,3430,3467,3459,3455,3473,3483,3480,3459,3451,3459,3464,3458,3463};
    double QTot_PMT_Run2_Sigma[18] = {134.3,133.2,138.7,132,136.6,134.4,138.3,135.9,139.6,137.5,139.4,140,134,134.3,133.5,135.2,134.9,134.4};
    double Time[18]={0,3,7,10,13,18,33,36,39,43,46,53,68,72,75,78,84,88};
    
    double QTotR_Sigma2oPMT[18];
    double QTotR_SigmaoPMT[18];
    double RQTotR_Sigma2oPMT[18];
    double RQTotR_SigmaoPMT[18];
    
    
    for(int pmtT = 0; pmtT<18; pmtT++)
       {
          
         RQTotR_Sigma2oPMT[pmtT] = (QTot_PMT_Run2_Sigma[pmtT]*QTot_PMT_Run2_Sigma[pmtT])/QTot_PMT_Run2[pmtT];
         RQTotR_SigmaoPMT[pmtT] = QTot_PMT_Run2_Sigma[pmtT]/QTot_PMT_Run2[pmtT];
         
         QTotR_Sigma2oPMT[pmtT] = RQTotR_Sigma2oPMT[pmtT]/RQTotR_Sigma2oPMT[0];
         QTotR_SigmaoPMT[pmtT] = RQTotR_SigmaoPMT[pmtT]/RQTotR_SigmaoPMT[0];
       
       }
    
    TGraph *RQTotSig2oQvsTime_PMT = new TGraph(18,Time,QTotR_Sigma2oPMT);
    TGraph *RQTotSigoQvsTime_PMT = new TGraph(18,Time,QTotR_SigmaoPMT);
    
    RQTotSig2oQvsTime_PMT->SetMarkerStyle(20);
    RQTotSig2oQvsTime_PMT->SetMarkerSize(2);
    RQTotSig2oQvsTime_PMT->SetMarkerColor(kBlack);
    RQTotSig2oQvsTime_PMT->GetHistogram()->GetXaxis()->SetTitle("Time [min]");
    RQTotSig2oQvsTime_PMT->GetHistogram()->GetYaxis()->SetTitle("Ratio Q_{total} [a.u.]");
    
    RQTotSigoQvsTime_PMT->SetMarkerStyle(21);
    RQTotSigoQvsTime_PMT->SetMarkerSize(2);
    RQTotSigoQvsTime_PMT->SetMarkerColor(kRed);
    RQTotSigoQvsTime_PMT->GetHistogram()->GetXaxis()->SetTitle("Time [min]");
    RQTotSigoQvsTime_PMT->GetHistogram()->GetYaxis()->SetTitle("Ratio Sig/meanQ [a.u.]");
    
    RQTotSig2oQvsTime_PMT->Draw("AP");
    RQTotSigoQvsTime_PMT->Draw("PSAME");
    
    leg = new TLegend(0.1,0.7,0.18,0.9);
    leg->AddEntry(RQTotSig2oQvsTime_PMT,"Sigma2_o_meanQ","P");
    leg->AddEntry(RQTotSigoQvsTime_PMT,"Sigma_o_meanQ","P");
  
    leg->Draw();

}
