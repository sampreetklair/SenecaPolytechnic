# Lab 2


### function 1:

Analyze the following function with respect to number

### Solution:
#### Step 0: Write down the code

```python
def function1(number):
	total=0;

	for i in range(0,number):
		x = (i+1)
		total+=(x*x)

	return total
```

#### Step 1: Establish variables and functions (mathematical ones):
Let n represent the value we are finding the factorial for\
Let T(n) represent the number of operations needed to find the factorial of n

#### Step 2: Count the operations
```python
def function1(number):
	total=0;				# 1

	for i in range(0,number):		# n + 1
		x = (i+1)			# n (1 + 1)
		total+=(x*x)			# n (1 + 1 + 1)

	return total				# 1
```

#### Step 3: Establish the Mathematical Expression for T(n)
T(n) = 1 + (n + 1) +(n (1 + 1)) + (n (1 + 1 + 1)) + 1

#### Step 4: Simplify the Equation
T(n) = 3n + 8

#### Step 5: State the final result
Therefore, T(n) = O(n) :- Linear Growth Rate

---

### function 2:

Analyze the following function with respect to number

### Solution:
#### Step 0: Write down the code
```python
def function2(number):
	return  ((number)*(number+1)*(2*number + 1))/6

```

#### Step 1: Establish variables and functions (mathematical ones):
Let n represent the value we are taking as an argument in the function where the parameter is number\
Let T(n) represent the number of operations needed to execute this function

#### Step 2: Count the operations

```python
def function2(number):
	return  ((number)*(number+1)*(2*number + 1))/6		# 1

```
#### Step 3: Establish the Mathematical Expression for T(n)
T(n) = 1

#### Step 4: Simplify the Equation
T(n) = 1

#### Step 5: State the final result
Therefore, T(n) = O(1) :- Constant Growth Rate

---

### function 3:

Analyze the following with respect to the length of the list.  Note that the function call len() which returns the length of the list is constant (O(1)) with respect to the length of the list.

### Solution:
#### Step 0: Write down the code
```python

def function3(list):
	for i in range (0,len(list)-1):
		for j in range(0,len(list)-1-i):
			if(list[j]>list[j+1]):
				tmp=list[j]
				list[j]=list[j+1]
				list[j+1]=tmp

```

#### Step 1: Establish variables and functions (mathematical ones):
Let n represent the value we are taking as an argument in the function where the parameter is number\
Let T(n) represent the number of operations needed to execute this function

#### Step 2: Count the operations
```python

def function3(list):
	for i in range (0,len(list)-1):				# n (1 + 1 + 1)
		for j in range(0,len(list)-1-i):		# n * n * (1 + 1 + 1 + 1)
			if(list[j]>list[j+1]):			# n * n * (1 + 1)
				tmp=list[j]			# n * n * (1)
				list[j]=list[j+1]		# n * n * (1 + 1)
				list[j+1]=tmp			# n * n * (1 + 1)

```
#### Step 3: Establish the Mathematical Expression for T(n)
T(n) = (n (1 + 1 + 1)) + (n * n * (1 + 1 + 1 + 1)) + (n * n * (1 + 1)) + (n * n * (1)) + (n * n * (1 + 1)) + (n * n * (1 + 1))

#### Step 4: Simplify the Equation
T(n) = 3n + 4n² + 2n² + n² + 2n² + 2n²\
T(n) = 11 n² + 3n

#### Step 5: State the final result
Therefore, T(n) = O(n²) :- Quadratic Growth Rate

---

### function 4:

Analyze the following function with respect to number

### Solution:
#### Step 0: Write down the code
```python
def function4(number):
	total=1
	for i in range(1 to number):
		total=total*(i+1)
	return total
```

#### Step 1: Establish variables and functions (mathematical ones):
Let n represent the value we are taking as an argument in the function where the parameter is number\
Let T(n) represent the number of operations needed to execute this function

#### Step 2: Count the operations

```python
def function4(number):
	total=1						# 1
	for i in range(1 to number):			# n * 1
		total=total*(i+1)			# n (1 + 1 + 1)
	return total					# 1
```

#### Step 3: Establish the Mathematical Expression for T(n)
T(n) = 1 + n + n (1 + 1 + 1) + 1

#### Step 4: Simplify the Equation
T(n) = 1 + n + n (1 + 1 + 1) + 1\
T(n) = 1 + n + 3n + 1\
T(n) 4n + 2

#### Step 5: State the final result
Therefore, T(n) = O(n) :- Linear Growth Rate


## In class portion


### Timing Data

#### Part 1:
![lab2 - partb_one](https://github.com/seneca-dsa456-s24/labs-sklair2/assets/88450907/5f9cf297-b5a4-49ac-935e-54140253f5d2)

#### Part 2:
![lab2 - partb_two](https://github.com/seneca-dsa456-s24/labs-sklair2/assets/88450907/36e627c0-e963-475b-a623-3f54dcb4e5cd)

#### Part 3:
![lab2 - partb_three](https://github.com/seneca-dsa456-s24/labs-sklair2/assets/88450907/764023bf-b53c-44f4-93b6-a0038e212f35)


### Summary 
|function| runtime based on analysis | Most similar curve | 
|---|---|---|
|partb_one()| O(n²) | Quadratic |
|partb_two()| O(nlogn) | Loglinear |
|partb_three()| O(n) | Linear |


### Discussion:

Look at the code from lab 1 and discuss the differences between fastest/slowest versions. Was it a difference in syntax? A difference in approach?  Write down your observations.\
**Answer**: In lab 1 there were 4 functions, I think out of those 4 functions wins_rock_scissors_paper() is the most efficient one having linear growth rate and O(1) efficiency, and sum_to_goal() is the most inefficient one because it used nested loops, had quadratic growth rate and O(n²) efficiency. We can also see that implementing functions using different approaches can lead to different efficiency of functions, for instance for factorial() and fibonacci() I used simple for loop and got linear growth rate and O(n) efficiency, but if I were to use recursion in implementing those functions, the result would have been very different.

## Reflection:

1. for each function what growth rate best match your results?
   * For partb_one() we have T(n) = O(n²) and our graph matches Quadratic growth rate
   * For partb_two() we have T(n) = O(nlogn) and our graph matches Loglinear growth rate
   * For partb_three() we have T(n) = O(n) and our graph matches Linear growth rate
     
2. Does your analysis match your analysis?  If not, where do you suppose the error occurred?\
   Yes, our analysis matches our analysis. After we calculated and concluded with our analysis of given functions. We used program lab2_timer to find the time taken to run the functions and using those functions, we plotted graphs which matched our expectations.
   
3. What sort of conclusions can you draw based on your observations?\
   Based on our observations, we can conclude that partb_one() function has T(n) = O(n²) which means it has a quadratic growth rate due to nested loops used in the function. partb_two() function has T(n) = O(nlogn) which means it has a loglinear growth rate due to the sort() built-in functions used in the function that has loglinear growth rate. And, partb_three() function has T(n) = O(n) which means it has a linear growth rate.


