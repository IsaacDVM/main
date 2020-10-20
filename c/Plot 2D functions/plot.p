#set terminal postfile       (These commented lines would be used to )
#set output  "d1_plot.ps"    (generate a postscript file.            )
set   autoscale                        # scale axes automatically
set title "Funciones"
set xlabel "x(m)"
set ylabel "y(m)"
set xrange [-10:10]
set yrange [-10:10]
set xzeroaxis linetype -1 linewidth 1
set yzeroaxis linetype -1 linewidth 1
set xtics 1
set ytics 1
set mytics 1
set mxtics 1
set grid
plot "plot_2D.dat" u 1:2 with lines notitle
pause -1 "Hit any key to continue"
