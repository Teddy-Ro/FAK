#ifndef FIELDGROUP_H
#define FIELDGROUP_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>

class FieldGroup : public QWidget
{
    Q_OBJECT

public:
    explicit FieldGroup(const QString &name, QWidget *parent = nullptr);
    void add_first_field();

private slots:
    void toggle_fields();
    void create_input_field();
    void delete_group();
    void update_name();

private:
    void initUI();

    bool expanded;
    QList<QHBoxLayout*> fields;
    QString name;
    QVBoxLayout *main_layout;
    QLineEdit *name_field;
    QPushButton *collapse_btn;
    QPushButton *delete_group_btn;
    QWidget *fields_container;
    QVBoxLayout *fields_layout;
};

#endif // FIELDGROUP_H
