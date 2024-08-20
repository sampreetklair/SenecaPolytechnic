#
# Author: 
# Student Number: 
#
# Place the code for your lab 3 here.  Read the specs carefully.  
#
# To test, run the following command :
#     python test_lab3.py
#

def factorial(number):
	if number == 0 or number == 1:
		return 1
	else:
		return number * factorial(number-1)


def linear_search(list, key):
	def recursive_linear_search(list, key, index):
		if len(list) == 0:
			return -1
		elif list[0] == key:
			return index
		else:
			return recursive_linear_search(list[1:], key, index + 1)
	return recursive_linear_search(list, key, 0)


def binary_search(list, key):
	def recursive_binary_search(list, key, low, high):
		if len(list) == 0 or (low > high):
			return -1
		else:
			mid = (low + high) // 2
			if list[mid] == key:
				return mid		
			elif list[mid] > key:
				return recursive_binary_search(list, key, low, mid - 1)
			else:
				return recursive_binary_search(list, key, mid + 1, high)
	return recursive_binary_search(list, key, 0, len(list) - 1)