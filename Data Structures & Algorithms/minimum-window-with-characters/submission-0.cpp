class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> map1;
        int n = s.size();

        // Frequency map for t
        for(char c : t){
            map1[c]++;
        }

        int minLen = INT_MAX;
        int startIndex = 0;

        for(int i = 0; i < n; i++){

            unordered_map<char,int> map2 = map1;

            // Check first character
            if(map2.find(s[i]) != map2.end()){
                map2[s[i]]--;

                if(map2[s[i]] == 0){
                    map2.erase(s[i]);
                }
            }

            for(int j = i; j < n; j++){

                // Skip first character because already processed
                if(j != i && map2.find(s[j]) != map2.end()){

                    map2[s[j]]--;

                    if(map2[s[j]] == 0){
                        map2.erase(s[j]);
                    }
                }

                // All characters found
                if(map2.empty()){

                    int len = j - i + 1;

                    if(len < minLen){
                        minLen = len;
                        startIndex = i;
                    }

                    break;
                }
            }
        }

        if(minLen == INT_MAX){
            return "";
        }

        return s.substr(startIndex, minLen);
    }
};