class Solution {
public:
    bool ispalindrome(string current){
        int i = 0;
        int j = current.size() - 1;

        while(i < j){
            if(current[i] != current[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void create(int index, string current,
                vector<string>& result,
                vector<vector<string>>& results,
                string s) {

        if(index == s.size()) {
            if(current == "")
                results.push_back(result);
            return;
        }

        current.push_back(s[index]);

        // Continue current substring
        create(index + 1, current, result, results, s);

        // Cut here
        if(ispalindrome(current)) {
            result.push_back(current);

            create(index + 1, "", result, results, s);

            result.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {

        vector<string> result;
        vector<vector<string>> results;
        string current = "";

        create(0, current, result, results, s);

        return results;
    }
};