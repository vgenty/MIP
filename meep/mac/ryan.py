import sys
from ROOT import larlite as fmwk
from ROOT import larutil

my_proc = fmwk.ana_processor()

my_proc.enable_filter(True)

the_filter = fmwk.ThroughGoingFilter()
the_filter.Filter(True)
the_filter.Stopping(False)

# Specify IO mode
my_proc.set_io_mode(fmwk.storage_manager.kREAD)

# Specify analysis output root file name
my_proc.set_ana_output_file("out.root");


# Set input root file
for x in xrange(len(sys.argv)-1):
    my_proc.add_input_file(sys.argv[x+1])

#mcflasher = fmwk.MCFlasher()

my_proc.add_process(the_filter)
#my_proc.add_process(mcflasher)

my_proc.run()

sys.exit(0)
