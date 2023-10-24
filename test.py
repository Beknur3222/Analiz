#%%
#Қажетті кітапханалар қосу
import psycopg2
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# %%
#Деректер қорына қосылу
conn = psycopg2.connect(
    dbname="analiz", 
    host="127.0.0.1", 
    user="postgres", 
    password="beknur32", 
    port="5432")

#%%
#Селект запрос жасау
query = "SELECT * FROM mtcars;"
df = pd.read_sql_query(query, conn)

# %%
#Кестедегі жолдарды экранға шығару
print(len(df))
print(df.head())

# %%
#Ең тек көлікті анықтау
max_cars = df[df['qsec'] == df['qsec'].max()]
print('Самая быстрая машина:')
print(max_cars)

#%%
#Ең үлкен объем анықтау
max_cars = df[df['disp'] == df['disp'].max()]
print('Объем')
print(max_cars)

# %%
#Бағандар мен жолдар саны
num_rows, num_columns = df.shape
print(f"Количество строк: {num_rows}")
print(f"Количество столбцов: {num_columns}")

# %%
#Соңы 5 жол шығару
df.tail(5)

#%%
#Ақпараттар түрін шығару
df.dtypes

#%%
#am бағанын өшіру
df = df.drop(['am'], axis=1)
df.head(5)

#%%
# Баған есімін өзгерту
df = df.rename(columns={"hp": "HP"})
df.head(5)

#%%
#форма шығару
df.shape

#%%
#Қайталанылатын деректер шығару
duplicate_rows_df = df[df.duplicated()]
print("number of duplicate rows: ", duplicate_rows_df.shape)

#%%
#Бос емес жолдар санау
df.count()

#%%
#Қайталынатын бағандар өшіру
df = df.drop_duplicates()
df.head(5)

#%%
#Бос жолдардың суммасы
print(df.isnull().sum())

# %%
df = df.drop(['model'], axis=1)
Q1 = df.quantile(0.25)
Q3 = df.quantile(0.75)
IQR = Q3 - Q1
print("Межквартильные диапазоны:\n", IQR)

# %%
filtered_df = df[~((df < (Q1 - 1.5 * IQR))) | (df > (Q3 + 1.5 * IQR)).any(axis=1)]
filtered_df_shape = filtered_df.shape
print("Размерность данных после фильтрации:", filtered_df_shape)

# %%
plt.figure(figsize=(10,5))
correlation_matrix = df.corr()
sns.heatmap(correlation_matrix, cmap="BrBG", annot=True)
plt.show()

#%%
#Қорап түріндегі граффик
sns.boxplot(x=df['mpg'])

#%%
#Қорап түріндегі граффик
sns.boxplot(x=df['hp'])

#%%
#Граффик шығару
fig, ax = plt.subplots(figsize=(10,6))
ax.scatter(df['hp'], df['mpg'])
ax.set_xlabel('hp')
ax.set_ylabel('mpg')
plt.show()

# %%
#Байланысты аяқтау
conn.close()
