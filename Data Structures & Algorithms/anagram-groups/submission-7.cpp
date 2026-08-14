class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // map that keys sorted string to a vector of matching strings
        map<string, vector<string>> occ;
        for(int i = 0; i < strs.size(); i++){
            string ogStr = strs[i];
            string sortedStr = strs[i];
            sort(sortedStr.begin(), sortedStr.end());
            
            if(occ.find(sortedStr) == occ.end())
                occ.insert({sortedStr, {ogStr}});
            else
                occ[sortedStr].push_back(ogStr);
        }

        // iterate through occurrence map and add all value string vectors to result
        vector<vector<string>> res;
        map<string, vector<string>>::iterator mit;
        for(mit = occ.begin(); mit != occ.end(); ++mit){
            vector<string> strs = mit->second;
            res.push_back(strs);
        }

        return res;
    }
};
