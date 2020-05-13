#!/usr/bin/env python
# importo i moduli che mi servono
from PyQt5.QtWidgets import QApplication, QLabel, QWidget, QVBoxLayout, QPushButton, QLayout, QHBoxLayout, QLineEdit, QCheckBox, QFileDialog, QTextEdit, QMessageBox
from PyQt5.QtGui import QIcon, QPixmap
from PyQt5.QtCore import QProcess, QSize, QByteArray

class MyWin(QWidget):
    def __init__(self, parent=None):
        super(MyWin, self).__init__(parent)
        self.initUI()

    #metodo che costruisce la GUI
    def initUI(self):
        # impostazione titolo
        self.setWindowTitle("lorecast162's youtube-dl frontend")
        #layout manager
        self.mainLayout = QVBoxLayout(self)

        #Label sopra la link box
        self.linkLabel = QLabel("Link:", self)
        self.linkLabel.setMaximumHeight(32);
        # textbox dove mettere il link
        self.linkTextBox = QLineEdit(self);
        
        # checkbox per decidere se estrarre l'audio
        self.extractAudioCheckBox = QCheckBox('Extract Audio', self);

        # pulsante per iniziare il download
        self.startBtn = QPushButton('Download', self)
        self.startBtn.setIcon(QIcon('./res/download.svg'))
        self.startBtn.setIconSize(QSize(24, 24))
        self.startBtn.setFixedHeight(32)
        #binding callback per pulsante cliccato
        self.startBtn.clicked.connect(self.startButtonClick)

        # pulsante per interrompere il download
        self.cancelBtn = QPushButton('Cancel', self)
        self.cancelBtn.setFixedHeight(32)
        self.cancelBtn.setEnabled(False)
        self.cancelBtn.clicked.connect(self.cancelButtonClick)
        self.cancelBtn.setIcon( QIcon('./res/cancel.svg'))
        self.cancelBtn.setIconSize(QSize(32, 32))

        # label e textbox per l'output del processo
        self.processOutputLabel = QLabel('Process output:')
        self.processOutput = QTextEdit()
        
        #aggiunta elementi al layout
        self.mainLayout.addWidget(self.linkLabel)
        self.mainLayout.addWidget(self.linkTextBox)
        self.mainLayout.addWidget(self.extractAudioCheckBox)
        self.mainLayout.addWidget(self.startBtn)
        self.mainLayout.addWidget(self.processOutputLabel)
        self.mainLayout.addWidget(self.processOutput)
        self.mainLayout.addWidget(self.cancelBtn)

        #impostazione layout manager alla finestra
        self.setLayout(self.mainLayout)
        self.setFixedSize(640, 480)

        # creazione oggetto QProcess e binding callback a dataReady
        self.process = QProcess(self);
        self.process.readyRead.connect(self.dataReady)

        # set abilitazione pulsanti per fare in modo di non ripetersi
        self.process.started.connect(lambda: self.startBtn.setEnabled(False))
        self.process.finished.connect(self.processEnded)

    # callback chiamata quando il pulsante download viene premuto
    def startButtonClick(self):
        linkTextBoxText = self.linkTextBox.text()
        if (linkTextBoxText != ''):
            commandStr = "youtube-dl -o "
            destPath = QFileDialog.getExistingDirectory(self, 'Select destination directory', '/home/lorecast162')
            if (destPath == ''):
                destPath = "$HOME"
            commandStr += destPath + "/%(title)s-%(id)s.%(ext)s "
            if (self.extractAudioCheckBox.isChecked()):
                commandStr += "-x --audio-format=best "
            commandStr += linkTextBoxText
            self.processOutput.clear()
            command = commandStr.split()
            self.process.start(command[0], command[1:])
        else:
            QMessageBox.warning(self, "", "Link text box empty!")
    
    # callback quando il processo manda dati. usata per il textbox output
    def dataReady(self):
        cursor = self.processOutput.textCursor()
        cursor.movePosition(cursor.End)
        cursor.insertText(bytes(self.process.readAll()).decode('UTF-8'))
        self.cancelBtn.setEnabled(True)
        self.processOutput.ensureCursorVisible()

    # callback quando il processo termina.
    # viene chiamata anche quando viene interrotto
    def processEnded(self):
        cursor = self.processOutput.textCursor()
        cursor.movePosition(cursor.End)
        cursor.insertText('\nProcess Finished!')
        self.processOutput.ensureCursorVisible()
        self.startBtn.setEnabled(True)
        self.cancelBtn.setEnabled(False)
        QMessageBox.information(self, 'Info', 'The file has been downloaded!')

    #callback per cancel
    def cancelButtonClick(self):
        reply = QMessageBox.question(self, 'Message', 'Are you sure you want to cancel the download?\nYou will have to manually remove .part files!', QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if (reply == QMessageBox.Yes):
            self.process.terminate()


def main():
    # parentesi perche' l'app non accetta parametri CLI
    # quindi mandiamo niente
    app = QApplication([])

    # finestra che contiene le cose
    window = MyWin()

    # mostrare la finestra
    window.show()

    #eseguire le cose
    app.exec_()

if __name__ == '__main__':
    main()
