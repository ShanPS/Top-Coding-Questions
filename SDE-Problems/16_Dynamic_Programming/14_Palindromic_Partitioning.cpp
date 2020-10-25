/*
Problem: Given a string str, a partitioning of the string is a palindrome partitioning if every 
sub-string of the partition is a palindrome. 
Determine the fewest cuts needed for palindrome partitioning of given string.

link: https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1
solution: https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/
*/

class Solution{
public:
    int palindromicPartition(string str) {
        int n = str.size();
        int cuts[n];
        bool palindrome[n][n];
        
        for(int i=0; i<n; i++)
            palindrome[i][i] = true;
        for(int len=2; len<=n; len++) {
            for(int i=0; i<n-len+1; i++) {
                int j = i+len-1;
                
                if(len == 2)
                    palindrome[i][j] = (str[i] == str[j]);
                else
                    palindrome[i][j] = (str[i] == str[j]) && palindrome[i+1][j-1];
            }
        }
        for(int i=0; i<n; i++) {
            if(palindrome[0][i] == true)
                cuts[i] = 0;
            else {
                cuts[i] = INT_MAX;
                for(int j=0; j<i; j++) {
                    if(palindrome[j+1][i] == true && 1+cuts[j]<cuts[i])
                        cuts[i] = 1 + cuts[j];
                }
            }
        }        
        return cuts[n-1];
    }
};


// SOLUTION USING MEMOIZATION
// class Solution{
//     bool isPalindrome(string &str, int left, int right) {
//         while(left < right) {
//             if(str[left] != str[right])
//                 return false;
//             left++; right--;
//         }
//         return true;
//     }
    
//     string convert(int num1, int num2) {
//         return to_string(num1) + "" + to_string(num2);
//     }
    
//     int memoPalindromicPartition(string &str, int i, int j, unordered_map<string, int> &memo) {
//         if(i >= j) return 0;
        
//         string ij = convert(i, j);
//         if(memo.find(ij) != memo.end())
//             return memo[ij];
        
//         if(isPalindrome(str, i, j)) {
//             memo[ij] = 0;
//             return 0;
//         }
        
//         int minCuts = INT_MAX;
//         for(int k=i; k<j; k++) {
//             int left_min = INT_MAX;
//             int right_min = INT_MAX;
//             string left = convert(i, k);
//             string right = convert(k+1, j);
            
//             if(memo.find(left) != memo.end())
//                 left_min = memo[left];
//             if(memo.find(right) != memo.end())
//                 right_min = memo[right];
//             if(left_min == INT_MAX)
//                 left_min = memoPalindromicPartition(str, i, k, memo);
//             if(right_min == INT_MAX)
//                 right_min = memoPalindromicPartition(str, k+1, j, memo);
            
//             minCuts = min(minCuts, left_min + 1 + right_min);
//         }
//         memo[ij] = minCuts;
//         return minCuts;
//     }
    
// public:
//     int palindromicPartition(string str) {
//         unordered_map<string, int> memo;
        
//         return memoPalindromicPartition(str, 0, str.size()-1, memo);
//     }
// };