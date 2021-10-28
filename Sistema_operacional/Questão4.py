import threading
import random
import time

def sorteio (shared, oldShared):
  print("Sorteando")
  for i in range (random.randint(0,5)):
    print(".")
    time.sleep(1)
  oldShared[0] = shared[0]
  shared[0] = random.randint(1,10)

def resultado (shared, oldShared):
  print("shared: {}, Old: {}".format(shared,oldShared))
  if (shared[0] != oldShared[0]):
    print("Resultado do sorteio: "+ str(shared[0]))
  else:
    print("Repetido")

def Sorteios(n):
  shared = [0]
  oldShared  = [-1]
  for i in range(n):
    print("sorteio: {}".format(i+1))
    produtora = threading.Thread(target=sorteio,args=(shared, oldShared))
    produtora.start()       
    produtora.join()
    monitor   = threading.Thread(target=resultado  ,args=(shared, oldShared))
    monitor.start()
    monitor.join()


Sorteios(2)
