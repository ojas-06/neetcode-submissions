class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        for(int i=0;i<16;i++){
            if(((n >> i) & 1) != ((n >> (31-i)) & 1)){
                n ^= (1U << i);
                n ^= (1U << (31-i));
            }
        }
        return n;
    }
};