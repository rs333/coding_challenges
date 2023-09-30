#!/bin/bash
if [[ $# -ne 2 ]]
then
  echo "usage: newcontest.sh <problem_number> <description>"
  exit
fi

if (( $1 < 00001 || $1 > 99999 ))
then
  echo "<problem_number> must be in range of 00001-99999"
  exit
fi
problem_number=`printf "%05d" $1`
source_directory="problems\\00000_ProblemName"
directory="contests\\weekly\\${problem_number}"

if [[ $2 == b* ]]
then
  directory="contests\\biweekly\\${problem_number}"
fi

if [[ -d $directory || -s $directory ]]
then
  echo "Directory \"$directory\" already exists"
else 
  echo Creating $directory
  mkdir $directory
fi

for a in {1..4}
do
  if [[ -f ${directory}\\${problem_number}_${a}.cpp ]]
  then
    echo ${directory}\\${problem_number}_${a}.cpp already exists.
  else
    cp ${source_directory}\\00000.cpp ${directory}\\${problem_number}_${a}.cpp
  fi
  if [[ -f ${directory}\\${problem_number}_${a}.input ]]
  then
    echo ${directory}\\${problem_number}_${a}.input already exists.
  else
    touch ${directory}\\${problem_number}_${a}.input
  fi
done


