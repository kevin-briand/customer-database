#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QDir>
#include <QListWidgetItem>
#include <QLabel>
#include <QFormLayout>
#include <QDesktopServices>

#ifndef DEBUG
    #define DEBUG qDebug()
#endif

enum rappel_State {
    Tous,
    Financement,
    Aucun
};

#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Save_Client();
    void New();
    void UpdateTable();
    void Clear();
    void Search(QString word);
    void Show_Client(int row);
    void EditClient(int id);
    void Init();
    void AddDocuments();
    void Show_Option();
    void warning(QString text);
    void RappelProcess();
    void SendEmail();
    void UpdateRappel();
    void Reload();
    void UpdateCalendar();
    void ResizeTable(int tab);
    void About();
    void Bug_Report() { QDesktopServices::openUrl(QUrl("https://github.com/firedream89/customer-database/issues")); };

private:
    void ResizeTableColumns(QTableWidget *table);
    void resizeEvent(QResizeEvent* event);
    Ui::MainWindow *ui;
    database db;
    QString docFilePath = QDir::homePath() + "/Documents/DB_Client";
    QString SavedFilePath = "/Clients/";
    qint64 _rappel_jours_financement;
    qint64 _rappel_jours_livraison;


};
#endif // MAINWINDOW_H