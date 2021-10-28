import random
import time


def bubbleSort(array):
    # Tamanho do array
    n = len(array)
    # Passando por todo o array
    for i in range(n-1):
        for j in range(0, n-i-1):
            # Varre o array de 0 para n-i
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]


array = []
for i in range(int(input('Quantos numeros aleatorios?: '))):
    array.append(random.randint(1, 100))

start = time.time()
bubbleSort(array)
end = time.time()

print("Array organizado:", array)
print("Tempo gasto:", (end - start)*1000)

arrayString = '\n'.join([str(item) for item in array])
lines = arrayString

with open("Numeros.txt", "w") as numeros:
    numeros.write(lines)
