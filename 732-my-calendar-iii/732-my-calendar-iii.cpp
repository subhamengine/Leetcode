class MyCalendarThree {
public:
    map<int,int>mp;
    int mxC = 0;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int c = 0;
        for(auto it:mp){
            c+=it.second;
            mxC = max(c,mxC);
        }
        return mxC;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */