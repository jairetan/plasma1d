set multiplot layout 3,3 title "Diagnostics"
set tmargin 4 #margin between graphs

set title "Density distribution 0"
unset key
set ylabel "Charge Density"
set xlabel "Grid Point"
plot "0density_out.dat"

set title "Density distribution 1"
unset key
set ylabel "Charge Density"
set xlabel "Grid Point"
plot "1density_out.dat"

set title "Density distribution 2"
unset key
set ylabel "Charge Density"
set xlabel "Grid Point"
plot "2density_out.dat"

set title "Density distribution 3"
unset key
set ylabel "Charge Density"
set xlabel "Grid Point"
plot "3density_out.dat"

set title "Density distribution 4"
unset key
set ylabel "Charge Density"
set xlabel "Grid Point"
plot "4density_out.dat"

set title "Density distribution 5"
unset key
set ylabel "Charge Density"
set xlabel "Grid Point"
plot "5density_out.dat"

set title "Density distribution 6"
unset key
set ylabel "Charge Density"
set xlabel "Grid Point"
plot "6density_out.dat"

set title "Density distribution 7"
unset key
set ylabel "Charge Density"
set xlabel "Grid Point"
plot "7density_out.dat"

set title "Density distribution 8"
unset key
set ylabel "Charge Density"
set xlabel "Grid Point"
plot "8density_out.dat"

set title "Density distribution 9"
unset key
set ylabel "Charge Density"
set xlabel "Grid Point"
plot "9density_out.dat"


unset multiplot
