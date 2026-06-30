class Solution {
public:
    long long countVowels(string word) {
        long long ans=0;
        long long sum=0;
        for(int i=0;i<word.length();i++){
            if(word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u') sum+=i+1;
            ans+=sum;
        }
        return ans;
    }
};