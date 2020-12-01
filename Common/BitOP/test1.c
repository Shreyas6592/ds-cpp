#include <stdio.h>
#include <stdint.h>

#define G_UINT64_NUMOFBITS 64U

uint64_t circShift(uint64_t const f_val, uint64_t const f_shiftLen, uint64_t f_bitwidth)
{
    if (f_bitwidth > (G_UINT64_NUMOFBITS - 1U))
    {
        f_bitwidth = (G_UINT64_NUMOFBITS - 1U);
        // f_shiftLen_u8 does not need a special care, as implicitly checked below
    }

    uint64_t const shiftGuard = (f_shiftLen % f_bitwidth);
    uint64_t const leftShiftedVal = (f_val << shiftGuard);
    uint64_t const bitwidthGuard = (1ULL << f_bitwidth) - 1ULL; //PRQA S 3130,3136 // // range check for f_bitwidth_u8 is done already //

    return ((leftShiftedVal) & (bitwidthGuard)) | ((f_val & bitwidthGuard) >> (f_bitwidth - shiftGuard));
}

void main()
{
    unsigned int i = 2;
    i |= (i<<1);
    printf("%d \n",i);
}