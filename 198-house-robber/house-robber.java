class Solution {
    public int rob(int[] nums) {
    int prevno=0;
        int prevyes=0;
        for(int n:nums){
            int temp = prevno;
            prevno = Math.max(prevno,prevyes);
            prevyes=n+temp;
        }
        return Math.max(prevno,prevyes);
    }
}