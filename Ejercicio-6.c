#include <stdio.h>
#include <stdlib.h>

/*
    Debes crear una peque¤a aplicaci¢n para gestionar los empleados de una empresa. Para
    guardar los datos vamos a utilizar una lista simple enlazada que solo apunta al primero y
    £ltimo de la lista.
    Los datos que se deben registrar de un empleado son:
        - C¢digo de empleado, que ser  un entero.
        - Nombre del empleado (longitud m xima de 50 caracteres).
        - Salario del empleado, que ser  un n£mero con decimales.
    El programa de gesti¢n de empleados tendr  las siguientes opciones:
        1. Dar de alta empleado: solicita los datos del empleado y lo a¤ade a la colecci¢n. Si el
        c¢digo ya existe no debe incluirlo. A¤adiremos los empleados en orden dentro de la
        lista de menor a mayor.
        2. Dar de baja empleado: solicita el c¢digo de empleado y lo borra de la colecci¢n. Si
        no hay empleados o el c¢digo no existe debe informar de ello.
        3. Listar empleados, mostrar  un listado completo con el c¢digo, nombre y salario de
        cada empleado (un empleado por l¡nea).
        4. Media de los sueldos: Imprime por pantalla la media de todos los sueldos. Para
        calcular la media debes sumar todos los sueldos y dividirlo entre el n£mero total de
        empleados.
        5. Salir del programa.
*/

struct datosEmpleado
{
    int codigo;
    char nombre[51];
    float salario;
    struct datosEmpleado *siguiente;
};

struct listaEmpleados
{
    struct datosEmpleado *primero;
    struct datosEmpleado *ultimo;
};

int main()
{
    enum miBooleano {FALSO, VERDADERO} codigoRepetido;
    struct listaEmpleados lista;
    lista.primero = NULL;
    lista.ultimo = NULL;

    int opcion, contador, codigoBorrar;
    float media;
    struct datosEmpleado *empleAux;
    struct datosEmpleado *empleNuevo;
    struct datosEmpleado *empleBorrar;

    do
    {
        printf("1. Dar de alta a empleado\n2. Dar de baja a empleado\n3. Listar empleados\n4. Imprimir media de los sueldos\n5. Salir del programa\n");
        scanf("%i", &opcion);

        switch (opcion)
        {
            case 1:
                empleNuevo = (struct datosEmpleado*)malloc(sizeof(struct datosEmpleado));

                printf("Introduzca los datos del empleado\nC¢digo:\n");
                scanf("%i", &empleNuevo->codigo);
                printf("Nombre:\n");
                fflush(stdin);
                gets(empleNuevo->nombre);
                printf("Salario\n");
                scanf("%f", &empleNuevo->salario);
                empleNuevo->siguiente = NULL;

                if (lista.primero == NULL)
                {
                    lista.primero = empleNuevo;
                    lista.ultimo = empleNuevo;
                } else
                {
                    codigoRepetido = FALSO;
                    empleAux = lista.primero;
                    do 
                    {
                        if (empleAux->codigo == empleNuevo->codigo)
                        {
                            codigoRepetido = VERDADERO;
                            break;
                        }
                        empleAux = empleAux->siguiente;
                    } while (empleAux != NULL);

                    if (codigoRepetido)
                    {
                        printf("El c¢digo introducido ya existe, por lo que no se a¤adir  a la cola\n");
                        free(empleNuevo);
                        empleNuevo = NULL;
                    } else
                    {
                        lista.ultimo->siguiente = empleNuevo;
                        lista.ultimo = empleNuevo;
                    }
                }
                break;
            case 2:
                if (lista.primero == NULL)
                {
                    printf("La lista est  vac¡a\n");
                } else
                {
                    printf("Introduzca el c¢digo del empleado que desea dar de baja\n");
                    scanf("%i", &codigoBorrar);

                    codigoRepetido = FALSO;
                    empleBorrar = lista.primero;
                    if (empleBorrar->codigo == codigoBorrar)
                    {
                        lista.primero = empleBorrar->siguiente;
                        free(empleBorrar);
                        empleBorrar=NULL;
                        break;
                    }
                    do 
                    {
                        if (empleBorrar->siguiente->codigo == codigoBorrar)
                        {
                            codigoRepetido = VERDADERO;
                            
                            if (empleBorrar->siguiente == lista.ultimo)
                            {
                                lista.ultimo = empleBorrar;
                                empleBorrar = empleBorrar->siguiente;
                                free(empleBorrar);
                                empleBorrar=NULL;
                            } else
                            {
                                empleAux = empleBorrar;
                                empleBorrar = empleAux->siguiente;
                                empleAux->siguiente = empleAux->siguiente->siguiente;
                                free(empleBorrar);
                                empleBorrar=NULL;
                            }
                            break;
                        }
                        empleBorrar = empleBorrar->siguiente;
                    } while (empleAux != NULL);

                    if (!codigoRepetido)
                    {
                        printf("El c¢digo introducido no existe\n");
                    }
                }
                break;
            case 3:
                if (lista.primero == NULL)
                {
                    printf("La lista est  vac¡a\n");
                } else 
                {
                    empleAux = lista.primero;
                    do 
                    {
                        printf("C¢digo: %i Nombre: %s Salario: %g\n", empleAux->codigo, empleAux->nombre, empleAux->salario);
                        empleAux = empleAux->siguiente;
                    } while (empleAux != NULL);
                }
                break;
            case 4:
                if (lista.primero == NULL)
                {
                    printf("La lista est  vac¡a\n");
                } else
                {
                    empleAux = lista.primero;
                    media = 0;
                    contador = 0;
                    do 
                    {
                        media = media + empleAux->salario;
                        contador++;
                        empleAux = empleAux->siguiente;
                    } while (empleAux != NULL);
                    
                    media = media / contador;
                    printf("La media es de %g\n", media);
                }
                break;
            case 5:
                break;
            default:
                printf("El valor introducido es incorrecto\n");
                break;
        }

    } while (opcion != 5);
}