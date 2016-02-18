#!/bin/bash

let t1=`date +%s`

make

let t2=`date +%s`
t3=$(( t2 - t1 ))

echo $t3

