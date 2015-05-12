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
#include "../splay.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void firstSlot();

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

    QWidget *infoWidget;
    QVBoxLayout *infoLayout;
    QLabel *inOrderLabel;

    splay s;
};

#endif // MAINWINDOW_H
