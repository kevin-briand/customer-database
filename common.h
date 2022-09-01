#ifndef COMMON_H
#define COMMON_H

#include <QObject>
#include <QTableWidgetItem>
#include <QDir>

#include "database.h"

enum rappel_State {
    Tous,
    Financement,
    Aucun
};

enum save_Error {
    noError,
    copyFileError,
    removeFileError,
    removeFolderError,
    dbRecordError
};

class Common : public QObject
{
    Q_OBJECT
public:
    explicit Common(QObject *parent = nullptr);
    QList<QTableWidgetItem*> SuppressionDoublon(QList<QTableWidgetItem*> items);
    bool InitData();
    int SaveData(QMap<QString, QVariant> data);
    int NewCustomer() { return db.Get_Last_Id()+1; }
    QMap<QString, QVariant> GetCustomerInfo(int id) { return db.GetCustomerInfo(id); }
    void SetTableDocument(QTableWidget *table, QStringList documents, bool setType = true);
    void UpdateTable(QTableWidget *table, QString filter = "");

    inline static const QString appVersion = "1.0-beta6";
    inline static const QString updateLink = "https://api.github.com/repos/firedream89/customer-database/releases";
    inline static QString docFilePath = QDir::homePath() + "/Documents/DB_Client";
    inline static const QString SavedFilePath = "/Clients/";

signals:


private:
    database db;
};

#endif // COMMON_H