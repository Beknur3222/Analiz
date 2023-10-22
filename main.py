#%%
a = int(input())
b = int(input())
if(a > b):
    print(a)
else:
    print(b)
# %%
a = int(input())
if(a % 4 == 0 and a % 100 != 0) or (a % 400 == 0):
    print("YES")
else:
    print("NO")
# %%
a = int(input())
b = int(input())
for i in range(a, b + 1):
    if(i % 2 == 0):
        print(i, end=' ')
# %%
a = int(input())
i = 1
while(i * i <= a):
    print(i * i)
    i += 1
# %%
def SumOfDigits(a):
    return sum(map(int, str(a)))
a = int(input())
print(SumOfDigits(a))
# %%
a = int(input())
m = list(map(int, input().split()))
for i in range(0, a, 2):
    print(m[i], end=' ')
# %%
a = input().split()
for i in range(0, len(a), 2):
    print(a[i], end=' ')
# %%
a = int(input())
f = 1
for i in range(1, a + 1):
    f *= i
print(f)
# %%

