#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Vas a implementar una cola del supermercado.
    Los datos de cada proceso a registrar son:
        - Nombre del cliente.
        - Total del carrito de la compra.
    El programa tendr  las siguientes opciones:
        1. Entrar en la cola: Solicita al usuario el nombre y el total del carrito. Pueden existir clientes con el mismo nombre. Imprime la cola despu‚s de insertar el cliente.
        2. Salir de la cola: Si la cola est  vac¡a debes informar al usuario. Sale de la cola el cliente correspondiente. Imprime la cola actual, si la cola se ha quedado vac¡a informa de ello.
        3. Salir del programa: Sale del programa.
*/

struct infoCliente
{
    char nombre[51];
    float totalCarrito;
    struct infoCliente *siguiente;
};

struct cola
{
    struct infoCliente *primero;
    struct infoCliente *ultimo;
};

int main()
{
    int opcion;
    struct cola super; //super de supermercado
    super.primero = NULL;
    super.ultimo = NULL;
    
    struct infoCliente *clienteAux;

    do
    {
            printf("1. Entrar en la cola\n2. Salir de la cola\n3. Salir del programa\n");
            scanf("%i", &opcion);

        switch (opcion)
        {
            case 1:
                clienteAux = (struct infoCliente*)malloc(sizeof(struct infoCliente));

                printf("Introduzca el nombre del cliente\n");
                fflush(stdin);
                gets(clienteAux->nombre);
                printf("Introduzca el total del carrito\n");
                scanf("%f", &clienteAux->totalCarrito);
                clienteAux->siguiente = NULL;

                if (super.primero == NULL)
                {
                    super.primero = clienteAux;
                    super.ultimo = clienteAux;
                } else
                {
                    super.ultimo->siguiente = clienteAux;
                    super.ultimo = clienteAux;
                }

                clienteAux = super.primero;
                while (clienteAux!= NULL)
                {
                    printf("Nombre: %s Total: %g\n", clienteAux->nombre, clienteAux->totalCarrito);
                    clienteAux = clienteAux->siguiente;
                }
                
                break;
            case 2:
                if (super.primero == NULL)
                {
                    printf("La cola est  vac¡a\n");
                } else
                {
                    clienteAux = super.primero;
                    super.primero = super.primero->siguiente;
                    free(clienteAux);
                    clienteAux = NULL;

                    if (super.primero == NULL)
                    {
                        printf("La cola est  vac¡a\n");
                    } else
                    {
                        clienteAux = super.primero;
                        while (clienteAux!= NULL)
                        {
                            printf("Nombre: %s Total: %g\n", clienteAux->nombre, clienteAux->totalCarrito);
                            clienteAux = clienteAux->siguiente;
                        }
                    }
                }
                break;
            case 3:
                break;
            default:
                printf("El valor introducido es inv lido, pruebe de nuevo\n");
                break;
        }
    } while (opcion != 3);
    
}