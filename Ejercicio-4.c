#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

/*
    Programa una aplicaci¢n en C que resuelva el siguiente ejercicio. Existen 10 taxis en
    una ciudad dando vueltas. Un cliente llama a un taxi y se acercar  el taxi m s cercano a
    recogerle. Para resolver el siguiente ejercicio tenemos una estructura de datos con la
    siguiente informaci¢n sobre los taxis:

        - N£mero del taxi (entero)
        - Coordenada x (entero)
        - Coordenada y (entero)

    Ese d¡a sabemos que por la ciudad hay 10 taxis. Crear s un array de 10 taxis. Numera
    los taxis del 1 al 10 e inicializa las coordenadas de los taxis con n£meros aleatorios del
    0 al 100. Imprime por pantalla el array que has generado. Tu programa al empezar
    solicita al usuario unas coordenadas (x,y), deben ser valores positivos entre 0 y 100.
    Calcular s el taxi que se encuentra m s cerca de ‚l. Imprime por pantalla el n£mero del
    taxi m s cercano y sus coordenadas. Despu‚s de imprimir esta informaci¢n el programa
    termina.

    La distancia entre dos puntos lo resuelves con la siguiente f¢rmula:
    - Distancia = sqrt((x2 - x1)^2 + (y2 - y1)^2)

    - Coordenada Usuario (x1 , y1) = (1, 3)

    - Coordenada Taxi (x2 , y2) = (2, 5)

    - Distancia = sqrt((2 - 1)^2 + (5 - 3)^2) = sqrt((1)^2 + (2)^2) = sqrt(1 + 4) = sqrt(5) = 2,23606

    Para este ejercicio puedes hacer uso de funciones (pow, sqrt, etc?) de la librer¡a
    math.h y de la librer¡a random.h.
    Utiliza las siguientes funciones:

        - Funci¢n generaTaxis: Tiene un par metro que es un n£mero entero que
        representa el n£mero del taxi y devuelve una estructura de taxi. Esta funci¢n
        crea una estructura de taxi, asigna el par metro entero al campo n£mero de taxi
        y asigna a los campos coordenadas los valores aleatorios del 0 al 100.
        - Funci¢n calculaDistancia: Recibe como par metros x1, y1, x2, y2 y una variable
        distancia que se pasa por referencia. No devuelve nada. Esta funci¢n calcula la
        distancia entre los puntos (x1 , y1) y (x2 , y2) y lo asigna a la variable distancia
        pasada por referencia.

    No puedes utilizar variables globales.
*/

#define TAM 10

struct infoTaxis
{
    int numTaxi;
    int abscisas;
    int ordenadas;
};

struct infoTaxis generaTaxis(int numTaxi)
{
    //Creo la variable de tipo estructura en la que introducir‚ los datos.
    struct infoTaxis taxi;

    taxi.numTaxi = numTaxi;

    //Utilizo el tiempo como semilla con la que asegurarme de que los valores sean realmente aleatorios y se los asigno a las variables de coordenadas.
    srand(time(NULL));
    taxi.abscisas = (rand() * numTaxi) % 101;
    taxi.ordenadas = (rand() * numTaxi) % 101;

    return taxi;
}

void calculaDistancia(int x1, int y1, int x2, int y2, float *distancia)
{
    *distancia = sqrt((pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

int main()
{
    //Creo la variable de tipo estructura en la que guardar‚ los datos de los taxis usando la funci¢n generarTaxis.
    struct infoTaxis taxisCercanos[TAM];
    int inputX, inputY, taxiMasCercano = 0, i;
    float distancia, menorDistancia;

    //Genero todos los datos de los taxis y los guardo en el array.
    for (i = 0; i < TAM; i++)
    {
        taxisCercanos[i] = generaTaxis(i+1);
    }
    
    //Imprimo el array
    for (i = 0; i < TAM; i++)
    {
        printf("N£mero de taxi: %i\n", taxisCercanos[i].numTaxi);
        printf("Coordenada x: %i\n", taxisCercanos[i].abscisas);
        printf("Coordenada y: %i\n", taxisCercanos[i].ordenadas);
    }

    //Le pido sus coordenadas al usuario, y si introduce un valor incorrecto se las vuelvo a pedir.
    printf("Introuzca sus coordenadas (del 0 al 100)\n");
    printf("Coordenadas en x:\n");
    scanf("%i", &inputX);
    while (inputX < 0 || inputX > 100)
    {
        printf("El valor introducido es incorrecto, int‚ntelo de nuevo\n");
        scanf("%i", &inputX);
    }
    printf("Coordenadas en y:\n");
    scanf("%i", &inputY);
    while (inputY < 0 || inputY > 100)
    {
        printf("El valor introducido es incorrecto, int‚ntelo de nuevo\n");
        scanf("%i", &inputY);
    }

    //Calculo la distancia a la que est  el primer taxi, y uso esa como referencia para detectar cual es el m s cercano.
    calculaDistancia(inputX, inputY, taxisCercanos[0].abscisas, taxisCercanos[0].ordenadas, &distancia);
    menorDistancia = distancia;

    for (i = 1; i < TAM; i++)
    {
        calculaDistancia(inputX, inputY, taxisCercanos[i].abscisas, taxisCercanos[i].ordenadas, &distancia);
        if (distancia < menorDistancia)
        {
            menorDistancia = distancia;
            taxiMasCercano = i;
        }
    }

    printf("EL taxi m s cercano es el n£mero %i y sus coordenadas son las siguientes: (%i, %i)\n", taxiMasCercano, taxisCercanos[taxiMasCercano].abscisas, taxisCercanos[taxiMasCercano].ordenadas);

    return 0;
}