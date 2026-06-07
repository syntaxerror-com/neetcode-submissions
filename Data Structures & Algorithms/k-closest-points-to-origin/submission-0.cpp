class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>>pq;
        vector<vector<int>> result;
        for(auto &point:points){
            int a=pow(point[0],2);
            int b=pow(point[1],2);
            int c=a+b;
            pq.push({c,point});
        }
        while(k!=0){
            result.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return result;
    }
};
