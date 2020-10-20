#set terminal postfile       (These commented lines would be used to )
#set output  "d1_plot.ps"    (generate a postscript file.            )
set title "Trajectory"
set xlabel "x(m)"
set ylabel "y(m)"
set zlabel "z(m)"
plot "traj3D.txt" u 2:3:4
pause -1 "Hit any key to continue"
