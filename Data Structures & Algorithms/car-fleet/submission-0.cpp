class Solution {
public:

    static bool positionComparator(const pair<double, double>& a, const pair<double, double>& b){
        return a.first < b.first;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // create pair <position, speed>
        int n = position.size();
        vector<pair<double, int>> pairs(n);
        for(int i = 0; i < position.size(); i++)
            pairs[i] = { position[i], speed[i] };

        // sort the vector of pairs by position
        sort(pairs.begin(), pairs.end(), positionComparator);

        // iterate through the vector in reverse order using stack to hold car fleetts
        stack<double> fleetStack;
        for(int i = pairs.size()-1; i >= 0; i--){
            int p = pairs[i].first, s = pairs[i].second;
            fleetStack.push((double) (target - p) / s);
            if(fleetStack.size() >= 2){
                double val1 = fleetStack.top(); fleetStack.pop();
                double val2 = fleetStack.top(); fleetStack.pop();
                // if cars collide, keep fleet speed
                if(val1 <= val2){
                    fleetStack.push(val2);
                } 
                // otherwise, restore popped elements
                else {
                    fleetStack.push(val2);
                    fleetStack.push(val1);
                }
        
            }
        }

        // stack size at end will hold all arriving car fleets
        return fleetStack.size();
    }
};
