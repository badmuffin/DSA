/* 
2667. Create Hello World Function - Easy
------------------------------------------
Write a function createHelloWorld. It should return a new function that always returns "Hello World".
*/

/* FUnction inside a function */
const createHelloWorld = function() { // anonymous function
    return function(...args) {
        return "Hello World";
    }
}

const f = createHelloWorld();
console.log(f());


/*
Immediately Invoked Function Expression (IIFE) - You can create a function and immediately execute it 
-------------------------------------
const createHelloWorld1 = function() {
    return function(...args) {
        return "Hello World Again";
    }();
}

const f1 = createHelloWorld1();
console.log(f1);
*/
