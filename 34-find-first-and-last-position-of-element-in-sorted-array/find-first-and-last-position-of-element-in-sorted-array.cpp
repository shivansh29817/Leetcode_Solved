class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
         vector<int> result(2,-1); // arr vector of size 2 {-1,-1}

         //searching in the left part
        int low = 0;
        int high = n -1;
        while(low <= high){
            int mid = low+ (high - low )/2;
            if(nums[mid] < target){
                low = mid + 1;
             }
             else{
                high = mid -1; 
             } 
            
        }

        if(low < n && nums[low] == target){ // traversing through each part 
            result[0] = low; // updating the left most
        }
        else{
            return result; //target not found
        }

        //searching in the righmost 
               high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;  // Correct mid calculation
            if (nums[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        result[1] = high;  // Update rightmost position

        return result;
    }
            
};