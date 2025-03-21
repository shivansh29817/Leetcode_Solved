class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSumCount;
        prefixSumCount[0] = 1;
        return dfs(root, 0, targetSum, prefixSumCount);
    }

private:
    int dfs(TreeNode* node, long long currentSum, int targetSum, unordered_map<long long, int>& prefixSumCount) {
        if (!node) return 0;
        currentSum += node->val;
        int paths = prefixSumCount[currentSum - targetSum];
        prefixSumCount[currentSum]++;
        paths += dfs(node->left, currentSum, targetSum, prefixSumCount);
        paths += dfs(node->right, currentSum, targetSum, prefixSumCount);
        prefixSumCount[currentSum]--;
        return paths;
    }
};