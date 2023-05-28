#!/bin/bash

make

./antman/antman text.txt > compressed.txt
./giantman/giantman text.txt > uncompressed.txt

