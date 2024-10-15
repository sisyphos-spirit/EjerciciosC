#include <stdio.h>
#include <string.h>


/*
    Crea un programa un C que guarda una serie de c¢digos v lidos y los imprime por pantalla.
        - Vas a guardar los c¢digos en un array. En total solicitaremos 4 c¢digos.
        - Se solicitar n al usuario 4 c¢digos y validar s que el c¢digo tenga un formato
        adecuado (te describo m s adelante dicho formato).
        - No parar s de solicitar c¢digos al usuario hasta tener 4 c¢digos guardados que
        cumplan con el formato y sean distintos.
        - Si el c¢digo introducido no cumple con el formato no lo guardar s, informar s al
        usuario de ello y le pedir s otro c¢digo.
        - Tampoco lo guardar s si ya existe en el array de c¢digos.
        - Una vez que tengas introducidos los 4 c¢digos correctos los imprimir s por pantalla.
        - El c¢digo tiene que cumplir con el siguiente formato:
            - Es una cadena de 5 caracteres. Debes comprobar la longitud.
            - Los dos primeros son n£meros del 0 al 9.
            - El tercero es un gui¢n '-'.
            - El cuarto puede ser una 'Z' o 'X' may£sculas.
            - El quinto es un n£mero del 0 al 9.
            - Ejemplos que puedes utilizar para comprobar si lo has hecho bien:
                þ Ejemplos de c¢digos v lidos: 30-X2, 87-X1, 91-Z2, 33-Z1.
                þ Ejemplos de c¢digos no v lidos: 12A, 34-A2, 87.X1, XX-Z2, -3-B1.
        - No puedes utilizar variables globales.
        - Para resolver el ejercicio utilizar s las siguientes funciones:
            - Funci¢n valCod: Como par metro recibe un array que representa la cadena
            introducida por el usuario y devuelve 1 si es v lida y 0 si no es v lida. Esta
            funci¢n comprueba si el c¢digo tiene 5 caracteres y cumple con el formato
            exigido.
            - Funci¢n impCod: Como par metro recibe el array con todos los c¢digos y no
            devuelve nada. Imprime todos los c¢digos por pantalla.
        - énicamente puedes utilizar la funci¢n strcpy, strcat, strcmp y strlen si lo crees
        necesario. No puedes utilizar ninguna otra funci¢n de string.h.

*/

#define CANTIDAD_CODIGOS 4
#define TAM_CODIGOS 6

//Esta funcion sirve para comprobar si un caracter es equivalente a un n£mero del 0 al 9, proceso que realizar‚ en m s de una ocasi¢n en el programa.
int comprobarNum(char num)
{
    switch (num)
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                return 1;
            default:
                return 0;
        }
}

int valCod(char codigo[TAM_CODIGOS])
{   
    //Declaro el booleano como verdadero para empezar, y proceduralmente voy comprobando que el c¢digo haya sido introducido correctamente.
    enum miBooleano {FALSO, VERDADERO} codigoCorrecto = VERDADERO;
    int i;

    //Primero compruebo la cantidad de caracteres.
    if (strlen(codigo) != 5)
    {
        codigoCorrecto = FALSO;
    }
    
    //Me aseguro de que los dos primeros caracteres sean numeros de un digito.
    for (i = 0; i < 2; i++)
    {
        if (!comprobarNum(codigo[i]))
        {
            codigoCorrecto = FALSO;
        }
    }

    //Compruebo que el tercero sea un gui¢n.
    if (codigo[2] != '-')
    {
        codigoCorrecto = FALSO;
    }

    //Me cercioro de que el cuarto sea una 'Z' o 'X'.
    if (codigo[3] != 'Z' && codigo[3] != 'X')
    {
        codigoCorrecto = FALSO;
    }

    //Despues repito para el quinto caracter el mismo proceso que con los dos primeros.
    if (!comprobarNum(codigo[4]))
        {
            codigoCorrecto = FALSO;
        }

    if (codigoCorrecto)
    {
        return 1;
    } else
    {
        return 0;
    }
}

void impCod(char codigos[CANTIDAD_CODIGOS])
{
    int i;
    for (i = 0; i < CANTIDAD_CODIGOS; i++)
    {
        printf("C¢digo %i:\n", i+1);
        printf("%s\n", codigos[i]);
    }
}

int main()
{
    enum miBooleano {FALSO, VERDADERO} codigoRepetido;
    char codigos[CANTIDAD_CODIGOS][TAM_CODIGOS], inputCodigo[TAM_CODIGOS];
    int i, j;

    printf("Introduzca 4 c¢digos con el formato adecuado:\n");
    printf("-Es una cadena de 5 caracteres.\n");
    printf("-Los dos primeros son n£meros del 0 al 9.\n");
    printf("El tercero es un gui¢n '-'.");
    printf("El cuarto puede ser una 'Z' o 'X' may£sculas.\n");
    printf("El quinto es un n£mero del 0 al 9.\n");

    for (i = 0; i < CANTIDAD_CODIGOS; i++)
    {
        printf("------------------------\n");
        printf("C¢digo %i\n", i+1);
        fflush(stdin);
        gets(inputCodigo);
        
        if (valCod(inputCodigo))
        {
            codigoRepetido = FALSO;

            for (j = 0; j < CANTIDAD_CODIGOS; j++)
            {
                if (strcmp(inputCodigo, codigos[j]) == 0)
                {
                    codigoRepetido = VERDADERO;
                    printf("El c¢digo introducido es incorrecto, pruebe de nuevo\n");
                    i--;
                    break;
                }
            }

            if (!codigoRepetido)
            {
                strcpy(codigos[i], inputCodigo);
            }

        } else
        {
            printf("El c¢digo introducido es incorrecto, pruebe de nuevo\n");
            i--;
        }
    }
    
    impCod(codigos[CANTIDAD_CODIGOS]);

    return 0;
}