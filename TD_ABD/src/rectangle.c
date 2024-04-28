#include "abd.h"

void int_rectangle(T_Rectangle r, T_ABD T)
{
    if(T != NULL)
    {
        if(((r.H).x <= (T->p).x)&&((T->p).x <= (r.B).x)&&
        ((r.H).y >= (T->p).y)&&((T->p).y >= (r.B).y))
        {
            print_node(*T);
        }
        int_rectangle(r, T->g);
        int_rectangle(r, T->d);
    }
}

// Mieux si on n'explore pas tout l'abd mais seulement si c'est
// nécessaire x<> y<>