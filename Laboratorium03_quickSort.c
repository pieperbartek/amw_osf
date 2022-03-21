#include <stdio.h>
#include <stdlib.h>

// ###################
// #     QUICKSORT   #
// ###################

void quickSort(int tab[], int start_element, int last_element)  //funkcja quickSort(tablica,pierwszy element tablicy, ostatni element tablicy)
{
    if (last_element <= start_element) return;  //sprawdzenie czy tablica jest 1-elementowa lub mniejsza
    int pivot = partitionFunction(tab, start_element, last_element);    //przypisanie do zminnej pivot wartosci zwroconej przez funkcje partitionFunction
    quickSort(tab,start_element, pivot - 1);    //wykonanie funkcji quickSort dla elementow mniejszych od pivot
    quickSort(tab, pivot + 1, last_element);    //wykonanie funkcji quickSort dla elementow wiekszych od pivot
}

int partitionFunction(int tab[], int start_element, int last_element)   //funkcja partitionFunction zwracajaca wartosc pivot
{
    int i = start_element - 1;  //deklaracja zmiennej pomocniczej
    int pivot = tab[last_element];  //utworzenie zmiennej pivot i przypisanie do niej wartosci ostatniego elementu tablicy

    for(int k = start_element; k <= last_element; k++)  //petla do przechodzenia miedzy kolejnymi elementami tablicy
        {
        if(tab[k] < pivot)  //sprawdzenie czy wartosc jest mniejsza od pivot, jezeli nie, to zamieniamy ja miejscem z pivot
         {
            i++;

            //zamiana wartosci
			int temp = tab[i];
			tab[i] = tab[k];
			tab[k] = temp;
         }
        }
        //zamiana wartosci ostatniej z wartoscia tab[i]
        i++;
        int temp = tab[i];
        tab[i] = tab[last_element];
        tab[last_element] = temp;

        return i;
}

int main()
{
    int tab[] = {2, 4, 5, 10, 23, 65, 1000, 13, -982};  //zadeklarowanie 9-elementowej tablicy tab i przypisanie wartoœci
    int tab_size = sizeof(tab) / sizeof(tab[0]);    //zadeklarowanie zmiennej tab_size ktora przechowuje rozmiar tablicy tab

    quickSort(tab,0,tab_size - 1);  //wykonanie funkcji quickSort

    printf("Wynik sortowania tablicy: \n"); //wyswietlenie tekstu
    for (int i = 0; i < tab_size; i++)  //petla ktora wyswietla wszystkie elementy tablicy tab
    {
        printf("%d ", tab[i]);  //wyswietlenie elementu tablicy tab
    }
    return 0;
}
