class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> st;

        for(int i = 0; i < temperatures.size(); i++){
            while(!st.empty() && temperatures[i] > st.top().first){
                pair<int, int> p = st.top(); st.pop();
                int temp = p.first, index = p.second;
                res[index] = i - index;
            }
            st.push({temperatures[i], i});
        }

        return res;
    }
};
