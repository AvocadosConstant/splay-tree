#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QColor>
#include <QLineEdit>
#include <vector>
#include "../splay.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void insertSlot();
    void deleteSlot();
    void findSlot();
    void displayInOrder();
    void displayBreadth();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QWidget *window;
    QVBoxLayout *mainLayout;

    QWidget *contentWidget;
    QHBoxLayout *contentLayout;

    QWidget *controlPanel;
    QVBoxLayout *controlPanelLayout;

        QWidget* insertWidget;
        QHBoxLayout* insertLayout;
        QPushButton *insertButton;
        QLineEdit *insertText;

        QWidget* deleteWidget;
        QHBoxLayout* deleteLayout;
        QPushButton *deleteButton;
        QLineEdit *deleteText;

        QWidget* findWidget;
        QHBoxLayout* findLayout;
        QPushButton *findButton;
        QLineEdit *findText;

        //QPushButton *Button;
        //QLineEdit *Text;

    QWidget *infoWidget;
    QVBoxLayout *infoLayout;
        QLabel *inOrderLabel;
        QLabel *breadthLabel;


    QLabel *commandLabel;
    QLabel *consoleLabel;

    splay s;
};

#endif // MAINWINDOW_H
