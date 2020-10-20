#set terminal postfile       (These commented lines would be used to )
#set output  "d1_plot.ps"    (generate a postscript file.            )
#set   autoscale                        # scale axes automatically
set xlabel "x(m)"
set ylabel "y(m)"
set zlabel "z(m)"
set xrange [-50:50]
set yrange [-50:50]
set zrange [-50:50]
# filename and n=number of lines of your data 
filedata = 'data.dat'
n = system(sprintf('cat %s | wc -l', filedata))
set term gif animate
set output 'output.gif'
do for [j=1:n:20] {
    set title 'time '.j
    splot filedata u 2:3:4 every ::1::j w l lw 2, \
          filedata u 2:3:4 every ::j::j w p pt 7 ps 2
}
