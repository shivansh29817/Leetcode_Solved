class Solution {
public:
    int reverse(int x) {
        long res = 0;
        int digit;
        while(x != 0) {
            digit = x % 10;
            x /= 10;

            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit >= INT_MAX % 10))
                return 0;
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && digit <= INT_MIN % 10))
                return 0;

            res = (res*10) + digit;
        }
        return res;
    }
};