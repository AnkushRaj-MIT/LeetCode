class Solution {
public:
    int solver(int idx,vector<string>& words, vector<int> &freq, vector<int>& score){
        if(idx==words.size()) return 0;
        int notTake=solver(idx+1,words,freq,score);//option:1 skip the word
        string word=words[idx];//option:2 take the word
        int wordScore=0;
        bool possible=true;
        for(char ch:word){
            freq[ch-'a']--;
            if(freq[ch-'a']<0) possible =false;
            wordScore+=score[ch-'a'];
        }
        int take=0;
        if(possible) take+=wordScore + solver(idx+1,words,freq,score);
        for(char ch:word){
            freq[ch-'a']++;
        }
        return max(take,notTake);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26,0);
        for(char ch:letters){
            freq[ch-'a']++;
        }
        return solver(0,words,freq,score);
    }
};