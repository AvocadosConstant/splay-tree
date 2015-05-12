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

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QWidget *window;
    QVBoxLayout *mainLayout;

    QWidget *controlPanel;
    QHBoxLayout *controlPanelLayout;

        QPushButton *insertButton;
        QLineEdit *insertText;

        QPushButton *deleteButton;
        QLineEdit *deleteText;

        QPushButton *findButton;
        QLineEdit *findText;

        //QPushButton *Button;
        //QLineEdit *Text;

    QWidget *infoWidget;
    QVBoxLayout *infoLayout;
    QLabel *commandLabel;
    QLabel *inOrderLabel;

    splay s;
};

#endif // MAINWINDOW_H
