class Solution { 
public: 
    bool checkstring(string s1, string s2, int i, int j,
                     unordered_map<char,int> map1,
                     unordered_map<char,int> map2) { 

        if(map1 == map2) { 
            return true; 
        }

        if(j == s2.size() - 1) {
            return false;
        }

        map2[s2[i]]--;

        if(map2[s2[i]] == 0) {
            map2.erase(s2[i]);
        }

        i++;
        j++;

        map2[s2[j]]++;

        return checkstring(s1, s2, i, j, map1, map2);
    } 

    bool checkInclusion(string s1, string s2) { 

        if(s1.size() > s2.size()) {
            return false;
        }

        int i = 0; 
        int j = s1.size() - 1; 

        unordered_map<char,int> map1; 
        unordered_map<char,int> map2; 

        for(char c : s1) { 
            map1[c]++; 
        } 

        for(int k = 0; k < s1.size(); k++) { 
            map2[s2[k]]++; 
        } 

        return checkstring(s1, s2, i, j, map1, map2);
    } 
};