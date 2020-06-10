/* 
 * Problem statement: Given high and low, generate bit mask
 * Eg., high = 5 low = 4, Mask should be 0x30
 *
 */

#include <stdio.h>

unsigned int generate_mask(unsigned int high, unsigned low)
{
    unsigned int i = 0, j = 0, x = 0, y = 0;
    if((low > 32U ) || (high > 32U))
       return 0x0;

    if (low > high) {
       int a = low;
       low = high;
       high = a; 
    }

    while(i <= high) {
        x = x + (1 << i);
        ++i;
    }

    while(j < low) {
        y = y + (1 << j);
        ++j;
    }

    return x&(~y);
    
}

int main(void)
{
    unsigned int high = 0;
    unsigned int low =  0;
    printf("Mask: 0x%x\n", generate_mask(high, low));
    return 0;
}
