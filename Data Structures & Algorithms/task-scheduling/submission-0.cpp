class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) {

        int cycles = 0;

        unordered_map<char,int> map;

        for(char task : tasks){
            map[task]++;
        }

        while(!map.empty()){

            vector<char> temp;

            int cycle = n + 1;

            while(cycle > 0){

                char bestTask = '#';
                int maxFreq = 0;

                // find task with maximum frequency
                for(auto &mp : map){

                    if(mp.second > maxFreq &&
                       find(temp.begin(), temp.end(), mp.first) == temp.end()){

                        maxFreq = mp.second;
                        bestTask = mp.first;
                    }
                }

                // no available task -> idle
                if(bestTask == '#'){

                    if(map.empty()){
                        break;
                    }

                    cycles++;
                    cycle--;
                    continue;
                }

                // execute task
                map[bestTask]--;

                temp.push_back(bestTask);

                if(map[bestTask] == 0){
                    map.erase(bestTask);
                }

                cycles++;
                cycle--;
            }
        }

        return cycles;
    }
};