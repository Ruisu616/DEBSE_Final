import serial as s, time
auxiliar = [0,0,0]
valores = [0,0]
prom = [0,0]
led = 0
arduino = s.Serial("COM5", timeout = 1, baudrate=9600)
time.sleep(2)
if arduino.isOpen():
    while(True):
        try:
            valor = arduino.readline().decode("ascii")
            if valor != "":
                cont = 0
                for e in valor.strip().split("-"):
                    if e != "":
                        auxiliar[cont] = e
                        cont += 1
                    print(f'auxiliar {auxiliar}')
                    if int(auxiliar[0]) == 1:
                        print("Arduino a python")
                        for i in range(1,3):
                            aux = int(auxiliar[i])
                            if i == 1:
                                valores[i-1] = aux
                                prom[i-1] = int(aux/4)
                            else:
                                valores[i - 1] = aux
                                prom[i - 1] = int(aux/4)
                        print(f'valores {valores}')
                        print(f'promedio {prom}')
                        cad = str(prom[0])+","+str(prom[1])
                        arduino.write(cad.encode('ascii'))

        except Exception as x:
            print(x)




