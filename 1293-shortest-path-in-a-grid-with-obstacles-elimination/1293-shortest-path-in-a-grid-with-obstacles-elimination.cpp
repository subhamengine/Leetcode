class Solution 
{
public:
    int shortestPath(vector<vector<int>>& grid, int k) 
    {
        int m = grid.size(), n = grid[0].size();
        if (k >= m + n - 2) return m + n - 2;
        
        deque<vector<int>> dq;
        dq.push_back({0,0,k,0});
        set<vector<int>> seen;
        
        vector<pair<int,int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!dq.empty())
        {
            vector<int> p = dq.front(); dq.pop_front();
            int i = p[0], j = p[1], k = p[2], s = p[3];
            if (i == m-1 && j == n-1) return s;
            
            for (auto d : dirs)
            {
                int ii = i + d.first, jj = j + d.second;
                if (0 <= ii && ii < m && 0 <= jj && jj < n && k >= grid[ii][jj])
                {
                    vector<int> step = {ii, jj, k-grid[ii][jj]};
                    if (seen.count(step) == 0) 
                    {
                        seen.insert(step);
                        step.push_back(s+1);
                        dq.push_back(step);
                    }
                }
            }
        }
        
        return -1;
    }
};