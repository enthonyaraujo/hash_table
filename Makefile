run:
	gcc -Wall -Wextra -std=c11 src/main.c src/tabela.c -o tabela_hash
	./tabela_hash

clean:
	rm -rf *.o *~ printy