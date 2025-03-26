#include "task.h"

// Конструкторы
Task::Task() :
    m_important(false),
    m_planned(false),
    m_inMyDay(false),
    m_completed(false) {

    m_createdDate = QDateTime::currentDateTime();
}

Task::Task(const QString& text, bool important, bool planned, bool inMyDay) :
    m_text(text),
    m_important(important),
    m_planned(planned),
    m_inMyDay(inMyDay),
    m_completed(false) {

    m_createdDate = QDateTime::currentDateTime();
}

// Геттеры и сеттеры
QString Task::getText() const {
    return m_text;
}

void Task::setText(const QString& text) {
    m_text = text;
}

bool Task::isImportant() const {
    return m_important;
}

void Task::setImportant(bool important) {
    m_important = important;
}

bool Task::isPlanned() const {
    return m_planned;
}

void Task::setPlanned(bool planned) {
    m_planned = planned;
}

bool Task::isInMyDay() const {
    return m_inMyDay;
}

void Task::setInMyDay(bool inMyDay) {
    m_inMyDay = inMyDay;
}

bool Task::isCompleted() const {
    return m_completed;
}

void Task::setCompleted(bool completed) {
    m_completed = completed;
}

QDateTime Task::getCreatedDate() const {
    return m_createdDate;
}

void Task::setCreatedDate(const QDateTime& date) {
    m_createdDate = date;
}

QDateTime Task::getDueDate() const {
    return m_dueDate;
}

void Task::setDueDate(const QDateTime& date) {
    m_dueDate = date;
}

// Вспомогательные методы для тегов
bool Task::hasTag(const QString& tag) const {
    return m_tags.contains(tag);
}

void Task::addTag(const QString& tag) {
    if (!m_tags.contains(tag)) {
        m_tags.append(tag);
    }
}

void Task::removeTag(const QString& tag) {
    m_tags.removeAll(tag);
}

QStringList Task::getTags() const {
    return m_tags;
}

// Операторы для сериализации
QDataStream& operator<<(QDataStream& stream, const Task& task) {
    return stream << task.getText()
                 << task.isImportant()
                 << task.isPlanned()
                 << task.isInMyDay()
                 << task.isCompleted()
                 << task.getCreatedDate()
                 << task.getDueDate()
                 << task.getTags();
}

QDataStream& operator>>(QDataStream& stream, Task& task) {
    QString text;
    bool important, planned, inMyDay, completed;
    QDateTime createdDate, dueDate;
    QStringList tags;

    stream >> text >> important >> planned >> inMyDay >> completed >> createdDate >> dueDate >> tags;

    task.setText(text);
    task.setImportant(important);
    task.setPlanned(planned);
    task.setInMyDay(inMyDay);
    task.setCompleted(completed);
    task.setCreatedDate(createdDate);
    task.setDueDate(dueDate);

    // Добавляем теги
    for (const QString& tag : tags) {
        task.addTag(tag);
    }

    return stream;
}

// Операторы сравнения
bool operator==(const Task& left, const Task& right) {
    return left.getText() == right.getText() &&
           left.isImportant() == right.isImportant() &&
           left.isPlanned() == right.isPlanned() &&
           left.isInMyDay() == right.isInMyDay() &&
           left.isCompleted() == right.isCompleted() &&
           left.getCreatedDate() == right.getCreatedDate();
}

bool operator!=(const Task& left, const Task& right) {
    return !(left == right);
}
