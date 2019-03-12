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


#include "processD.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>

std::vector<TH1F*> e_in_all; // 1D energy distribution histograms
std::vector<TH1F*> r_all; // 1D energy weighted radial profile
std::vector<TH1F*> r; // 1D energy weighted radial profile (>energy_cut)

std::vector<TH2F*> xy_1k; // 2D energy weighted xy-profile (>energy_cut)
std::vector<TH2F*> xy_1h; // 2D energy weighted xy-profile zoom 1 (>energy_cut)
std::vector<TH2F*> xy_10; // 2D energy weighted xy-profile zoom 2 (>energy_cut)

std::vector<TH2F*> zx; // 2D energy deposit weighted
std::vector<TH2F*> zxv; // Source of the deposited energy

Int_t nFiles;             // no of files
Int_t evPerFile;          // no of events per file
Double_t weight;          // weight=1/(nFiles*evPerFile)
Int_t energy_cut;         // in this particular case we take energy_cut=1 MeV

TFile* rootfile;

TString folder;
TString tag;
TString particle;
std::map<TString, Int_t> pid;

std::map<Int_t,Int_t> detIn;     // Mapping collimator coil det ids to an array index

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
   particle=((TObjString *)(opt->At(2)))->String();
   rootfile=new TFile(Form("%s/%s_%s.root",folder.Data(),tag.Data(),particle.Data()) , "RECREATE");
   
   pid["e-"]=11;
   pid["e+"]=-11;
   pid["y"]=22;
   pid["n"]=2112;
   pid["p"]=2212;
   pid["pi0"]=111;
   pid["pi+"]=211;
   pid["pi-"]=-211;


   detIn[2001]=0; 
   detIn[2006]=1;
   detIn[2002]=2; 
   detIn[2004]=3; 
   detIn[2005]=4; 
   for (int i=4001;i<=4007;i++) detIn[i]=5; 
   for (int i=3001;i<=3014;i++) detIn[i]=6;
   detIn[30]=7; 
   Float_t startz[8]={5100, 5100,5800,8200,12790,6000,8000, 17900};
   Float_t endz[8]= {5700,5400,6000,8400,12890,8000, 18000,29000};
   Float_t startx[8]={-800,-800,-800,-800,-800, -800,-800,-1200};
   Float_t endx[8]={800,800,800,800,800,800,800,1200};
   char part[8][16]={"col1","col1fin","col2","col4","col5","ucoil","dcoil","bpipe"};
   

   nFiles=200; // no of runs 
   evPerFile=5000; // event per run
   weight=1.0/(nFiles*evPerFile); // Counts/incident electron gives Hz/uA
   energy_cut=1 ; // what is the minimum energy of incident electron you want to look at
   numr=20; // number of radial bins for 1D energy plots
   maxr=100.0; // max radius for 1D energy plots
  
   
   for(int j=0;j<8;j++){
   	zx.push_back(new TH2F(Form("zx_%s",part[j]), "Power Dep(MeV/e/(mm)^2)" , (int)(endz[j]-startz[j]), startz[j], endz[j],  (int)(endx[j]-startx[j]), startx[j], endx[j]));
        zxv.push_back(new TH2F(Form("zxv_%s",part[j]), "Source Dep(Mev/e/(mm)^2)", 29000, 0, 29000, 2400, -1200, 1200));
   }
 
   for(int i=24;i<=29;i++){

	r_all.push_back(new TH1F(Form("r_all_%i",i), "Incident Power (MeV/e/mm)", 100,0, 100));

	r.push_back(new TH1F(Form("r_%i",i), "Incident Power (MeV/e/mm) [E_in>1MeV]", 100,0,100));
	xy_1k.push_back(new TH2F(Form("xy_1k_%i",i), "Incident Power (MeV/e/(mm)^2) [E_in>1MeV]", 2000,-1000,1000,2000,-1000,1000));
        xy_1h.push_back(new TH2F(Form("xy_1h_%i",i), "Incident Power (MeV/e/(mm)^2) [E_in>1MeV]", 200,-100,100,200,-100,100));
        xy_10.push_back(new TH2F(Form("xy_10_%i",i), "Incident Power (MeV/e/(0.1mm)^2) [E_in>1MeV]", 200,-10,10,200,-10,10));

        for (int j=0;j<numr;j++){
        	e_in_all.push_back(new TH1F(Form("e_in_all_%i_%g",i,j*maxr/numr),Form("Rate (1/e) vs E_in (MeV), %g<=r<%g (mm)",j*maxr/numr,(j+1)*maxr/numr), 11000,0,11000));
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

   	if (particle!="all"&& hit_pid[i]!=pid[particle]) {continue;}   //  check if there is a particle cut and impose that cut

	if(hit_det[i]<30) {     // check if the detector is a plane detector
	
		r_all[hit_det[i]-24]->Fill(hit_r[i], weight*hit_e[i]);
        	if (hit_e[i]>energy_cut){
			r[hit_det[i]-24]->Fill(hit_r[i],weight*hit_e[i]);
			xy_1k[hit_det[i]-24]->Fill(hit_x[i],hit_y[i],weight*hit_e[i]);
		        xy_1h[hit_det[i]-24]->Fill(hit_x[i],hit_y[i],weight*hit_e[i]);
			xy_10[hit_det[i]-24]->Fill(hit_x[i],hit_y[i],weight*hit_e[i]);
		}
       		for (int j=0;j<numr;j++){
                	if (hit_r[i]>=j*maxr/numr && hit_r[i]<(j+1)*maxr/numr) {
               			e_in_all[(hit_det[i]-24)*numr+j]->Fill(hit_e[i], weight);
			}
        	}
	}else{
		zx[detIn[hit_det[i]]]->Fill(hit_z[i], hit_x[i], weight*hit_edep[i]);
                zxv[detIn[hit_det[i]]]->Fill(hit_vz[i], hit_vx[i], weight*hit_edep[i]);
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
   
   for(int j=0;j<8;j++){
   	zx[j]->Write("",TObject::kOverwrite);
        zxv[j]->Write("",TObject::kOverwrite);
   }

   for(int i=24;i<30;i++){
	r_all[i-24]->Write("",TObject::kOverwrite);
	r[i-24]->Write("",TObject::kOverwrite);
	xy_1k[i-24]->Write("",TObject::kOverwrite);
	xy_1h[i-24]->Write("",TObject::kOverwrite);
	xy_10[i-24]->Write("",TObject::kOverwrite);	
        for (int j=0;j<numr;j++){
        	e_in_all[(i-24)*numr+j]->Write("",TObject::kOverwrite);
        }
   }

   rootfile->Close();
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
}
