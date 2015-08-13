#!/bin/bash
trash data/*.dat
cd build
make -j 4
cd ..
./run

