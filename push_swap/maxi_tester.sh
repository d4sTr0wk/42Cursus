#!/bin/bash

if [ $# -ne 4 ]; then
    echo "Error: Invalid number of arguments"
    exit 1
fi

num_iteraciones=$1
NUM1=$2
NUM2=$3
limite_acciones=$4
timeout=5

for i in $(seq 1 $num_iteraciones); do
	nums=$(seq $NUM1 $NUM2 | shuf | tr '\n' ' ')
	check_time=$(timeout $timeout ./push_swap $nums > /dev/null)
    	if [[ $check_time -le $timeout && $(./push_swap $nums | wc -l) -le $limite_acciones ]];
    	then
		echo -e "\e[32mIteración $i: OK, $(./push_swap $nums | wc -l)\n\e[34m$nums\e[0m\n\e[0m"
    	else
		echo -e "\e[31mIteración $i: KO, $(./push_swap $nums | wc -l)\n$nums\n\e[0m"
    	fi
done
