#    Main Author(s): Saeed Bafana
#    Main Reviewer(s): Sampreet Klair, Harsahbaj Singh

class SortedList:

    class Node:
        def __init__(self, data=None, next=None, prev=None):
            self.data = data
            self.next = next
            self.prev = prev

        def get_data(self):
            return self.data

        def get_next(self):
            return self.next

        def get_previous(self):
            return self.prev

    def __init__(self):
        self.head = self.Node() 
        self.tail = self.Node()  
        self.head.next = self.tail
        self.tail.prev = self.head
        self.size = 0

    def get_front(self):
        return self.head.next if self.head.next != self.tail else None

    def get_back(self):
        return self.tail.prev if self.tail.prev != self.head else None

    def is_empty(self):
        return self.size == 0

    def __len__(self):
        return self.size

    def insert(self, data):
        new_node = self.Node(data)
        current = self.head.next
        while current != self.tail and current.data < data:
            current = current.next
        new_node.prev = current.prev
        new_node.next = current
        current.prev.next = new_node
        current.prev = new_node
        self.size += 1
        return new_node

    def erase(self, node):
        if node is None or node == self.head or node == self.tail:
            raise ValueError('Cannot erase node referred to by None')
        node.prev.next = node.next
        node.next.prev = node.prev
        self.size -= 1

    def search(self, data):
        current = self.head.next
        while current != self.tail:
            if current.data == data:
                return current
            current = current.next
        return None
