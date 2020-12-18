#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) // this is the mainwindow class definition with constructor(qmainwindow parent const)&create ui class and assign to the ui member
{
    ui->setupUi(this); //used to setup the user interface
    this->setCentralWidget(ui->textEdit);//used to display the textedit ui in full screen
}

MainWindow::~MainWindow() //destructor that is user to delete the user interface
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    CurrentFile.clear(); //whenever the new file is created the previous file is cleared using this
    ui->textEdit->setText(QString()); //used to clear the text edit widget and also to create a new file to work
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open File"); //the name of the file is stored in fileName which is fetched from opening a file
    QFile file(fileName); //qfile object used to read/write file with filename passed to it
    CurrentFile=fileName; //filename is stored in currentfile
    //condition to check whether the file is a valid file(valid text and readable file) if not valid the message pops ups showing error in human readable format
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"WARNING","Cannot Open File ! " + file.errorString());
    }
    //if file is valid
    setWindowTitle(fileName); //window title is set to filename
    QTextStream in(&file); //used to create interface for reading text from file
    QString text=in.readAll(); //used to copy the text from the file
    ui->textEdit->setText(text); //used to store the text to the text edit
    file.close(); //used to close the file
}


void MainWindow::on_actionSave_As_triggered()
{
    QString fileName=QFileDialog::getSaveFileName(this,"Save As"); //file name is saved to fileName
    QFile file(fileName); //qfile object is created with filename argument
    //if the file cant be written or invalid file an error message pops up
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"WARNING","Cannot Save File ! " + file.errorString());
        return;
    }
    //if not
     CurrentFile=fileName; //current file has the name of the file
     setWindowTitle(fileName); //window title is set to filename
     QTextStream out(&file); //used to create the interface for writing
     QString text =ui->textEdit->toPlainText(); //copy the text from the text edit to text
     out<<text; //used to move the text to the file
     file.close(); //file is closed
}

void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer; //QpRINTER OBJECT USED TO INTERACT ANY PRINTER
    printer.setPrinterName("Printer Name"); //USED TO SET THE PRINTER NAME(assigned to the qprint object)
    QPrintDialog pDialog(&printer,this); //used to open the print dialog box to choose the print options
    //if there is a problem connecting to the printer a message is displayed
    if(pDialog.exec() == QDialog::Rejected){
        QMessageBox::warning(this,"WARNING","Cannot Access Printer ! ");
        return;
    }
    ui->textEdit->print(&printer);//used to print the text in text edit

}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit(); // used to close the application
}

void MainWindow::on_actionCop_triggered()
{
    ui->textEdit->copy(); //used to copy
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut(); //used to cut
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste(); //used to paste
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo(); //used to undo
}

void MainWindow::on_actionRedo_triggered()
{
     ui->textEdit->redo(); //used to redo
}
