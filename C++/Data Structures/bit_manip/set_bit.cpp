32 bits:
16 bits + 16 bitset
word = a& 0xFF00
word = word>>16
reverse_bits(word)
for(i=15;i>=0;--i)
word = word<<1;
word | = a& 1<<i != 0;
