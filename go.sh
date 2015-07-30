#!/bin/bash
make clean
make > make_output.txt
./run
cd data
../plot_all.sh
