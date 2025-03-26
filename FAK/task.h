#ifndef TASK_H
#define TASK_H

#include <QString>
#include <QDateTime>
#include <QDataStream>

class Task {
public:
    // Конструкторы
    Task();
    Task(const QString& text, bool important = false, bool planned = false, bool inMyDay = true);

    // Геттеры и сеттеры
    QString getText() const;
    void setText(const QString& text);

    bool isImportant() const;
    void setImportant(bool important);

    bool isPlanned() const;
    void setPlanned(bool planned);

    bool isInMyDay() const;
    void setInMyDay(bool inMyDay);

    bool isCompleted() const;
    void setCompleted(bool completed);

    QDateTime getCreatedDate() const;
    void setCreatedDate(const QDateTime& date);

    QDateTime getDueDate() const;
    void setDueDate(const QDateTime& date);

    // Вспомогательные методы
    bool hasTag(const QString& tag) const;
    void addTag(const QString& tag);
    void removeTag(const QString& tag);
    QStringList getTags() const;

private:
    QString m_text;
    bool m_important;
    bool m_planned;
    bool m_inMyDay;
    bool m_completed;
    QDateTime m_createdDate;
    QDateTime m_dueDate;
    QStringList m_tags;
};

// Операторы для сериализации
QDataStream& operator<<(QDataStream& stream, const Task& task);
QDataStream& operator>>(QDataStream& stream, Task& task);

// Операторы сравнения для поиска задач
bool operator==(const Task& left, const Task& right);
bool operator!=(const Task& left, const Task& right);

#endif // TASK_H
