import numpy as n

mTransicion = [
[0.3,0.2,0.18,0.32],
[0.4,0.2,0.3,0.1],
[0.35,0.28,0.17,0.2],
[0.5,0.05,0.32,0.13],
]

mE = [0.2,0.1,0.4,0.3]



matrizTransicion = n.array(mTransicion)
matrizEstadoIniciales = n.array(mE)

#print("Matriz Transicion: ", matrizTransicion)
#print("\nMatriz E. Iniciales: ", matrizEstadoIniciales)

P1 = matrizEstadoIniciales.dot(matrizTransicion)
#print("P1: ", P1)

P2 = P1.dot(matrizTransicion)
#print("P2: ", P2)

P3 = P2.dot(matrizTransicion)
#print("P3: ", P3)

P4 = P3.dot(matrizTransicion)
#print("P4: ", P4)

P5 = P4.dot(matrizTransicion)
#print("P4: ", P5)

n = int(input("Ingresa el estado inicial a conocer\n"))
PN = matrizEstadoIniciales.dot(matrizTransicion)

for i in range(int(n)):
     PN = PN.dot(matrizTransicion)

if n==1:
     print("Estado", n, ": ", matrizEstadoIniciales)
else:
     print("Estado", n, ": ", PN)