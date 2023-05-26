
using System;
using System.Collections.Generic;

public class Solution
{
    private readonly int[] RANGE_INPUT_VALUES = { 1, 1000 };
    public IList<int> Intersection(int[][] input)
    {
        int numberOfInputArrays = input.Length;
        int[] frequencyValues = new int[RANGE_INPUT_VALUES[1] + 1];
        fillFrequencyValues(input, frequencyValues);
        return findIntersection(frequencyValues, numberOfInputArrays);
    }

    private void fillFrequencyValues(int[][] input, int[] frequencyValues)
    {
        foreach (var subarray in input)
        {
            foreach (var n in subarray)
            {
                ++frequencyValues[n];
            }
        }
    }

    private IList<int> findIntersection(int[] frequencyValues, int numberOfInputArrays)
    {
        IList<int> intersection = new List<int>();
        for (int i = RANGE_INPUT_VALUES[0]; i <= RANGE_INPUT_VALUES[1]; ++i)
        {
            if (frequencyValues[i] == numberOfInputArrays)
            {
                intersection.Add(i);
            }
        }
        return intersection;
    }
}
