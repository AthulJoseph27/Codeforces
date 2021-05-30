import random

l = []

for i in range(1,round(1e5)+1):
    l.append(str(i)+'\n')

l.insert(0,str(len(l))+'\n')

with open('in','w') as file:
    file.writelines(l)