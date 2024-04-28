#include"abr.h"

int main()
{
    T_ABR t = init_ABR(12);
    print_ABR(t);

    add_root(&t, 3);
    print_ABR(t);

    add_root(&t, 2);
    print_ABR(t);
    
    add_root(&t, 5);
    print_ABR(t);

    add_root(&t, 4);
    print_ABR(t);

    add_root(&t, 7);
    print_ABR(t);

    add_root(&t, 9);
    print_ABR(t);

    add_root(&t, 11);
    print_ABR(t);

    add_root(&t, 14);
    print_ABR(t);

    add_root(&t, 10);
    print_ABR(t);
}
