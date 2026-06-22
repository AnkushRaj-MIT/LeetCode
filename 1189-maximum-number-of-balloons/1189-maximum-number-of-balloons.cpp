class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> m;
        for(char ch:text){
            m[ch]++;
        }
        string req="balloon";
        int ans=0;
        return min({m['b'],m['a'],m['l']/2,m['o']/2,m['n']});
    }
};