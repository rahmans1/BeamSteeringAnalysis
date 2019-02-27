#include <TFile.h>
#include <TChain.h>
int smallana(){

TChain *T=new TChain("T");
TFile *file=new TFile("/global/scratch/rahmans/scratch/beamStudy/beamUpstreamR0.0/col2_15cm/beam_BS_50k.root");
T->Add("/global/scratch/rahmans/scratch/beamStudy/beamUpstreamR0.0/col2_15cm/beam_BS_50k.root");
TTreeReader reader(T);
TTreeReaderArray<Double_t> hit_x = {reader, "hit.x"};

while (reader.Next()){

std::cout<< hit_x.GetSize() <<std::endl;

}
return 0;
}
