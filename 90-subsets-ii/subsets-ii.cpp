class Solution {
public:
     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ret;
    ret.push_back(vector<int>());
    sort(nums.begin(), nums.end());
    vector<vector<int>> sub;
    for (int i = 0; i < nums.size(); ++i) {
        if (i == 0 || nums[i] != nums[i-1]) sub = ret;
        for (auto& j:sub) j.push_back(nums[i]);
        ret.insert(ret.end(), sub.begin(), sub.end());
    }
    return ret;
}
};