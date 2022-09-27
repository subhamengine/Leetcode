class Solution {
public:
    string pushDominoes(string dominoes) {
        queue<pair<char,int>>dom;
        for(int i = 0 ; i < dominoes.size() ; i++){
            if(dominoes[i] != '.'){
                dom.push({dominoes[i],i});
            }
        }
        
        while(dom.size()){
            pair<char,int>p = dom.front();
            dom.pop();
            char curChar = p.first;
            int curInd = p.second;
            
            if(curChar == 'L'){
                if(curInd > 0 and dominoes[curInd-1] == '.'){
                    dom.push({'L',curInd-1});
                    dominoes[curInd-1] = 'L'; 
                }
            }
            else if(curChar == 'R'){
                if(curInd < dominoes.size()-1 and dominoes[curInd+1] == '.'){
                    if(curInd + 2 < dominoes.size()  and dominoes[curInd+2] == 'L'){
                        dom.pop();
                    }else{
                        dom.push({'R',curInd+1});
                        dominoes[curInd+1] = 'R'; 
                    }
                }
            }
        }
        return dominoes;
    }
};