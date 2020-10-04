/*
Problem: Given an integer array.
Find the contiguous subarray within the given array (containing at least one number) 
which has the largest product.

link: https://leetcode.com/problems/maximum-product-subarray/
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> products;
        int product = 1;
        int answer = INT_MIN;
        int startNegNum = 0;
        
        for (int num : nums) {
            product *= num;
            products.push_back(product);
            
            if(product == 0)
                product = 1;
        }
        
        for (int num : products) {
            if (num < 0) {
                if(startNegNum == 0) {
                    startNegNum = num;
                    answer = max(answer, num);
                }
                else {
                    answer = max(answer, num/startNegNum);
                }
            }
            else if (num == 0) {
                startNegNum = 0;
                answer = max(answer, num);
            }
            else {
                answer = max(answer, num);
            }
        }
        
        return answer;
    }
};


// Another approach:

// int maxProduct(vector<int>& nums) {
// 	int globalMax = nums[0];
// 	int localMax = nums[0], localMin = nums[0];
// 	int n = nums.size();

// 	for(int i=1; i<n; i++) {
// 		int curMax = max(nums[i], max(localMax*nums[i], localMin*nums[i]));
// 		int curMin = min(nums[i], min(localMax*nums[i], localMin*nums[i]));

// 		globalMax = max(globalMax, curMax);
// 		localMax = curMax;
// 		localMin = curMin;
// 	}

// 	return globalMax;
// }