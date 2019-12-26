#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QStringListModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void affiche(QModelIndex);

private:
    Ui::MainWindow *ui;
    QSqlTableModel *model ;
    QSqlQueryModel *model2;
    QStringListModel *listM;
};
#endif // MAINWINDOW_H
