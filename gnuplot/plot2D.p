#set terminal postfile       (These commented lines would be used to )
#set output  "d1_plot.ps"    (generate a postscript file.            )
set   autoscale # scale axes automatically
#set border ls 50
set title "Funciones"
set xlabel "x(m)"
set ylabel "y(m)"
set xrange [-10:10]
set yrange [-10:10]
set xzeroaxis linetype -1 linewidth 2
set yzeroaxis linetype -1 linewidth 2
set xtics 1
set ytics 1
set mytics 1
set mxtics 1
set grid
f(x) = 7*x/3-5
g(x) = x/3+1
plot f(x) with lines notitle linestyle 2, \
   g(x) with lines notitle linestyle 1
pause -1 "Hit any key to continue"
