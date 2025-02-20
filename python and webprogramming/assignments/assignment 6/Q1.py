#Write a class called Password_manager. The class should have a list called old_passwords that
#holds all of the user’s past passwords. The last item of the list is the user’s current pass word.
#There should be a method called get_password that returns the current password and a method
#called set_password that sets the user’s password. The set_password method should only
#change the password if the attempted password is different from all the user’s past passwords.
#Finally, create a method called is_correct that receives a string and returns a boolean True or
#False depending on whether the string is equal to the current password or not.

class PasswordManager:
    def __init__(self):
        self.old_passwords = [] 

    def set_password(self, new_password):
        if new_password not in self.old_passwords:
            self.old_passwords.append(new_password)

    def get_password(self):
        if self.old_passwords:
            return self.old_passwords[-1]  
        return None 

    def is_correct(self, string):
        return string == self.get_password()

s1 = PasswordManager()

s1.set_password("pass123")  
s1.set_password("aftab456")

print(s1.get_password()) 
print(s1.is_correct("sss456"))  
print(s1.is_correct("aftab456"))  
        