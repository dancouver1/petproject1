#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_AddBtn_clicked()
{
    QString inputLineEdit = ui->lineEdit->text();
    QString inputTrimmed = inputLineEdit.trimmed();

    if(inputTrimmed.isEmpty()){
        ui->lineEdit->clear();
    }
    else{
        QListWidgetItem* item = new QListWidgetItem(ui->lineEdit->text());
        ui->listWidget->addItem(item);
        ui->lineEdit->clear();
        ui->lineEdit->setFocus();
        item->setFlags(item->flags() | Qt::ItemIsEditable);
    }

}


void MainWindow::on_AddBtn_2_clicked()
{
    QListWidgetItem* item = ui->listWidget->takeItem(ui->listWidget->currentRow());
    delete item;
}


void MainWindow::on_AddBtn_3_clicked()
{
    ui->listWidget->clear();
}

