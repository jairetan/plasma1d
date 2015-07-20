set multiplot layout 3,3 title "Diagnostics"
set tmargin 4 #margin between graphs

set title "Phase 0"
unset key
set ylabel "Velocity"
set xlabel "Position"
plot "0phase_out.dat"

set title "Phase 1"
unset key
set ylabel "Velocity"
set xlabel "Position"
plot "1phase_out.dat"

set title "Phase 2"
unset key
set ylabel "Velocity"
set xlabel "Position"
plot "2phase_out.dat"

set title "Phase 3"
unset key
set ylabel "Velocity"
set xlabel "Position"
plot "3phase_out.dat"

set title "Phase 4"
unset key
set ylabel "Velocity"
set xlabel "Position"
plot "4phase_out.dat"

set title "Phase 5"
unset key
set ylabel "Velocity"
set xlabel "Position"
plot "5phase_out.dat"

set title "Phase 6"
unset key
set ylabel "Velocity"
set xlabel "Position"
plot "6phase_out.dat"

set title "Phase 7"
unset key
set ylabel "Velocity"
set xlabel "Position"
plot "7phase_out.dat"

set title "Phase 8"
unset key
set ylabel "Velocity"
set xlabel "Position"
plot "8phase_out.dat"

set title "Phase 9"
unset key
set ylabel "Velocity"
set xlabel "Position"
plot "9phase_out.dat"


unset multiplot
