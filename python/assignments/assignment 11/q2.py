import pandas as pd
s = pd.Series(['X', 'Y', 'T', 'Aaba', 'Baca', 'CABA', None, 'bird', 'horse', 'dog'])
upper_case = s.str.upper()
print("Upper case:\n", upper_case, "\n")
lower_case = s.str.lower()
print("Lower case:\n", lower_case, "\n")
lengths = s.str.len()
print("Length of strings:\n", lengths)