class Solution {
public:
    /*
        - anagrams are when two strings share the same characters
          and it doesn't matter what kind of arrangement they are in
        - constraints: the two strings will consist of only lowercase
                       English letters
        - things to think about:
            - if two strings are not same length, we know one string
              doesn't contain a character that the other string has
            - if both strings are empty, should return true (empty set)
            - complexity: want efficient solution

        - approach:
            - [] --> 26 (english alphabet) | --> 128 for ascii | --> x for z
            - [ 1 0 1 0 0 0 0 0 ... 1 ] --> s pass
            - [ 0 0 0 0 0 0 0 0 ... 0 ] --> t pass --> if negative val ever, false

        - complexity:
            - O(S + T) Time --> iterating through S and T separately
            - O(1) Space    --> we know size of look-up table beforehand
    */
        
    bool isAnagram(string s, string t) {
        // Base Case - strings not same size
        if(s.size() != t.size())
            return false;

        // Create look-up table (size 26 for English alphabet)
        int alphabet[26] = { 0 };

        // 1st Pass : s
        for(int i = 0; i < s.size(); i++){
            // Treat 'a' as index 0 for [0, 25]
            int index = s[i] - 'a';
            alphabet[index] += 1;
        }

        // 2nd Pass : t
        for(int i = 0; i < t.size(); i++){
            // Counter the value for this index (should be 0)
            int index = t[i] - 'a';
            alphabet[index] -= 1;

            // If we hit a negative value, character exist in t but not s
            if(alphabet[index] < 0)
                return false;
        }

        // By default, return true
        return true;
    }
};
