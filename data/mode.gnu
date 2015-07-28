set multiplot layout 3,3 title "Mode Energy Plots"
set tmargin 4 #margin between graphs

set title "Mode 0"
unset key
set ylabel "U(k)"
set xlabel "Iteration"
plot "0mode_out.dat"

set title "Mode 1"
unset key
set ylabel "U(k)"
set xlabel "Iteration"
plot "1mode_out.dat"

set title "Mode 2"
unset key
set ylabel "U(k)"
set xlabel "Iteration"
plot "2mode_out.dat"

set title "Mode 3"
unset key
set ylabel "U(k)"
set xlabel "Iteration"
plot "3mode_out.dat"

set title "Mode 4"
unset key
set ylabel "U(k)"
set xlabel "Iteration"
plot "4mode_out.dat"

set title "Mode 5"
unset key
set ylabel "U(k)"
set xlabel "Iteration"
plot "5mode_out.dat"

set title "Mode 6"
unset key
set ylabel "U(k)"
set xlabel "Iteration"
plot "6mode_out.dat"

set title "Mode 7"
unset key
set ylabel "U(k)"
set xlabel "Iteration"
plot "7mode_out.dat"

set title "Mode 8"
unset key
set ylabel "U(k)"
set xlabel "Iteration"
plot "8mode_out.dat"

set title "Mode 9"
unset key
set ylabel "U(k)"
set xlabel "Iteration"
plot "9mode_out.dat"


unset multiplot
