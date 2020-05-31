# Algorithm-in-Python
## QuickSort under Tail Recursion
In this algorithm, we used an iterative version with a simulated tail recursion. The speed is slower (10 to 11 times) than the  Timsort at python. However, Timsort is implemented in C through the Cpython interface, thus this is explainable. 
Additionally, you have that:
+ The algorithm is not stable 
  + I am planning to make it stable.
+ The Complexities are as follow:
  + Time O(nlogn)
  + Space O(n)
  + Function calls and recursive calls O(logn)
