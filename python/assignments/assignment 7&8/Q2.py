# 2. Write a Python program to create a class representing a queue data structure. Include methods 
# for enqueueing and dequeuing elements.
class Queue:
    def __init__(self):
        self.items = []
    
    def Enqueue(self,item):
        self.items.append(item)

    def Dequeue(self):
        if(len(self.items) == 0):
            print("Queue is Empty")
            return
        print(f"Dequeued Item: {self.items[0]}")
        self.items.remove(self.items[0])

    def isEmpty(self):
        if not len(self.items):
            print("Queue is Empty")
        else:
            print("Queue Not Empty!")
    
    def peek(self):
        if not len(self.items):
            print("Queue is Empty!")
            return
        print(f"First Element: {self.items[0]}")
    
    def sizeofQ(self):
        print(f"Size: {len(self.items)}")

queue = Queue()
queue.Enqueue(5)
queue.peek()
queue.Enqueue(10)
queue.Dequeue()
queue.peek()
queue.sizeofQ()