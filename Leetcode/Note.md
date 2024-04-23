##### Power of 2

To check if a number `n` is power of 2 or not just do bitwise `and` operation between `n` and `n-1`
When you subtract 1 from a power of 2, the result will have all bits set to 1 up to the position of the least significant bit (LSB) in the original number, and all bits to the right of the LSB will be 0. Therefore, the result of the bitwise AND will be 0 if n is a power of 2, and non-zero otherwise.

if((n&(n-1))==0){return true;}
