// Está mal de momento

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void palabraRandom (char palabras[][10], char palabraAleatoria[]){
    strcpy(palabraAleatoria, palabras[rand() % 10]);
}

void rellenar (char palabraAsterisco[], char palabraAleatoria[]){
    strcpy(palabraAsterisco, palabraAleatoria);
    for (int i=0; i<strlen(palabraAleatoria); i++){
        palabraAsterisco[i]='*';
    }
}

int comprobar (char palabraAleatoria[], char palabraAsterisco[], char letra){
    int aciertos=0;
    for(int i=0; i<strlen(palabraAleatoria); i++){
        if(letra==palabraAleatoria[i]){
            palabraAsterisco[i]=palabraAleatoria[i];
            aciertos++;
        }
    }
    if(aciertos==0){
        printf("Has fallado\n");
        return 0;
    }
    return 1;
}

int main(){
    char palabras[10][10]={"ordenador", "ordenador", "portatil", "portatil", "portatil", "ordenador", "raton", "raton", "raton", "portatil"};
    char palabraAleatoria[10];
    char palabraAsterisco[10];
    char letra;
    int salida=0, intentos=3, i;
    srand(time(NULL));
    palabraRandom(palabras, palabraAleatoria);
    rellenar(palabraAsterisco, palabraAleatoria);
    printf("La palabra es: %s\n", palabraAleatoria);
    do{
        printf("Progreso: %s\n", palabraAsterisco);
        printf("Introduzca una letra, dispone de %i intentos\n", intentos);
        fflush(stdin);
        scanf("%c", &letra);
        if(comprobar(palabraAleatoria, palabraAsterisco, letra)==0){
            intentos--;
        }else if(comprobar(palabraAleatoria, palabraAsterisco, letra)==1){
            printf("Has acertado la letra %c\n", letra);
        }
        if(strcmp(palabraAsterisco, palabraAleatoria)==0){
            printf("Has ganado\n¿Deseas volver a jugar? (Para parar pulse N)\n");
            fflush(stdin);
            scanf("%c", &letra);
            if (letra=='N'){
                salida=1;
            }
        }else if(intentos==0){
            printf("Has perdido\n La palabra era %s\n¿Deseas volver a jugar? (Para parar pulse N)\n", palabraAleatoria);
            fflush(stdin);
            scanf("%c", &letra);
            if (letra=='N'){
                salida=1;
            }
        }
    }while(salida == 0);
    return 0;
}