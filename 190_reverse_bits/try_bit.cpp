class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t digit = 1;
        uint32_t ans = 0;
        for(int i = 0; i < 32; ++i){
            ans = ans << 1;
            ans += (digit & n ? 1 : 0);
            digit = digit << 1;
        }
        return ans;
    }
};
