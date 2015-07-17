set multiplot layout 2,2 title "Diagnostics"
set tmargin 4 #margin between graphs

set title "Momentum vs Time" font "Arial bold, 15"
unset key #remove key
set ylabel "Momentum"
set xlabel "Iteration"
plot "mom_out.dat"

set title "Kinetic Energy vs Time"
unset key
set ylabel "Kinetic Energy"
set xlabel "Iteration"
plot "ke_out.dat"

#set title "Electron Position vs Time"
#unset key
#plot "e_data.dat"

#set title "Ion position vs Time"
#unset key
#plot "pos_out.dat"

#set title "E(k) vs k"
#unset key
#plot "e_k_data.dat"

set title "Electric Potential Energy vs time"
unset key
set ylabel "EPE"
set xlabel "Iteration"
plot "pe_out.dat"

#set title "Total Energy vs Time"
#unset key
#plot "total_nrg.dat"

set title "Total Energy vs Time"
unset key
set ylabel "Total Energy"
set xlabel "Iteration"
plot "e_out.dat"

#set title "Power Spectrum"
#unset key
#set ylabel "Power Spectral Density"
#set xlabel "Grid Point"
#plot "psd_out.dat"

unset multiplot
