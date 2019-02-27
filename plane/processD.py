import sys
import os
import ROOT as R



T=R.TChain("T")
T.Add(sys.argv[1])


T.Process("/home/rahmans/analysis/BeamSteeringAnalysis/plane/processD.C+",sys.argv[2]+","+sys.argv[3])
