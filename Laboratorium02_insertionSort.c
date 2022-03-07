#include <stdio.h>
#include <stdlib.h>

void insertionSort(int tab[]){
    //petla do przechodzenia miedzy kolejnymi indexami tablicy
    for(int i=1;i<15;i++){

        //tymczasowo przypisuje wartoœæ tablicy[i] do zmiennej temp
        int temp=tab[i];

        //tworze druga zmienna - t, ktora bedzie przechodzic miedzy elementami tablicy
        //zmienna t jest mniejsza o 1 od i, poniewaz porownuje elementy tablica[t]na lewo od tablica[i]
        int t=i-1;

        //petla do przestawiana elementow
        while(t>=0 && tab[t]>temp){
            tab[t+1]=tab[t];

            //zmniejszamy wartosc t, aby porownywac kolejne elementy na lewo od tablica[i]
            t--;
            tab[t+1]=temp;
        }

    }
}

int main()
{
    //stworzenie tablicy 15-elementowej tablicy
    int tablica[]={6,5,4,3,2,1,2,3,4,5,6,8,9,7,8};

    //wyswietlenie tablicy przed sortowaniem
    for(int i=0;i<15;i++){
        printf("%d",tablica[i]);
    }

    //funkcja: sortowanie przez wstawianie
    insertionSort(tablica);

    printf("\nPo sortowaniu: \n");

    //wyswietlenie tablicy po sortowaniu
    for(int i=0;i<15;i++){
        printf("%d",tablica[i]);
    }

    return 0;
}
