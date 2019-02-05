{
  TCanvas *c1 = new TCanvas("c1","c1",600,500);
  gStyle->SetOptStat(0);
  TFile *f = new TFile("Q_vs_T_RGB_woLED.root","RECREATE");
    
  TH2F *FBK_RGB_cold_0kV = new TH2F("FBK_RGB_cold_woLED_0kV","FBK_RGB_woLED_0kV",10000,0,10000,5100,0,5100);
  TH2F *FBK_RGB_cold_3kV = new TH2F("FBK_RGB_cold_woLED_3kV","FBK_RGB_woLED_3kV",200000,0,200000,11000,0,11000);
  TH2F *FBK_RGB_cold_6kV = new TH2F("FBK_RGB_cold_woLED_6kV","FBK_RGB_woLED_6kV",200000,0,200000,11000,0,11000);
  TH2F *FBK_RGB_cold_9kV = new TH2F("FBK_RGB_cold_woLED_9kV","FBK_RGB_woLED_9kV",200000,0,200000,11000,0,11000);
  TH2F *FBK_RGB_cold_12kV = new TH2F("FBK_RGB_cold_woLED_12kV","FBK_RGB_woLED_12kV",200000,0,200000,11000,0,11000);  
  TH2F *FBK_RGB_cold_15kV = new TH2F("FBK_RGB_cold_woLED_15kV","FBK_RGB_woLED_15kV",200000,0,200000,11000,0,11000);
    
  ifstream Open_FBK_RGB_cold_0kV("SiPM_0_0_dt.txt");
 /*
  ifstream Open_FBK_RGB_cold_3kV("SiPM_0_3_dt.txt"); 
  ifstream Open_FBK_RGB_cold_6kV("SiPM_0_6_dt.txt"); 
  ifstream Open_FBK_RGB_cold_9kV("SiPM_0_9_dt.txt"); 
  ifstream Open_FBK_RGB_cold_12kV("SiPM_0_12_dt.txt"); 
  ifstream Open_FBK_RGB_cold_15kV("SiPM_0_15_dt.txt");   
   */ 
    
  while(!Open_FBK_RGB_cold_0kV.eof())
    {
      float x, y; 
      Open_FBK_RGB_cold_0kV >> x >> y;
      FBK_RGB_cold_0kV->Fill(x,y);
    }
   
     /* 
  while(!Open_FBK_RGB_cold_3kV.eof())
    {
      float x, y; 
      Open_FBK_RGB_cold_3kV >> x >> y;
      FBK_RGB_cold_3kV->Fill(x,y);
    }
    
  while(!Open_FBK_RGB_cold_6kV.eof())
    {
      float x, y; 
      Open_FBK_RGB_cold_6kV >> x >> y;
      FBK_RGB_cold_6kV->Fill(x,y);
    }
 
 while(!Open_FBK_RGB_cold_9kV.eof())
    {
      float x, y; 
      Open_FBK_RGB_cold_9kV >> x >> y;
      FBK_RGB_cold_9kV->Fill(x,y);
    }
    
 while(!Open_FBK_RGB_cold_12kV.eof())
    {
      float x, y; 
      Open_FBK_RGB_cold_12kV >> x >> y;
      FBK_RGB_cold_12kV->Fill(x,y);
    }
    
 while(!Open_FBK_RGB_cold_15kV.eof())
    {
      float x, y; 
      Open_FBK_RGB_cold_15kV >> x >> y;
      FBK_RGB_cold_15kV->Fill(x,y);
    }
 */
 /*
 FBK_RGB_cold_0kV->SetMarkerStyle(20);
 FBK_RGB_cold_0kV->SetLineColor(kBlack);
 FBK_RGB_cold_0kV->GetXaxis()->SetTitle("#DeltaT [ns]");
 FBK_RGB_cold_0kV->GetXaxis()->SetTitleSize(0.075);
 FBK_RGB_cold_0kV->GetXaxis()->SetTitleOffset(0.7);
 FBK_RGB_cold_0kV->GetXaxis()->SetLabelSize(0.05);
 FBK_RGB_cold_0kV->GetYaxis()->SetTitle("Q [a.u]");
 FBK_RGB_cold_0kV->GetYaxis()->SetTitleSize(0.075);
 FBK_RGB_cold_0kV->GetYaxis()->SetTitleOffset(0.5);
 FBK_RGB_cold_0kV->GetYaxis()->SetLabelSize(0.05);
 
 FBK_RGB_cold_3kV->SetMarkerStyle(20);
 FBK_RGB_cold_3kV->SetLineColor(kBlack);
 FBK_RGB_cold_3kV->GetXaxis()->SetTitle("#DeltaT [ns]");
 FBK_RGB_cold_3kV->GetXaxis()->SetTitleSize(0.075);
 FBK_RGB_cold_3kV->GetYaxis()->SetTitle("Q [a.u]");
 FBK_RGB_cold_3kV->GetYaxis()->SetTitleSize(0.075);
 
 FBK_RGB_cold_6kV->SetMarkerStyle(20);
 FBK_RGB_cold_6kV->SetLineColor(kBlack);
 FBK_RGB_cold_6kV->GetXaxis()->SetTitle("#DeltaT [ns]");
 FBK_RGB_cold_6kV->GetXaxis()->SetTitleSize(0.075);
 FBK_RGB_cold_6kV->GetYaxis()->SetTitle("Q [a.u]");
 FBK_RGB_cold_6kV->GetYaxis()->SetTitleSize(0.075);
 
 FBK_RGB_cold_9kV->SetMarkerStyle(20);
 FBK_RGB_cold_9kV->SetLineColor(kBlack);
 FBK_RGB_cold_9kV->GetXaxis()->SetTitle("#DeltaT [ns]");
 FBK_RGB_cold_9kV->GetXaxis()->SetTitleSize(0.075);
 FBK_RGB_cold_9kV->GetYaxis()->SetTitle("Q [a.u]");
 FBK_RGB_cold_9kV->GetYaxis()->SetTitleSize(0.075);
 
 FBK_RGB_cold_12kV->SetMarkerStyle(20);
 FBK_RGB_cold_12kV->SetLineColor(kBlack);
 FBK_RGB_cold_12kV->GetXaxis()->SetTitle("#DeltaT [ns]");
 FBK_RGB_cold_12kV->GetXaxis()->SetTitleSize(0.075);
 FBK_RGB_cold_12kV->GetYaxis()->SetTitle("Q [a.u]");
 FBK_RGB_cold_12kV->GetYaxis()->SetTitleSize(0.075);
 
 FBK_RGB_cold_15kV->SetMarkerStyle(20);
 FBK_RGB_cold_15kV->SetLineColor(kBlack);
 FBK_RGB_cold_15kV->GetXaxis()->SetTitle("#DeltaT [ns]");
 FBK_RGB_cold_15kV->GetXaxis()->SetTitleSize(0.075);
 FBK_RGB_cold_15kV->GetYaxis()->SetTitle("Q [a.u]");
 FBK_RGB_cold_15kV->GetYaxis()->SetTitleSize(0.075);
 */
 
  FBK_RGB_cold_0kV->Draw("COL");
 //FBK_RGB_cold_3kV->Draw("p");
 //FBK_RGB_cold_6kV->Draw("p");
 //FBK_RGB_cold_9kV->Draw("p");
 //FBK_RGB_cold_12kV->Draw("p");
 //FBK_RGB_cold_15kV->Draw("p");

 /*leg = new TLegend(0.1,0.7,0.18,0.9);
 leg->AddEntry(FBK_RGB_warm,"EF=0 kV/cm","p");
 leg->AddEntry(FBK_RGB_cold_0kV,"EF=0 kV/cm","l");
 leg->AddEntry(FBK_RGB_cold_3kV,"EF=6 kV/cm","l");
 leg->AddEntry(FBK_RGB_cold_6kV,"EF=12 kV/cm","l");
 leg->AddEntry(FBK_RGB_cold_9kV,"EF=18 kV/cm","l");
 leg->AddEntry(FBK_RGB_cold_12kV,"EF=24 kV/cm","l");
 leg->AddEntry(FBK_RGB_cold_15kV,"EF=30 kV/cm","l");

 leg->Draw();
*/
 c1->cd();
 f->Write();
}
