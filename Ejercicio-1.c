#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

/*
    Inicializa un array con 10 palabras. El array debes inicializarlo t£ con las 10 palabras que
    quieras. Vamos a jugar con el usuario a adivinar una palabra. P¡dele al usuario una palabra
    y este tendr  que adivinar la palabra que ha seleccionado tu programa del array de palabras
    de forma aleatoria. El usuario tendr  como m ximo 3 intentos para intentar adivinar la
    palabra. Informa al usuario si ha ganado o perdido al finalizar. Imprime al comienzo la
    palabra seleccionada para comprobar que tu programa funciona.
    Puedes utilizar funciones o no, es opcional.
    Puedes utilizar funciones de string.h.
    No puedes utilizar variables globales.
    Para generar un n£mero aleatorio utiliza la librer¡a random.h
*/

#define TAM 25

int main()
{
    //Declaro variables para todas las palabras, la elegida aleatoriamente y la introducida por el usuario.
    char palabras[10][TAM] = {{"patata"}, {"euclideo"}, {"electroencefalografista"}, {"peliagudo"}, {"trisque"}, {"tintinear"}, {"monitorizar"}, {"centinela"}, {"magnanimidad"}, {"sardina"}};
    char palabraElegida[TAM], palabraUsuario[TAM];
    //Estas variables son solo para el correcto funcionamiento del programa.
    int numeroDePalabra, i;

    //Pongo una semilla para la generaci¢n de n£meros aleatorios y la establezco entre 0 y 9.
    srand(time(NULL));
    numeroDePalabra = rand() % (10);
    //Imprimo el n£mero para comprobar que el programa est  funcionando correctamente, para jugar realmente hay que suprimir esta linea.
    printf("%i\n", numeroDePalabra);

    //Dependiendo del n£mero aleatorio, asigno la palabra correcta a la variable correspondiente.
    switch (numeroDePalabra)
    {
        case 0:
            strcpy(palabraElegida, palabras[0]);
            break;
        case 1:
            strcpy(palabraElegida, palabras[1]);
            break;
        case 2:
            strcpy(palabraElegida, palabras[2]);
            break;
        case 3:
            strcpy(palabraElegida, palabras[3]);
            break;
        case 4:
            strcpy(palabraElegida, palabras[4]);
            break;
        case 5:
            strcpy(palabraElegida, palabras[5]);
            break;
        case 6:
            strcpy(palabraElegida, palabras[6]);
            break;
        case 7:
            strcpy(palabraElegida, palabras[7]);
            break;
        case 8:
            strcpy(palabraElegida, palabras[8]);
            break;
        case 9:
            strcpy(palabraElegida, palabras[9]);
            break;
    }
    //Imprimo la palabra comprobar que el programa funciona correctamente. En caso de querer jugar realmente esta linea ha de ser suprimida.
    printf("%s\n", palabraElegida);

    //Muestro las 10 palabras al usuario y le explico el juego.
    printf("Una de estas 10 palabras es la palabra elegida:\n");
    printf("patata, euclideo, electroencefalografista, peliagudo, trisque, tintinear, monitorizar, centinela, magnanimidad, sardina\n");
    printf("Introduzca una palabra para comprobar si es la elegida.\n");
    printf("-------------------------------------------\n");
    fflush(stdin);

    //Este bucle se asegura de que el usuario no tenga m s de 3 intentos y le comunica los intentos restantes.
    for (i = 3; i > 0; i--)
    {
        printf("Intentos restantes: %i\n", i);
        gets(palabraUsuario);

        if (strcmp(palabraElegida, palabraUsuario) == 0)
        {
            break;
        } else 
        {
            printf("La palabra introducida no es la palabra elegida\n");
        }
    }

    printf("-------------------------------------------\n");

    //Comparo la palabra elegida con la introducida y le digo al usuario si ha ganado o perdido el jugo.
    if (strcmp(palabraElegida, palabraUsuario) == 0)
    {
        printf("Enhorabuena, ­La palabra introducida es la palabra elegida!");
    } else
    {
        printf("Derrota. Intentelo de nuevo la pr¢xima vez");
    }

return 0;
}