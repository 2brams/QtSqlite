#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QDir>
#include <QSqlTableModel>
#include <QModelIndex>
#include <QStringListModel>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->tableView,SIGNAL(pressed(QModelIndex)),this, SLOT(affiche(QModelIndex)));

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/ibrahim/QT_Projects/SQLITE/mabaseSQLITE1.db");
    bool ok = db.open();

    listM = new QStringListModel();

    if(ok)
    {
        /* QSqlQuery query("SELECT typecom, com, ncc FROM communes2019 WHERE dep='75'");
        model2 = new QSqlQueryModel();
        model2->setQuery(query);
        ui->tableView->setModel(model2);*/
        //ui->tableView->selectionBehavior(QAbstractItemView::SelectRows)

        model = new QSqlTableModel();
        model->setTable("communes2019");
        model->select();

        ui->tableView->setModel(model);
        ui->tableView->setColumnWidth(3,0);
        ui->tableView->setColumnWidth(1,0);
        ui->tableView->setColumnWidth(2,0);
        ui->tableView->setColumnWidth(4,0);
        ui->tableView->setColumnWidth(5,0);
        ui->tableView->setColumnWidth(10,0);


    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::affiche(QModelIndex ind)
{
    QStringList list;
    for (int i=0;i< model->columnCount();i++) {

        list << ind.sibling(ind.row(),i).data().toString();

    }

    listM->setStringList(list);
    ui->listView->setModel(listM);
//    qDebug() << ind.data().toString();
}

