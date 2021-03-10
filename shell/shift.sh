#!/bin/bash
# an exmple for shift-position segment
if [ -z $1 ]; then
  echo "$0 + some arguments"
  exit 0
else
  echo "argument number is: $#"
  i=0
  while (( $# > 0 )); do
    echo "argument $i : $1"
    (( ++i ))
    shift
    done
fi


