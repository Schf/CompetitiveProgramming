# Statement asks: "Can we use built-in data types?", refering to native fixed word size
# integers (such as 32 bit signed int). It can be done with prime factorization, but I
# don't want to.

import math
if math.factorial(25)%9317 != 0:
    print("Not divisible.")
else:
    print("Divisible.")
