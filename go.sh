#!/bin/bash
make clean
make -j 4> make_output.txt
./run

