class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, int>> cars(n);
        for(int i = 0; i < n; i++){
            cars[i] = {position[i], speed[i]};
        }

        sort(cars.begin(), cars.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.first > b.first;
        });

        vector<double> stack;

        for(const auto& car: cars){
            double time = (double)(target - car.first) / car.second;

            if(stack.empty() || time > stack.back()){
                stack.push_back(time);
            }
        }
        return stack.size();
    }
};