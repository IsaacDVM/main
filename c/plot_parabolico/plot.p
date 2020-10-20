#set terminal postfile       (These commented lines would be used to )
#set output  "d1_plot.ps"    (generate a postscript file.            )
#set   autoscale                        # scale axes automatically
set title "Trajectory"
set xlabel "x(m)"
set ylabel "y(m)"
set zlabel "z(m)"
splot "parabolico.dat" u 2:3:4 with lines
pause -1 "Hit any key to continue"
