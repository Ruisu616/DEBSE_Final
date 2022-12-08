
#considerar el uso de 6 pulsadores
#descargar emulador y un rom de un juego sencillo (ejemplo vba)

##uso de modulo pyserial
import serial as s,time
#from pynput import keyboard
#from pynput.keyboard import Key, Controller


#keyboard = Controller()
###################################

import sys

from PyQt5 import uic, QtWidgets, QtCore
from PyQt5.QtWidgets import QMessageBox

pulsadores = []
puls = 1
cadena = ""
auxiliar = [0,0,0]
valores = [0,0]
prom = [0,0]
led = 0

qtCreatorFile = "Lectura_Guardado_de_datos.ui"  # Nombre del archivo

Ui_MainWindow, QtBaseClass = uic.loadUiType(qtCreatorFile)


class MyApp(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self):
        QtWidgets.QMainWindow.__init__(self)
        Ui_MainWindow.__init__(self)
        self.setupUi(self)
        self.cadena = ""
        self.aux = ""
        self.arduino = None

        self.colorR = f'background-color: rgb({0}, {0}, {0});' \
                      f'color: rgb({255}, {0}, {0});' \
                      f'border: 3px solid Green;' \
                      f'border-radius: 10px;' \
                      f'font: 75 26pt "Segoe Print";'  # Declaracion de los colores para los radio buttons y labels de los numeros(Verde)
        self.colorV = f'background-color: rgb({0}, {0}, {0});' \
                      f'color: rgb({0}, {255}, {0});' \
                      f'border: 3px solid Black;' \
                      f'border-radius: 10px;' \
                      f'font: 75 26pt "Segoe Print";'


        self.btn_conexion.clicked.connect(self.conexion)
        self.btn_desconectar.clicked.connect(self.desc)
        self.btn_archivo.clicked.connect(self.guardar)


        self.SegundoPlano = QtCore.QTimer()
        self.SegundoPlano.timeout.connect(self.accion)


    def accion(self):

        #self.arduino.write("G".encode())
        if self.arduino.inWaiting():
            v = self.arduino.readline()
            print("Valor", v, "G")
            self.valor = v.decode()
            self.valor = self.valor.replace("\n","")
            self.valor = self.valor.replace("\r", "")
            self.datosSensor.addItem(self.valor)
            self.aux += self.valor
            #print(valor)


    def conexion(self):
        v = self.btn_conexion.text()
        if v == "CONECTAR": #pasa de desconectado a conectado

            if self.arduino == None: #SI NUNCA ME HABIA CONECTADO
                com = "COM" + self.txt_com.text()
                #com = self.txt_com.text()
                self.arduino = s.Serial(com, baudrate=9600, timeout=10) ##realiza la conexion
                # y la iniciliza
                self.txt_estado.setText("INICIALIZADA")
                self.txt_estado.setStyleSheet(self.colorV)


                self.SegundoPlano.start(5)
            elif not self.arduino.isOpen():
                self.arduino.open()
                self.txt_estado.setText("REESTABLECIDA")
                self.txt_estado.setStyleSheet(self.colorV)

                self.SegundoPlano.start(5)

    def desc(self):

        self.arduino.close()
        self.txt_estado.setText("CERRADA")
        self.txt_estado.setStyleSheet(self.colorR)

        self.SegundoPlano.stop()

    def guardar(self):
        #print(self.aux)
        #print(len(self.aux))
        cont = 0
        for e in self.aux.split("."):
            f = open("Datos Potenciometro.txt", "w")
            self.cadena += f"{cont},{e}\n"
            f.write(self.cadena)
            f.close()
            cont+=1
        QMessageBox.information(self, '\tImportante', 'ARCHIVO GUARDADO CORRECTAMENTE')


    def mensaje(self, msj):
        m = QtWidgets.QMessageBox()
        m.setText(msj)
        m.exec_()


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = MyApp()
    window.show()
    sys.exit(app.exec_()) 



