#!/bin/bash

# Loop infinito que ejecuta el programa con GDB
while true; do
    # Ejecuta el programa dentro de GDB y pasa los argumentos
    gdb --batch --ex "run 4 310 200 100" --ex "bt" --ex "quit" ./philo

    # Verifica si el programa terminó con un core dump
    if [ $? -eq 139 ]; then
        echo "Core dumped detectado. El programa se ha caído."
        break
    fi
done

