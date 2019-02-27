import sys
import os
import ROOT as R

filename=sys.argv[1]
plot= sys.argv[2]
cut= sys.argv[3]
option= sys.argv[4]





T=R.TChain("T")


n=T.Add(filename)
c=R.TCanvas("c","c", 800, 600)
T.Draw(plot,cut,option)
c.Print("plot.png")





	

