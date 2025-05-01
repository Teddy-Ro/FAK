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

protected:
    void contextMenuEvent(QContextMenuEvent *event) override;

private slots:
    void createButtonFromInput();
    void handleTaskButtonClick();
    void handleCheckboxToggle(bool checked);
    void handleDeleteButtonClick();
    void showTaskProperties();
    void setTaskDeadline();

private:
    Ui::MyDayTasks *ui;
    QSqlDatabase db;
    QPushButton* contextMenuButton = nullptr;

    void initDatabase();
    void saveTaskToDatabase(const QString &taskText, bool completed = false, const QDateTime &deadline = QDateTime());
    void updateTaskStatusInDatabase(const QString &taskText, bool completed);
    void updateTaskDeadlineInDatabase(const QString &taskText, const QDateTime &deadline);
    void deleteTaskFromDatabase(const QString &taskText);
    void loadTasksFromDatabase();
    void moveTaskToBottom(QWidget* taskWidget);
    void updateTaskStyle(QPushButton* button, bool completed);
    void checkForOverdueTasks();
    QPushButton* getButtonAtPos(const QPoint &pos);
    QString extractBaseTaskText(const QString &fullText);
    QDateTime extractDeadlineFromText(const QString &fullText);
};

#endif // MYDAYTASKS_H
