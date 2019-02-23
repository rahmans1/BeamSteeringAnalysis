import sys
import os
import ROOT as R


#R.TProof.Open("", "workers=4")
T=R.TChain("T")
#T.SetProof()
T.Add(sys.argv[1])


T.Process("/home/rahmans/analysis/analyse_col/processD.C",sys.argv[2]+","+sys.argv[3])
