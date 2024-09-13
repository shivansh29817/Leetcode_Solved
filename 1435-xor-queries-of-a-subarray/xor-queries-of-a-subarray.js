/**
 * @param {number[]} arr
 * @param {number[][]} queries
 * @return {number[]}
 */
var xorQueries = function(arr, queries) {
    for (let i = 1; i < arr.length; i++) {
        arr[i] ^= arr[i - 1];
    }
    
    return queries.map(([start, end]) => 
        start > 0 ? arr[end] ^ arr[start - 1] : arr[end]
    );
};