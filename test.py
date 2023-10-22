#%%
#
import psycopg2
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# %%
conn = psycopg2.connect(
    dbname="analiz", 
    host="127.0.0.1", 
    user="postgres", 
    password="beknur32", 
    port="5432")

#%%
query = "SELECT * FROM mtcars;"
df = pd.read_sql_query(query, conn)

# %%
print(len(df))
print(df.head())

# %%
max_cars = df[df['qsec'] == df['qsec'].max()]
print('Самая быстрая машина:')
print(max_cars)

#%%
max_cars = df[df['disp'] == df['disp'].max()]
print('Объем')
print(max_cars)

# %%
num_rows, num_columns = df.shape
print(f"Количество строк: {num_rows}")
print(f"Количество столбцов: {num_columns}")

# %%
df.tail(5)

#%%
df.dtypes

#%%
df = df.drop(['am'], axis=1)
df.head(5)

#%%
df = df.rename(columns={"hp": "HP"})
df.head(5)

#%%
df.shape

#%%
duplicate_rows_df = df[df.duplicated()]
print("number of duplicate rows: ", duplicate_rows_df.shape)

#%%
df.count()

#%%
df = df.drop_duplicates()
df.head(5)

#%%
print(df.isnull().sum())

#%%
sns.boxplot(x=df['mpg'])

#%%
sns.boxplot(x=df['hp'])

#%%
fig, ax = plt.subplots(figsize=(10,6))
ax.scatter(df['hp'], df['mpg'])
ax.set_xlabel('hp')
ax.set_ylabel('mpg')
plt.show()

# %%
conn.close()
