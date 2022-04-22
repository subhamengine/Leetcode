class ATM {
public:
    vector<long long>v;
    map<int,int>m;
    ATM() {
        v.resize(5,0);
        m[4] = 500;
        m[3] = 200;
        m[2] = 100;
        m[1] = 50;
        m[0] = 20;
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i = 0 ; i < 5 ; i++){
            v[i]+=banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int>ans(5,0);
        for(int i = 4 ; i>=0 ; i--){
            if(amount>=m[i]){
                int c = amount/m[i];
                if(c > v[i]) c = v[i];
                v[i]-=c;
                amount = amount - (m[i]*c);
                ans[i]+=c;
            }
        }
        if(amount == 0)return ans;
        else {
            for(int i = 0 ; i < 5 ; i++){
                v[i]+=ans[i];
            }
            return {-1};
        }
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */