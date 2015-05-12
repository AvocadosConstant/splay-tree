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
    deleteButton = new QPushButton("Delete");
    deleteText = new QLineEdit();
    findButton = new QPushButton("Find");
    findText = new QLineEdit();


    controlPanelLayout->addWidget(insertText);
    controlPanelLayout->addWidget(insertButton);
    controlPanelLayout->addWidget(deleteText);
    controlPanelLayout->addWidget(deleteButton);
    controlPanelLayout->addWidget(findText);
    controlPanelLayout->addWidget(findButton);

    controlPanel->setLayout(controlPanelLayout);
    mainLayout->addWidget(controlPanel);

    infoWidget = new QWidget();
    infoLayout = new QVBoxLayout;

    commandLabel = new QLabel("Most Recent Command");
    inOrderLabel = new QLabel("In Order Print");

    infoLayout->addWidget(commandLabel);
    infoLayout->addWidget(inOrderLabel);
    infoWidget->setLayout(infoLayout);
    mainLayout->addWidget(infoWidget);

    window->setLayout(mainLayout);
    setCentralWidget(window);

    s.insert(5);
    s.insert(4);
    s.insert(6);
    s.inOrder();


    connect(insertButton, SIGNAL(clicked()), this, SLOT(insertSlot()));
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteSlot()));
    connect(findButton, SIGNAL(clicked()), this, SLOT(findSlot()));


}

void MainWindow::insertSlot() {
    QString txt = insertText->text();
    commandLabel->setText("Recent Command: Insert " + txt);
    double dta = txt.toDouble();
    s.insert(dta);
    displayInOrder();
}

void MainWindow::deleteSlot() {
    QString txt = deleteText->text();
    commandLabel->setText("Recent Command: Delete " + txt);
    double dta = txt.toDouble();
    s.deleteKey(dta);
    displayInOrder();
}

void MainWindow::findSlot() {
    QString txt = findText->text();
    commandLabel->setText("Recent Command: Find " + txt);
    double dta = txt.toDouble();
    s.search(dta);
    displayInOrder();
}

void MainWindow::displayInOrder() {
    inOrderLabel->setText("In Order Print\n    ");

    std::vector<double> vct = s.sortedArray();

    for(auto val : vct) {
        QString txt = inOrderLabel->text();
        txt.append(" | " + QString::number(val));
        inOrderLabel->setText(txt);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
