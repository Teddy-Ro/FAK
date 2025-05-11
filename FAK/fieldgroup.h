#ifndef FIELDGROUP_H
#define FIELDGROUP_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QSqlDatabase>
#include <QSqlQuery>

class FieldGroup : public QWidget
{
    Q_OBJECT

public:
    explicit FieldGroup(const QString &name, QWidget *parent = nullptr);
    void addGroup(FieldGroup* group);
    void add_first_field();
    void setTextColor(const QString &color);

signals:
    void newGroupRequested();
    void taskClicked(const QString &taskData);

private slots:
    void toggle_fields();
    void create_input_field();
    void create_new_group();
    void delete_group();
    void update_name();
    void show_field_settings(QPushButton* fieldBtn);
    void onTaskButtonClicked();

private:
    void initUI();

    bool expanded;
    QList<QHBoxLayout*> fields;
    QString name;
    QVBoxLayout *main_layout;
    QLineEdit *name_field;
    QPushButton *collapse_btn;
    QPushButton *delete_group_btn;
    QPushButton *add_task_btn;
    QWidget *fields_container;
    QVBoxLayout *fields_layout;
    QSqlDatabase db;
};

#endif // FIELDGROUP_H
