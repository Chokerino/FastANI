#!/bin/bash

make clean
./bootstrap.sh
./configure --with-gsl=/global/homes/b/bhavay07/gsl/
make
