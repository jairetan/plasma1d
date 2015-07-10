set multiplot layout 3,2 title "Diagnostics"
set tmargin 4 #margin between graphs

set title "Momentum vs Time"
unset key #remove key
plot "mom_out.dat"

set title "Kinetic Energy vs Time"
unset key
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
plot "pot_out.dat"

set title "Final Electric Field vs Position"
unset key
plot "field_out.dat"

set title "Electric Potential Energy vs time"
unset key
plot "pe_out.dat"

#set title "Final velocity Distribution"
#unset key
#plot "vel_out.dat"

#set title "Total Energy vs Time"
#unset key
#plot "total_nrg.dat"

set title "Density distribution"
unset key
plot "density_out.dat"


unset multiplot

