#include <stdio.h>
#include <stdlib.h>

//############################
//#     MERGE SORT !!!!!!!   #
//############################

void merge(int tab[], int l_side, int middle, int r_side)   //funkcja merge - ³¹cz¹ca i sortujaca tablice
{
    int i, j, k;    //zadeklarowanie zmiennych pomocniczych
    int n1 = middle - l_side + 1;   //zmienna przechowujaca dlugosc tablicy pomocniczej(l_temp)
    int n2 = r_side - middle;   //zmienna przechowujaca dlugosc tablicy pomocniczej (r_temp)
    int L_temp[n1], R_temp[n2]; //deklaracja tablic pomocniczych


    for (i = 0; i < n1; i++)    //petla laczaca tablice (od lewej strony)
    {
        L_temp[i] = tab[l_side + i];    //przypisanie elementu tablicy tab do tablicy pomocniczej
    }

    for (j = 0; j < n2; j++)    //petla laczaca tablice(od prawej strony)
    {
        R_temp[j] = tab[middle + 1 + j];    //przypisanie elementu tablicy tab do tablicy pomocniczej
    }


    i = 0;      //przypisanie wartosci do zmiennej pomocniczej
    j = 0;      //przypisanie wartosci do zmiennej pomocniczej
    k = l_side; //przypisanie wartosci do zmiennej pomocniczej

    //petla laczaca elementy tablicy
    while (i < n1 && j < n2)
        {
            if (L_temp[i] <= R_temp[j]) //sprawdzenie ktora wartosc jest mniejsza, aby je posortowac przed laczeniem
            {
                tab[k] = L_temp[i]; //laczenie tablicy
                i++;    //iteracja w celu przejscia na kolejny element
            }
            else
            {
                tab[k] = R_temp[j]; //laczenie tablicy
                j++;    //iteracja w celu przejscia na kolejny element
            }
        k++;
        }


    while (i < n1)  //laczenie tablic jezeli elementy sa juz posortowane
        {
            tab[k] = L_temp[i];
            i++;
            k++;
        }

    while (j < n2)  //laczenie tablic jezeli elementy sa juz posortowane
        {
            tab[k] = R_temp[j];
            j++;
            k++;
        }
}


void mergeSort(int tab[], int l_side, int r_side) //funkcja mergeSort - dzieli tablice tab na pojedyncze elementy
{
    if (l_side < r_side) {  //sprawdzenie czy lewa strona jest mniejsza od prawej

        int middle = l_side + (r_side - l_side) / 2;    //zadeklarowanie zmiennej middle ktora przechowuje index srodkowy


        mergeSort(tab, l_side, middle); //wykonanie funkcji mergeSort dla elementow tablicy tab na lewo od indexu middle (w³¹cznie z indexem middle)
        mergeSort(tab, middle + 1, r_side); //wykonanie funkcji mergeSort dla elementow tablicy tab na prawo od indexu middle (z pominiêciem indexu middle)
        merge(tab, l_side, middle, r_side); //wykonanie funkcji ³¹cz¹cej tablice - merge
    }
}

int main()
{
    int tab[] = { 4, 13, 5325, 1231, 23, 5, 9, -1 };    //zadeklarowanie tablicy i uzupe³nienie jej wartoœciami
    int tab_size = sizeof(tab) / sizeof(tab[0]);    //zadeklarowanie zmiennej tab_size przechowujacej dlugosc tablicy

    mergeSort(tab, 0, tab_size - 1);    //wykonanie funkcji mergeSort

    printf("Wynik sortowania tablicy: \n"); //wyœwietlenie tekstu
    for (int i = 0; i < tab_size; i++)  //pêtla do wyœwietlania kolejnych elementów tablicy tab
    {
        printf("%d ", tab[i]);  //wyœwietlenie elementu tablicy tab[i]
    }

    return 0;
}
