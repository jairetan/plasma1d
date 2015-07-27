#!/bin/bash
make clean
make
./run
cd data
../plot_all.sh
