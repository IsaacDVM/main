#set terminal postfile       (These commented lines would be used to )
#set output  "d1_plot.ps"    (generate a postscript file.            )
set   autoscale                        # scale axes automatically
set hidden3d
set title "Trajectory earth"
set xlabel "x(m)"
set ylabel "y(m)"
set zlabel "z(m)"
set xrange [-150E9:150E9]
set yrange [-150E9:150E9]
set zrange [-1:1]
splot "gravity.txt" u 2:3:4 with lines, "gravity.txt" u 8:9:10
pause -1 "Hit any key to continue"
