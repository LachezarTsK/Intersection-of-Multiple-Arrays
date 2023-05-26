
import java.util.List;
import java.util.ArrayList;

public class Solution {

    private static final int[] RANGE_INPUT_VALUES = {1, 1000};

    public List<Integer> intersection(int[][] input) {
        final int numberOfInputArrays = input.length;
        int[] frequencyValues = new int[RANGE_INPUT_VALUES[1] + 1];
        fillFrequencyValues(input, frequencyValues);
        return findIntersection(frequencyValues, numberOfInputArrays);
    }

    private void fillFrequencyValues(int[][] input, int[] frequencyValues) {
        for (int[] subarray : input) {
            for (int n : subarray) {
                ++frequencyValues[n];
            }
        }
    }

    private List<Integer> findIntersection(int[] frequencyValues, int numberOfInputArrays) {
        List<Integer> intersection = new ArrayList<>();
        for (int i = RANGE_INPUT_VALUES[0]; i <= RANGE_INPUT_VALUES[1]; ++i) {
            if (frequencyValues[i] == numberOfInputArrays) {
                intersection.add(i);
            }
        }
        return intersection;
    }
}
