#ifndef MYDAYTASKS_H
#define MYDAYTASKS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QPushButton>
#include <QCheckBox>
#include <QToolButton>
#include <QDateTime>
#include <QMenu>
#include <QContextMenuEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MyDayTasks;
}
QT_END_NAMESPACE

class MyDayTasks : public QWidget
{
    Q_OBJECT

public:
    explicit MyDayTasks(QWidget *parent = nullptr);
    ~MyDayTasks();

    void setDatabaseName(const QString &name);
    void loadTaskData(const QString &taskData);
    void createTaskFromData(const QString &taskData);
    static QString extractBaseTaskText(const QString &fullText);
    static QDateTime extractDeadlineFromText(const QString &fullText);

    // Перенесенные из private в public методы
    void updateTaskStyle(QPushButton* button, bool completed);
    void updateTaskDeadlineInDatabase(const QString &taskText, const QDateTime &deadline);

signals:
    void showDeadlinePanelRequested(QWidget* taskWidget);

protected:
    void contextMenuEvent(QContextMenuEvent *event) override;

private slots:
    void createButtonFromInput();
    void handleTaskButtonClick();
    void handleCheckboxToggle(bool checked);
    void handleDeleteButtonClick();
    void showTaskProperties();
    void setTaskDeadline();
    void showDeadlineOptions();

private:
    Ui::MyDayTasks *ui;
    QSqlDatabase db;
    QPushButton* contextMenuButton = nullptr;

    void initDatabase();
    void saveTaskToDatabase(const QString &taskText, bool completed = false, const QDateTime &deadline = QDateTime());
    void updateTaskStatusInDatabase(const QString &taskText, bool completed);
    void deleteTaskFromDatabase(const QString &taskText);
    void loadTasksFromDatabase();
    void moveTaskToBottom(QWidget* taskWidget);
    void checkForOverdueTasks();
    QPushButton* getButtonAtPos(const QPoint &pos);
};

#endif // MYDAYTASKS_H
