import random as x
import numpy as np

Vector = []
Card = []
vt = []
N_Card = 0
tamano = 0
cantidad = 0
cantidad = input("Ingrese la cantidad de vectores\n")
tamano = input("Ingrese longitud del vector\n")

for i in range(int(cantidad)):
    Vector.clear()
    for j in range(int(tamano)):
        Vector.append(x.randint(0, 1))
    vt.append(Vector)
    print(Vector)


print(vt)

# n=2

# output=[vt[i:i + n] for i in range(0, len(vt), n)]
# print(output)
