#include "ROOT/RMakeUnique.hxx"
#include "TString.h"
#include "TROOT.h"
#include "TChain.h"
#include "TFileCollection.h"
#include "TH1F.h"
#include "TTreeReader.h"
#include "ROOT/TTreeProcessorMP.hxx"
#include "processD.h"


int wrapper(){

TChain* T=new TChain("T");
T->Add("/global/scratch/rahmans/scratch/beamStudy/beamUpstreamR0.0/col2_15cm_raster/5k/beam_1.root");

/*
gROOT->SetBatch(kTRUE);
TString selectorPath="/home/rahmans/analysis/BeamSteeringAnalysis/colprocessD.C";
auto sel=TSelector::GetSelector(selectorPath);
sel->SetOption("/home/rahmans/analysis/BeamSteeringAnalysis/coldefault.txt,default");

ROOT::TTreeProcessorMP pool(4);

pool.Process(*T,*sel);
//sel->GetOutputList()->Delete();
*/
T->Process("/home/rahmans/analysis/BeamSteeringAnalysis/plane/processD.C+","/home/rahmans/analysis/BeamSteeringAnalysis/plane,default,e-");

return 0;
}


