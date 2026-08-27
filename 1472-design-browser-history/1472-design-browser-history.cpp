class BrowserHistory {
public:
    class Node{
     public:   
        string url;
        Node* next;
        Node* prev;
        Node(string u){
            url=u;
            next=NULL;
            prev=NULL;
        }
    };
    Node* curr;
    BrowserHistory(string homepage) {
        curr=new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode=new Node(url);
        curr->next=newNode;
        newNode->prev=curr;
        curr=newNode;
    }
    
    string back(int steps) {
        while(steps-- && curr->prev!=NULL){
            curr=curr->prev;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while(steps-- && curr->next!=NULL){
            curr=curr->next;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */