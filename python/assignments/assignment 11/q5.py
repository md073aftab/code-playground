# Given a dataset of concerts, count the number of concerts per (artist, venue), per year
# month. Make the resulting table be a wide table - one row per year month with a column
# for each unique (artist, venue) pair. Use the cross product of the artists and venues Series
# to determine which (artist, venue) pairs to include in the result.

import pandas as pd
import numpy as np
from itertools import product

data = {
    'artist': ['Adele', 'Adele', 'Drake', 'Adele', 'Drake', 'Taylor Swift'],
    'venue': ['MSG', 'MSG', 'MSG', 'Barclays', 'MSG', 'MSG'],
    'date': pd.to_datetime([
        '2023-01-15', '2023-01-20', '2023-01-15',
        '2023-02-01', '2023-02-20', '2023-01-25'
    ])
}

concerts_df = pd.DataFrame(data)

concerts_df['year_month'] = concerts_df['date'].dt.to_period('M')

artists = pd.Series(concerts_df['artist'].unique(), name="artist")
venues = pd.Series(concerts_df['venue'].unique(), name="venue")

artist_venue_pairs = pd.MultiIndex.from_product([artists, venues], names=['artist', 'venue'])

grouped = concerts_df.groupby(['year_month', 'artist', 'venue']).size()

wide_table = grouped.unstack(['artist', 'venue'])

wide_table = wide_table.reindex(columns=artist_venue_pairs, fill_value=0)

wide_table = wide_table.reset_index()

print(wide_table)