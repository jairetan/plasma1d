#!/bin/bash
rm data/*.dat
cd build
make -j 4
cd ..
./run

