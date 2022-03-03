#include <stdio.h>
#include <stdlib.h>

void selectionSort(int cyfry[]){

    //petla do przechodzenia miedzy kolejnymi elementami tablicy
    //poza ostatnim, poniewaz ostatni element jest juz posortowany
    for(int i=0;i<10;i++){

        //przypisanie pierwszego indexu jako wartosc minimum
        int min=i;

        //sprawdzanie czy kolejne elementy tablicy sa wieksze od wartosci cyfry[min
        //zaczynam od i+1 bo juz przypisalem min=i
        for(int t=i+1;t<=10;t++){
            if(cyfry[min]>cyfry[t]) min=t;
        }

        int temp=cyfry[i];

        //zamiana wartosci
        cyfry[i]=cyfry[min];
        cyfry[min]=temp;
    }
}

int main()
{
    //stworzenie tablicy 11-elementowej tablicy z numerem pesel
    int pesel[]={6,5,4,3,2,1,2,3,4,5,6};

    //wyswietlenie tablicy przed sortowaniem
    for(int i=0;i<11;i++){
        printf("%d",pesel[i]);
    }

    //funkcja sortowania
    selectionSort(pesel);

    printf("\nPo sortowaniu: \n");

    //wyswietlenie tablicy po sortowaniu
    for(int i=0;i<11;i++){
        printf("%d",pesel[i]);
    }

    return 0;
}
