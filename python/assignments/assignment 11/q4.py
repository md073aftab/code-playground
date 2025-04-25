import pandas as pd
import numpy as np

df = pd.DataFrame({
    'John':  [True, False, False, True, False, True, False, False, True, False],
    'Judy':  [True, True, False, False, False, True, True, False, True, False]
})

df['party'] = df['John'] & df['Judy']

days_til_party = [None] * len(df)

party_indices = df.index[df['party']].tolist()

if not party_indices:
    df['days_til_party'] = np.nan
else:
    next_party_idx = None
    for i in reversed(range(len(df))):
        if i in party_indices:
            days_til_party[i] = 0
            next_party_idx = i
        else:
            days_til_party[i] = next_party_idx - i if next_party_idx is not None else np.nan

    df['days_til_party'] = days_til_party

df.drop(columns='party', inplace=True)

print(df)