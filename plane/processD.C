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

std::vector<TH1F*> e_in_all; // 1D energy distribution histograms
std::vector<TH2F*> xy; // 2D energy weighted rate on radial bins (>1MeV)
std::vector<TH2F*> xy_all; // 2D energy weighted rate on radial bins



Int_t nFiles;
Int_t evPerFile;
Double_t weight;
Int_t energy_cut;

ofstream outfile;
TFile* rootfile;

TString folder;
TString tag;

Int_t numr;
Float_t maxr;

void processD::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).
   
   TString option = GetOption();
   TObjArray *opt= option.Tokenize(",");
   folder=((TObjString *)(opt->At(0)))->String();
   tag= ((TObjString *)(opt->At(1)))->String();
   outfile.open(Form("%s/%s.txt",folder.Data(),tag.Data()));  
   rootfile=new TFile(Form("%s/%s.root",folder.Data(),tag.Data()) , "update");


   nFiles=200; // no of runs 
   evPerFile=5000; // event per run
   weight=1.0/(nFiles*evPerFile); // Counts/incident electron gives Hz/uA
   outfile<< weight << "\n";
   energy_cut=1 ; // what is the minimum energy of incident electron you want to look at
   numr=20; // number of radial bins for 1D energy plots
   maxr=100.0; // max radius for 1D energy plots

 
   for(int i=24;i<=29;i++){
        for (int j=0;j<numr;j++){
        	e_in_all.push_back(new TH1F(Form("e_in_all_%i_%g",i,j*maxr/numr),Form("Rate (1/e) vs E_in (MeV), %g<=r<%g (mm)",j*maxr/numr,(j+1)*maxr/numr), 11000,0,11000));
                xy.push_back(new TH2F(Form("xy_%i_%g",i, j*maxr/numr), "Incident Power (MeV/e/mm^2) [E_in>1MeV]", 200,-100,100,200, -100,100));
                xy_all.push_back(new TH2F(Form("xy_all_%i_%g",i, j*maxr/numr), "Incident Power (MeV/e/mm^2)", 200, -100, 100, 200, -100, 100));
        }
   	
   }
}

void processD::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

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
        if(hit_det[i]<30){
                for (int j=0;j<numr;j++){
                        if (hit_r[i]>=j*maxr/numr && hit_r[i]<(j+1)*maxr/numr) {
                		e_in_all[(hit_det[i]-24)*numr+j]->Fill(hit_e[i], weight);
				xy_all[(hit_det[i]-24)*numr+j]->Fill(hit_x[i],hit_y[i], weight*hit_e[i]);
                                if (hit_e[i]>energy_cut){
					xy[(hit_det[i]-24)*numr+j]->Fill(hit_x[i],hit_y[i], weight*hit_e[i]);
               
				}
			}
                }
		
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
   TCanvas *c=new TCanvas("c","c", 1200,400);
   c->Divide(3,1);
   for(int i=24;i<30;i++){
        for (int j=0;j<numr;j++){
               	e_in_all[(i-24)*numr+j]->Write("",TObject::kOverwrite);
                xy_all[(i-24)*numr+j]->Write("",TObject::kOverwrite);
		xy[(i-24)*numr+j]->Write("",TObject::kOverwrite);
        }
   }
   rootfile->Close();
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
