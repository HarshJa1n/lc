class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;

        int shifts = 0;
        while (n > 1) {
            if (n & 1) return false; // if the last bit is 1, it's not a power of four
            n >>= 1; // right shift
            shifts++;
        }
        return (shifts % 2 == 0);
    }
};