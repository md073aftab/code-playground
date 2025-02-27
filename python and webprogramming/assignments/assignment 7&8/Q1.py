# 1. Write a Python program to create a class representing a linked list data structure. Include 
# methods for displaying linked list data, inserting and deleting nodes. 

class Node:
    def __init__(self,data):
        self.data = data
        self.next = None
class LinkedList:
    def __init__(self):
        self.head = None

    def insertAtBegin(self,data):
        newNode = Node(data)
        newNode.next = self.head
        self.head = newNode

    def insertAtEnd(self,data):
        newNode = Node(data)
        if(self.head == None):
            self.head = newNode
            return
        current = self.head
        while(current.next):
            current = current.next
        current.next = newNode
    
    def insertAtPosition(self,data,pos):
        if pos < 1:
            print("Invalid Position!")
        
        if(pos == 1):
            self.insertAtBegin(data)
            return
        newNode = Node(data)
        current = self.head
        for i in range(pos-2):
            if current == None:
                print("Position Out Of Bounds")
                return 
            current = current.next
        newNode.next = current.next
        current.next = newNode
    
    def deleteAtBegin(self):
        if(self.head == None):
            print("List is Empty")
            return
        self.head = self.head.next
    
    def deleteAtEnd(self):
        if(self.head == None):
            print("List is Empty")
            return
        if self.head.next is None:
            self.head = None
            return
        current = self.head
        while(current.next.next):
            current = current.next
        current.next = None
    
    def deleteFromPos(self,pos):
        if pos < 1:
            print("Invalid Position!")
            return
        elif self.head == None:
            print("List is Empty")
            return
        if(pos == 1):
            self.deleteAtBegin()
            return
        i = 1
        current = self.head
        while(i < pos-1):
            if current == None or current.next == None:
                print("Position out of Bounds!")
                return
            i += 1
            current = current.next
        if(current == None):
            print("Position out of Bounds!")
            return
        current.next = current.next.next
    
    def printList(self):
        current = self.head
        while(current != None):
            print(current.data,end=' ')
            current = current.next
        print("\n")
        
    def sizeofLL(self):
        i = 0
        current = self.head
        while(current):
            current = current.next
            i += 1
        print("Size: ",i)
    
list = LinkedList()
list.insertAtBegin('A')
list.insertAtEnd('B')
list.insertAtPosition('C', 2)
list.insertAtPosition('D', 10)
list.printList()
list.deleteFromPos(2)
list.deleteFromPos(10)
list.printList()
list.sizeofLL()