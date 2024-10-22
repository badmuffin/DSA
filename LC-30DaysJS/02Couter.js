/*
2620. Counter - Easy
--------------------
Given an integer n, return a counter function. This counter function 
initially returns n and then returns 1 more than the previous value 
every subsequent time it is called (n, n + 1, n + 2, etc).
*/

var createCounter = function(n) {
    let num = n;
    return function() {
        return num++;
    };
};

const counter = createCounter(10)
console.log(counter());
console.log(counter());
console.log(counter());
