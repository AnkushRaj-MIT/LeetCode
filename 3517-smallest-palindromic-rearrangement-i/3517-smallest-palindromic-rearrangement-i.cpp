class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.length();
        if(n%2==0){
            sort(s.begin(),s.begin()+n/2);
            string str=s.substr(0,n/2);
            string rev=str;
            reverse(rev.begin(),rev.end());
            return str+rev;
        }else{
            char middle=s[n/2];
            sort(s.begin(),s.begin()+n/2);
            string str=s.substr(0,n/2);
            string rev=str;
            reverse(rev.begin(),rev.end());
            return str+middle+rev;
        }
    }
};