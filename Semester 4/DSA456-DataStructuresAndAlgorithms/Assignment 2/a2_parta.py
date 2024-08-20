#	Main Author(s): Sampreet Klair
#	Main Reviewer(s): Saeed Bafana, Harsahbaj Singh

class HashTable:

    # You cannot change the function prototypes below. Other than that,
    # how you implement the class is your choice as long as it is a hash table.

    # Initializer for the HashTable class. Sets the initial capacity to 32 by default.
    # Creates a list with capacity elements, each initialized as an empty list for chaining.
    def __init__(self, cap=32):
        self._capacity = cap
        self._size = 0
        self._table = [[] for i in range(self._capacity)]

    # Hash function to map keys to table indices.
    # Utilizes Python's built-in hash function and the modulus operator to ensure index is within table capacity.
    def hash_function(self, key):
        return hash(key) % self._capacity

    # Resizes the hash table when the load factor exceeds 0.7.
    # Creates a new table with the new capacity and rehashes all existing key-value pairs into it.
    def _resize(self, new_capacity):
        old_table = self._table
        self._capacity = new_capacity
        self._table = [[] for i in range(new_capacity)]
        self._size = 0

        for bucket in old_table:
            for key, value in bucket:
                self.insert(key, value)

    # Inserts a key-value pair into the hash table.
    # Checks if the key already exists in the bucket before appending the new pair.
    # Resizes the table if the load factor exceeds 0.7.
    def insert(self, key, value):
        index = self.hash_function(key)
        for pair in self._table[index]:
            if pair[0] == key:
                return False
        self._table[index].append([key, value])
        self._size += 1

        # Resize if necessary
        if self._size > self._capacity * 0.7:
            self._resize(self._capacity * 2)
        return True

    # Modifies the value associated with an existing key.
    # Searches for the key and updates its value if found.
    # Returns True if modification was successful, False otherwise.
    def modify(self, key, value):
        index = self.hash_function(key)
        for pair in self._table[index]:
            if pair[0] == key:
                pair[1] = value
                return True
        return False

    # Removes a key-value pair from the table.
    # Searches for the key and deletes it if found.
    # Resizes the table if the load factor falls below 0.2 and the capacity is greater than 32.
    def remove(self, key):
        index = self.hash_function(key)
        for i, pair in enumerate(self._table[index]):
            if pair[0] == key:
                del self._table[index][i]
                self._size -= 1
                # Resize if necessary
                if self._size < self._capacity * 0.2 and self._capacity > 32:
                    self._resize(self._capacity)
                return True
        return False

    # Searches for a key and returns its associated value.
    # Returns None if the key is not found in the table.
    def search(self, key):
        index = self.hash_function(key)
        for pair in self._table[index]:
            if pair[0] == key:
                return pair[1]
        return None

    # Returns the current capacity of the hash table.
    def capacity(self):
        return self._capacity

    # Returns the number of key-value pairs stored in the hash table.
    def __len__(self):
        return self._size