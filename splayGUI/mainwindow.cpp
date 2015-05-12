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


    insertButton = new QPushButton("Insert");
    insertText = new QLineEdit();


    controlPanelLayout->addWidget(insertText);
    controlPanelLayout->addWidget(insertButton);
    controlPanel->setLayout(controlPanelLayout);

    mainLayout->addWidget(controlPanel);

    infoWidget = new QWidget();
    infoLayout = new QVBoxLayout;
    inOrderLabel = new QLabel("In Order Print");
    infoLayout->addWidget(inOrderLabel);
    infoWidget->setLayout(infoLayout);
    mainLayout->addWidget(infoWidget);

    window->setLayout(mainLayout);
    setCentralWidget(window);

    s.insert(5);


    connect(insertButton, SIGNAL(clicked()), this, SLOT(firstSlot()));


}

void MainWindow::firstSlot() {
    QString txt = insertText->text();
    inOrderLabel->setText(txt);
}

MainWindow::~MainWindow()
{
    delete ui;
}
