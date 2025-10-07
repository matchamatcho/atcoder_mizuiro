def f(x,p):

    return x+p*(2**(-x/1.5))

import math

# print(f(1,1))
p=float(input())

z=math.exp(2)/1.5

zz=-math.exp(z/p)/z

print(f(zz,p))



