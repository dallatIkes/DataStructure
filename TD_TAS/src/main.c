#include "TAS.h"

int main()
{
    T_TAB_TAS file = T_TAB_TAS_Init();
    T_TAS_TAB_Insertion(file, 5);
    T_TAS_TAB_Affichage(file);
}