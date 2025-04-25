import pandas as pd

asking_prices = pd.Series([20000, 22000, 18000, 25000, 21000])
fair_prices = pd.Series([21000, 21500, 20000, 24000, 22000])

good_deals = asking_prices[asking_prices < fair_prices].index.tolist()

print("Indices of good deals:", good_deals)
