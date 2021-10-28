import time
import random


def countingSort(preArray):
    n = max(preArray)
    contadorArray = n+1
    countArray = [0] * contadorArray

    # Varrer o array  contando
    for el in preArray:
        countArray[el] += 1
    # Para cada elemento, soma o seu valor no anterior
    for i in range(1, contadorArray):
        countArray[i] += countArray[i-1]
    # Calculando a posicao do elemento
    posArray = [0] * len(preArray)
    i = len(preArray) - 1
    while i >= 0:
        elemAtual = preArray[i]
        countArray[elemAtual] -= 1
        newPosition = countArray[elemAtual]
        posArray[newPosition] = elemAtual
        i -= 1
    return posArray


array = []
for i in range(int(input('Quantos numeros aleatorios?: '))):
    array.append(random.randint(1, 100))

start = time.time()
arraySort = countingSort(array)
end = time.time()


print("Counting sort result = ", arraySort)
print("Tempo gasto:", (end - start)*1000)
