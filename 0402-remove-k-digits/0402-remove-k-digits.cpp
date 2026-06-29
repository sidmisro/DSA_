class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = "";
        int n = num.length();
        if(k == n) {
            return "0";
        }
        stack<char> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k > 0) {
            st.pop();
            k--;
        }
        if(st.empty()) {
            return "0";
        }
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        int nonzeroidx = -1;
        for(int i = 0; i < result.length(); i++) {
            if(result[i] != '0') {
                nonzeroidx = i;
                break;
            }
        }
        if (nonzeroidx == -1) {
            return "0";
        }
        return result.substr(nonzeroidx, result.length()-nonzeroidx+1);
    }
};