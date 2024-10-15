#include <stdio.h>
#include <string.h>

/*
    Crea un programa en C que almacena comerciales de una empresa en una estructura que
    contenga:
    
        - Nombre del comercial.
        - Cantidad de comisi¢n en euros (Ejemplo: 1000, 200.9, 190.5 ...)

    Vamos a guardar c¢mo m ximo la informaci¢n de 5 comerciales.
    Tu programa muestra un men£ al usuario con las siguientes opciones:

        1. Insertar comercial: Desde esta opci¢n se insertan comerciales en el array. S¢lo le
        solicitaremos informaci¢n (nombre y comisi¢n) de un £nico comercial. No podremos
        tener m s 5 comerciales guardados. En caso de llegar al m ximo debemos avisar al
        usuario de que ya no es posible a¤adir m s comerciales. Solicitaremos el nombre
        del comercial y su comisi¢n. No podremos insertar el nombre de un comercial que ya
        exista en nuestro array. La comisi¢n introducida debe ser un valor entre 0 y 1000. Si
        el usuario desea introducir m s de un comercial, deber  volver a seleccionar esta
        opci¢n en el men£.

        2. Mostrar comerciales: Esta opci¢n mostrar  el nombre y la comisi¢n en euros de
        cada comercial guardado hasta el momento.

        3. Comerciales con menor comisi¢n: Se imprimir  el nombre de los comerciales con
        menor comisi¢n. Podr¡a darse el caso de que haya m s de uno. Tambi‚n puede
        darse el caso de que no se hayan insertado comerciales todav¡a en ese caso
        informa al usuario.

        4. Salir: El programa se despide del usuario y termina.

        Cualquier otra opci¢n se avisar  al usuario que no es correcta.
        El programa estar  continuamente mostrando el men£ al usuario hasta que decida salir.
        Puedes utilizar funciones o no, es opcional.
        énicamente puedes utilizar la funci¢n strcpy, strcat, strcmp y strlen si lo crees necesario. No
        puedes utilizar ninguna otra funci¢n de string.h.
        No puedes utilizar variables globales
*/

#define TAM_NOMBRES 30
#define TAM_COMERCIALES 5

int main()
{
    enum miBooleano {FALSO, VERDADERO} repetirMenu = VERDADERO, datosIncorrectos, datosIntroducidos[TAM_COMERCIALES], menorComision[TAM_COMERCIALES];
    //Declaro un array de tipo estructura para guardar los datos de cada comercial.
    struct datos
    {
        char nombre[TAM_NOMBRES];
        float comision;
    } comerciales[TAM_COMERCIALES];

    char nombreComprobacion[TAM_NOMBRES];
    int opcion, comercialesGuardados = 0, comisionComprobacion, valorMenorComision = 1001, i;

    //Inicializo los booleanos como falso para todos los comerciales porque a£n no se ha introducido ninguno. (Esto ser  relevante para la segunda y tercera opci¢n).
    for (i = 0; i < TAM_COMERCIALES; i++)
    {
        datosIntroducidos[i] = FALSO;
        menorComision[i] = FALSO;
    }

    printf("Elija una de las siguientes opciones:\n");
    do
    {
        //Hago un bucle que se repita mientras el usuario no quiera salir del programa e incluyo el men£ en el bucle para que el usuario pueda verlo cada vez que se reinicie el proceso.
        printf("----------------------\n");
        printf("1. Insertar comercial\n");
        printf("2. Mostrar comerciales\n");
        printf("3. Comerciales con menor comisi¢n\n");
        printf("4. Salir\n");
        printf("-------------------------\n");
        fflush(stdin);
        scanf("%i", &opcion);

        switch (opcion)
        {
            case 1: //Insertar comercial:
                //Compruebo que no haya m s de 5 comerciales
                if (comercialesGuardados < TAM_COMERCIALES)
                {
                    //Inizializo datosIncorrectos como falso por si el usuario ha introducido datos incorrectos anteriormente.
                    datosIncorrectos = FALSO;

                    printf("Introduzca los datos de un comercial:\n");
                    printf("Nombre:\n");
                    fflush(stdin);
                    gets(nombreComprobacion);

                    //Antes de guardar el nombre en el array compruebo que sea uno que no exista previamente.
                    for (i = 0; i < comercialesGuardados; i++)
                    {
                        if (strcmp(comerciales[i].nombre, nombreComprobacion) == 0)
                        {
                            datosIncorrectos = VERDADERO;
                        }
                    }
                    if (datosIncorrectos)
                    {
                        printf("El comercial introducido ya existe\n");
                        break;
                    }

                    printf("Comisi¢n:\n");
                    scanf("%i", &comisionComprobacion);

                    //Antes de guardar el valor de la comision, compruebo que se encuentre entre 0 y 1000 (ambos incluidos).
                    for (i = 0; i < TAM_COMERCIALES; i++)
                    {
                        if (comisionComprobacion < 0 || comisionComprobacion > 1000)
                        {
                            datosIncorrectos = VERDADERO;
                        }
                    }
                    if (datosIncorrectos)
                    {
                        printf("La comisi¢n introducida es inv lida\n");
                        break;
                    }
                    
                    //Despues de haber comprobado que los datos sean correctos, los guardo en el array, sumo 1 a la lista de comerciales guardados y establezco datosIntroducidos como verdadero.
                    strcpy(comerciales[comercialesGuardados].nombre, nombreComprobacion);

                    comerciales[comercialesGuardados].comision = comisionComprobacion;
                    //Si la comision introducida es menor que la anterior menor, entonces cambio el valor de la variable valorComisionMenor y adem s establezco que los comerciales que antes ten¡an la menor comision ya no la tienen.
                    if (comerciales[comercialesGuardados].comision < valorMenorComision)
                    {
                        valorMenorComision = comerciales[comercialesGuardados].comision;
                        for (i = 0; i < comercialesGuardados; i++)
                        {
                            menorComision[i] = FALSO;
                        }
                        menorComision[comercialesGuardados] = VERDADERO;
                    } else if (comerciales[comercialesGuardados].comision == valorMenorComision)
                    {
                        menorComision[comercialesGuardados] = VERDADERO;
                    }
                    
                    datosIntroducidos[comercialesGuardados] = VERDADERO;
                    comercialesGuardados++;
                } else 
                {
                    printf("Ya se ha registrado la cantidad m xima de comerciales\n");
                }

                break;
            case 2: //Mostrar comerciales:
                printf("Cantidad de comerciales guardados: %i\n", comercialesGuardados);
                for (i = 0; i < TAM_COMERCIALES; i++)
                {
                    //Solo muestro los datos si el comercial est  introducido, en caso contrario paro y salgo del bucle.
                    if (datosIntroducidos[i])
                    {
                        printf("--------------\n");
                        printf("Comercial n£mero: %i\n", i+1);
                        printf("Nombre: %s\n", comerciales[i].nombre);
                        printf("Comisi¢n: %g\n", comerciales[i].comision);
                    } else
                    {
                        break;
                    }
                }
                break;
            case 3: //Comerciales con menor comision.
                //Si no hay comerciales guardados aviso al usuario.
                if (comercialesGuardados == 0)
                {
                    printf("No hay comerciales registrados\n");
                } else
                {
                    printf("La menor comisi¢n es: %i\n", valorMenorComision);
                    printf("Comerciales con menor comisi¢n:\n");
                    for (i = 0; i < comercialesGuardados; i++)
                    {
                        //Solo muestro el nombre de aquellos comerciales que tengan la menor comisi¢n.
                        if (menorComision[i])
                        {
                            printf("%s\n", comerciales[i].nombre);
                        }
                    }
                }

                break;
            case 4: //Salir.
                repetirMenu = FALSO;
            default: //Valor incorrecto.
                printf("El valor introducido es incorrecto\n");
                break;
        }
    } while (repetirMenu);

    return 0;
}