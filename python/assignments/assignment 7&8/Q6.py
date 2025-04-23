#6. Create a class "BankAccount" with attributes account number and balance. Implement 
#methods to deposit and withdraw funds, and a display method to show the account details. 
class BankAccount:
    def __init__(self,acc_num,balance=0):
        self.acc_num = acc_num
        self.balance = balance

    def deposit(self,amount):
        if(amount > 0):
            self.balance += amount
            return True
        return False

    def withdraw(self,amount):
        if (0 < amount <= self.balance):
            self.balance -= self.balance
            return True
        else:
            print("Sufficient Balance Not Available!\n")
            return False

    def display(self):
        print(f"Account No.: {self.acc_num}")
        print(f"Available Balance: {self.balance}\n")

acc = BankAccount(2)
acc.deposit(1000)
acc.display()
acc.withdraw(3000)
acc.display()