/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
var argumentsLength = function(...args) {
   let num=0;
   for(let i of args)
   num++
   return num;
};

/**
 * argumentsLength(1, 2, 3); // 3
 */