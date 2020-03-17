/* Data de submissao:
 * Nome:
 * RA:
 */

#include <stdio.h>
#include <stdlib.h>
const int tam_buffer=100;

typedef struct fila{
	struct fila * ant;
	char valor;
}fila;

fila *createFila(){
	fila *f;
	f = malloc(sizeof(fila));
	f->ant = NULL;
	f->valor = 0;
	return f;
}

fila *addToFila(fila *f, char c){
	fila *p = createFila();
	p->ant = f;
	p->valor = c;
	return p;
}

fila *popFila(fila *f){
	if (f->ant == NULL) return f;
	printf("%c",f->valor);
	fila *tmp = f->ant;
	free(f);
	return popFila(tmp);
}

int main() {
  char buffer[tam_buffer];
  fgets(buffer, tam_buffer, stdin);
  fila *f = createFila();
  int i;
  for (i = 0; i < tam_buffer && buffer[i] != '\0'; i++){
  	if (buffer[i] == ' ' || buffer[i] == '\n'){
		f = popFila(f);
		printf(" ");

	}else{
		f = addToFila(f, buffer[i]);
	}
  }
  printf("\n");
  return 0;
}
