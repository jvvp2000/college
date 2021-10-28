import threading
import time
import random

def chamada_bloqueante():
  time.sleep(3)
  #time.sleep(random.randint(0,30)) 
def menuThread():
  while True:
    print("===========================\n")
    print("1) Sair \n")
    print("2) Chamada Bloqueante\n")
    option = input ()
    print(threading.active_count())
    if option == 1:
      break
    else:
      if threading.active_count() >= 7:
        print('Não possível executar o comando\n')
      else:
        if option == 2:

          bloqueio = threading.Thread(target=chamada_bloqueante)
          bloqueio.start()

  menuThread()