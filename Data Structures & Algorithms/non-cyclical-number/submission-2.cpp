class Solution {
public:
    // bool isHappy(int n) {
    //     int modu;
    //     int count = 0;
    //     while (n) {
    //         modu = n%10;
    //         if (modu != 0) {
    //             count++;
    //             if (count > 1)
    //                 return false;
    //         }
    //         n /= 10;
    //     }
    //     return true;
    // }
    int sumOfSquares(int n) {
        int output = 0;

        while (n > 0) {
            int digit = n % 10;
            digit = digit * digit;
            output += digit;
            n /= 10;
        }
        return output;
    }
    bool isHappy(int n) {
        unordered_set<int> us;
        while (us.find(n) == us.end()) {
            us.insert(n);
            n = sumOfSquares(n);
            if (n==1) return true;
        }
        return false;
    }
};
