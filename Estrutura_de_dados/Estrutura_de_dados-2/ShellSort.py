import random
import time


def shellSort(array):
    # Realoca os elemtnos até n/2, n/4, n/8, ... intervalos
    n = len(array)
    intervalo = n // 2
    while intervalo > 0:
        # Varre do intervalo até n
        for i in range(intervalo, n):
            temp = array[i]
            j = i
            while j >= intervalo and array[j - intervalo] > temp:
                array[j] = array[j - intervalo]
                j -= intervalo
            array[j] = temp
        intervalo //= 2


array = []
for i in range(int(input('Quantos numeros aleatorios?: '))):
    array.append(random.randint(1, 100))

start = time.time()
shellSort(array)
end = time.time()

print("Array organizado:", array)
print("Tempo gasto:", (end - start)*1000)

arrayString = '\n'.join([str(item) for item in array])
lines = arrayString

with open("Numeros.txt", "w") as numeros:
    numeros.write(lines)
