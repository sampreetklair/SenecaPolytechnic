# Write the code for your lab 1 here.  Read the specs carefully.  
# Function name must be exactly as provided.  
# Names of variables and parameters can be whatever you wish it to be
#
# To test, run the following command :
#     python test_lab1.py
#
# Author: 
# Student Number: 
#

# In some function solutions, I could have used recursion, but I preferred not using it as my solution has better time complexity
# wins_rock_scissors_paper function declaration
def wins_rock_scissors_paper(player, opponent):
	# if-else statements determining if the player is winner
	if player.lower() == 'rock' and opponent.lower() == 'scissors':
		return True
	elif player.lower() == 'rock' and opponent.lower() == 'paper':
		return False
	elif player.lower() == 'paper' and opponent.lower() == 'scissors':
		return False
	elif player.lower() == 'paper' and opponent.lower() == 'rock':
		return True
	elif player.lower() == 'scissors' and opponent.lower() == 'rock':
		return False
	elif player.lower() == 'scissors' and opponent.lower() == 'paper':
		return True
	else:
		return False

#factorial function declaration
def factorial(num):
	# declared an int variable that stores the factorial value
	multiplier = 1

	# for-loop that first increments i and then multiplies it with multiplier variable that results in the factorial answer
	for i in range(num):
		i+=1
		multiplier = multiplier * i
	
	# returning the answer to the function
	return multiplier

# fibonacci function declaration
def fibonacci(num):
	# declared an int variable that stores the index of our series
	series_index = 0
	
	# declared a list that stores each index value of the fibonacci series
	series = []

	# for-loop that runs from 0 to the index entered as function parameter
	for i in range(num+1):

		# if-else statement having three cases, if, i=0, 0 is added to the series
		if i==0:
			series.append(i)

		# else if, i=1, 1 is added to the series
		elif i==1:
			series.append(i)

		# else, we add to the list, sum of previous two items present in the list
		else:
			series_index = series[i-1] + series[i-2]
			series.append(series_index)

	# returning the answer to the function
	return series[i]

# sum_to_goal function declaration
def sum_to_goal(nums, goal):

	# for-loop that runs through the list nums
	for i in range(len(nums)):

		# nested for-loop that runs through the list nums
		for j in range(len(nums)):

			# if-else statement that returns product of two numbers if there sum is equal to any item present in our list
			if nums[i]+nums[j] == goal:
				return nums[i] * nums[j]

	# returns 0 if there are no two items in our list whose sum is equal to goal
	return 0
    
# UpCounter class declaration
class UpCounter:
	# initializer function for class UpCounter
    def __init__(self, step_size=1, counted=0):
        self.step_size = step_size
        self.counted = counted
	
	# function count that returns current counter value
    def count(self):
        return self.counted
        
	# function update that increases the counter value by stepsize
    def update(self):
        self.counted += self.step_size

# DownCounter class declaration which inherits class UpCounter
class DownCounter(UpCounter):
	# initializer function for class DownCounter
    def __init__(self, step_size=1, counted=0):
        super().__init__(step_size, counted)
               
	# function update that decreases the counter value by stepsize
    def update(self):
        self.counted -= self.step_size