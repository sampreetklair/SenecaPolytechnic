# Analysis and Reflection for Lab 3

## function 1:

Analyze the following function with respect to number

### Solution:
#### Step 0: Write down the code

```python
def function1(value, number):
	if (number == 0):
		return 1
	elif (number == 1):
		return value
	else:
		return value * function1(value, number-1)
```
#### Step 1: Establish variables and functions (mathematical ones)
Let n represent the value we are taking as an argument in the function where the parameter is number\
Let T(n) represent the number of operations needed to execute this function

#### Step 2: Count the operations
```python
def function1(value, number):
	if (number == 0):						# 1		
		return 1						# 1
	elif (number == 1):						# 1
		return value						# 1
	else:
		return value * function1(value, number-1)		# 1 + 1 + T(n-1)
```
#### Step 3: Establish the Mathematical Expression for T(n)
T(n) = 1 + 1 + 1 + 1 + 1 + 1 + T(n-1)
T(n) = T(n-1) + 6

T(n-1) = T(n-2) + 6
T(n-2) = T(n-3) + 6
...

T(1) = 2
T(0) = 2

#### Step 4: Simplify the Equation
T(n) = 6(n-1) + 2
T(n) = 6n - 6 + 2
T(n) = 6n - 4

#### Step 5: State the final result
Therefore, T(n) = O(n) :- Linear Growth Rate

---

## function 2:

Analyze function2 with respect to the length of the mystring.  Hint, you will need to set up two mathematical functions for operator counting.  one for function2 and the other for recursive_function2

#### Step 0: Write down the code
```python

def recursive_function2(mystring,a, b):
	if(a >= b ):
		return True
	else:
		if(mystring[a] != mystring[b]):
			return False
		else:
			return recursive_function2(mystring,a+1,b-1)

def function2(mystring):
	return recursive_function2(mystring, 0,len(mystring)-1)

```
#### Step 1: Establish variables and functions (mathematical ones)
Let n represent the length of the string we are taking as an argument in the function where the parameter is mystring\
Let T(N) represent the number of operations needed to execute recursive_function2()
Let T(n) represent the number of operations needed to execute function2()

#### Step 2: Count the operations
```python
def recursive_function2(mystring,a, b):
	if(a >= b ):								# 1
		return True							# 1
	else:
		if(mystring[a] != mystring[b]):					# 1
			return False						# 1
		else:
			return recursive_function2(mystring,a+1,b-1)		# 1 + 1 + 1 + T(N-1)

def function2(mystring):
	return recursive_function2(mystring, 0,len(mystring)-1)			# 1 + 1 + 1 + T(N)
```
#### Step 3a: Establish the Mathematical Expression for recursive_function2()
T(N) = 1 + 1 + 1 + 1 + 1 + 1 + 1 + T(N-1)
T(N) = T(N-1) + 7

T(N-1) = T(N-2) + 7
T(N-2) = T(N-3) + 7
...

T(1) = 2
T(0) = 2

#### Step 4a: Simplify the Equation
T(N) = 7(N-1) + 2
T(N) = 7N - 7 + 2
T(N) = 7N - 5

#### Step 3b: Establish the Mathematical Expression for function2()
T(n) = 1 + 1 + 1 + T(N)
T(n) = T(N) + 3

#### Step 4b: Simplify the Equation
T(n) = T(N) + 3
T(n) = 7n - 5 + 3
T(n) = 7n - 2

#### Step 5: State the final result
Therefore, T(n) = O(n) :- Linear Growth Rate

---

### function 3 (optional challenge):

Analyze the following function with respect to number


```python
def function3(value, number):
	if (number == 0):
		return 1
	elif (number == 1):
		return value
	else:
		half = number // 2
		result = function3(value, half)
		if (number % 2 == 0):
			return result * result
		else:
			return value * result * result

```

## Part C reflection

Answer the following questions

1. Describe how to a approach writing recursive functions, what steps do you take?\
   While writing a recursive function there are three main steps that we need to take care of and consider while writing our solution. The first one is to create a base case or exit case that will terminate our recursive code. The second is to define a solution that can call itself and repeat itself. The third one is, that the solution while repeating decreases the count until we get the first index at the base case.

2. Describe the process of analyzing recursive functions.  How does it differ from from analyzing non-recursive functions?  How is it the same?\
   The process of analyzing recursive functions is similar to that of a non-recursive function with some differences. The first step is to establish mathematical variables and functions, the second step is to count the operations, here we see a difference at the place where we call the recursive function inside itself, we add a T(n-1) variable operation there, the third step is to establish the mathematical expression for T(n), the fourth step is to simplify the equation, and the fifth step is to state the final result.\
   The difference between the analysis of non-recursive function and recursive function is that in non-recursive function we do not consider the time complexity of T(n-1) while we find the time complexity of T(n).\
   The similarity between the analysis of non-recursive function and recursive function is the 5 steps process we do to the analysis of the function. 

