class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> sublist;
        for(string str : strs){
            string og = str;
            sort(str.begin(), str.end());
            sublist[str].push_back(og);
        }

        vector<vector<string>> res;
        unordered_map<string, vector<string>>::iterator mit;
        for(mit = sublist.begin(); mit != sublist.end(); ++mit)
            res.push_back(mit->second);

        return res;
    }
};
