import random as x

Vector = []
Card = []
N_Card = 0
tamano = 0
cantidad = 0
cantidad = input("Ingrese la cantidad de vectores\n")
tamano = input("Ingrese longitud del vector\n")

for i in range(int(cantidad)):
    Vector.clear()
    for j in range(int(tamano)):
        Vector.append(x.randint(0, 1))
        N_Card = sum(Vector)
    Card.append(N_Card)
    print(Vector)
    print('Cardinalidad', N_Card)


MaxCard = max(Card)
print("Mayor Cardinalidad", MaxCard)


