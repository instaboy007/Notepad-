#ifndef MAINWINDOW_H //to make sure the header files are loaded only once
#define MAINWINDOW_H

#include <QMainWindow> //provide main application window in which the user interface is built
#include <QFile> //used to work with files
#include <QFileDialog> //used to show a dialogue while opening a file
#include <QTextStream> //to read text fom files
#include <QMessageBox> //used to show user errors
#include <QtPrintSupport/QPrinter> //used to print using a printer
#include <QtPrintSupport/QPrintDialog> //used to show the printing dialog box




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; } //this is standard namespace ui which is tied to the ui file(mainwindow.ui)
QT_END_NAMESPACE

class MainWindow : public QMainWindow //Mainwindow class is declared as n Q_Object which is the base class for all Q_Objects (qobjects can handle events and are executer at their own thread)
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr); //(mainwindow)constructor with no parent(nullptr)
    ~MainWindow();

private slots: //slots are functions that can be called normally a singnal from ca class can be invoking the slots
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_As_triggered();

    void on_actionPrint_triggered();

    void on_actionExit_triggered();

    void on_actionCop_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

private:
    Ui::MainWindow *ui; //points to ui class(mainwindow.ui->class)
    QString CurrentFile=""; //holds the name of the file

};
#endif // MAINWINDOW_H
