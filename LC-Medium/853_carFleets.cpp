/*
853. Car Fleet
-----------------
There are n cars at given miles away from the starting mile 0, 
traveling to reach the mile target.
You are given two integer arrays position and speed, both of 
length n, where position[i] is the starting mile of the ith car 
and speed[i] is the speed of the ith car in miles per hour.

A car cannot pass another car, but it can catch up and then travel 
next to it at the speed of the slower car.

A car fleet is a car or cars driving next to each other. The speed 
of the car fleet is the minimum speed of any car in the fleet.

If a car catches up to a car fleet at the mile target, it will still 
be considered as part of the car fleet.

Return the number of car fleets that will arrive at the destination.

--------------------

Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
Output: 3
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;

        // calculate the time for each car using t=d/s formula
        vector<pair<int, double>> cars; // position, time
        for(int i=0; i<n; i++) {
            double time = (double)(target - position[i])/speed[i];
            cars.push_back({position[i], time});
        }

        // sort the cars array in descending order on the basis of position
        // the car which is nearest to the target will come first
        sort(cars.rbegin(), cars.rend());

        // actual calculation for fleet
        // keep track of the 'slowest time' of the current fleet
        // if the curr car's time is greater than the fleet's time, it means it cannot
        // catch up and becomes a new fleet otherwise, it will joins the fleet ahead

        int fleets = 0;
        double maxTime = 0.0;

        for(auto &car: cars) {
            if(car.second > maxTime) {
                fleets++;
                maxTime = car.second;
            }
        }

        return fleets;
    }
};

int main() {
    Solution sol;

    int target = 12;
    vector<int> position = {10,8,0,5,3};
    vector<int> speed = {2,4,1,1,3};

    int totalCarFleets = sol.carFleet(target, position, speed);
    cout << "Total Car Fleets: " << totalCarFleets << endl;

    return 0;
}