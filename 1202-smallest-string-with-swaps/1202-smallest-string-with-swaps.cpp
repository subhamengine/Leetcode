class Solution {
public:
    vector<int> indices;                                                 //Stores indices of same group.
    vector<bool> visited;
    vector<vector<int>> adjList;
    string indiceString;                                                 //Stores  string formed by indices in the same group.
    void dfs(string &s,int n)                                             //DFS to get all indices in same group.
    {
        visited[n]=true;
        indices.push_back(n);
        indiceString+=s[n];
        for(int &i:adjList[n])
            if(!visited[i])
               dfs(s,i);
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) 
    {
        adjList.resize(s.length());
        visited.resize(s.length(),false);
        for(vector<int> &v:pairs)                               //Create adjacency list using the indice pairs
            adjList[v[0]].push_back(v[1]),adjList[v[1]].push_back(v[0]);
        for(int i=0;i<s.length();i++)
            if(!visited[i])
            {
                indiceString="";                              //Clear string formed by one group of indices before finding next group.
                indices.clear();                             //Clear indices vector before finding another group.
                dfs(s,i);
                sort(indiceString.begin(),indiceString.end());                    //Sort the characters in the same group.
                sort(indices.begin(),indices.end());                                  //Sort the indices in the same group.            
                for(int i=0;i<indices.size();i++)          //Replace all the indices in the same group with the sorted characters.
                    s[indices[i]]=indiceString[i];
            }
        return s;
    }
};