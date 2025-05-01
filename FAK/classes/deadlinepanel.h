#ifndef DEADLINEPANEL_H
#define DEADLINEPANEL_H

#include <QWidget>
#include <QDateTime>

class QDateTimeEdit;
class QPushButton;

class DeadlinePanel : public QWidget
{
    Q_OBJECT

public:
    explicit DeadlinePanel(QWidget *parent = nullptr);

    void setDeadline(const QDateTime &deadline);
    QDateTime getDeadline() const;

signals:
    void deadlineApplied(const QDateTime &deadline);
    void cancelled();

private slots:
    void applyClicked();
    void cancelClicked();

private:
    QDateTimeEdit *deadlineEdit;
    QPushButton *applyButton;
    QPushButton *cancelButton;
};

#endif // DEADLINEPANEL_H
