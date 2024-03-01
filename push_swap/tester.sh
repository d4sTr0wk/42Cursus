# Este es un programa tester que ejecutará una línea múliplles veces con argumentos diferentes para ver si el número que devuelve alguna vez supera un límite.

# El programa que vamos a testear es el siguiente:

# Path: programa.sh

#!/bin/bash


if [ $# -ne 3 ]; then
    echo "Error: número de argumentos incorrecto"
    exit 1
fi

num_iteraciones=$1
NUMS=$2
num_acciones_limite=$3
timeout_segundos=5
tmp_file=$(mktemp)

for ((i = 1; i <= num_iteraciones; i++)); do
	numeros=$(src/tester $NUMS | awk '{for(i=1;i<=NF;i++) print $i}' | sort | uniq | shuf | tr '\n' ' ')
	timeout $timeout_segundos ./push_swap $numeros > "$tmp_file" 2>/dev/null
	time_res=$?
	acciones=$(cat $tmp_file | echo "$(wc -l) - 100 - 3" | bc)
	if [[ $time_res -eq 0 && $acciones -lt $num_acciones_limite ]]; then
		echo -e "\e[32m$i: $acciones\e[0m"
	else
		if [[ $time_res -ne 0 ]]; then
			echo -e "\e[33m$i: TIMEOUT_ERROR \n$numeros\e[0m"
		else
			echo -e "\e[31m$i: $acciones ERROR\n$numeros\e[0m"
		fi
		exit 1
	fi
	rm "$tmp_file"
done

exit 0
