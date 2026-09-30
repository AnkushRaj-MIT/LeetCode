class WordFilter {
public:
    class TrieNode{
    public:
        TrieNode* children[27];
        int idx;
        TrieNode(){
            for(int i=0;i<27;i++){
                children[i]=NULL;
            }
            idx=-1;
        }    
    };

    TrieNode* root=new TrieNode();

    void insert(string word,int index){
        TrieNode* curr=root;
        for(char ch:word){
            int idx;
            if(ch=='#') idx=26;
            else idx=ch-'a';
            if(curr->children[idx]==NULL){
                curr->children[idx]=new TrieNode();
            }
            curr=curr->children[idx];
            curr->idx=index;
        }
    }

    WordFilter(vector<string>& words) {
        int n=words.size();
        for(int i=0;i<n;i++){
            string word=words[i];
            for(int j=0;j<word.length();j++){
                string suf=word.substr(j);
                insert(suf+"#"+word,i);
            }
            insert("#"+word,i);
        }
    }
    
    int f(string pref, string suff) {
        string search=suff+"#"+pref;
        TrieNode* curr=root;
        for(char ch:search){
            int idx;
            if(ch=='#') idx=26;
            else idx=ch-'a';
            if(curr->children[idx]==NULL) return -1;
            curr=curr->children[idx];
        }
        return curr->idx;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */