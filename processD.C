#define processD_cxx
// The class definition in processD.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("processD.C")
// root> T->Process("processD.C","some options")
// root> T->Process("processD.C+")
//


#include "processD.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>


std::vector<TH2F*> xz;
std::vector<TH2F*> xzv;
//TFile* rootFile;
Int_t nFiles;
Int_t evPerFile;
Double_t weight;
Int_t energy_cut;
ofstream outfile;
TString tag;
std::map<int,int> detIn;



void processD::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).
  /* 
   TString option = GetOption();
   TObjArray *opt= option.Tokenize(",");
   outfile.open(((TObjString *)(opt->At(0)))->String());   
   tag= ((TObjString *)(opt->At(1)))->String();
   //rootFile=new TFile(((TObjString *)(opt->At(0)))->String() , "update");

   nFiles=200; // no of runs 
   evPerFile=5000; // event per run
   weight=1.0/(nFiles*evPerFile); // Counts/incident electron gives Hz/uA
   outfile<< weight << "\n";
   energy_cut=0 ; // what is the minimum energy of incident electron you want to look at
   
   
   Float_t startz[8]={5100, 5100,5800,8200,12790,6000,8000, 17900};
   Float_t endz[8]= {5700,5400,6000,8400,12890,8000, 18000,29000};
   detIn[2001]=0; 
   detIn[2006]=1;
   detIn[2002]=2; 
   detIn[2004]=3; 
   detIn[2005]=4; 
   for (int i=4001;i<=4007;i++) detIn[i]=5; 
   for (int i=3001;i<=3014;i++) detIn[i]=6;
   detIn[30]=7; 
   
    for(int j=0; j<=6;j++){
	xz.push_back(new TH2F(Form("xz%i",j), Form("xz%i",j), (int)(endz[j]-startz[j]), startz[j], endz[j], 1600, -800.0, 800.0));
        xzv.push_back(new TH2F(Form("xzv%i",j), Form("xzv%i",j), 29000, 0, 29000, 2400, -1200, 1200));
    }
    xz.push_back(new TH2F(Form("xz%i",7), Form("xz%i",7), (int)(endz[7]-startz[7]), startz[7], endz[7], 2400, -1200.0, 1200.0));
    xzv.push_back(new TH2F(Form("xzv%i",7), Form("xzv%i",7), 29000, 0, 29000, 2400, -1200, 1200));
*/
}

void processD::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

    
   TString option = GetOption();
   TObjArray *opt= option.Tokenize(",");
   outfile.open(((TObjString *)(opt->At(0)))->String());   
   tag= ((TObjString *)(opt->At(1)))->String();
   //rootFile=new TFile(((TObjString *)(opt->At(0)))->String() , "update");

   nFiles=200; // no of runs 
   evPerFile=5000; // event per run
   weight=1.0/(nFiles*evPerFile); // Counts/incident electron gives Hz/uA
   outfile<< weight << "\n";
   energy_cut=0 ; // what is the minimum energy of incident electron you want to look at
   
   
   Float_t startz[8]={5100, 5100,5800,8200,12790,6000,8000, 17900};
   Float_t endz[8]= {5700,5400,6000,8400,12890,8000, 18000,29000};
   detIn[2001]=0; 
   detIn[2006]=1;
   detIn[2002]=2; 
   detIn[2004]=3; 
   detIn[2005]=4; 
   for (int i=4001;i<=4007;i++) detIn[i]=5; 
   for (int i=3001;i<=3014;i++) detIn[i]=6;
   detIn[30]=7; 
   
    for(int j=0; j<=6;j++){
	xz.push_back(new TH2F(Form("xz%i",j), Form("xz%i",j), (int)(endz[j]-startz[j]), startz[j], endz[j], 1600, -800.0, 800.0));
        xzv.push_back(new TH2F(Form("xzv%i",j), Form("xzv%i",j), 29000, 0, 29000, 2400, -1200, 1200));
    }
    xz.push_back(new TH2F(Form("xz%i",7), Form("xz%i",7), (int)(endz[7]-startz[7]), startz[7], endz[7], 2400, -1200.0, 1200.0));
    xzv.push_back(new TH2F(Form("xzv%i",7), Form("xzv%i",7), 29000, 0, 29000, 2400, -1200, 1200));


}

Bool_t processD::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // When processing keyed objects with PROOF, the object is already loaded
   // and is available via the fObject pointer.
   //
   // This function should contain the \"body\" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

   fReader.SetLocalEntry(entry);
   
   for(int i=0;i<hit_det.GetSize();i++){
        if(hit_det[i]>=30){
		xz[detIn[hit_det[i]]]->Fill( hit_z[i], hit_x[i], weight*hit_edep[i]);
                xzv[detIn[hit_det[i]]]->Fill( hit_vz[i], hit_vx[i], weight);
        }
   }



   return kTRUE;
}

void processD::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void processD::Terminate()
{
   gStyle->SetOptStat(0);
  // gStyle->SetContour(100);
   gStyle->SetPalette(53);
   TCanvas *c=new TCanvas("c","c", 800,600);
   TCanvas *c1=new TCanvas("c1","c1", 800,600);
 //  c->Divide(3,1);
   for(int i=0;i<=7;i++){
        c->cd();
        c->SetLogz();
        c->SetRightMargin(0.13);
	xz[i]->Draw("colz");       
        outfile<< xz[i]->Integral() <<"\n";
        c->Print(Form("%s%i.png",tag.Data(),i));
        c1->cd();
        c1->SetLogz();
        c1->SetRightMargin(0.13);
	xzv[i]->Draw("colz");       
        c1->Print(Form("v%s%i.png",tag.Data(),i));
   }
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
