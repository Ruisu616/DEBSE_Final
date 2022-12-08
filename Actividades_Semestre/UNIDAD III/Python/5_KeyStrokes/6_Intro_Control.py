
#considerar el uso de 6 pulsadores
#descargar emulador y un rom de un juego sencillo (ejemplo vba)

##uso de modulo pyserial
import serial as s
from pynput import keyboard
from pynput.keyboard import Key, Controller
keyboard = Controller()
###################################

import sys

from PyQt5 import uic, QtWidgets, QtCore

pulsadores = []
puls = 1

qtCreatorFile = "6_Intro_Control.ui"  # Nombre del archivo

Ui_MainWindow, QtBaseClass = uic.loadUiType(qtCreatorFile)


class MyApp(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self):
        QtWidgets.QMainWindow.__init__(self)
        Ui_MainWindow.__init__(self)
        self.setupUi(self)

        self.arduino = None

        self.btn_conexion.clicked.connect(self.conexion)


        self.SegundoPlano = QtCore.QTimer()
        self.SegundoPlano.timeout.connect(self.accion)


    def accion(self):
        self.arduino.write("G".encode())
        if self.arduino.inWaiting():
            v = self.arduino.readline()
            print("Valor", v, "G")
            valor = v.decode()
            valor = valor.replace("\n","")
            valor = valor.replace("\r", "")
            #print(valor)
            pulsadores = valor.split("-")
            print(pulsadores)
            if pulsadores[0] == "0":
                pass
                keyboard.press('a')
                keyboard.release('a')
            if pulsadores[1] == "0":
                pass
                keyboard.press('b')
                keyboard.release('b')
            if pulsadores[2] == "0":
                pass
                keyboard.press('c')
                keyboard.release('c')



    def conexion(self):
        v = self.btn_conexion.text()
        if v == "CONECTAR": #pasa de desconectado a conectado
            self.btn_conexion.setText("DESCONECTAR")

            if self.arduino == None: #SI NUNCA ME HABIA CONECTADO
                com = "COM" + self.txt_com.text()
                #com = self.txt_com.text()
                self.arduino = s.Serial(com, baudrate=9600, timeout=10) ##realiza la conexion
                # y la iniciliza
                self.txt_estado.setText("INICIALIZADA")

                self.SegundoPlano.start(5)
            elif not self.arduino.isOpen():
                self.arduino.open()
                self.txt_estado.setText("REESTABLECIDA")

                self.SegundoPlano.start(5)

        else: #pasa de conectado a desconectado
            self.btn_conexion.setText("CONECTAR")

            self.arduino.close()
            self.txt_estado.setText("CERRADA")

            self.SegundoPlano.stop()
    def mensaje(self, msj):
        m = QtWidgets.QMessageBox()
        m.setText(msj)
        m.exec_()


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = MyApp()
    window.show()
    sys.exit(app.exec_()) 



