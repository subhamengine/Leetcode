class Solution {
public:
    int parent[26];
    int fetchParent(int index ){
        if(parent[index] == index){
            return index;
        }
        return fetchParent(parent[index]);
    }
    
    bool equationsPossible(vector<string>& equations) {
        for(int i = 0 ; i < 26 ; i++){
            parent[i] = i;
        }
        
        for(auto eq : equations){
            char e = eq[1];
            if(e == '='){
                int var1 = fetchParent(eq[0]-'a');
                int var2 = fetchParent(eq[3]-'a');
                if(var1 != var2){
                    parent[var2] = var1;
                }
            }
        }
        
        for(auto eq:equations){
            char e = eq[1];
            if(e == '!'){
                int var1 = fetchParent(eq[0]-'a');
                int var2 = fetchParent(eq[3]-'a');
                if(var1 == var2) return false;
            }
        }
        return true;
    }
};