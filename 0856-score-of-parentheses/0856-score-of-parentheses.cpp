class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                st.push(0);
            }
            else if(s[i] == ')') {
                int score = st.top();
                st.pop();
                st.top() += (score == 0) ? 1 : 2 * score;
            }
        }
        return st.top();
    }
};