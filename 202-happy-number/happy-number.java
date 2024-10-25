import java.util.HashSet;
import java.util.Set;

class Solution {
    public boolean isHappy(int n) {
        Set<Integer> visit = new HashSet<>(); // MEMORY O(n)
        while (!visit.contains(n)) {
            visit.add(n);
            n = sumOfSquares(n);
            if (n == 1) {
                return true;
            }
        }
        return false;
    }

    public int sumOfSquares(int n) {
        int output = 0;
        while (n > 0) {
            int digit = n % 10;
            digit = digit * digit;
            output += digit;
            n = n / 10;
        }
        return output;
    }
}