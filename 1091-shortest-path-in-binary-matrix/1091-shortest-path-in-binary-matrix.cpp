class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        pair<int,int>source={0,0};
        pair<int,int>destination={n-1,n-1};
        if(grid[0][0]==1)
            return -1;
        // Edge Case: if the source is only the destination.
        if (source.first == destination.first &&
            source.second == destination.second)
            return 1;

        // Create a queue for storing cells with their distances from source
        // in the form {dist,{cell coordinates pair}}.
        queue<pair<int, pair<int, int>>> q;
        int m = grid[0].size();

        // Create a distance matrix with initially all the cells marked as
        // unvisited and the source cell as 0.
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[source.first][source.second] = 1;
        q.push({1, {source.first, source.second}});

        // The following delta rows and delts columns array are created such that
        // each index represents each adjacent node that a cell may have 
        // in a direction.
        int dr[] = {-1, 0, 1, 0,-1,+1,-1,+1};
        int dc[] = {0, 1, 0, -1,+1,+1,-1,-1};

        // Iterate through the maze by popping the elements out of the queue
        // and pushing whenever a shorter distance to a cell is found.
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            // Through this loop, we check the 4 direction adjacent nodes
            // for a shorter path to destination.
            for (int i = 0; i < 8; i++)
            {
                int newr = r + dr[i];
                int newc = c + dc[i];

                // Checking the validity of the cell and updating if dist is shorter.
                if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] 
                == 0 && dis + 1 < dist[newr][newc])
                {
                    dist[newr][newc] = 1 + dis;

                    // Return the distance until the point when
                    // we encounter the destination cell.
                    if (newr == destination.first &&
                        newc == destination.second)
                        return dis + 1;
                    q.push({1 + dis, {newr, newc}});
                }
            }
        }
        // If no path is found from source to destination.
        return -1;
    }
};