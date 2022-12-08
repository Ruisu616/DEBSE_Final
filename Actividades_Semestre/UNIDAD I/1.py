import random as x
numeros = []
validacion = False
size = 0
while validacion == False:
    cantidad = input('INGRESE EL TAMAÑO DEL VECTOR:\n')
    for i in range(int(cantidad)):
        numeros.append(0)
    print(len(numeros))
    size = len(numeros)
    if size % 2 == 0:
        print('Es Par:', size)
        validacion = True
    else:
        print('Es Impar:', size)
        numeros.clear()
numeros.clear()
for i in range(size):
    numeros.append(x.randint(1, 20))
print(numeros)
numeros.sort(reverse=True)
print(numeros)
def split_list(lst, n):
    for i in range(0, len(lst), n):
        yield lst[i:i + n]
n = int(size/2)
output = list(split_list(numeros, n))
vectorA = []
for i in range(len(output[0])):
    vectorA.append(output[0][n-1])
    n = n - 1
print('Vector A Ascendente = ', vectorA)
output[1].sort()
vector = output[1]
vectorN = []
for i in range(len(vector)):
    if i == 0:
        vectorN.append(vector[i])
    else:
        num1 = vectorN[i-1]
        num2 = vector[i]
        suma = num1+num2
        vectorN.append(suma)
print('Vector B = ', output[1])
print('Vector B Sumar = ', vectorN)
print('Finalizado')
