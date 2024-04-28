#include <stdio.h>
#include "TAS.h"

void swap(int *tab, int i, int j)
{
    int temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
}

int indice_pere(int i)
{
    return (i - 1) / 2;
}

T_TAB_TAS T_TAB_TAS_Init()
{
    T_TAB_TAS file;
    file.last = 0;
    return file;
}

void T_TAS_TAB_Insertion(T_TAB_TAS file, int e)
{
    file.last++;
    int i = file.last;
    while (e < file.T[indice_pere(i)])
    {
        swap(file.T, i, indice_pere(i));
    }
}

void T_TAS_TAB_Affichage(T_TAB_TAS file)
{
    for (int i = 0; i < file.last; i++)
    {
        printf("%d ", file.T[i]);
    }
}