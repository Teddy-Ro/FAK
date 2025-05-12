#include "mainwindow.h"
#include <QApplication>
#include "databasemanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Создаем главную базу данных приложения
    DatabaseManager::createDatabase("main_db");

    MainWindow w;
    w.show();

    return a.exec();
}
