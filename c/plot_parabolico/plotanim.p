#set terminal postfile       (These commented lines would be used to )
#set output  "d1_plot.ps"    (generate a postscript file.            )
#set   autoscale                        # scale axes automatically
set xlabel "x(m)"
set ylabel "y(m)"
set zlabel "z(m)"
set xrange [-500:500]
set yrange [-500:500]
set zrange [0:500]
# filename and n=number of lines of your data 
filedata = 'parabolico.dat'
n = system(sprintf('cat %s | wc -l', filedata))
set term gif animate
set output 'output1.gif'
do for [j=1:n] {
    set title 'time '.j
    splot filedata u 2:3:4 every ::1::j w l lw 2, \
          filedata u 2:3:4 every ::j::j w p pt 7 ps 2
}
