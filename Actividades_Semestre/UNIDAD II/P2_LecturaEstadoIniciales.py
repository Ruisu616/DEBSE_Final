import serial as s
import numpy as n

arduino = s.Serial("COM5", timeout = 1, baudrate=9600)
mTransicion = [[0.3,0.2,0.18,0.32],
[0.4,0.2,0.3,0.1],
[0.35,0.28,0.17,0.2],
[0.5,0.05,0.32,0.13],
]

matrizTransicion = n.array(mTransicion)

if arduino.isOpen():
    while(True):
        cadena = arduino.readline()
        cadena = cadena.decode() #decodificacion de la cadena
        cadena = cadena.replace("\n", "")
        cadena = cadena.replace("\r", "")

        #cadena = cadena.replace("E", "")
        #cadena = cadena.replace("F", "")

        if cadena != "":
            print("R", cadena, "R")
            auxiliar = cadena.split("G")
            EstadosIniciales = list(map(int,auxiliar[1:-2]))
            for i in range(len(EstadosIniciales)):
                EstadosIniciales[i] = EstadosIniciales[i] / 1023
            matrizEstadosIniciales = n.array(EstadosIniciales)
            P1 = matrizEstadosIniciales.dot(matrizTransicion)
            print("P1: ", P1)

