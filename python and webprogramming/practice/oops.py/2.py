class animal:

    def __init__(self,name):
        self.name=name
    def eat(self):
        print(f"{self.name} is eating")

class prey(animal):
    def flee(self):
        print(f"{self.name} is fleeing")
class predator(animal):
    def hunt(self):
        print(f"{self.name }is hunting")
class rabbit(prey):
    def eat(se):
        print(f"{se.name} eats grass")

abbit=rabbit("sim")     
rrabbit=prey("sim")     
rrabbit.eat()
 