#include "fieldgroup.h"
#include <QPushButton>
#include <QLineEdit>
#include <QDebug>

FieldGroup::FieldGroup(const QString &dbId, const QString &name, QWidget *parent)
    : QWidget(parent), m_dbId(dbId), m_name(name)
{
    setupDatabase();
    initUI();
    loadTasks();
}

FieldGroup::~FieldGroup()
{
    DatabaseManager::execute(m_dbId,
        QString("UPDATE groups SET name = '%1' WHERE id = 1").arg(m_name));
}

void FieldGroup::setupDatabase()
{
    if (m_dbId.isEmpty()) {
        m_dbId = DatabaseManager::createDatabase();

        DatabaseManager::execute(m_dbId,
            "CREATE TABLE IF NOT EXISTS tasks ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "name TEXT NOT NULL, "
            "db_id TEXT NOT NULL UNIQUE)");

        DatabaseManager::execute(m_dbId,
            "CREATE TABLE IF NOT EXISTS groups ("
            "id INTEGER PRIMARY KEY, "
            "name TEXT NOT NULL)");

        DatabaseManager::execute(m_dbId,
            QString("INSERT INTO groups (id, name) VALUES (1, '%1')").arg(m_name));
    }
}

void FieldGroup::initUI()
{
    m_mainLayout = new QVBoxLayout(this);
    m_mainLayout->setContentsMargins(5, 5, 5, 5);

    QHBoxLayout *headerLayout = new QHBoxLayout();

    QLineEdit *nameEdit = new QLineEdit(m_name);
    nameEdit->setStyleSheet("color: white;");
    connect(nameEdit, &QLineEdit::textChanged, [this](const QString &text) {
        m_name = text;
    });
    headerLayout->addWidget(nameEdit);

    QPushButton *addTaskBtn = new QPushButton("+ Задача");
    addTaskBtn->setStyleSheet("color: white;");
    connect(addTaskBtn, &QPushButton::clicked, this, &FieldGroup::onAddTaskClicked);
    headerLayout->addWidget(addTaskBtn);

    QPushButton *addGroupBtn = new QPushButton("+ Группа");
    addGroupBtn->setStyleSheet("color: white;");
    connect(addGroupBtn, &QPushButton::clicked, this, &FieldGroup::onAddGroupClicked);
    headerLayout->addWidget(addGroupBtn);

    m_mainLayout->addLayout(headerLayout);

    m_scrollArea = new QScrollArea();
    m_scrollArea->setWidgetResizable(true);

    m_scrollContent = new QWidget();
    m_tasksLayout = new QVBoxLayout(m_scrollContent);
    m_tasksLayout->setAlignment(Qt::AlignTop);

    m_scrollArea->setWidget(m_scrollContent);
    m_mainLayout->addWidget(m_scrollArea);
}

void FieldGroup::addTask(const QString &taskName, const QString &taskDbId)
{
    QString dbId = taskDbId.isEmpty() ? DatabaseManager::createDatabase() : taskDbId;

    // Создаем структуру БД для задачи, если это новая задача
    if (taskDbId.isEmpty()) {
        DatabaseManager::execute(dbId,
            "CREATE TABLE IF NOT EXISTS items ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "text TEXT NOT NULL, "
            "completed BOOLEAN NOT NULL DEFAULT 0)");
    }

    QPushButton *taskBtn = new QPushButton(taskName);
    taskBtn->setStyleSheet("color: white; text-align: left;");
    taskBtn->setProperty("dbId", dbId);
    connect(taskBtn, &QPushButton::clicked, this, &FieldGroup::onTaskClicked);

    m_tasksLayout->addWidget(taskBtn);

    DatabaseManager::execute(m_dbId,
        QString("INSERT INTO tasks (name, db_id) VALUES ('%1', '%2')")
        .arg(taskName).arg(dbId));
}

void FieldGroup::loadTasks()
{
    QSqlQuery query = DatabaseManager::query(m_dbId, "SELECT name, db_id FROM tasks");

    while (query.next()) {
        QString name = query.value(0).toString();
        QString dbId = query.value(1).toString();

        QPushButton *taskBtn = new QPushButton(name);
        taskBtn->setStyleSheet("color: white; text-align: left;");
        taskBtn->setProperty("dbId", dbId);
        connect(taskBtn, &QPushButton::clicked, this, &FieldGroup::onTaskClicked);

        m_tasksLayout->addWidget(taskBtn);
    }
}

void FieldGroup::onAddTaskClicked()
{
    QString taskName = QString("Задача %1").arg(m_tasksLayout->count() + 1);
    addTask(taskName);
}

void FieldGroup::onTaskClicked()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (btn) {
        emit taskClicked(btn->property("dbId").toString());
    }
}

void FieldGroup::onAddGroupClicked()
{
    emit newGroupRequested();
}

QString FieldGroup::dbId() const
{
    return m_dbId;
}
