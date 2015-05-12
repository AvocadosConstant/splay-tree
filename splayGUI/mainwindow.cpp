#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    window = new QWidget();
    mainLayout = new QVBoxLayout();

    contentWidget = new QWidget();
    contentLayout = new QHBoxLayout();

    controlPanel = new QWidget();
    controlPanelLayout = new QVBoxLayout();
    insertWidget = new QWidget();
    insertLayout = new QHBoxLayout();
    insertButton = new QPushButton("Insert");
    insertText = new QLineEdit();
    insertLayout->addWidget(insertText);
    insertLayout->addWidget(insertButton);
    insertWidget->setLayout(insertLayout);

    deleteWidget = new QWidget();
    deleteLayout = new QHBoxLayout();
    deleteButton = new QPushButton("Delete");
    deleteText = new QLineEdit();
    deleteLayout->addWidget(deleteText);
    deleteLayout->addWidget(deleteButton);
    deleteWidget->setLayout(deleteLayout);

    findWidget = new QWidget();
    findLayout = new QHBoxLayout();
    findButton = new QPushButton("Find");
    findText = new QLineEdit();
    findLayout->addWidget(findText);
    findLayout->addWidget(findButton);
    findWidget->setLayout(findLayout);


    controlPanelLayout->addWidget(insertWidget);
    controlPanelLayout->addWidget(deleteWidget);
    controlPanelLayout->addWidget(findWidget);


    controlPanel->setLayout(controlPanelLayout);
    contentLayout->addWidget(controlPanel);

    infoWidget = new QWidget();
    infoLayout = new QVBoxLayout;

    inOrderLabel = new QLabel("In Order Print");
    inOrderLabel->setStyleSheet("QLabel { font-size: 18px; padding: 5px; width: 500px;}");
    breadthLabel = new QLabel("Breadth First Print");
    breadthLabel->setStyleSheet("QLabel { font-size: 18px; padding: 5px; width: 500px;}");

    infoLayout->addWidget(inOrderLabel);
    infoLayout->addWidget(breadthLabel);
    infoWidget->setLayout(infoLayout);
    infoWidget->setStyleSheet("background-color:white;");
    contentLayout->addWidget(infoWidget);

    contentWidget->setLayout(contentLayout);

    mainLayout->addWidget(contentWidget);

    commandLabel = new QLabel("Most Recent Command");
    commandLabel->setStyleSheet("QLabel { background-color: lightgray; color: black; padding: 5px;}");
    mainLayout->addWidget(commandLabel);

    consoleLabel = new QLabel("Console Log");
    consoleLabel->setStyleSheet("QLabel { background-color: black; color: white; padding: 5px;}");
    mainLayout->addWidget(consoleLabel);
    window->setLayout(mainLayout);

    setCentralWidget(window);

    connect(insertButton, SIGNAL(clicked()), this, SLOT(insertSlot()));
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteSlot()));
    connect(findButton, SIGNAL(clicked()), this, SLOT(findSlot()));


}

void MainWindow::insertSlot() {
    consoleLabel->setText("Console Log");
    QString txt = insertText->text();

    if(txt.length() == 0) {
        commandLabel->setText("Recent Command: Please enter a value to insert.");
        return;
    }

    commandLabel->setText("Recent Command: Insert " + txt);
    double dta = txt.toDouble();
    s.insert(dta);
    displayInOrder();
    displayBreadth();

    consoleLabel->setText("Inserted node with value: " + QString::number(dta) +
                          "\nSplaying node to root.");
}

void MainWindow::deleteSlot() {
    consoleLabel->setText("Console Log");
    QString txt = deleteText->text();

    if(txt.length() == 0) {
        commandLabel->setText("Recent Command: Please enter a value to delete.");
        return;
    }

    commandLabel->setText("Recent Command: Delete " + txt);
    double dta = txt.toDouble();
    node* nd = s.deleteKey(dta);
    displayInOrder();
    displayBreadth();

    if(!nd) {
        consoleLabel->setText("Node with value " + QString::number(dta) + " was not found!" +
                                                                          "\nCould not delete.");
        return;
    }

    consoleLabel->setText("Found node with value: " + QString::number(nd->data) +
                          "\nSplaying node to root." +
                          "\nDeleting root." +
                          "\nJoining subtrees.");
}

void MainWindow::findSlot() {
    consoleLabel->setText("Console Log");
    QString txt = findText->text();
    commandLabel->setText("Recent Command: Find " + txt);
    if(txt.length() == 0) {
        commandLabel->setText("Recent Command: Please enter a value to find.");
        return;
    }
    double dta = txt.toDouble();
    node* nd = s.search(dta);
    displayInOrder();
    displayBreadth();

    if(!nd) {
        consoleLabel->setText("Node with value " + QString::number(dta) + " was not found!");
        return;
    }

    consoleLabel->setText("Found node with value: " + QString::number(nd->data) +
                          "\nSplaying node to root.");
}

void MainWindow::displayInOrder() {
    inOrderLabel->setText("In Order Print\n    ");

    std::vector<double> vct = s.sortedArray();
    QString txt = inOrderLabel->text();
    for(auto val : vct) {
        txt.append(" | " + QString::number(val));
    }
    txt.append(" | ");
    inOrderLabel->setText(txt);
}

void MainWindow::displayBreadth() {
    breadthLabel->setText("Breadth First Print\n    ");

    std::vector<double> vct = s.printBreadthFirst();
    QString txt = breadthLabel->text();
    for(auto val : vct) {
        txt.append(" | " + QString::number(val));
    }
    txt.append(" | ");
    breadthLabel->setText(txt);
}

MainWindow::~MainWindow()
{
    delete ui;
}
