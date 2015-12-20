import sys
from ROOT import gSystem
gSystem.Load("libMIP_meep")
from ROOT import sample

try:

    print "PyROOT recognized your class %s" % str(sample)

except NameError:

    print "Failed importing meep..."

sys.exit(0)

