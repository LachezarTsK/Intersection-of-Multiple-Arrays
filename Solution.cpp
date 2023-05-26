
#include <array>
#include <vector>
using namespace std;

class Solution {
    
    static constexpr array<int, 2> RANGE_INPUT_VALUES{1, 1000};
    using FrequencyValues = array<int, RANGE_INPUT_VALUES[1] + 1>;
    
public:
    vector<int> intersection(const vector<vector<int>>& input) const {
        const size_t numberOfInputArrays = input.size();
        FrequencyValues frequencyValues{};
        fillFrequencyValues(input, frequencyValues);
        return findIntersection(frequencyValues, numberOfInputArrays);
    }

private:
    void fillFrequencyValues(const vector<vector<int>>& input, FrequencyValues& frequencyValues) const {
        for (const auto& subarray : input) {
            for (const auto& n : subarray) {
                ++frequencyValues[n];
            }
        }
    }

    vector<int> findIntersection(const FrequencyValues& frequencyValues, size_t numberOfInputArrays) const {
        vector<int> intersection;
        for (int i = RANGE_INPUT_VALUES[0]; i <= RANGE_INPUT_VALUES[1]; ++i) {
            if (frequencyValues[i] == numberOfInputArrays) {
                intersection.push_back(i);
            }
        }
        return intersection;
    }
};
