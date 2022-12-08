import statistics
import sys
from statistics import mean
from PyQt5 import uic, QtWidgets, QtCore
from PyQt5.QtWidgets import QMessageBox
import numpy as np

qtCreatorFile = "Lectura_Datos.ui"
UiMainWindow, QtBaseClass = uic.loadUiType(qtCreatorFile)

TxtFile = open("DatosLeidos.txt", "r")
data = [int(i) for i in TxtFile]
from sklearn import preprocessing



class MyApp(QtWidgets.QMainWindow, UiMainWindow):

    def __init__(self):
        QtWidgets.QMainWindow.__init__(self)
        UiMainWindow.__init__(self)
        self.setupUi(self)

        self.btnLeer.clicked.connect(self.Cargar)

    def Cargar(self):
        try:

            max = round(XMax(data),2)
            min = round(XMin(data),2)
            promedio = round(mean(data),2)
            desv_std = round(statistics.pstdev(data),2)

            salida = "Indice" + "/" + "Estandarizacion" + "/" + "Normalización" + "/" + "Complemento"
            self.dtsleidos.addItem(salida)
            self.dtsleidos.setCurrentRow(self.dtsleidos.count() - 1)
            self.xmin.setText(str(min))
            self.xmax.setText(str(max))
            self.prom.setText(str(promedio))
            self.desvest.setText(str(desv_std))

            for i in data:
                est = round(estand(i, promedio, desv_std), 2)
                norm = round(nm(i, min, max), 2)
                cmp = round(1 - nm(i, min, max), 2)
                salida = str(i) + "/" + str(est) + "/" + str(norm) + "/" + str(cmp)

            self.dtsleidos.addItem(salida)
            self.dtsleidos.setCurrentRow(self.dtsleidos.count() - 1)

        except Exception as e:
            print(e)

def XMax(self):
        max = data[0];
        for x in data:
            if x > max:
                max = x
        return max

def XMin(self):
        min = data[0];
        for x in data:
            if x < min:
                min = x
        return min

def mean(data):
    return sum(data) / len(data)

def nm(x, xmin, xmax):
    resN = (x - xmin) / (xmax - xmin)
    return resN


def estand(x, p, de):
    resE = (x - p) / de
    return resE

if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = MyApp()
    window.show()
    sys.exit(app.exec_())
