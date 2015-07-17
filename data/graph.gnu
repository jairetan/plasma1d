set multiplot layout 3,3 title "Diagnostics"
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

set title "Final Potential vs Position"
unset key
set ylabel "Potential"
set xlabel "Grid Point"
plot "pot_out.dat"

set title "Final Electric Field vs Position"
unset key
set ylabel "Electric Field"
set xlabel "Grid Point"
plot "field_out.dat"

set title "Electric Potential Energy vs time"
unset key
set ylabel "EPE"
set xlabel "Iteration"
plot "pe_out.dat"

set title "Final velocity Distribution"
unset key
set ylabel "Velocity"
set xlabel "Grid Point"
plot "vel_out.dat"

#set title "Total Energy vs Time"
#unset key
#plot "total_nrg.dat"

set title "Density distribution"
unset key
set ylabel "Charge Density"
set xlabel "Grid Point"
plot "density_out.dat"

set title "Power Spectrum"
unset key
set ylabel "Power Spectral Density"
set xlabel "Grid Point"
plot "psd_out.dat"

unset multiplot
