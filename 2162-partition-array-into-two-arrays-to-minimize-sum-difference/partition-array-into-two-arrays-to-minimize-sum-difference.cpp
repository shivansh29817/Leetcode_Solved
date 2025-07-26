#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int minimumDifference(std::vector<int>& nums) {
        int N = nums.size();
        int n = N / 2;
        long long total_sum = std::accumulate(nums.begin(), nums.end(), 0LL);

        std::vector<int> left_half(nums.begin(), nums.begin() + n);
        std::vector<int> right_half(nums.begin() + n, nums.end());

        std::vector<std::vector<int>> left_sums(n + 1);
        generate_subset_sums(left_half, n, left_sums);

        std::vector<std::vector<int>> right_sums(n + 1);
        generate_subset_sums(right_half, n, right_sums);

        for (int i = 0; i <= n; ++i) {
            std::sort(right_sums[i].begin(), right_sums[i].end());
        }

        int min_diff = INT_MAX;

        for (int i = 0; i <= n; ++i) {
            int j = n - i;
            
            for (int s_left : left_sums[i]) {
                long long target = (total_sum / 2) - s_left;

                auto& search_space = right_sums[j];
                auto it = std::lower_bound(search_space.begin(), search_space.end(), target);

                if (it != search_space.end()) {
                    long long s_right = *it;
                    long long current_partition_sum = s_left + s_right;
                    min_diff = std::min(min_diff, (int)std::abs(total_sum - 2 * current_partition_sum));
                }

                if (it != search_space.begin()) {
                    it--;
                    long long s_right = *it;
                    long long current_partition_sum = s_left + s_right;
                    min_diff = std::min(min_diff, (int)std::abs(total_sum - 2 * current_partition_sum));
                }
            }
        }
        return min_diff;
    }

private:
    void generate_subset_sums(const std::vector<int>& arr, int n, std::vector<std::vector<int>>& sums) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            int current_sum = 0;
            int set_bits = 0;
            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    current_sum += arr[i];
                    set_bits++;
                }
            }
            sums[set_bits].push_back(current_sum);
        }
    }
};