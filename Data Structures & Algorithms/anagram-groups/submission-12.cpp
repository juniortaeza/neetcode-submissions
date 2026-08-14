class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> group;

        for(int i = 0; i < strs.size(); i++){
            string str = strs[i];
            int alphabet[26] = { 0 };
            for(int j = 0; j < str.size(); j++)
                alphabet[str[j] - 'a'] += 1;

            string key = "";
            for(int k = 0; k < 26; k++)
                key += "-" + to_string(alphabet[k]);

            group[key].push_back(str);
        }

        vector<vector<string>> result;
        unordered_map<string, vector<string>>::iterator it;
        for(it = group.begin(); it != group.end(); ++it)
            result.push_back(it->second);

        return result;
    }
};
