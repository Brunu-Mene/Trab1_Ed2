#!/bin/bash
ORDENACAO="-2e"

make

echo -e '\n\n insertionsort'

# echo -e '\n\n arquivo 100000.txt'
# ./a.out "$ORDENACAO" 1000 ./testes/aleatorio1/100000.txt
# ./a.out "$ORDENACAO" 1000 ./testes/invertido/100000.txt
# ./a.out "$ORDENACAO" 1000 ./testes/ordenado/100000.txt
# ./a.out "$ORDENACAO" 1000 ./testes/quase-ordenado/100000.txt

# echo -e '\n\n arquivo 100000.txt'
# ./a.out "$ORDENACAO" 100000 ./testes/aleatorio1/100000.txt
# ./a.out "$ORDENACAO" 40000 ./testes/invertido/100000.txt
# ./a.out "$ORDENACAO" 40000 ./testes/ordenado/100000.txt
# ./a.out "$ORDENACAO" 40000 ./testes/quase-ordenado/100000.txt

echo -e '\n\n arquivo 1000000.txt'
./a.out "$ORDENACAO" 10000 ./testes/aleatorio1/1000000.txt
./a.out "$ORDENACAO" 10000 ./testes/invertido/1000000.txt
./a.out "$ORDENACAO" 10000 ./testes/ordenado/1000000.txt
./a.out "$ORDENACAO" 10000 ./testes/quase-ordenado/1000000.txt

echo -e '\n\n arquivo 1000000.txt'
./a.out "$ORDENACAO" 700000 ./testes/aleatorio1/1000000.txt
#./a.out "$ORDENACAO" 700000 ./testes/invertido/1000000.txt
./a.out "$ORDENACAO" 700000 ./testes/ordenado/1000000.txt
./a.out "$ORDENACAO" 700000 ./testes/quase-ordenado/1000000.txt

echo -e '\n\n arquivo 10000000.txt'
./a.out "$ORDENACAO" 10000 ./testes/aleatorio1/10000000.txt
./a.out "$ORDENACAO" 10000 ./testes/invertido/10000000.txt
./a.out "$ORDENACAO" 10000 ./testes/ordenado/10000000.txt
./a.out "$ORDENACAO" 10000 ./testes/quase-ordenado/10000000.txt

echo -e '\n\n arquivo 10000000.txt'
./a.out "$ORDENACAO" 130000 ./testes/aleatorio1/10000000.txt
./a.out "$ORDENACAO" 130000 ./testes/invertido/10000000.txt
./a.out "$ORDENACAO" 130000 ./testes/ordenado/10000000.txt
./a.out "$ORDENACAO" 130000 ./testes/quase-ordenado/10000000.txt