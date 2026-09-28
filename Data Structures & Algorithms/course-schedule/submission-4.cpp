class Solution {
    unordered_map<int, vector<int>> prereqMap;
    unordered_set<int> visitedSet;

public:
    bool dfs(int crs){
        if(visitedSet.contains(crs)) return false;
        if(prereqMap[crs].empty())   return true;

        visitedSet.insert(crs);
        for(int pre : prereqMap[crs]){
            if(!dfs(pre))
                return false;
        }
        visitedSet.erase(crs);

        prereqMap[crs].clear();
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(vector<int>& prereq : prerequisites)
            prereqMap[prereq[0]].push_back(prereq[1]);

        for(int c = 0; c < numCourses; c++){
            if(!dfs(c))
                return false;
        }

        return true;
    }
};
