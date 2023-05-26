
/**
 * @param {number[][]} input
 * @return {number[]}
 */
var intersection = function (input) {
    this.RANGE_INPUT_VALUES = [1, 1000];
    const numberOfInputArrays = input.length;
    const frequencyValues = new Array(RANGE_INPUT_VALUES[1] + 1).fill(0);
    fillFrequencyValues(input, frequencyValues);
    return findIntersection(frequencyValues, numberOfInputArrays);
};

/**
 * @param {number[][]} input
 * @param {number[]} frequencyValues 
 * @return {void}
 */
function fillFrequencyValues(input, frequencyValues) {
    for (let subarray of input) {
        for (let n of subarray) {
            ++frequencyValues[n];
        }
    }
}

/**
 * @param {number[]} frequencyValues
 * @param {number} numberOfInputArrays 
 * @return {number[]}
 */
function findIntersection(frequencyValues, numberOfInputArrays) {
    const intersection = [];
    for (let i = this.RANGE_INPUT_VALUES[0]; i <= this.RANGE_INPUT_VALUES[1]; ++i) {
        if (frequencyValues[i] === numberOfInputArrays) {
            intersection.push(i);
        }
    }
    return intersection;
}
