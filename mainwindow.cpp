
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
  ui->setupUi(this); // обов'язкова частина
    QRegularExpression rx ("^[1-9][0-9]{1,7}([\.][0-9]{1,2})?$");
    QValidator *validator = new QRegularExpressionValidator(rx, this);
    ui->lineEdit_3->setValidator(validator);
    ui->lineEdit_6->setValidator(validator);
  QSqlDatabase mybd=QSqlDatabase::addDatabase("QSQLITE");
  mybd.setDatabaseName("E:/StepIT/2 курс/MySQL/16/project29sqlite/копія.db");
  if (mybd.open())
  {
      ui->label->setText("База даних відкрита");
  }
  else
  {
      ui->label->setText("Закрита");
  }
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    QSqlQuery query;
    QString   query_string = "SELECT * FROM accountstotal;";
}


void MainWindow::on_pushButton_2_clicked()
{
    QSqlQuery query;
    auto   account = ui->lineEdit->text();
    QString   type    = ui->lineEdit_2->text();
    QString   amount  = ui->lineEdit_3->text();
    QString query_string = "insert into income(account, type, sum) values("+account+","+"'"+type+"',"+amount+");";
    //query.prepare("insert into income(account, type, sum) values(6,'інше',555);");
    //query.exec();
    if (query.exec(query_string))
    {
      ui->label->setText("Запис додано");
    }
    else
    {
      ui->label->setText("Запис не додано");
      qDebug() << query.lastError();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QSqlQuery query;
    auto   account = ui->lineEdit_4->text();
    QString   type    = ui->lineEdit_5->text();
    QString   amount  = ui->lineEdit_6->text();
    QString query_string = "insert into expence(account, type, sum) values("+account+","+"'"+type+"',"+amount+");";
    //query.prepare("insert into expence(account, type, sum) values(6,'інше',555);");
    //query.exec();
    if (query.exec(query_string))
    {
      ui->label->setText("Запис додано");
    }
    else
    {
      ui->label->setText("Запис не додано");
      qDebug() << query.lastError();
    }
}

