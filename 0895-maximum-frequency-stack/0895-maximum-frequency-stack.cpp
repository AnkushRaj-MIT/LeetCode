class FreqStack {
public:
    unordered_map<int,int> freq;
    int maxFreq;
    unordered_map<int,stack<int>> group;

    FreqStack() {
        
    }

    void push(int val) {
        freq[val]++;
        int f=freq[val];
        group[f].push(val);
        maxFreq=max(maxFreq,f);
    }
    
    int pop() {
        int val=group[maxFreq].top();
        group[maxFreq].pop();
        freq[val]--;
        if(group[maxFreq].empty()) maxFreq--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */