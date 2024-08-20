# Copy over your a1_partc.py file here

#	Main Author(s): 
#	Main Reviewer(s): 

class Stack:

	def __init__(self, cap = 10):
		self.cap = cap
		self.stack = [None] * cap
		self.size = 0

	def capacity(self):
		return self.cap

	def push(self, data):
		if self.size >= self.cap:
			self.cap *= 2
			new_stack = [None] * self.cap
			for i in range(self.size):
				new_stack[i] = self.stack[i]
			self.stack = new_stack
		self.stack[self.size] = data
		self.size += 1

	def pop(self):
		if self.size == 0:
			raise IndexError('pop() used on empty stack')
		else:
			self.size -= 1
			poped_item = self.stack[self.size]
			self.stack[self.size] = None
			return poped_item

	def get_top(self):
		if self.size == 0:
			return None
		else:
			return self.stack[self.size - 1]

	def is_empty(self):
		return self.size == 0

	def __len__(self):
		return self.size


class Queue:

	def __init__(self, cap=10):
		self.cap = cap
		self.queue = [None] * cap
		self.size = 0
		self.front = 0
		self.back = 0

	def capacity(self):
		return self.cap

	def enqueue(self, data):
		if self.size >= self.cap:
			self.cap *= 2
			new_queue = [None] * self.cap
			for i in range(self.size):
				new_queue[i] = self.queue[(self.front + i) % self.size]
			self.queue = new_queue
			self.front = 0
			self.back = self.size
		self.queue[self.back] = data
		self.back = (self.back + 1) % self.cap
		self.size += 1

	def dequeue(self):
		if self.size == 0:
			raise IndexError('dequeue() used on empty queue')
		data = self.queue[self.front]
		self.queue[self.front] = None
		self.front = (self.front + 1) % self.cap
		self.size -= 1
		return data

	def get_front(self):
		if self.size == 0:
			return None
		return self.queue[self.front]

	def is_empty(self):
		return self.size == 0

	def __len__(self):
		return self.size


class Deque:

	def __init__(self, cap=10):
		self.cap = cap
		self.deque = [None] * cap
		self.size = 0
		self.front = 0
		self.back = 0

	def capacity(self):
		return self.cap

	def push_front(self, data):
		if self.size >= self.cap:
			self.cap *= 2
			new_deque = [None] * self.cap
			for i in range(self.size):
				new_deque[i] = self.deque[(self.front + i) % self.size]
			self.deque = new_deque
			self.front = 0
			self.back = self.size
		self.front = (self.front - 1) % self.cap
		self.deque[self.front] = data
		self.size += 1

	def push_back(self, data):
		if self.size >= self.cap:
			self.cap *= 2
			new_deque = [None] * self.cap
			for i in range(self.size):
				new_deque[i] = self.deque[(self.front + i) % self.size]
			self.deque = new_deque
			self.front = 0
			self.back = self.size
		self.deque[self.back] = data
		self.back = (self.back + 1) % self.cap
		self.size += 1

	def pop_front(self):
		if self.size == 0:
			raise IndexError('pop_front() used on empty deque')
		data = self.deque[self.front]
		self.deque[self.front] = None
		self.front = (self.front + 1) % self.cap
		self.size -= 1
		return data

	def pop_back(self):
		if self.size == 0:
			raise IndexError('pop_back() used on empty deque')
		self.back = (self.back - 1) % self.cap
		data = self.deque[self.back]
		self.deque[self.back] = None
		self.size -= 1
		return data

	def get_front(self):
		if self.size == 0:
			return None
		return self.deque[self.front]

	def get_back(self):
		if self.size == 0:
			return None
		return self.deque[(self.back - 1) % self.cap]

	def is_empty(self):
		return self.size == 0

	def __len__(self):
		return self.size

	def __getitem__(self, k):
		if k < 0 or k >= self.size:
			raise IndexError('Index out of range')
		return self.deque[(self.front + k) % self.cap]