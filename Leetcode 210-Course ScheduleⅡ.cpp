//faster than 80%

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        vector<vector<int>> graph(numCourses,vector<int>());
        vector<int> degree(numCourses, 0);
        for(auto val: prerequisites)
        {
                graph[val[1]].push_back(val[0]);
                degree[val[0]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (degree[i] == 0) q.push(i);
        while (!q.empty()) {
            int curr = q.front(); result.push_back(curr); q.pop(); numCourses--;
        for (auto next: graph[curr])
            if (--degree[next] == 0) q.push(next);
        }
        
        if (numCourses!=0) return {};
        else return result;
    }
};