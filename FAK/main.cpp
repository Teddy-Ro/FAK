#include "mainwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Load and apply stylesheet
    QFile styleFile(":/styles/style.qss");
    if (styleFile.open(QFile::ReadOnly | QFile::Text)) {
        QString style = styleFile.readAll();
        app.setStyleSheet(style);
        styleFile.close();
    } else {
        // Fallback to embedded style
        app.setStyleSheet(
            "QPushButton {"
            "   padding: 5px;"
            "   background: #f0f0f0;"
            "   border: 1px solid #ccc;"
            "   border-radius: 3px;"
            "}"
            "QPushButton:hover {"
            "   background: #e0e0e0;"
            "}"
            "QLineEdit {"
            "   padding: 5px;"
            "   border: 1px solid #ccc;"
            "   border-radius: 3px;"
            "}"
            "FieldGroup {"
            "   border: 1px solid #ddd;"
            "   border-radius: 5px;"
            "   padding: 5px;"
            "   margin: 5px;"
            "}"
        );
    }

    MainWindow window;
    window.show();

    return app.exec();
}
