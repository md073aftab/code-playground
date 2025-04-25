import pandas as pd
from datetime import datetime, time

dt1 = pd.Timestamp('2012-01-15')
print("a) Date time object for Jan 15 2012:", dt1)

dt2 = pd.Timestamp('2012-01-15 21:20:00')
print("b) Specific date and time of 9:20 PM:", dt2)

dt3 = pd.Timestamp.now()
print("c) Local date and time:", dt3)

dt4 = dt3.date()
print("d) A date without time:", dt4)

dt5 = pd.to_datetime("today").date()
print("e) Current date:", dt5)

dt6_time = dt3.time()
print("t) Time from a datetime:", dt6_time)

dt7 = datetime.now().time()
print("g) Current local time:", dt7)