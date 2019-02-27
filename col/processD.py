import sys
import os
import ROOT as R

R.gROOT.SetBatch(1)
#R.TProof.Open("", "workers=4")
ch=R.TChain("T")
#T.SetProof()
ch.Add(sys.argv[1])



#selectorPath = "/home/rahmans/analysis/BeamSteeringAnalysis/colprocessD.C+"
#sel = R.TSelector.GetSelector(selectorPath);
#sel.SetOption(sys.argv[2]+","+sys.argv[3])
#print("selector used is: "+ selectorPath+" with option "+sel.GetOption()) 

#pool=R.TTreeProcessorMP(4)

#pool.Process(ch, sel, "T",4,0);
#sel.GetOutputList().Delete();




ch.Process("/home/rahmans/analysis/BeamSteeringAnalysis/col/processD.C+",sys.argv[2]+","+sys.argv[3])


