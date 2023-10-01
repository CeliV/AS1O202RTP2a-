#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_THREADS 2
#define CANTIDAD_INICIAL_HAMBURGUESAS 20

int cantidad_restante_hamburguesas = CANTIDAD_INICIAL_HAMBURGUESAS 
int TURNO = 0;

void *comer_hamburguesa(void *tid) {
    while (1) { // Repetir infinitamente hasta que se fuerce la terminación del hilo con pthread_exit

        if (TURNO == (int)tid) {
            if (cantidad_restante_hamburguesas > 0) {
                printf("Hola! Soy el hilo(comensal) %d, me voy a comer una hamburguesa! Quedan %d hamburguesas\n", (int)tid, cantidad_restante_hamburguesas);
                cantidad_restante_hamburguesas--; // Me como una hamburguesa
                if (TURNO == 0) {
                    TURNO = 1;
                } else {
                    TURNO = 0;
                }
            } else {
                printf("SE TERMINARON LAS HAMBURGUESAS :( \n");
                if (TURNO == 0) {
                    TURNO = 1;
                } else {
                    TURNO = 0;
                }
                pthread_exit(NULL); // Forzar terminación del hilo
            }
        }
    }
}

int main() {
    pthread_t threads[NUMBER_OF_THREADS];
    int i;

    for (i = 0; i < NUMBER_OF_THREADS; i++) {
        int rc = pthread_create(&threads[i], NULL, comer_hamburguesa, (void *)i);
        if (rc) {
            printf("Error al crear el hilo %d\n", i);
            exit(-1);
        }
    }

    for (i = 0; i < NUMBER_OF_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_exit(NULL);
    return 0;
}
#include <stdlib.h> 
#define NUMBER_OF_THREADS 2
#define CANTIDAD_INICIAL_HAMBURGUESAS 20
int cantidad_restante_hamburguesas = CANTIDAD_INICIAL_HAMBURGUESAS; 

int turno = 0;

void *comer_hamburguesa(void *tid) { 
while(1 == 1){ //repetir infinitamente hasta que fuerce la terminacion del hilo con pthread_exit
	
	if (cantidad_restante_hamburguesas > 0) {
	printf("Hola! soy el hilo(comensal) %d , me voy a comer una hamburguesa ! ya que todavia queda/n %d \n",tid, cantidad_restante_hamburguesas);
	cantidad_restante_hamburguesas--; //me como una hamburguesa
	} else
	{
	printf("SE TERMINARON LAS HAMBURGUESAS :( \n"); 
	
	pthread_exit(NULL); //forzar terminacion del hilo
	}

}