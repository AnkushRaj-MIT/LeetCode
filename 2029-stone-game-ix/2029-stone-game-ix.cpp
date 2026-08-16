class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> freq(3,0);
        for(int num:stones){
            freq[num%3]++;
        }
        if(freq[0]%2==0){
            return min(freq[1],freq[2])>0;
        }
        return abs(freq[1]-freq[2])>2;
    }
};