import random

class RockPaperScissor:
    def __init__(self, current_round=0, total_round=0):
        self.current_round = current_round
        self.total_round = total_round
    
    # Method to get user choice
    def get_user_choice(self):
        user_choice = input("Enter your choice (rock, paper, scissor): ").lower()
        while user_choice not in ["rock", "paper", "scissor"]:
            user_choice = input("Invalid choice. Please enter rock, paper, or scissor: ").lower()
        return user_choice
    
    # Method to get computer choice
    def get_computer_choice(self):
        computer_choice = random.choice(["rock", "paper", "scissor"])
        return computer_choice
    
    # Method to determine the winner
    def winner(self):
        self.total_round = int(input("Enter the number of rounds: "))
        user_wins = 0
        computer_wins = 0
        ties = 0
        
        for i in range(0,self.total_round):
            user = self.get_user_choice()
            computer = self.get_computer_choice()
            
            if (computer == "rock" and user == "paper") or(computer == "paper" and user == "scissor") or(computer == "scissor" and user == "rock" ):
                print("You won this round!")
                user_wins += 1
                self.current_round+=1
                print(f"this is {self.current_round}st round ")
            elif computer == user:
                print("It's a tie this round!")
                ties += 1

                self.current_round+=1
                print(f"this is {self.current_round}st round ")
            else:
                print("Computer won this round!")
                computer_wins += 1
                self.current_round+=1
                print(f"this is {self.current_round}st round ")
        
        # Displaying the final result
        print("\nFinal Results:")
        print(f"User Wins: {user_wins}")
        print(f"Computer Wins: {computer_wins}")
        print(f"Ties: {ties}")
        
        if user_wins > computer_wins:
            print("You are the overall winner!")
        elif computer_wins > user_wins:
            print("The computer is the overall winner!")
        else:
            print("It's an overall tie!")

# Create an instance of the RockPaperScissor class and call the winner method
s1 = RockPaperScissor()
s1.winner()