#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
    connect(ui->deleteTaskButton, &QPushButton::clicked, this, &MainWindow::deleteTask);
    connect(ui->detailsTaskButton, &QPushButton::clicked, this, &MainWindow::showTaskDetails);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTask()
{
    bool ok;
    QString taskTitle = QInputDialog::getText(this, "Добавить задачу", "Название задачи:", QLineEdit::Normal, "", &ok);
    if (ok && !taskTitle.isEmpty()) {
        ui->tasksListWidget->addItem(taskTitle);
    }
}

void MainWindow::deleteTask()
{
    QListWidgetItem *item = ui->tasksListWidget->currentItem();
    if (item) {
        delete item;
    }
}

void MainWindow::showTaskDetails()
{
    QListWidgetItem *item = ui->tasksListWidget->currentItem();
    if (item) {
        QMessageBox::information(this, "Детали задачи", "Название задачи: " + item->text());
    }
}
