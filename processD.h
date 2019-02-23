//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Feb 20 16:38:30 2019 by ROOT version 6.14/04
// from TChain T/
//////////////////////////////////////////////////////////

#ifndef processD_h
#define processD_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>
#include "remolltypes.hh"
// Headers needed by this particular selector




class processD : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<Double_t> ppm = {fReader, "ppm"};
   TTreeReaderValue<Double_t> ppb = {fReader, "ppb"};
   TTreeReaderValue<Double_t> nm = {fReader, "nm"};
   TTreeReaderValue<Double_t> um = {fReader, "um"};
   TTreeReaderValue<Double_t> mm = {fReader, "mm"};
   TTreeReaderValue<Double_t> cm = {fReader, "cm"};
   TTreeReaderValue<Double_t> m = {fReader, "m"};
   TTreeReaderValue<Double_t> mm2 = {fReader, "mm2"};
   TTreeReaderValue<Double_t> cm2 = {fReader, "cm2"};
   TTreeReaderValue<Double_t> m2 = {fReader, "m2"};
   TTreeReaderValue<Double_t> mm3 = {fReader, "mm3"};
   TTreeReaderValue<Double_t> cm3 = {fReader, "cm3"};
   TTreeReaderValue<Double_t> m3 = {fReader, "m3"};
   TTreeReaderValue<Double_t> eV = {fReader, "eV"};
   TTreeReaderValue<Double_t> keV = {fReader, "keV"};
   TTreeReaderValue<Double_t> MeV = {fReader, "MeV"};
   TTreeReaderValue<Double_t> GeV = {fReader, "GeV"};
   TTreeReaderValue<Double_t> rad = {fReader, "rad"};
   TTreeReaderValue<Double_t> deg = {fReader, "deg"};
   TTreeReaderValue<Double_t> sr = {fReader, "sr"};
   TTreeReaderValue<Double_t> barn = {fReader, "barn"};
   TTreeReaderValue<Double_t> mbarn = {fReader, "mbarn"};
   TTreeReaderValue<Double_t> ubarn = {fReader, "ubarn"};
   TTreeReaderValue<Double_t> nsec = {fReader, "nsec"};
   TTreeReaderValue<Double_t> msec = {fReader, "msec"};
   TTreeReaderValue<Double_t> sec = {fReader, "sec"};
   TTreeReaderValue<Double_t> Hz = {fReader, "Hz"};
   TTreeReaderValue<Double_t> kHz = {fReader, "kHz"};
   TTreeReaderValue<Double_t> MHz = {fReader, "MHz"};
   TTreeReaderValue<Double_t> GHz = {fReader, "GHz"};
   TTreeReaderValue<Int_t> planeDet = {fReader, "dets.sd.planeDet"};
   TTreeReaderValue<Int_t> Lead_Shield_Hut_Det = {fReader, "dets.sd.Lead_Shield_Hut_Det"};
   TTreeReaderValue<Int_t> Lead_PolyShield_Hut_Det = {fReader, "dets.sd.Lead_PolyShield_Hut_Det"};
   TTreeReaderValue<Int_t> Lead_Collar_Det = {fReader, "dets.sd.Lead_Collar_Det"};
   TTreeReaderValue<Int_t> Lead_Collar_Poly_Shield_Det = {fReader, "dets.sd.Lead_Collar_Poly_Shield_Det"};
   TTreeReaderValue<Int_t> collDet = {fReader, "dets.sd.collDet"};
   TTreeReaderValue<Int_t> coilDet = {fReader, "dets.sd.coilDet"};
   TTreeReaderValue<Int_t> Shielding_Block_US_1_Det = {fReader, "dets.sd.Shielding_Block_US_1_Det"};
   TTreeReaderValue<Int_t> Shielding_Block_US_2_Det = {fReader, "dets.sd.Shielding_Block_US_2_Det"};
   TTreeReaderValue<Int_t> Poly_Shielding_Block_US_1_2_Det = {fReader, "dets.sd.Poly_Shielding_Block_US_1_2_Det"};
   TTreeReaderValue<Int_t> Shielding_Block_3_Det = {fReader, "dets.sd.Shielding_Block_3_Det"};
   TTreeReaderValue<Int_t> Poly_Shielding_Block_3_Det = {fReader, "dets.sd.Poly_Shielding_Block_3_Det"};
   TTreeReaderValue<Int_t> Poly_Shielding_Block_4_Det = {fReader, "dets.sd.Poly_Shielding_Block_4_Det"};
   TTreeReaderValue<Int_t> Shielding_Block_4_Det = {fReader, "dets.sd.Shielding_Block_4_Det"};
   TTreeReaderValue<Int_t> Shielding_Block_Roof_Det = {fReader, "dets.sd.Shielding_Block_Roof_Det"};
   TTreeReaderValue<Int_t> Shielding_Block_PolyRoof_Det = {fReader, "dets.sd.Shielding_Block_PolyRoof_Det"};
   TTreeReaderValue<Int_t> Shielding_Block_Local_poly = {fReader, "dets.sd.Shielding_Block_Local_poly"};
   TTreeReaderValue<Int_t> Aluminum_Can_Det = {fReader, "dets.sd.Aluminum_Can_Det"};
   TTreeReaderValue<Int_t> Lead_shldtube = {fReader, "dets.sd.Lead_shldtube"};
   TTreeReaderValue<Int_t> logicWasher_5 = {fReader, "dets.lv.logicWasher_5"};
   TTreeReaderValue<Int_t> beamPipeDS_logical = {fReader, "dets.lv.beamPipeDS_logical"};
   TTreeReaderValue<Int_t> boxtgtShield1_logic = {fReader, "dets.lv.boxtgtShield1_logic"};
   TTreeReaderValue<Int_t> boxtgtPolyShield1_logic = {fReader, "dets.lv.boxtgtPolyShield1_logic"};
   TTreeReaderValue<Int_t> boxShieldColl1_logic = {fReader, "dets.lv.boxShieldColl1_logic"};
   TTreeReaderValue<Int_t> boxPolyShield_LeadCollar_logic = {fReader, "dets.lv.boxPolyShield_LeadCollar_logic"};
   TTreeReaderValue<Int_t> logicUScol1fin_1 = {fReader, "dets.lv.logicUScol1fin_1"};
   TTreeReaderValue<Int_t> logicUScoll_1 = {fReader, "dets.lv.logicUScoll_1"};
   TTreeReaderValue<Int_t> logicUScoilunion_0 = {fReader, "dets.lv.logicUScoilunion_0"};
   TTreeReaderValue<Int_t> logicUScollunion_1 = {fReader, "dets.lv.logicUScollunion_1"};
   TTreeReaderValue<Int_t> logiccoll2trap = {fReader, "dets.lv.logiccoll2trap"};
   TTreeReaderValue<Int_t> logicWasher_1 = {fReader, "dets.lv.logicWasher_1"};
   TTreeReaderValue<Int_t> logicWasher_2 = {fReader, "dets.lv.logicWasher_2"};
   TTreeReaderValue<Int_t> logicUScoilunion_1 = {fReader, "dets.lv.logicUScoilunion_1"};
   TTreeReaderValue<Int_t> logicUScoilunion_2 = {fReader, "dets.lv.logicUScoilunion_2"};
   TTreeReaderValue<Int_t> logicUScoilunion_3 = {fReader, "dets.lv.logicUScoilunion_3"};
   TTreeReaderValue<Int_t> logicUScoilunion_4 = {fReader, "dets.lv.logicUScoilunion_4"};
   TTreeReaderValue<Int_t> logicUScoilunion_5 = {fReader, "dets.lv.logicUScoilunion_5"};
   TTreeReaderValue<Int_t> logicUScoilunion_6 = {fReader, "dets.lv.logicUScoilunion_6"};
   TTreeReaderValue<Int_t> boxUSShieldColl1_logic = {fReader, "dets.lv.boxUSShieldColl1_logic"};
   TTreeReaderValue<Int_t> boxUSShieldColl2_logic = {fReader, "dets.lv.boxUSShieldColl2_logic"};
   TTreeReaderValue<Int_t> boxUSPolyShield1_logic = {fReader, "dets.lv.boxUSPolyShield1_logic"};
   TTreeReaderValue<Int_t> logicDScoil_0 = {fReader, "dets.lv.logicDScoil_0"};
   TTreeReaderValue<Int_t> logicWasher_3 = {fReader, "dets.lv.logicWasher_3"};
   TTreeReaderValue<Int_t> logicWasher_4 = {fReader, "dets.lv.logicWasher_4"};
   TTreeReaderValue<Int_t> logicDScoil_1 = {fReader, "dets.lv.logicDScoil_1"};
   TTreeReaderValue<Int_t> logicDScoil_2 = {fReader, "dets.lv.logicDScoil_2"};
   TTreeReaderValue<Int_t> logicDScoil_3 = {fReader, "dets.lv.logicDScoil_3"};
   TTreeReaderValue<Int_t> logicDScoil_4 = {fReader, "dets.lv.logicDScoil_4"};
   TTreeReaderValue<Int_t> logicDScoil_5 = {fReader, "dets.lv.logicDScoil_5"};
   TTreeReaderValue<Int_t> logicDScoil_6 = {fReader, "dets.lv.logicDScoil_6"};
   TTreeReaderValue<Int_t> logicDScoil_7 = {fReader, "dets.lv.logicDScoil_7"};
   TTreeReaderValue<Int_t> logicDScoil_8 = {fReader, "dets.lv.logicDScoil_8"};
   TTreeReaderValue<Int_t> logicDScoil_9 = {fReader, "dets.lv.logicDScoil_9"};
   TTreeReaderValue<Int_t> logicDScoil_10 = {fReader, "dets.lv.logicDScoil_10"};
   TTreeReaderValue<Int_t> logicDScoil_11 = {fReader, "dets.lv.logicDScoil_11"};
   TTreeReaderValue<Int_t> logicDScoil_12 = {fReader, "dets.lv.logicDScoil_12"};
   TTreeReaderValue<Int_t> logicDScoil_13 = {fReader, "dets.lv.logicDScoil_13"};
   TTreeReaderValue<Int_t> boxDSShieldColl1_logic = {fReader, "dets.lv.boxDSShieldColl1_logic"};
   TTreeReaderValue<Int_t> logicDScoll_5 = {fReader, "dets.lv.logicDScoll_5"};
   TTreeReaderValue<Int_t> logicPDScollunion_1 = {fReader, "dets.lv.logicPDScollunion_1"};
   TTreeReaderValue<Int_t> logicpcoll2trap = {fReader, "dets.lv.logicpcoll2trap"};
   TTreeReaderValue<Int_t> boxDSPolyShield1_logic = {fReader, "dets.lv.boxDSPolyShield1_logic"};
   TTreeReaderValue<Int_t> boxDSPolyShield2_logic = {fReader, "dets.lv.boxDSPolyShield2_logic"};
   TTreeReaderValue<Int_t> boxDSShield1_logic = {fReader, "dets.lv.boxDSShield1_logic"};
   TTreeReaderValue<Int_t> boxDSShield1_roof_logic = {fReader, "dets.lv.boxDSShield1_roof_logic"};
   TTreeReaderValue<Int_t> boxDSShield1_polyroof_logic = {fReader, "dets.lv.boxDSShield1_polyroof_logic"};
   TTreeReaderValue<Int_t> boxDSShield_local_logic = {fReader, "dets.lv.boxDSShield_local_logic"};
   TTreeReaderValue<Int_t> boxDSShield_polylocal_logic = {fReader, "dets.lv.boxDSShield_polylocal_logic"};
   TTreeReaderValue<Int_t> boxAlCan_logic = {fReader, "dets.lv.boxAlCan_logic"};
   TTreeReaderValue<Int_t> DSShield_Tube_logic = {fReader, "dets.lv.DSShield_Tube_logic"};
   TTreeReaderValue<Double_t> rate = {fReader, "rate"};
   TTreeReaderValue<Double_t> A = {fReader, "A"};
   TTreeReaderValue<Double_t> Am = {fReader, "Am"};
   TTreeReaderValue<Double_t> xs = {fReader, "xs"};
   TTreeReaderValue<Double_t> Q2 = {fReader, "Q2"};
   TTreeReaderValue<Double_t> W2 = {fReader, "W2"};
   TTreeReaderValue<Double_t> thcom = {fReader, "thcom"};
   TTreeReaderValue<Double_t> beamp = {fReader, "beamp"};
   TTreeReaderValue<Double_t> x = {fReader, "x"};
   TTreeReaderValue<Double_t> y = {fReader, "y"};
   TTreeReaderValue<Double_t> z = {fReader, "z"};
   TTreeReaderValue<Double_t> dx = {fReader, "dx"};
   TTreeReaderValue<Double_t> dy = {fReader, "dy"};
   TTreeReaderValue<Double_t> dz = {fReader, "dz"};
   TTreeReaderValue<Double_t> th = {fReader, "th"};
   TTreeReaderValue<Double_t> ph = {fReader, "ph"};
   TTreeReaderArray<Int_t> part_pid = {fReader, "part.pid"};
   TTreeReaderArray<Double_t> part_vx = {fReader, "part.vx"};
   TTreeReaderArray<Double_t> part_vy = {fReader, "part.vy"};
   TTreeReaderArray<Double_t> part_vz = {fReader, "part.vz"};
   TTreeReaderArray<Double_t> part_px = {fReader, "part.px"};
   TTreeReaderArray<Double_t> part_py = {fReader, "part.py"};
   TTreeReaderArray<Double_t> part_pz = {fReader, "part.pz"};
   TTreeReaderArray<Double_t> part_sx = {fReader, "part.sx"};
   TTreeReaderArray<Double_t> part_sy = {fReader, "part.sy"};
   TTreeReaderArray<Double_t> part_sz = {fReader, "part.sz"};
   TTreeReaderArray<Double_t> part_th = {fReader, "part.th"};
   TTreeReaderArray<Double_t> part_ph = {fReader, "part.ph"};
   TTreeReaderArray<Double_t> part_p = {fReader, "part.p"};
   TTreeReaderArray<Double_t> part_tpx = {fReader, "part.tpx"};
   TTreeReaderArray<Double_t> part_tpy = {fReader, "part.tpy"};
   TTreeReaderArray<Double_t> part_tpz = {fReader, "part.tpz"};
   TTreeReaderArray<Int_t> part_trid = {fReader, "part.trid"};
   TTreeReaderArray<vector<double>> part_tjx = {fReader, "part.tjx"};
   TTreeReaderArray<vector<double>> part_tjy = {fReader, "part.tjy"};
   TTreeReaderArray<vector<double>> part_tjz = {fReader, "part.tjz"};
   TTreeReaderArray<Int_t> hit_det = {fReader, "hit.det"};
   TTreeReaderArray<Int_t> hit_id = {fReader, "hit.id"};
   TTreeReaderArray<Int_t> hit_trid = {fReader, "hit.trid"};
   TTreeReaderArray<Int_t> hit_pid = {fReader, "hit.pid"};
   TTreeReaderArray<Int_t> hit_gen = {fReader, "hit.gen"};
   TTreeReaderArray<Int_t> hit_mtrid = {fReader, "hit.mtrid"};
   TTreeReaderArray<Double_t> hit_t = {fReader, "hit.t"};
   TTreeReaderArray<Double_t> hit_x = {fReader, "hit.x"};
   TTreeReaderArray<Double_t> hit_y = {fReader, "hit.y"};
   TTreeReaderArray<Double_t> hit_z = {fReader, "hit.z"};
   TTreeReaderArray<Double_t> hit_xl = {fReader, "hit.xl"};
   TTreeReaderArray<Double_t> hit_yl = {fReader, "hit.yl"};
   TTreeReaderArray<Double_t> hit_zl = {fReader, "hit.zl"};
   TTreeReaderArray<Double_t> hit_r = {fReader, "hit.r"};
   TTreeReaderArray<Double_t> hit_ph = {fReader, "hit.ph"};
   TTreeReaderArray<Double_t> hit_px = {fReader, "hit.px"};
   TTreeReaderArray<Double_t> hit_py = {fReader, "hit.py"};
   TTreeReaderArray<Double_t> hit_pz = {fReader, "hit.pz"};
   TTreeReaderArray<Double_t> hit_pxl = {fReader, "hit.pxl"};
   TTreeReaderArray<Double_t> hit_pyl = {fReader, "hit.pyl"};
   TTreeReaderArray<Double_t> hit_pzl = {fReader, "hit.pzl"};
   TTreeReaderArray<Double_t> hit_sx = {fReader, "hit.sx"};
   TTreeReaderArray<Double_t> hit_sy = {fReader, "hit.sy"};
   TTreeReaderArray<Double_t> hit_sz = {fReader, "hit.sz"};
   TTreeReaderArray<Double_t> hit_p = {fReader, "hit.p"};
   TTreeReaderArray<Double_t> hit_e = {fReader, "hit.e"};
   TTreeReaderArray<Double_t> hit_m = {fReader, "hit.m"};
   TTreeReaderArray<Double_t> hit_vx = {fReader, "hit.vx"};
   TTreeReaderArray<Double_t> hit_vy = {fReader, "hit.vy"};
   TTreeReaderArray<Double_t> hit_vz = {fReader, "hit.vz"};
   TTreeReaderArray<Double_t> hit_edep = {fReader, "hit.edep"};
   TTreeReaderArray<vector<remollGenericDetectorSumByPID_t>> sum_by_pid = {fReader, "sum.by_pid"};
   TTreeReaderArray<Double_t> sum_edep = {fReader, "sum.edep"};
   TTreeReaderArray<Int_t> sum_det = {fReader, "sum.det"};
   TTreeReaderArray<Int_t> sum_vid = {fReader, "sum.vid"};


   processD(TTree * /*tree*/ =0) { }
   virtual ~processD() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(processD,0);

};

#endif

#ifdef processD_cxx
void processD::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t processD::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef processD_cxx
