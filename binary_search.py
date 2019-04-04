import random
import time
start = time. time()
for i in range(0,10):
    print(random.randint(0,10))
end = time. time()
print(end - start)