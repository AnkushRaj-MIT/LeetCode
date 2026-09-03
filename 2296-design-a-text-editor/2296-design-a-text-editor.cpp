class TextEditor {
public:
    class ListNode{
    public:
        char val;
        ListNode* prev;
        ListNode* next;
        ListNode(char val){
            this->val=val;
            prev=next=NULL;
        }
    };

    ListNode* head;
    ListNode* cursor;

    TextEditor() {
        head = new ListNode('#');
        cursor = head;
    }

    void insert(char ch){
        ListNode* newNode=new ListNode(ch);
        newNode->prev=cursor;
        newNode->next=cursor->next;
        if(cursor->next!=NULL){
            cursor->next->prev=newNode;
        }
        cursor->next=newNode;
        cursor=newNode;
    }

    void addText(string text) {
        for(char ch:text){
            insert(ch);
        }
    }
    
    int deleteText(int k) {
        int count=0;
        while(k>0 && cursor!=head){
            ListNode* temp=cursor;
            cursor=cursor->prev;
            cursor->next=temp->next;
            if(temp->next!=NULL){
                temp->next->prev = cursor;
            }
            delete(temp);
            count++;
            k--;
        }
        return count;
    }
    
    string cursorLeft(int k) {
        while(k > 0 && cursor != head) {
            cursor = cursor->prev;
            k--;
        }
        return getLast10();
    }
    
    string cursorRight(int k) {
        while(k > 0 && cursor->next != NULL) {
            cursor = cursor->next;
            k--;
        }
        return getLast10();
    }
    
    string getLast10(){
        string ans = "";
        ListNode* temp = cursor;
        while(temp != head && ans.size() < 10) {
            ans += temp->val;
            temp = temp->prev;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */