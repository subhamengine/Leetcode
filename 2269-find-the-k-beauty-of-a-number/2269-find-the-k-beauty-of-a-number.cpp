class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int j = 0, ans = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if(i-j+1==k){
                string str = s.substr(j,k);
                int temp = stoi(str);
                if(temp!= 0 && num%temp == 0) ans++;
                j++;
            }
        }
        return ans;
    }
};