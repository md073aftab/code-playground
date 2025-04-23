class password_manager:

    def __init__(self):
        self.old_passwords=old_passwords=[]
        self.current_password="0000"

    def set_password(self,new_password):
        if new_password not in self.old_passwords:
            self.current_password=new_password
            self.old_passwords.append(self.current_password)
        else:
            print("This password already exist, try another password")
    def get_password(self):
        curr=self.old_passwords[-1]
        print(f"current password is {curr}")

    def is_correct(self,password):
        if password==self.old_passwords[-1]:
            print("**CORRECT PASSWORD**")
        else :
            print("**password incorrect**")

app1=password_manager()
app1.set_password("Md073@ftab")
app1.get_password()



        