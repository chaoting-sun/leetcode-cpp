class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int> events;
        for (auto& log: logs) {
            int birth = log[0], death = log[1];
            events[birth]++;
            events[death]--;
        }
        int earliestYear = 0;
        int currentPopulation = 0, maxPopulation = 0;
        
        for (auto [year, population]: events) {
            currentPopulation += population;
            if (currentPopulation > maxPopulation) {
                earliestYear = year;
                maxPopulation = currentPopulation;
            }
        }
        return earliestYear;
    }
};

