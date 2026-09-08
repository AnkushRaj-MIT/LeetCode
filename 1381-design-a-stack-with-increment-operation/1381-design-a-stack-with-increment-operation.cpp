class CustomStack {
public:
    int *st;
    int top=-1;
    int size;
    CustomStack(int maxSize) {
        st=new int[maxSize];
        size=maxSize;
    }
    
    void push(int x) {
        if(top+1<size){
            top++;
            st[top]=x;
        }
    }
    
    int pop() {
        if(top==-1) return -1;
        else{
            int ele=st[top];
            top--;
            return ele;
        }
    }
    
    void increment(int k, int val) {
        k = min(k, top + 1);
        for (int i = 0; i < k; i++) {
            st[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */