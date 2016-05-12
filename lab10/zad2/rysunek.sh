#!/bin/bash
gnuplot << EOF
set terminal png truecolor enhanced
set output "rys.png"
plot x-2
EOF
