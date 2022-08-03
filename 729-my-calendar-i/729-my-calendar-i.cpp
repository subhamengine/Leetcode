class MyCalendar {
public:
    set<pair<int,int>>st;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(st.empty()){
            st.insert({start,end});
            return true;
        }
        auto it = st.lower_bound({start,end});
        if(it!=st.end() and end > it->first)return false;
        if(it != st.begin() and (--it)->second > start) return false;
        st.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */