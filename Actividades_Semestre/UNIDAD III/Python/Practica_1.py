import serial, time

arduino = serial.Serial('COM5', baudrate = 9600)

if arduino.isOpen():
    a_sensores = []
    while True:
        cadena = arduino.readline()
        cadena = cadena.decode('ascii')
        #cadena.replace('\n', "")
        #cadena.replace('\r', "")

        if cadena != "":
            a_sensores = cadena.split("-")
            print(a_sensores)
            a_sensores = list(map(int, a_sensores))

            cadena = '-'.join([str(i) for i in a_sensores])
            arduino.write(cadena.encode('ascii'))

            print(a_sensores)
            print(cadena)

        #try:

        #except Exception as x:
         #   print(x)



