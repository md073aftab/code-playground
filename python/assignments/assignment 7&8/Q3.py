#  3. Write a Python program to create a class representing a bank. Include methods for managing customer accounts and transactions. 

class Bank:
    def __init__(self):
        self.accounts = {}
        self.next_acc_number = 1
    
    def create_account(self,customer_name,initial_deposit=0):
        account_number = self.next_acc_number
        self.accounts[account_number] = {
            'name' : customer_name,
            'balance' : initial_deposit
        }
        self.next_acc_number += 1
        return account_number
    
    def deposit(self,account_number,amount):
        if account_number in self.accounts:
            if amount > 0:
                self.accounts[account_number]['balance'] += amount
                return True
            else:
                print("Enter Valid Deposit Amount!")
                return False
        else:
            print("Account not Found")
            return False
        
    def withdraw(self,account_number,amount):
        if account_number in self.accounts:
            if 0 < amount <= self.accounts[account_number]['balance']:
                self.accounts[account_number]['balance'] -= amount
                return True
            else:
                print("Sufficient Balance Not Available!")
                return False
        else:
            print("Account not Found!")
            return False
        
    def get_balance(self,account_number):
        if account_number in self.accounts:
            return self.accounts[account_number]['balance']
        else:
            print("Account Not Found!")
            return None
        
    def get_account_details(self,account_number):
        if account_number in self.accounts:
            return self.accounts[account_number]
        else:
            print("Account Not Found!")
            return None
        
bank = Bank()
acc_num = bank.create_account("Dhiraj",1000)
print(f"Account Number: {acc_num}")
print(f"Balance: {bank.get_balance(acc_num)}")

bank.deposit(acc_num,500)
print(f"After Deposit: {bank.get_balance(acc_num)}")

bank.withdraw(acc_num,1000)
print(f"After Withdrawal: {bank.get_balance(acc_num)}")

print(f"Account Details: {bank.get_account_details(acc_num)}")