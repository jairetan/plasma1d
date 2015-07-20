set multiplot layout 3,3 title "Diagnostics"
set tmargin 4 #margin between graphs

set title "Field 0"
unset key
set ylabel "Field"
set xlabel "Grid Point"
plot "0field_out.dat"

set title "Field 1"
unset key
set ylabel "Field"
set xlabel "Grid Point"
plot "1field_out.dat"

set title "Field 2"
unset key
set ylabel "Field"
set xlabel "Grid Point"
plot "2field_out.dat"

set title "Field 3"
unset key
set ylabel "Field"
set xlabel "Grid Point"
plot "3field_out.dat"

set title "Field 4"
unset key
set ylabel "Field"
set xlabel "Grid Point"
plot "4field_out.dat"

set title "Field 5"
unset key
set ylabel "Field"
set xlabel "Grid Point"
plot "5field_out.dat"

set title "Field 6"
unset key
set ylabel "Field"
set xlabel "Grid Point"
plot "6field_out.dat"

set title "Field 7"
unset key
set ylabel "Field"
set xlabel "Grid Point"
plot "7field_out.dat"

set title "Field 8"
unset key
set ylabel "Field"
set xlabel "Grid Point"
plot "8field_out.dat"

set title "Field 9"
unset key
set ylabel "Field"
set xlabel "Grid Point"
plot "9field_out.dat"


unset multiplot
