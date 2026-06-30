class Solution {
public:
    long long countVowels(string word) {
        //instad of generating all subbstring ,count how many substring belongs  to each voweleach vowel
        long long ans = 0;
        long long n = word.size();
        for (long long i = 0; i < n; i++) {
            char ch = word[i];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                ans += (i + 1) * (n - i);
            }
        }
        return ans;
    }
};