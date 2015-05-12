#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    window = new QWidget();
    mainLayout = new QVBoxLayout();

    controlPanel = new QWidget();
    controlPanelLayout = new QHBoxLayout();


    insertLabel = new QLabel("Insert");
    insertText = new QLineEdit();


    controlPanelLayout->addWidget(insertLabel);
    controlPanelLayout->addWidget(insertText);
    controlPanel->setLayout(controlPanelLayout);

    mainLayout->addWidget(controlPanel);

    window->setLayout(mainLayout);
    setCentralWidget(window);
}

MainWindow::~MainWindow()
{
    delete ui;
}
