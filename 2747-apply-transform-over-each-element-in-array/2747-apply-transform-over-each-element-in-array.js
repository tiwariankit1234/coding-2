/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let n=arr.length;
    const newArray=[];
    for(let i=0;i<n;i++){
        newArray[i]=fn(arr[i],i);
    }
    return newArray;
};