#include <iostream> 
#include <bitset>
extern "C"
{
#include <stdint.h>
#include <limits.h>
}

using namespace std;

uint8_t G_UINT64_NUMOFBITS = (unsigned)64;
uint64_t G_DATAPATTERN = static_cast<uint64_t>(0xCCCCCCCCCCCCCCCCU); 
uint64_t G_ANTIDATAPATTERN = static_cast<uint64_t>(~G_DATAPATTERN); 
  
uint8_t clz64(uint64_t const f_val)
{
    uint8_t res = 64; // return 64 in case f_val is zero
    uint64_t tempVar = f_val;

    if (f_val != 0U)
    {

        uint8_t numOfSetBits = 0U;
        // right-shift till the number gets 0
        while (true)
        {
            if (tempVar > 0U)
            {
                tempVar >>= 1U;
                numOfSetBits++;
            }
            else
            {
                break;
            }
        }
        res = (64 - numOfSetBits); // equals to num of zeros;
    }
    return res;
}

void PRINT_B(uint64_t const size, uint64_t n)
{
    for (uint32_t i = 1 << (size - 1); i > 0U; i = i / 2U)
    {
        (n & i) ? cout<<"1" : cout<<"0";
    }

cout<<endl;
}

uint8_t log2_clz64(uint64_t const f_val)
{
    uint8_t res = 0U; // log2 of 0 is indefinit
    if (f_val > 0U)
    {
        /// @brief num of bits within a word substracted by
        /// the leading zeros of the same value results in the log2 of f_val
        res = (64 - clz64(f_val));
    }
    return res;
}

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

bool tempF(uint64_t f_actvAddrGroup)
{
    cout<<"Received the start address:"<<(uint64_t)f_actvAddrGroup<<endl;
	uint64_t currAddrOffset = f_actvAddrGroup;
	do
	{
		bitset<32> c(currAddrOffset);
        cout<<"Addr:   "<<currAddrOffset<<"     Hex: "<<c<<endl;
		currAddrOffset = circShift(currAddrOffset, 1U, static_cast<uint64_t>(14) - 1U);

		if (currAddrOffset == f_actvAddrGroup)
		{
			break;
		}
	} while (true);    
    return false;
}

int main()
{
    uint8_t lines = log2_clz64(65536/sizeof(uint64_t));
    cout<<"Lines:"<<(unsigned)lines<<endl;
    uint64_t m_addrMask = static_cast<uint64_t>(65536/sizeof(uint64_t)) - 1U; //all bits are set
    PRINT_B(lines,m_addrMask);
    cout<<"Addr Mask: "<<m_addrMask<<endl;

    uint64_t actvAddrGroup = 1U;
    cout<<"Loop start"<<endl;
    do
    {
        if (tempF(actvAddrGroup) == false) // in case the stuck-at high analysis has not failed
        {
            //
        }
        else
        {
            break;
        }
        actvAddrGroup |= (actvAddrGroup << 1);
        if (actvAddrGroup > m_addrMask)
        {
            break;
        }
    } while (true); 

    bitset<64> DP(G_DATAPATTERN);
    bitset<64> ADP(G_ANTIDATAPATTERN);

    cout<<"Data Pattern:"<<DP <<endl;
    cout<<"AntiDate pattern:"<<ADP<<endl;
}
