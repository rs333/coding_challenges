#!/bin/bash
if [[ $# -ne 2 ]]
then
  echo "usage: newproblem.sh <problem_number> <description>"
  exit
fi

if (( $1 < 00001 || $1 > 99999 ))
then
  echo "<problem_number> must be in range of 00001-99999"
  exit
fi
problem_number=`printf "%05d" $1`
source_directory="problems\\00000_ProblemName"
directory="problems\\${problem_number}_$2"
if [[ -d $directory || -s $directory ]]
then
  echo "Directory \"$directory\" already exists"
else 
  echo Creating $directory
  mkdir $directory
fi

if [[ -f ${directory}\\${problem_number}.cpp ]]
then
  echo ${directory}\\${problem_number}.cpp already exists.
else
  cp ${source_directory}\\00000.cpp ${directory}\\${problem_number}.cpp
fi

if [[ -f ${directory}\\${problem_number}.input ]]
then
  echo ${directory}\\${problem_number}.input already exists.
else
  touch ${directory}\\${problem_number}.input
fi
