#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int tab[]){
    //petla zewnetrzna, powtarza proces
    for(int i=0; i<14;i++){

        //petla do przechodzenia miedzy kolejnymi elementami(parami)
        for(int t=0;t<14-i;t++){

            //instrukcja warunkowa do sprawdzenia czy kolejny element tablicy jest wiekszy
            if(tab[t]>tab[t+1]){

                //jezeli tak, to ponizsze instrukcje zamieniaja je (tab[t] i tab[t+1]) miejscami
                int temp=tab[t];
                tab[t]=tab[t+1];
                tab[t+1]=temp;
            }
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

    //funkcja: sortowanie babelkowe
    bubbleSort(tablica);

    printf("\nPo sortowaniu: \n");

    //wyswietlenie tablicy po sortowaniu
    for(int i=0;i<15;i++){
        printf("%d",tablica[i]);
    }

    return 0;
}
