#include <stdio.h>

int get_bit(int number, int bit_position)
{
    if( (number >> bit_position) & 1)
        return 1;
    else 
        return 0;
}

int main(void)
{
    printf("%d\n", get_bit(5, 3));
}