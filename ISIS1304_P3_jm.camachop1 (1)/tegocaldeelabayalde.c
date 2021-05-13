#include <stdio.h>
#include <stdlib.h>

void empaquetamiento(char *cadena, int *arreglo)
{
    printf("Entrada: %s \n",cadena);
    int charCounter = 1;
    char numberStart = cadena[0];
    while(*cadena != '\0')
    {
        char currentChar = cadena[0];
        *arreglo |= currentChar; 
        if(1!=charCounter && 0==charCounter%4)
        {
            arreglo++;
            numberStart = cadena[1];
        }
        else
        {
            *arreglo <<= 8;
            if(cadena[1] =='\0')
                {
                    while(*arreglo <= 0x00FFFFFF)
                    {
                        *arreglo <<= 8;
                    }
                }
        }
        charCounter++;
        cadena++;
    }
}

int main(){

    char cadena[100];

    printf("ingrese cadena: ");
    scanf("%s", &cadena);

    int charCounter = 0;

    while(cadena[charCounter]!=0)
    {
        charCounter++;
    }

    int *arrayPointer;

    arrayPointer = calloc(charCounter, sizeof(char));

    char * charpointer = &cadena[0];

    empaquetamiento(charpointer, arrayPointer);

    int positionsNeeded = (charCounter%4 != 0)? (charCounter/4)+1 :charCounter/4 ;

    printf("Salida: ");
    int i = 0;
    for (; i < positionsNeeded-1; i++)
    {
        printf("0x%X, ",arrayPointer[i]);
    }
    printf("0x%X",arrayPointer[i]);
    printf("\n");
    return 0;
}