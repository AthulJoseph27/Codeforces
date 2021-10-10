k = int(input())

nodes = pow(2,k)-2

mod = 10**9+7

res = 6*pow(4,nodes,mod)

res%=mod

print(res)