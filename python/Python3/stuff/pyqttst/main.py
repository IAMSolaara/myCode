# importo i moduli che mi servono
from PyQt5.QtWidgets import QApplication, QLabel, QWidget, QVBoxLayout, QPushButton, QLayout, QHBoxLayout


class MyWin(QWidget):
    def __init__(self, parent=None):
        super(MyWin, self).__init__(parent)
        self.initUI()

    def initUI(self):
        #layout manager
        self.mainLayout = QHBoxLayout()

        self.leftLayout = QVBoxLayout()
        self.rightLayout = QVBoxLayout()

        #pulsanti carini
        self.topBtn = QPushButton('Top', self)
        self.topBtn.setFixedSize(32, 16)
        self.topBtn.move(0,0)
        self.bottomBtn = QPushButton('Bottom', self)
        self.bottomBtn.setFixedSize(48, 16)

        #binding callback per pulsante cliccato
        self.topBtn.clicked.connect(self.topButtonClick)
        self.bottomBtn.clicked.connect(self.bottomButtonClick)

        #aggiunta pulsante al layout
        self.leftLayout.addWidget(self.topBtn)
        self.leftLayout.addWidget(self.bottomBtn)

        #creazione label e aggiunta al layout
        self.label = QLabel()
        self.rightLayout.addWidget(self.label)

        self.mainLayout.addItem(self.leftLayout)
        self.mainLayout.addItem(self.rightLayout)

        #binding layout alla finestra
        self.setLayout(self.mainLayout)
        self.setFixedSize(640, 480)

        #mostrare la finestra
        self.show()

    def bottomButtonClick(self):
        self.label.setText("TESTAMENTO DI SOTTO")

    def topButtonClick(self):
        self.label.setText("TESTAMENTO DI SOPRA")



# parentesi perche' l'app non accetta parametri CLI
# quindi mandiamo niente
app = QApplication([])

# finestra che contiene le cose
window = MyWin()

#eseguire le cose
app.exec_()