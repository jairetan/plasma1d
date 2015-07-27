set multiplot layout 3,3 title "Diagnostics"
set tmargin 4 #margin between graphs

set title "Mode 0"
unset key
set ylabel "Mode"
set xlabel "Grid Point"
plot "0mode_out.dat"

set title "Mode 1"
unset key
set ylabel "Mode"
set xlabel "Grid Point"
plot "1mode_out.dat"

set title "Mode 2"
unset key
set ylabel "Mode"
set xlabel "Grid Point"
plot "2mode_out.dat"

set title "Mode 3"
unset key
set ylabel "Mode"
set xlabel "Grid Point"
plot "3mode_out.dat"

set title "Mode 4"
unset key
set ylabel "Mode"
set xlabel "Grid Point"
plot "4mode_out.dat"

set title "Mode 5"
unset key
set ylabel "Mode"
set xlabel "Grid Point"
plot "5mode_out.dat"

set title "Mode 6"
unset key
set ylabel "Mode"
set xlabel "Grid Point"
plot "6mode_out.dat"

set title "Mode 7"
unset key
set ylabel "Mode"
set xlabel "Grid Point"
plot "7mode_out.dat"

set title "Mode 8"
unset key
set ylabel "Mode"
set xlabel "Grid Point"
plot "8mode_out.dat"

set title "Mode 9"
unset key
set ylabel "Mode"
set xlabel "Grid Point"
plot "9mode_out.dat"


unset multiplot
