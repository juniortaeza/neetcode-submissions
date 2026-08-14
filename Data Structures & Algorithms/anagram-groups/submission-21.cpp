class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(int i = 0; i < strs.size(); i++){
            string og = strs[i];
            string s = strs[i];
            sort(s.begin(), s.end());

            if(m.find(s) == m.end())
                m.insert({s, {og}});
            else
                m.find(s)->second.push_back(og);
        }

        vector<vector<string>> res;
        for(auto key : m){
            res.push_back(key.second);
        }

        return res;
    }
};
