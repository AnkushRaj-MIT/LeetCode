class WordDictionary {
public:
    class TrieNode{
    public:    
        TrieNode* children[26];
        bool isTerminal;
        TrieNode(){
            isTerminal=false;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
        }
    };

    TrieNode* root;

    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr=root;
        for(char ch:word){
            int idx=ch-'a';
            if(curr->children[idx]==NULL){
                curr->children[idx]=new TrieNode;
            }
            curr=curr->children[idx];
        }
        curr->isTerminal=true;
    }

    bool dfs(TrieNode* curr,string &word,int i){
        if(i==word.size()) return curr->isTerminal;
        char ch=word[i];
        if(ch!='.'){
            int idx=ch-'a';
            if(curr->children[idx]==NULL) return false;
            return dfs(curr->children[idx],word,i+1);
        }
        else{// for '.'
            for(int j=0;j<26;j++){
                if(curr->children[j]!=NULL){
                    if(dfs(curr->children[j],word,i+1)) return true;
                }
            }
            return false;
        }
    }

    bool search(string word) {
        return dfs(root,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */