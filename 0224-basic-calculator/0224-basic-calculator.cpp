class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        long long num = 0, sign = 1, res = 0;
        for(auto& it: s) {
            if(isdigit(it)) {
                num = num * 10 + (it-'0');
            } else if(it == '+') {
                res += (sign * num);
                sign = 1;
                num = 0;
            } else if(it == '-') {
                res += (sign * num);
                sign = -1;
                num = 0; 
            } else if(it == '(') {
                st.push(res);
                st.push(sign);
                num = 0;
                sign = 1;
                res = 0;
            } else if(it == ')'){
                res += (sign * num);
                num = 0;
                int stSign = st.top();st.pop();
                res *= stSign;
                res += st.top();st.pop();
            }
        }
        res += (sign * num);
        return res;
    }
};