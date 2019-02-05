#include <fstream>
#include <iostream>
#include <string>
#include "TString.h"
#include "TGraph.h"

using namespace std;
/*
For FBK-Low new data with LED 280 nm
2018_5_27_82707  2018_5_27_83039  2018_5_27_83356  2018_5_27_83731  2018_5_27_84058  2018_5_27_84422
For FBK-Low new data #2 with LED 280 nm
2018_6_1_94030   2018_6_1_94707   2018_6_1_95322   2018_6_1_95905   2018_6_1_100459  2018_6_1_101302
*/

void analysis_SiPM1n_wLED(){
  TString infilename = "/junofs/users/yanwq/HV_test/2018_6_1_100459/ch0.txt"; //for SiPM
  //TString infilename = "/junofs/users/yanwq/HV_test/2018_6_1_100459/ch1.txt"; //for PMT
    ifstream file (infilename);
    ifstream fileread (infilename);
    TFile *fileRoot = new TFile("Output_root/outputfile_nLFwLED2_2018_6_1_12.root", "recreate");   
    
    string ll,ss,hh;
    
    int PT_start[2500]={0};
    int PT_end[2500]={0};
    int signal_time[2500];
    int min_h[20];
    double amplitudeValue[2500]={0};
    double amplitudeValueMBL[2500]={0};
    double timeValue[2500]={0};
    double pulseQ[2500]={0};
    
    int amp_min_time = 0.;
    int waveformtime=2500;
    int pt=0;
    int ev = 0;
    int width = 0;
    int nPulses = 0;
    double amp_min = 2000.;
    double aev = 0;
    double gev = 0;
    double evwp = 0;
    double baseline=0; 
    double SiPMQ=0; 
    double QDC_thr=0;
    double QDC_thr_btc = 0;
    double baselinemod=0;
    double wi = 0;
    bool badevent = false;
    
    TH1F *Allevents = new TH1F("number_of_events_differentCuts", "number_of_events_differentCuts",5,0.,5.);
    TH1F *Allevents_R = new TH1F("Ratio_number_of_events_differentCuts", "Ratio_number_of_events_differentCuts",5,0.,5.);
    TH1F *charge_waveform = new TH1F("charge_whole_waveform","charge_whole_waveform",10000,0.,10000.);
    TH1F *BaseLS = new TH1F("BaseLine_spread", "BaseLine_spread", 40,-20,20);
    TH1F *STA_BL = new TH1F("BLmSTAmplitude", "BLmSTAmplitude", 200,0.,10);
    TH1F *nOPulses = new TH1F("nPulses_per_Event", "nPulses_per_event",20,0,20);
    TH1F *Baseline = new TH1F("BaseLine", "BaseLine", 100,750,850);
    TH1F *PTstart = new TH1F("pulseStartTime","PulseStartTime",2000,0.,2000.);
    TH1F *PTend = new TH1F("pulseEndTime","PulseEndTime",2000,0.,2000.);
    TH1F *PTtrig = new TH1F("TrigPulseTime","TrigPulseTime",2000,0.,2000.);
    TH1F *Amplitude = new TH1F("Amplitude","Amplitude",200,700,900);
    TH1F *LowSig = new TH1F("waveform_lowSignal","waveform_lowSignal",2000,0.,2000.); 
    TH1F *PulseTimeWidth_BTC = new TH1F("pulsWidth_EndmStart_beforeTcut","pulseWidth_EndmStart_beforeTcut",2000,0.,2000.);
    TH1F *PulseTimeWidth = new TH1F("pulsWidth_EndmStart","pulseWidth_EndmStart",2000,0.,2000.);
    TH1F *signal_Time_minamp = new TH1F("pulse_Time_atMinAMp","pulse_Time_atMinAmp",2000,0.,2000.);
    TH1F *Sig_DeltaT = new TH1F("pulse_PulseTmTrigT","pulse_DeltaTime_PulseTmTrigT",2000,0.,2000.);
    TH1F *ST_badPul =  new TH1F("StartTime_badSignals","StartTime_badSignals",2000,0.,2000.);
    TH1F *charge_Sig = new TH1F("charge_Signal","QDC_charge_Signal",10000,0.,10000.);
    TH1F *charge_Sig_clean =  new TH1F("charge_clean","QDC_charge_clean",1000,0.,1000.);
    TH2F *all_waveforms = new TH2F("All_waveforms","All_waveforms",2000,0.,2000.,250,650,900);
    TH2F *all_cleand_waveforms = new TH2F("All_cleand_waveforms","All_clean_waveforms",2000,0.,2000.,250,650,900);
    TH2F *all_cleand_waveforms_mbl = new TH2F("All_cleand_waveforms_m_baseline","All_cleand_waveforms_m_baseline",2000,0,2000,250,650,900);
    TH2F *exlevt = new TH2F("excluded_events","exclud_edevents",2000,0.,2000.,250,650,900);
    TH2F * tt_vs_sw = new TH2F("TrigTime_vs_PulseST_m_PulseET","TrigTime_vs_Charge_vs_PulseST_m_PulseET",1000,0.,1000.,1000,0.,1000.);
    TH2F *Q_vs_st = new TH2F("Charge_vs_pulseStartTime","Charge_vs_pulseStartTime",1000,0.,1000.,1000,0.,1000.);
    TH2F *Q_vs_tw = new TH2F("Charge_vs_PulseTime_m_TrigTime","Charge_vs_PulseTime_m_TrigTime",1000,0.,1000.,1000,0.,1000.);
    TH2F *Q_vs_sw_btc = new TH2F("Charge_vs_PulseST_m_PulseET_BTC","Charge_vs_PulseST_m_PulseET_BTC",1000,0.,1000.,1000,0.,1000.);
    TH2F *Q_vs_sw = new TH2F("Charge_vs_PulseST_m_PulseET","Charge_vs_PulseST_m_PulseET",1000,0.,1000.,1000,0.,1000.);
    /*
    TH1F *wf = new TH1F ("smoothed_waveform", "smoothed_waveform", 1000,0,1000);
    TH1F *SiPMQ_smooth = new TH1F("smoothed_charge_signal","smoothed_charge_Signal",1000,0.,1000.);
    TH1F *SignalTime = new TH1F("smoothed_signal_time","smooth_signal_time",1000,0.,1000.);
    TH2F *Signal_Q_vs_Time = new TH2F("SignalCharge_vs_SignalTime","SignalCharge_vs_SignalTime",1000,0.,1000.,1000,0.,1000.);
    */
    
    while(getline(fileread, hh))//get the number of collected events
        {
           ev++;
	    }
    
    for(int j=0; j<ev; j++)
      {
	aev++; //original number of events
	
	//bounadries for ROOT graphical cut
	TCutG *cutg = new TCutG("CUTG",8);
	cutg->SetPoint(0,1.23888,4.88997);
	cutg->SetPoint(1,4.4155,4.88997);
	cutg->SetPoint(2,10.9276,26.2836);
	cutg->SetPoint(3,10.9276,82.824);
	cutg->SetPoint(4,4.01842,50.7335);
	cutg->SetPoint(5,0.682973,24.7555);
	cutg->SetPoint(6,0.603557,0.305616);
	cutg->SetPoint(7,1.23888,4.88997);
	
	getline(file, ss);
	istringstream is(ss);
	
	pt=0;
	wi=0;
	baseline = 0;
	QDC_thr = 0.;
	QDC_thr_btc = 0;
	nPulses = 0;
	badevent = false;
	
	for(int f=0; f<waveformtime; f++)
	  {
	    PT_start[f]=0.0;
	    PT_end[f]=0.0;
	    amplitudeValue[f]=0.;
	    timeValue[f] = 0;
	    signal_time[f] = 0;
	  }
	
    //Extract infor from the waveforms
	for(int i=0; i<waveformtime; i++)
	  {
	    is >> amplitudeValue[i];
	    timeValue[i] = i;
	    all_waveforms->Fill(timeValue[i],amplitudeValue[i]);
	    if(i < 250) Amplitude->Fill(amplitudeValue[i]);
	    	    
	    if(i < 250 && (amplitudeValue[i] < 748 || amplitudeValue[i] > 760)) badevent = true; //Exclude bad events with high noise
	    if(badevent == true) exlevt->Fill(timeValue[i],amplitudeValue[i]); //excluded waveforms
	    	   	    	    	    	    
	    if(i < 140) baseline +=amplitudeValue[i];
	    else 
	      {
		if(i == 141){baseline = baseline/140; Baseline->Fill(baseline);} //average baseline
		else
		  {
		    if(i > 250 && amplitudeValue[i] < (baseline-6) && PT_start[pt] == 0) PT_start[pt] = i;
		    if(PT_start[0] > 473) badevent = true;
		    if(i > 250 && amplitudeValue[i] > (baseline-1) && PT_start[pt] > 0) PT_end[pt] = i;
		    if(i > 250 && PT_start[pt] > 0 && PT_end[pt] > 0 && (PT_end[pt]-PT_start[pt]) > 0) {PulseTimeWidth_BTC->Fill(PT_end[pt]-PT_start[pt]); pt++;}
		  }
	      }  
	  }
	
	if(badevent == true) continue; //exclude events with bad waveforms from further analysis
	gev++; //number of survived events after events exclusion 
			
	for(int q=0; q<waveformtime; q++)
	  {
	    amplitudeValueMBL[q] = baseline-amplitudeValue[q];
	    all_cleand_waveforms->Fill(timeValue[q],amplitudeValue[q]);
	    all_cleand_waveforms_mbl->Fill(timeValue[q],amplitudeValueMBL[q]);  
	  }
	
	nPulses = pt;
	nOPulses->Fill(nPulses);
		
	if(nPulses > 0)
	  {	    
	    evwp++; //number of survived events with at least 1 pulse in the waveform
	    
	    for(int h=0; h <140; h++) //baseline spread
	      {BaseLS->Fill(amplitudeValue[h]-baseline);}
	    
	    STA_BL->Fill(baseline-amplitudeValue[PT_start[0]]);
	        
	    for(int p = 0; p < nPulses; p++) //loop over all pulses in the waveform
	      {
		wi = PT_end[p]-PT_start[p];
		
		for(int o = PT_start[p]-4; o < PT_end[p]+2; o++) //SiPMQ whole waveform PT_end[p]
		  {
		    QDC_thr +=baseline-amplitudeValue[o]; 
		  }
		Q_vs_sw_btc->Fill(wi,QDC_thr);
		
		if(cutg->IsInside(wi,QDC_thr)) ST_badPul->Fill(PT_start[p]); //start time of excluded pulses
		
		//if(p == 0) charge_Sig->Fill(QDC_thr); //Q main/trigger pulse
		if(p == 0 && !cutg->IsInside(wi,QDC_thr)) charge_Sig->Fill(QDC_thr); //Q trig pulse without pedestal
		//if(wi > 20) charge_Sig_clean->Fill(QDC_thr);
		
		if(!cutg->IsInside(wi,QDC_thr)) 
		  {		
		    for(int h=PT_start[p]; h < PT_end[p]; h++)
		      {
			if(amplitudeValue[h] < amp_min) //to find the pulse time of max amplitude
			  {
			    amp_min = amplitudeValue[h];
			    amp_min_time = h;
			  }
		      }
		    
		    for(int tp=PT_start[p]; tp <  PT_end[p]; tp++)
		      {
			if(tp > PT_start[0] && tp < amp_min_time) width++;
		      }
		    
		    PTstart->Fill(PT_start[p]);
		    PTend->Fill(PT_end[p]);
		    PTtrig->Fill(PT_start[0]);
		    signal_Time_minamp->Fill(width+PT_start[p]);
		    Sig_DeltaT->Fill((width+PT_start[p])-PT_start[0]);
		    PulseTimeWidth->Fill(wi);
		    charge_waveform->Fill(QDC_thr);
		    tt_vs_sw->Fill(PT_start[0],wi);
		    Q_vs_st->Fill(PT_start[p],QDC_thr);
		    Q_vs_sw->Fill(wi,QDC_thr);
		    Q_vs_tw->Fill(((width+PT_start[p])-PT_start[0]),QDC_thr);
		    
		    }
					
		QDC_thr=0;
		width = 0.0;
		amp_min = 2000.;
		amp_min_time = 0.;
		
		
		wi=0;
	      }

	    if(j > 525 && j < 527)
	      {
		for(int z=0; z<waveformtime; z++)
		  {
		    LowSig->Fill(timeValue[z],amplitudeValue[z]);
		  }
		cout << "evt. " << j << " has " << nPulses << " pulses, and" << " DeltaT = " << (width+PT_start[p])-PT_start[0] << endl;
		cout << "PT_start " << PT_start[p] << ", PT_time" <<  width+PT_start[p] << ", and PT_end " << PT_end[p] << ", and Q = " << QDC_thr << endl;
	      }
	    
	    
	    /************************************************Smoothing and signal finding************************************************/
	    /*
	    for(int r=0; r<1000; r++)
	    {
	    wf->SetBinContent(r,baseline-amplitudeValue[r]);
	    }
	    if(j<100) wf->Write();	
	  
	  //Smooth the waveform and search in the smoothed one for peaks
	  wf->Smooth();
	  TSpectrum *s = new TSpectrum(15);//max positions/peaks
	  s->SetAverageWindow(12);
	  
	  Int_t nfound = s->Search(wf, 2., "nobackground", 0.25);//1.5 sigma, 0.2 threshold	  	  
	  Float_t* xpeaks = s->GetPositionX();
	  if(j < 100) wf->Write();

	  for(Int_t p = 0; p < nfound; p++) 
	    {
	      signal_time[p] = xpeaks[p];
	      SignalTime->Fill(signal_time[p]);
	      
	      Int_t xbin = 1 + Int_t(xpeaks[p]);
	      if(signal_time[p]>180)
		{
		  
		  for(Int_t j = xbin; j >= 0; j--) 
		    {
		      if(wf->GetBinContent(j) < 0) break;
		      pulseQ[p] += wf->GetBinContent(j);
		    }
		  SiPMQ_smooth->Fill(pulseQ[p]*100);
		  Signal_Q_vs_Time->Fill(signal_time[p],(pulseQ[p]*100));
		  
		  for(Int_t k = xbin+1; k < xbin+123; k++) 
		    {
		      if(wf->GetBinContent(k) < 0) break;
		      pulseQ[p] += wf->GetBinContent(k);
		    }
		  SiPMQ_smooth->Fill(pulseQ[p]*100);
		  Signal_Q_vs_Time->Fill(signal_time[p],(pulseQ[p]*100));
		}
	    }
	  pulseQ[p]=0;
	  //SiPMQ = 0.;
	  */
	  }	
	
      }
    double ev1 = aev/aev;
    double ev2 = gev/aev;
    double ev3 = evwp/aev;
    Allevents->Fill(1,aev);
    Allevents_R->Fill(1,ev1);
    Allevents->Fill(2,gev);
    Allevents_R->Fill(2,ev2);
    Allevents->Fill(3,evwp);
    Allevents_R->Fill(3,ev3);
    
    
    Allevents->Write();
    Allevents_R->Write();
    Baseline->Write();
    BaseLS->Write();
    STA_BL->Write();
    nOPulses->Write();
    PTstart->Write();
    PTend->Write();
    PTtrig->Write();
    Amplitude->Write();
    LowSig->Write();
    PulseTimeWidth_BTC->Write();
    PulseTimeWidth->Write();
    signal_Time_minamp->Write();
    Sig_DeltaT->Write();
    ST_badPul->Write();
    charge_waveform->Write();
    charge_Sig->Write();
    charge_Sig_clean->Write();
    all_waveforms->Write();
    all_cleand_waveforms->Write();
    all_cleand_waveforms_mbl->Write();
    exlevt->Write();
    tt_vs_sw->Write();
    Q_vs_tw->Write();
    Q_vs_st->Write();
    Q_vs_sw_btc->Write();
    Q_vs_sw->Write();

    /*
    SignalTime->Write();
    SiPMQ_smooth->Write();
    Signal_Q_vs_Time->Write();
    */
    
    fileRoot->Close();
       
}
