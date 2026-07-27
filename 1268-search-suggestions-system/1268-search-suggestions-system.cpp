class Solution {
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
    class Trie{
    public:    
        TrieNode* root;
        Trie(){
            root=new TrieNode('-');
        }
        void insertword(TrieNode* root,string word){
            if(word.length()==0){
                root->isTerminal=true;
                return;
            }
            int idx=word[0]-'a';
            TrieNode* child;
            if(root->children[idx]==NULL){
                child=new TrieNode(word[0]);
                root->children[idx]=child;
            }
            else{
                child=root->children[idx];
            }
            insertword(child,word.substr(1));
        }
        void insert(string word){
            insertword(root,word);
        }
        void printSuggestions(TrieNode* curr,vector<string> &temp,string prefix){
            if(curr->isTerminal){
                temp.push_back(prefix);
            }
            if(temp.size()==3) return;
            for(char ch='a';ch<='z';ch++){
                if(temp.size() == 3) return;
                TrieNode* next=curr->children[ch-'a'];
                if(next!=NULL){
                    prefix.push_back(ch);
                    printSuggestions(next,temp,prefix);
                    prefix.pop_back();
                }
            }
        }
        vector<vector<string>> getSuggestions(string  word){
            vector<vector<string>> ans;
            TrieNode* prev=root;
            string prefix="";
            for(int i=0;i<word.length();i++){
                char lastch=word[i];
                prefix.push_back(lastch);
                vector<string> temp;
                TrieNode* curr=prev->children[lastch-'a'];
                if(curr==NULL){
                    while(i < word.length()){
                        ans.push_back({});
                        i++;
                    }
                    break;
                }
                printSuggestions(curr,temp,prefix);
                ans.push_back(temp);
                prev=curr;
            }
            return ans;
        }
    };
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* t=new Trie();
        for(int i=0;i<products.size();i++){
            t->insert(products[i]);
        }
        return t->getSuggestions(searchWord);
    }
};