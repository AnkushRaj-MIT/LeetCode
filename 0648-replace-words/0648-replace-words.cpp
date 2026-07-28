class Solution {
public:
    class TrieNode{
    public:
       TrieNode* children[26];
       bool isTerminal;
       TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
       }
    };
    TrieNode* root=new TrieNode();
    void insert(string word){
        TrieNode* curr=root;
        for(char ch:word){
            int idx=ch-'a';
            if(curr->children[idx]==NULL){
                curr->children[idx]=new TrieNode();
            }
            curr=curr->children[idx];
        }
        curr->isTerminal=true;
    }
    string searchWord(string word){
        TrieNode* curr=root;
        string ans="";
        for(char ch:word){
            int idx=ch-'a';
            if(curr->children[idx]==NULL) return word;
            curr=curr->children[idx];
            ans+=ch;
            if(curr->isTerminal) return ans;
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        for(string rootWord:dictionary){
            insert(rootWord);
        }
        stringstream ss(sentence);
        string word;
        string ans="";
        while(ss>>word){
            ans+=searchWord(word);
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};