all:
	gcc -std=c11 -Wall -Wextra -O2 src/tabela.c src/aplicacao.c src/main.c -o hashapp
	gcc -std=c11 -Wall -Wextra -O2 src/tabela.c src/experimentos.c -o experimentos

run:
	mkdir -p resultados
	./experimentos > resultados/experimentos_config40.md

clean: 
	rm -rf experimentos hashapp resultados
