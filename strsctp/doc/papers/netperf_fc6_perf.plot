set terminal fig color small portrait fontsize 9 inches size 4.5 2.4
set output 'netperf_fc6_perf.fig'
set nologscale
set logscale x
set ylabel 'Message Rate (Messages per Second)'
set y2label '|'
set xlabel 'Message Size (Bytes)'
set grid x y
set key bottom left Right noreverse
set xtics nomirror (1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192)
set ytics nomirror
set border 3 lw 1
plot \
     'netperf_fc6.dat' using 1:($4/10) smooth unique title "SCTP Streams Tx" with linespoints lt 6,\
     'netperf_fc6.dat' using 1:($5/10) smooth unique title "SCTP Streams Rx" with linespoints lt 5,\
     'netperf_fc6.dat' using 1:($6/10) smooth unique title "TCP Sockets Tx" with linespoints lt 4,\
     'netperf_fc6.dat' using 1:($7/10) smooth unique title "TCP Sockets Rx" with linespoints lt 3,\
     'netperf_fc6.dat' using 1:($2/10) smooth unique title "TCP XTIoS Tx"   with linespoints lt 1,\
     'netperf_fc6.dat' using 1:($3/10) smooth unique title "TCP XTIoS Rx"   with linespoints lt 2