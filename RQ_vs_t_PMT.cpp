{
    /* Data taken without LED: Here the Tot_Charge on the SiPM at #HV is corrected to the tot_charge of the 0kV total_charge*/
    
    TCanvas *c1 = new TCanvas("c1","c1",600,500);
    gStyle->SetOptStat(0);
    TFile *f = new TFile("PMT_stbility.root","RECREATE");
    
    double QWin_SiPM0[8] = {7.347,7.389,7.384,7.378,7.376,7.381,7.373,7.382,};
    double QWin_SiPM0_err[8] = {0.006,0.006,0.006,0.006,0.006,0.006,0.006,0.006};
           
    double t[8] = {0,30,45,60,75,90,105,120};
    double t_err[8] = {0,0,0,0,0,0,0,0};
    double RQ_V0_SiPM0[8];
    double RQ_V0_SiPM0_Err[8];
        
    for(er = 0; er < 8; er++)
    {                                        
         //FBK-RGB
         RQ_V0_SiPM0[er] = QWin_SiPM0[er]/QWin_SiPM0[0];
         RQ_V0_SiPM0_Err[er] = sqrt((QWin_SiPM0_err[er]*QWin_SiPM0_err[er])+((RQ_V0_SiPM0[er]*RQ_V0_SiPM0[er])*(QWin_SiPM0_err[0]*QWin_SiPM0_err[0])))/QWin_SiPM0[0];
    }

    TGraphErrors *RQ_V0vsHV_SiPM0 = new TGraphErrors(8,t,RQ_V0_SiPM0,t_err,RQ_V0_SiPM0_Err);
    
    RQ_V0vsHV_SiPM0->SetMarkerStyle(20);
    RQ_V0vsHV_SiPM0->SetMarkerSize(2.5);
    RQ_V0vsHV_SiPM0->SetMarkerColor(kBlack);
    RQ_V0vsHV_SiPM0->GetHistogram()->GetXaxis()->SetTitle("E Field [kV/cm]");
    RQ_V0vsHV_SiPM0->GetHistogram()->GetYaxis()->SetTitle("Ratio Q_{total} [a.u.]");
    RQ_V0vsHV_SiPM0->GetHistogram()->GetYaxis()->SetRangeUser(0.9,1.1);

         
    RQ_V0vsHV_SiPM0->Draw("AP");//Write();
    
    
    //leg = new TLegend(0.1,0.7,0.18,0.9);
    //leg->AddEntry(RQ_V0vsHV_SiPM0,"FBK-RGB SiPM","P");
    //leg->Draw();
    
    //f->Close();
    /*
      Ratio  = ( (double)cond_real)/cond_mc;
      ratioErr  = sqrt(cond_real_err*cond_real_err+Ratio*Ratio*cond_mc_err*cond_mc_err)/cond_mc;
     */
}
