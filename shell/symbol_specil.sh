#!/bin/bash

:<<!
    test shell script' symbol specil
    测试shell脚本中的特殊符号使用
!

abc=123

echo ${abc}23423
echo "$abc"23423

:<<!
if (($1 > $2)); then
    echo "$1 large then $2"
else
    echo "$2 large then $1"
fi
`pwd`
if [ $1 > $2 ]; then
    echo "$1 large then $2"
else
    echo "$2 large then $1"
fi
!

echo '$$'="$$"
echo '$!'="$!"
echo '$@'="$@"
echo '$*'="$*"
echo '$#'="$#"
echo '$?'="$?"
echo '$0'="$0"
echo '$1'="$1"
