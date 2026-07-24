class Trie {
public: 
    class TrieNode{
      public:  
        char data;
        TrieNode* children[26];
        bool isTerminal;
        TrieNode(char ch){
            data=ch;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            isTerminal=false;
        }
    };
    TrieNode* root;
    Trie() {
        root=new TrieNode('-');
    }
    void insertWord(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        int idx=word[0]-'a';
        TrieNode* child;
        if(root->children[idx]!=NULL){
            child=root->children[idx];
        }
        else{
            child=new TrieNode(word[0]);
            root->children[idx]=child;
        }
        insertWord(child,word.substr(1));
    }
    void insert(string word) {
        insertWord(root,word);
    }
    bool searchWord(TrieNode* root,string word){
        if(word.length()==0){
            return root->isTerminal;
        }
        int idx=word[0]-'a';
        TrieNode* child;
        if(root->children[idx]!=NULL){
            child=root->children[idx];
            return searchWord(child,word.substr(1));
        }
        else{
            return false;
        }
    }
    bool search(string word) {
        return searchWord(root,word);
    }
    bool startsWithPrefix(TrieNode* root,string word){
        if(word.length()==0){
            return true;
        }
        int idx=word[0]-'a';
        TrieNode* child;
        if(root->children[idx]!=NULL){
            child=root->children[idx];
            return startsWithPrefix(child,word.substr(1));
        }
        else{
            return false;
        }
    }
    bool startsWith(string prefix) {
        return startsWithPrefix(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */