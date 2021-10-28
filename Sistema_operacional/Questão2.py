import threading
listaPrimos = []


def checarPrimo(primo):
    if primo % 2 == 0 and primo > 2:
        return False
    for i in range(3, primo, 2):
        if primo % i == 0:
            return False
    return True


def checarLista(inicio, lista, fim):
    for i in range(inicio, fim):
        if(checarPrimo(i)):
            lista.append(i)


def threads(lista):
    mil = 1000
    for i in range(100):
        x = threading.Thread(target=checarLista,
                             args=(i*mil, lista, (i+1)*mil-1))
        x.start()
    print(lista)


threads(listaPrimos)
