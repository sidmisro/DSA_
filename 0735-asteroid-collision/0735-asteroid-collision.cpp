/*Approach: 
-Use a stack to keep track of the surviving asteroids.
-For each asteroid :
    -If it is moving right, push it into the stack.
    -If it is moving left, resolve collisions with right-moving asteroids on the stack.
    -Continue the collisions until one asteroid survives or both are destroyed.
Time complexity: O(n).
Space complexity: O(n).
*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        vector<int> result;
        for(int i = 0; i < n; i++) {
            bool destroyed = false;
            while(!st.empty() && st.top() > 0 && asteroids[i] < 0) {
                if(st.top() < abs(asteroids[i])) {
                    st.pop();
                }
                else if(st.top() == abs(asteroids[i])) {
                    st.pop();
                    destroyed = true;
                    break;
                }
                else {
                    destroyed = true;
                    break;
                }
            }
            if(!destroyed) {
                st.push(asteroids[i]);
            }
        }
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
