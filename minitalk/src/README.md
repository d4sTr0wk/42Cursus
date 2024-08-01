client.c: Envía una señal SIGUSR1 o SIGUSR2 al servidor dependiendo del bit que lea de un caracter que forma parte del envío total de un mensaje. SIGUSR1 si el bit es 1 y SIGUSR2 si el bit es 0.

server.c: Recibe la señal SIGUSR1 o SIGUSR2 y dependiendo de cuál lo añade al mensaje que está recibiendo para mostrarlo después de recibir el mensaje completo.
