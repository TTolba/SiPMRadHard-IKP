{
    /* Data taken without LED: Here the Tot_Charge on the SiPM at #HV is corrected to the tot_charge of the 0kV total_charge*/
    /*
    TCanvas *c1 = new TCanvas("c1","c1",600,500);
    gStyle->SetOptStat(0);
    TFile *f = new TFile("Data_woLED.root","RECREATE");
    */
    ofstream myfile;
    myfile.open("Results.txt");
    
    double QWin_SiPM0[6] = {815.26,804.4,823.4,810.3,816.4,811.4};
    double QWin_SiPM0_err[6] = {6.1,6.03,6.1,6.07,6.1,6.08};
    double PrCT_SiPM0[6] = {0.992,0.991,0.9918,0.9844,0.9846,0.9848};
    double PrCT_SiPM0_err[6] = {0.0145,0.0146,0.0149,0.0167,0.02,0.014};
    double DCR_SiPM0[6] = {0.0105,0.0105,0.01,0.011,0.009,0.011};
    double DCR_SiPM0_err[6] = {0.0012,0.00114,0.00111,0.00123,0.00107,0.0017};
    
    double QWin_SiPM1[6] = {317,318,319.4,318,319,318};
    double QWin_SiPM1_err[6] = {2.37,2.37,2.38,2.37,2.38,2.37};
    double PrCT_SiPM1[6] = {0.953,0.977,0.973,0.947,0.935,0.94};
    double PrCT_SiPM1_err[6] = {0.014,0.014,0.014,0.014,0.0146,0.0147};
    double DCR_SiPM1[6] = {0.019,0.0192,0.022,0.02,0.021,0.0186};
    double DCR_SiPM1_err[6] = {0.0014,0.0014,0.0017,0.0018,0.0016,0.0015};
   // double DCR_SiPM1[6] = {0.03,0.03,0.031,0.031,0.03,0.022};
    //double DCR_SiPM1_err[6] = {0.0022,0.004,0.007,0.005,0.0044,0.004};
   
     
    double QWin_SiPM3[6] = {960,953,949,948,957,962};
    double QWin_SiPM3_err[6] = {7.2,7.14,7.1,7.1,7.16,7.2};
    double PrCT_SiPM3[6] = {0.160,0.155,0.158,0.161,0.163,0.166};
    double PrCT_SiPM3_err[6] = {0.0032,0.0031,0.0044,0.0045,0.0046,0.0039};
    double DCR_SiPM3[6] = {0.00199,0.00198,0.00198,0.0020,0.0025,0.00205};
    double DCR_SiPM3_err[6] = {0.000115,0.000115,0.000162,0.000167,0.0002,0.000124};
        
    double HV[6] = {0.0,6.0,12.0,18.,24.0,30.0};
    double HV_Err[6];
    
    double RQ_V0_SiPM0[6];
    double RQ_V0_SiPM0_Err[6];
    double PrCT_V0_SiPM0[6];
    double PrCT_V0_SiPM0_Err[6];
    double DCR_V0_SiPM0[6];
    double DCR_V0_SiPM0_Err[6];
    double DCR_V0_SiPM0_max[6];
    double DCR_V0_SiPM0_min[6];
    
    double RQ_V0_SiPM1[6];
    double RQ_V0_SiPM1_Err[6];
    double PrCT_V0_SiPM1[6];
    double PrCT_V0_SiPM1_Err[6];
    double DCR_V0_SiPM1[6];
    double DCR_V0_SiPM1_Err[6];
    
    double RQ_V0_SiPM3[6];
    double RQ_V0_SiPM3_Err[6];
    double PrCT_V0_SiPM3[6];
    double PrCT_V0_SiPM3_Err[6];
    double DCR_V0_SiPM3[6];
    double DCR_V0_SiPM3_Err[6];

    double RQ_V0_SiPM[6];
    double RQ_V0_SiPM_Err[6];
    double PrCT_V0_SiPM[6];
    double PrCT_V0_SiPM_Err[6];
    double DCR_V0_SiPM[6];
    double DCR_V0_SiPM_Err[6];    
    
    for(er = 0; er<6; er++)
    {
         //5% error on the HV value
         HV_Err[er] = HV[er]*0.05;    
                                              
         //FBK-RGB
         RQ_V0_SiPM0[er] = QWin_SiPM0[er]/QWin_SiPM0[0];
         RQ_V0_SiPM0_Err[er] = sqrt((QWin_SiPM0_err[er]*QWin_SiPM0_err[er])+((RQ_V0_SiPM0[er]*RQ_V0_SiPM0[er])*(QWin_SiPM0_err[0]*QWin_SiPM0_err[0])))/QWin_SiPM0[0];
         //RQ_V0_SiPM0_Err[er] = sqrt(((QWin_SiPM0_err[er]/QWin_SiPM0[er])*(QWin_SiPM0_err[er]/QWin_SiPM0[er]))+((QWin_SiPM0_err[0]/QWin_SiPM0[0])*(QWin_SiPM0_err[0]/QWin_SiPM0[0])))*RQ_V0_SiPM0[er];
         PrCT_V0_SiPM0[er] = PrCT_SiPM0[er]/PrCT_SiPM0[0];
         PrCT_V0_SiPM0_Err[er] = sqrt((PrCT_SiPM0_err[er]*PrCT_SiPM0_err[er])+((PrCT_V0_SiPM0[er]*PrCT_V0_SiPM0[er])*(PrCT_SiPM0_err[0]*PrCT_SiPM0_err[0])))/PrCT_SiPM0[0];
         //PrCT_V0_SiPM0_Err[er] = sqrt(((PrCT_SiPM0_err[er]/PrCT_SiPM0[er])*(PrCT_SiPM0_err[er]/PrCT_SiPM0[er]))+((PrCT_SiPM0_err[0]/PrCT_SiPM0[0])*(PrCT_SiPM0_err[0]/PrCT_SiPM0[0])))*PrCT_V0_SiPM0[er];
         DCR_V0_SiPM0[er] = DCR_SiPM0[er]/DCR_SiPM0[0];
         DCR_V0_SiPM0_Err[er] = sqrt((DCR_SiPM0_err[er]*DCR_SiPM0_err[er])+((DCR_V0_SiPM0[er]*DCR_V0_SiPM0[er])*(DCR_SiPM0_err[0]*DCR_SiPM0_err[0])))/DCR_SiPM0[0];
         //DCR_V0_SiPM0_Err[er] = sqrt(((DCR_SiPM0_err[er]/DCR_SiPM0[er])*(DCR_SiPM0_err[er]/DCR_SiPM0[er]))+((DCR_SiPM0_err[0]/DCR_SiPM0[0])*(DCR_SiPM0_err[0]/DCR_SiPM0[0])))*DCR_V0_SiPM0[er];
         DCR_V0_SiPM0_max[er] = DCR_V0_SiPM0[er]+DCR_V0_SiPM0_Err[er];
         DCR_V0_SiPM0_min[er] = DCR_V0_SiPM0[er]-DCR_V0_SiPM0_Err[er];
             
         //FBK-Low Field
         RQ_V0_SiPM1[er] = QWin_SiPM1[er]/QWin_SiPM1[0];
         RQ_V0_SiPM1_Err[er] = sqrt((QWin_SiPM1_err[er]*QWin_SiPM1_err[er])+((RQ_V0_SiPM1[er]*RQ_V0_SiPM1[er])*(QWin_SiPM1_err[0]*QWin_SiPM1_err[0])))/QWin_SiPM1[0];
         //RQ_V0_SiPM1_Err[er] = sqrt(((QWin_SiPM1_err[er]/QWin_SiPM1[er])*(QWin_SiPM1_err[er]/QWin_SiPM1[er]))+((QWin_SiPM1_err[0]/QWin_SiPM1[0])*(QWin_SiPM1_err[0]/QWin_SiPM1[0])))*RQ_V0_SiPM1[er];
         PrCT_V0_SiPM1[er] = PrCT_SiPM1[er]/PrCT_SiPM1[0];
         PrCT_V0_SiPM1_Err[er] = sqrt((PrCT_SiPM1_err[er]*PrCT_SiPM1_err[er])+((PrCT_V0_SiPM1[er]*PrCT_V0_SiPM1[er])*(PrCT_SiPM1_err[0]*PrCT_SiPM1_err[0])))/PrCT_SiPM1[0];
         //PrCT_V0_SiPM1_Err[er] = sqrt(((PrCT_SiPM1_err[er]/PrCT_SiPM1[er])*(PrCT_SiPM1_err[er]/PrCT_SiPM1[er]))+((PrCT_SiPM1_err[0]/PrCT_SiPM1[0])*(PrCT_SiPM1_err[0]/PrCT_SiPM1[0])))*PrCT_V0_SiPM1[er];
         DCR_V0_SiPM1[er] = DCR_SiPM1[er]/DCR_SiPM1[0];
         DCR_V0_SiPM1_Err[er] = sqrt((DCR_SiPM1_err[er]*DCR_SiPM1_err[er])+((DCR_V0_SiPM1[er]*DCR_V0_SiPM1[er])*(DCR_SiPM1_err[0]*DCR_SiPM1_err[0])))/DCR_SiPM1[0];
         //DCR_V0_SiPM1_Err[er] = sqrt(((DCR_SiPM1_err[er]/DCR_SiPM1[er])*(DCR_SiPM1_err[er]/DCR_SiPM1[er]))+((DCR_SiPM1_err[0]/DCR_SiPM1[0])*(DCR_SiPM1_err[0]/DCR_SiPM1[0])))*DCR_V0_SiPM1[er];
             
         //Hamamatsu
         RQ_V0_SiPM3[er] = QWin_SiPM3[er]/QWin_SiPM3[0];
         RQ_V0_SiPM3_Err[er] = sqrt((QWin_SiPM3_err[er]*QWin_SiPM3_err[er])+((RQ_V0_SiPM3[er]*RQ_V0_SiPM3[er])*(QWin_SiPM3_err[0]*QWin_SiPM3_err[0])))/QWin_SiPM3[0];
         //RQ_V0_SiPM3_Err[er] = sqrt(((QWin_SiPM3_err[er]/QWin_SiPM3[er])*(QWin_SiPM3_err[er]/QWin_SiPM3[er]))+((QWin_SiPM3_err[0]/QWin_SiPM3[0])*(QWin_SiPM3_err[0]/QWin_SiPM3[0])))*RQ_V0_SiPM3[er];
         PrCT_V0_SiPM3[er] = PrCT_SiPM3[er]/PrCT_SiPM3[0];
         PrCT_V0_SiPM3_Err[er] = sqrt((PrCT_SiPM3_err[er]*PrCT_SiPM3_err[er])+((PrCT_V0_SiPM3[er]*PrCT_V0_SiPM3[er])*(PrCT_SiPM3_err[0]*PrCT_SiPM3_err[0])))/PrCT_SiPM3[0];
         //PrCT_V0_SiPM3_Err[er] = sqrt(((PrCT_SiPM3_err[er]/PrCT_SiPM3[er])*(PrCT_SiPM3_err[er]/PrCT_SiPM3[er]))+((PrCT_SiPM3_err[0]/PrCT_SiPM3[0])*(PrCT_SiPM3_err[0]/PrCT_SiPM3[0])))*PrCT_V0_SiPM3[er];
         DCR_V0_SiPM3[er] = DCR_SiPM3[er]/DCR_SiPM3[0];
         DCR_V0_SiPM3_Err[er] = sqrt((DCR_SiPM3_err[er]*DCR_SiPM3_err[er])+((DCR_V0_SiPM3[er]*DCR_V0_SiPM3[er])*(DCR_SiPM3_err[0]*DCR_SiPM3_err[0])))/DCR_SiPM3[0];
         //DCR_V0_SiPM3_Err[er] = sqrt(((DCR_SiPM3_err[er]/DCR_SiPM3[er])*(DCR_SiPM3_err[er]/DCR_SiPM3[er]))+((DCR_SiPM3_err[0]/DCR_SiPM3[0])*(DCR_SiPM3_err[0]/DCR_SiPM3[0])))*DCR_V0_SiPM3[er];
    }

    
    for(Q=0; Q<6; Q++)
    {
       RQ_V0_SiPM[Q] = (RQ_V0_SiPM0[Q]+RQ_V0_SiPM1[Q]+RQ_V0_SiPM3[Q])/3;
       PrCT_V0_SiPM[Q] = (PrCT_V0_SiPM0[Q]+PrCT_V0_SiPM1[Q]+PrCT_V0_SiPM3[Q])/3;
       DCR_V0_SiPM[Q] = (DCR_V0_SiPM0[Q]+DCR_V0_SiPM1[Q]+DCR_V0_SiPM3[Q])/3;
       RQ_V0_SiPM_Err[Q] = (RQ_V0_SiPM0_Err[Q]+RQ_V0_SiPM1_Err[Q]+RQ_V0_SiPM3_Err[Q])/3;
       PrCT_V0_SiPM_Err[Q] = (PrCT_V0_SiPM0_Err[Q]+PrCT_V0_SiPM1_Err[Q]+PrCT_V0_SiPM3_Err[Q])/3;
       DCR_V0_SiPM_Err[Q] = (DCR_V0_SiPM0_Err[Q]+DCR_V0_SiPM1_Err[Q]+DCR_V0_SiPM3_Err[Q])/3;       
       //myfile << "Total charge ratio FBK-RGB[" << Q << "] = " << RQ_V0_SiPM[Q] << "+-" << RQ_V0_SiPM0_Err[Q] << "(" << HV[Q] << ")" <<"\n";
       //myfile << "Total charge ratio FBK-LFD[" << Q << "] = " << RQ_V0_SiPM1[Q] << "+-" << RQ_V0_SiPM1_Err[Q] << "(" << HV[Q] << ")" <<"\n";
       //myfile << "Total charge ratio Hamamat[" << Q << "] = " << RQ_V0_SiPM3[Q] << "+-" << RQ_V0_SiPM3_Err[Q] << "(" << HV[Q] << ")" <<"\n";
       //myfile << "PrCT  ratio        FBK-RGB[" << Q << "] = " << PrCT_V0_SiPM[Q] << "+-" << PrCT_V0_SiPM0_Err[Q] << "(" << HV[Q] << ")" <<"\n";
       //myfile << "PrCT  ratio        FBK-LFD[" << Q << "] = " << PrCT_V0_SiPM1[Q] << "+-" << PrCT_V0_SiPM1_Err[Q] << "(" << HV[Q] << ")" <<"\n";
       //myfile << "PrCT  ratio        Hamamat[" << Q << "] = " << PrCT_V0_SiPM3[Q] << "+-" << PrCT_V0_SiPM3_Err[Q] << "(" << HV[Q] << ")" <<"\n";
       //myfile << "DCR  ratio         FBK-RGB[" << Q << "] = " << DCR_V0_SiPM[Q] << "+-" << DCR_V0_SiPM0_Err[Q] << "(" << HV[Q] << ")" <<"\n";
       //myfile << "DCR  ratio         FBK-LFD[" << Q << "] = " << DCR_V0_SiPM1[Q] << "+-" << DCR_V0_SiPM1_Err[Q] << "(" << HV[Q] << ")" <<"\n";
       //myfile << "DCR  ratio         Hamamat[" << Q << "] = " << DCR_V0_SiPM3[Q] << "+-" << DCR_V0_SiPM3_Err[Q] << "(" << HV[Q] << ")" <<"\n";
    }  
    
    for(Q=0; Q<6; Q++)
    {
       
       myfile << "Total charge ratio FBK-RGB[" << Q << "] = " << RQ_V0_SiPM[Q] << "+-" << RQ_V0_SiPM0_Err[Q] << "(" << HV[Q] << ")" <<"\n";
       //myfile << "Total charge ratio FBK-LFD[" << Q << "] = " << RQ_V0_SiPM1[Q] << "+-" << RQ_V0_SiPM1_Err[Q] << "(" << HV[Q] << ")" <<"\n";
       //myfile << "Total charge ratio Hamamat[" << Q << "] = " << RQ_V0_SiPM3[Q] << "+-" << RQ_V0_SiPM3_Err[Q] << "(" << HV[Q] << ")" <<"\n";
       myfile << "PrCT  ratio        FBK-RGB[" << Q << "] = " << PrCT_V0_SiPM[Q] << "+-" << PrCT_V0_SiPM0_Err[Q] << "(" << HV[Q] << ")" <<"\n";
       //myfile << "PrCT  ratio        FBK-LFD[" << Q << "] = " << PrCT_V0_SiPM1[Q] << "+-" << PrCT_V0_SiPM1_Err[Q] << "(" << HV[Q] << ")" <<"\n";
       //myfile << "PrCT  ratio        Hamamat[" << Q << "] = " << PrCT_V0_SiPM3[Q] << "+-" << PrCT_V0_SiPM3_Err[Q] << "(" << HV[Q] << ")" <<"\n";
       myfile << "DCR  ratio         FBK-RGB[" << Q << "] = " << DCR_V0_SiPM[Q] << "+-" << DCR_V0_SiPM0_Err[Q] << "(" << HV[Q] << ")" <<"\n";
       //myfile << "DCR  ratio         FBK-LFD[" << Q << "] = " << DCR_V0_SiPM1[Q] << "+-" << DCR_V0_SiPM1_Err[Q] << "(" << HV[Q] << ")" <<"\n";
       //myfile << "DCR  ratio         Hamamat[" << Q << "] = " << DCR_V0_SiPM3[Q] << "+-" << DCR_V0_SiPM3_Err[Q] << "(" << HV[Q] << ")" <<"\n";
    }    
    
    myfile.close();
/*
    TGraphErrors *RQ_V0vsHV_SiPM0 = new TGraphErrors(6,HV,RQ_V0_SiPM0,HV_Err,RQ_V0_SiPM0_Err);
    TGraphErrors *PrCT_V0vsHV_SiPM0 = new TGraphErrors(6,HV,PrCT_V0_SiPM0,HV_Err,PrCT_V0_SiPM0_Err);
    TGraphErrors *DCR_V0vsHV_SiPM0 = new TGraphErrors(6,HV,DCR_V0_SiPM0,HV_Err,DCR_V0_SiPM0_Err);
        
    TGraphErrors *RQ_V0vsHV_SiPM1 = new TGraphErrors(6,HV,RQ_V0_SiPM1,HV_Err,RQ_V0_SiPM1_Err);
    TGraphErrors *PrCT_V0vsHV_SiPM1 = new TGraphErrors(6,HV,PrCT_V0_SiPM1,HV_Err,PrCT_V0_SiPM1_Err);
    TGraphErrors *DCR_V0vsHV_SiPM1 = new TGraphErrors(6,HV,DCR_V0_SiPM1,HV_Err,DCR_V0_SiPM1_Err);
    
    TGraphErrors *RQ_V0vsHV_SiPM3 = new TGraphErrors(6,HV,RQ_V0_SiPM3,HV_Err,RQ_V0_SiPM3_Err);
    TGraphErrors *PrCT_V0vsHV_SiPM3 = new TGraphErrors(6,HV,PrCT_V0_SiPM3,HV_Err,PrCT_V0_SiPM3_Err);
    TGraphErrors *DCR_V0vsHV_SiPM3 = new TGraphErrors(6,HV,DCR_V0_SiPM3,HV_Err,DCR_V0_SiPM3_Err);
  */
    /*
    TGraph *grmin = new TGraph(6,HV,DCR_V0_SiPM0_min);
    TGraph *grmax = new TGraph(6,HV,DCR_V0_SiPM0_max);
    TGraph *gr    = new TGraph(6,HV,DCR_V0_SiPM0);
    TGraph *grshade = new TGraph(2*6);
    for (i=0;i<6;i++) {
       grshade->SetPoint(i,HV[i],DCR_V0_SiPM0_max[i]);
       grshade->SetPoint(6+i,HV[6-i-1],DCR_V0_SiPM0_min[6-i-1]);
       }
   grshade->SetFillStyle(3013);
   grshade->SetFillColor(16);
   grshade->Draw("f");
   grmin->Draw("l");
   grmax->Draw("l");
   gr->SetLineWidth(4);
   gr->SetMarkerColor(4);
   gr->SetMarkerStyle(21);
   gr->Draw("CP");
    */
    /*
    RQ_V0vsHV_SiPM0->SetMarkerStyle(20);
    RQ_V0vsHV_SiPM0->SetMarkerSize(2.5);
    RQ_V0vsHV_SiPM0->SetMarkerColor(kBlack);
    RQ_V0vsHV_SiPM0->GetHistogram()->GetXaxis()->SetTitle("Electric field [kV/cm]");
    RQ_V0vsHV_SiPM0->GetHistogram()->GetYaxis()->SetTitle("Ratio Q_{m p.e.}");
    RQ_V0vsHV_SiPM0->GetHistogram()->GetYaxis()->SetRangeUser(0.8,1.2);
    PrCT_V0vsHV_SiPM0->SetMarkerStyle(20);
    PrCT_V0vsHV_SiPM0->SetMarkerSize(2.5);
    PrCT_V0vsHV_SiPM0->SetMarkerColor(kBlack);
    PrCT_V0vsHV_SiPM0->GetHistogram()->GetXaxis()->SetTitle("Electric field [kV/cm]");
    PrCT_V0vsHV_SiPM0->GetHistogram()->GetYaxis()->SetTitle("Ratio P_{CT}");
    PrCT_V0vsHV_SiPM0->GetHistogram()->GetYaxis()->SetRangeUser(0.8,1.2);
    DCR_V0vsHV_SiPM0->SetMarkerStyle(20);
    DCR_V0vsHV_SiPM0->SetMarkerSize(2.5);
    DCR_V0vsHV_SiPM0->SetMarkerColor(kBlack);
    DCR_V0vsHV_SiPM0->GetHistogram()->GetXaxis()->SetTitle("Electric field [kV/cm]");
    DCR_V0vsHV_SiPM0->GetHistogram()->GetYaxis()->SetTitle("Ratio P_{CN}");
    DCR_V0vsHV_SiPM0->GetHistogram()->GetYaxis()->SetRangeUser(0.0,2.0);
    
        
    RQ_V0vsHV_SiPM1->SetMarkerStyle(21);
    RQ_V0vsHV_SiPM1->SetMarkerSize(2.5);
    RQ_V0vsHV_SiPM1->SetMarkerColor(kBlue);
    RQ_V0vsHV_SiPM1->GetHistogram()->GetXaxis()->SetTitle("Electric field [kV/cm]");
    RQ_V0vsHV_SiPM1->GetHistogram()->GetYaxis()->SetTitle("Ratio Q_{m p.e.}");
    RQ_V0vsHV_SiPM1->GetHistogram()->GetYaxis()->SetRangeUser(0.8,1.2);
    PrCT_V0vsHV_SiPM1->SetMarkerStyle(21);
    PrCT_V0vsHV_SiPM1->SetMarkerSize(2.5);
    PrCT_V0vsHV_SiPM1->SetMarkerColor(kBlue);
    PrCT_V0vsHV_SiPM1->GetHistogram()->GetXaxis()->SetTitle("Electric field [kV/cm]");
    PrCT_V0vsHV_SiPM1->GetHistogram()->GetYaxis()->SetTitle("Ratio P_{CT}");
    PrCT_V0vsHV_SiPM1->GetHistogram()->GetYaxis()->SetRangeUser(0.8,1.2);
    DCR_V0vsHV_SiPM1->SetMarkerStyle(21);
    DCR_V0vsHV_SiPM1->SetMarkerSize(2.5);
    DCR_V0vsHV_SiPM1->SetMarkerColor(kBlue);
    DCR_V0vsHV_SiPM1->GetHistogram()->GetXaxis()->SetTitle("Electric field [kV/cm]");
    DCR_V0vsHV_SiPM1->GetHistogram()->GetYaxis()->SetTitle("P_{CN}");
    DCR_V0vsHV_SiPM1->GetHistogram()->GetYaxis()->SetRangeUser(0.0,2.0);             
            
    RQ_V0vsHV_SiPM3->SetMarkerStyle(23);
    RQ_V0vsHV_SiPM3->SetMarkerSize(2.5);
    RQ_V0vsHV_SiPM3->SetMarkerColor(kRed);
    RQ_V0vsHV_SiPM3->GetHistogram()->GetXaxis()->SetTitle("Electric field [kV/cm]");
    RQ_V0vsHV_SiPM3->GetHistogram()->GetYaxis()->SetTitle("Ratio Q_{m p.e.}");
    RQ_V0vsHV_SiPM3->GetHistogram()->GetYaxis()->SetRangeUser(0.8,1.2);
    PrCT_V0vsHV_SiPM3->SetMarkerStyle(23);
    PrCT_V0vsHV_SiPM3->SetMarkerSize(2.5);
    PrCT_V0vsHV_SiPM3->SetMarkerColor(kRed);
    PrCT_V0vsHV_SiPM3->GetHistogram()->GetXaxis()->SetTitle("Electric field [kV/cm]");
    PrCT_V0vsHV_SiPM3->GetHistogram()->GetYaxis()->SetTitle("Ratio P_{CT}");
    PrCT_V0vsHV_SiPM3->GetHistogram()->GetYaxis()->SetRangeUser(0.8,1.2);
    DCR_V0vsHV_SiPM3->SetMarkerStyle(23);
    DCR_V0vsHV_SiPM3->SetMarkerSize(2.5);
    DCR_V0vsHV_SiPM3->SetMarkerColor(kRed);
    DCR_V0vsHV_SiPM3->GetHistogram()->GetXaxis()->SetTitle("Electric field [kV/cm]");
    DCR_V0vsHV_SiPM3->GetHistogram()->GetYaxis()->SetTitle("Ratio P_{CN}");
    DCR_V0vsHV_SiPM3->GetHistogram()->GetYaxis()->SetRangeUser(0.0,2.0);
         
    //RQ_V0vsHV_SiPM0->Draw("AP");//Write();
    //RQ_V0vsHV_SiPM1->Draw("PSAME");//Write();
    //RQ_V0vsHV_SiPM3->Draw("PSAME");//Write();
    
    //PrCT_V0vsHV_SiPM0->Draw("PSAME");//Write();
    //PrCT_V0vsHV_SiPM1->Draw("PSAME");//Write();
    //PrCT_V0vsHV_SiPM3->Draw("PSAME"); //Write();
    
      DCR_V0vsHV_SiPM0->Draw("AP");//Write();
   // DCR_V0vsHV_SiPM1->Draw("PSAME");//Write();
   // DCR_V0vsHV_SiPM3->Draw("PSAME"); //Write();
    
    leg = new TLegend(0.1,0.7,0.18,0.9);
    //leg->AddEntry(RQ_V0vsHV_SiPM0,"FBK-RGB SiPM","P");
    //leg->AddEntry(PrCT_V0vsHV_SiPM0,"FBK-RGB SiPM","P");
    leg->AddEntry(DCR_V0vsHV_SiPM0,"FBK-RGB","P");
    //leg->AddEntry(RQ_V0vsHV_SiPM1,"FBK-LowField SiPM","P");
    //leg->AddEntry(PrCT_V0vsHV_SiPM1,"FBK-LowField SiPM","P");
    leg->AddEntry(DCR_V0vsHV_SiPM1,"FBK-low field","P");
    //leg->AddEntry(RQ_V0vsHV_SiPM3,"Hamamatsu VUV3 SiPM","P");
    //leg->AddEntry(PrCT_V0vsHV_SiPM3,"Hamamatsu VUV3 SiPM","P");
    leg->AddEntry(DCR_V0vsHV_SiPM3,"Hamamatsu VUV3","P");
    leg->Draw();
    */
    //f->Close();
    /*
      Ratio  = ( (double)cond_real)/cond_mc;
      ratioErr  = sqrt(cond_real_err*cond_real_err+Ratio*Ratio*cond_mc_err*cond_mc_err)/cond_mc;
     */
}
