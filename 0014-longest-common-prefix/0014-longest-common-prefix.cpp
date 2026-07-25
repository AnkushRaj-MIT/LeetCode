class Solution {
public:
    class TrieNode{
    public:
       char data;
       TrieNode* children[26];
       int childCount;
       bool isTerminal;
       TrieNode(char ch){
           data=ch;
           for(int i=0;i<26;i++){
               children[i]=NULL;
           }
           childCount=0;
           isTerminal=false;
       }
    };
    class Trie{
    public:
        TrieNode* root;
        Trie(){
            root=new TrieNode('-');
        }
        Trie(char ch){
            root=new TrieNode(ch);
        }
        void insertword(TrieNode* root,string word){
            if(word.length()==0){
                root->isTerminal=true;
                return;
            }
            int idx=word[0]-'a';
            char ch=word[0];
            TrieNode* child;
            if(root->children[idx]!=NULL){
                child=root->children[idx];
            }else{
                root->childCount++;
                child=new TrieNode(ch);
                root->children[idx]=child;
            }
            insertword(child,word.substr(1));
        }
        void insert(string key){
            insertword(root,key);
        }
        void lcp(string first,string &ans){
            if(first.empty()) return;
            for(int i=0;i<first.length();i++){
                char ch=first[i];
                if(root->childCount==1){
                    ans.push_back(ch);
                    root=root->children[ch-'a'];
                }
                else break;
                if(root->isTerminal) break;
            }

        }
    };
    string longestCommonPrefix(vector<string>& str) {
        Trie* t=new Trie();
        for(string s:str){
            if(s.size()==0) return "";
            t->insert(s);
        }
        if(str.empty()) return "";
        string first=str[0];
        string ans="";
        t->lcp(first,ans);
        return ans;
    }
};