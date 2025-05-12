#include "mainwindow.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include "databasemanager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initMainDatabase();

    QWidget *centralWidget = new QWidget();
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    // Левая панель с группами задач
    m_mainGroup = new FieldGroup(m_mainDbId, "Мои задачи");
    mainLayout->addWidget(m_mainGroup, 1);

    // Правая панель с контентом задач
    m_stackedWidget = new QStackedWidget();
    mainLayout->addWidget(m_stackedWidget, 3);

    setCentralWidget(centralWidget);

    connect(m_mainGroup, &FieldGroup::taskClicked,
            this, &MainWindow::onTaskClicked);
    connect(m_mainGroup, &FieldGroup::newGroupRequested,
            this, &MainWindow::onCreateNewGroup);

    loadGroups();
}

void MainWindow::initMainDatabase()
{
    m_mainDbId = DatabaseManager::createDatabase("main_db");

    DatabaseManager::execute(m_mainDbId,
        "CREATE TABLE IF NOT EXISTS groups ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "name TEXT NOT NULL, "
        "db_id TEXT NOT NULL UNIQUE)");
}

void MainWindow::loadGroups()
{
    QSqlQuery query = DatabaseManager::query(m_mainDbId, "SELECT name, db_id FROM groups");

    while (query.next()) {
        QString name = query.value(0).toString();
        QString dbId = query.value(1).toString();

        FieldGroup *group = new FieldGroup(dbId, name);
        m_mainGroup->addTask(name, dbId);  // Теперь соответствует новой сигнатуре
    }
}

void MainWindow::onTaskClicked(const QString &taskDbId)
{
    if (!m_taskWidgets.contains(taskDbId)) {
        QWidget *taskWidget = new QWidget();
        // Здесь можно добавить интерфейс для работы с задачей
        m_taskWidgets[taskDbId] = taskWidget;
        m_stackedWidget->addWidget(taskWidget);
    }

    m_stackedWidget->setCurrentWidget(m_taskWidgets[taskDbId]);
}

void MainWindow::onCreateNewGroup()
{
    QString groupDbId = DatabaseManager::createDatabase();
    QString groupName = QString("Группа %1").arg(m_mainGroup->dbId().toInt() + 1);

    DatabaseManager::execute(m_mainDbId,
        QString("INSERT INTO groups (name, db_id) VALUES ('%1', '%2')")
        .arg(groupName).arg(groupDbId));

    m_mainGroup->addTask(groupName, groupDbId);  // Теперь соответствует новой сигнатуре
}

MainWindow::~MainWindow()
{
    DatabaseManager::execute(m_mainDbId, "VACUUM");
}
