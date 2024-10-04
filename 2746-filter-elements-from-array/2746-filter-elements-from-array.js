/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let n=arr.length;
     const newArray=[];
    let k=0;

    for(let i=0;i<n;i++){
    if(fn(arr[i],i))
    newArray[k++]=arr[i]
    }
    

    return newArray;
};