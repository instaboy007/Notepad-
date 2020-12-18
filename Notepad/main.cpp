#include "mainwindow.h"

#include <QApplication> //used to handle widgets,event handling,mouse movements and overall look of out windows

int main(int argc, char *argv[]) // this is where the execution begins
{
    QApplication a(argc, argv); //function used to create the application object
    MainWindow w; //create main application object
    w.setWindowTitle("Notepad"); //used to give title to the application window
    w.setWindowIcon(QIcon(":/imgs/notepad.png")); //use to give logo to the application
    w.show();// used to display the application on the screen
    return a.exec(); //this is used to put the application in a loop while the events are being or about to be handled
}
