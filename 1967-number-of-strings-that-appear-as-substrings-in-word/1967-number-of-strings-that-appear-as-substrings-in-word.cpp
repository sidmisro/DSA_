/*Approach:
-Iterate through each string in the patterns vector.
-For each pattern check if it is substring of word .
-Time complexity: O(m*n), where n = number of patterns, m = length of the word.
-Space complexity: O(1).
*/
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for(int i = 0; i < patterns.size(); i++) {
            if(word.find(patterns[i]) != string::npos) {
                ans++;
            }
        }
        return ans;
    }
};
