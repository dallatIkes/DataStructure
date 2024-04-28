#define MAX 1000

typedef struct T_TAB_TAS_S
{
    int T[MAX];
    int last; // dernière case occupée
} T_TAB_TAS;

T_TAB_TAS T_TAB_TAS_Init();
void T_TAS_TAB_Insertion(T_TAB_TAS file, int e);
void T_TAS_TAB_Affichage(T_TAB_TAS file);