import numpy as np
import threading
import time

n = 3
A = np.random.randint(10, size=(n, n))
print(A)


def addMatrix(A,i):
    count = 0
    for j in range(n):
        count += A[i][j]
    print(count)
    count = 0


#threads = list()

#start = time.perf_counter()

for i in range(len(A)):
    x = threading.Thread(target=addMatrix, args=(A,i))
    # threads.append(x)
    x.start()
# for index, thread in enumerate(threads):
x.join()

#end = time.perf_counter()

#print(f"Time taken to complete add(): {round(end - start, 5)} seconds(s)")