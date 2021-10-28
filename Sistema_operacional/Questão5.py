import threading
import time
import random

def sorteio (shared):
  print("Sorteando")
  for i in range (random.randint(0,5)):
    print(".")
    time.sleep(1)
  shared.append(random.randint(1,10))

def resultado (shared):
    print("Resultado do sorteio: "+ str(shared.pop()))

def Sorteios(n):
  shared = []
  for i in range(n):
    print("sorteio: {}".format(i+1))
    produtora = threading.Thread(target=sorteio,args=(shared,))
    produtora.start()
    produtora.join()
    consumidor = threading.Thread(target=resultado,args=(shared,))
    consumidor.start()
    consumidor.join()

Sorteios(10)
