import random

class Rock_paper_scissors():
    def __init__(self):
        choices=["stone","paper","scissor"]
        user_wins=0
    def rounds(self):
        rounds=int(input("HELLO, how many rounds wound like to play"))
        return rounds
    def user_choice(self):
        self.user_choice=input("enter user choice from: {stone,paper,scissor}").lower()
        #while self.user_choice not in self.choices:
           # print("invalid choice")
           # self.user_choice=input("enter user choice from: {stone,paper,scissor}").lower()
        return self.user_choice    
    def computer_choice(self): 
        return random.choice(self.choices)
    def round_winner(self,user_choice):
        self.user_choice=user_choice
        self.comp_choice=self.computer_choice()
        if user_choice=="stone" and self.comp_choice=="scissor" or user_choice=="scissor" and self.comp_choice=="paper" or user_choice=="paper" and self.comp_choice=="stone":
            self.user_wins += 1
            print("user WON!!")
        else:
            print("computer WON!!")                        
    def winner(self,user_wins):
        if self.rounds/2 < self.user_wins:
            print("USER WON!!")
        else:
            print("COMPUTER WON!!")
user1=Rock_paper_scissors()
for i in range(0,user1.rounds()) :
    user1.round_winner(user1.user_choice())
user1.winner()