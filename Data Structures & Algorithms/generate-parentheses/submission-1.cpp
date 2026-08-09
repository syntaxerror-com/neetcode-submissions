class Solution {
public:

    void create(string current, int n, int k, vector<string>& results) {

        if(current.length() == 2 * n) {
            if(k == 0)
                results.push_back(current);
            return;
        }
       if(k<n){
        create(current + "(", n, k + 1, results);
        }
        if(k>0){
        create(current + ")", n, k - 1, results);
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> results;

        create("(", n, 1, results);

        return results;
    }
};