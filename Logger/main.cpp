#include <QApplication>
#include <QQmlApplicationEngine>

#include <QDebug>
#include <QLoggingCategory>
#include <QMessageLogger>

void SimpleDebugMessages()
{
    qSetMessagePattern("%{file}(%{line}): %{message}");
    int i{};
    // for more info see QT_NO_*_OUTPUT in the Logger.pro
    qInfo("Simple Info message %d", i++);
    qDebug("Simple Debug message %d", i++);
    qWarning("Simple Warning message %d", i++);
    qCritical("Simple Critical message %d", i++);

    QMessageLogger(__FILE__, __LINE__, Q_FUNC_INFO).debug() << "QMessageLogger message " << i++;
}

Q_DECLARE_LOGGING_CATEGORY(aCategory)
Q_LOGGING_CATEGORY(aWarning, "com.anothercompany.app", QtWarningMsg)
Q_LOGGING_CATEGORY(anInfo, "com.anothercompany.app", QtInfoMsg)

void DebugWithCategories ()
{
    QLoggingCategory category("com.mycompany.app");
    category.setEnabled(QtDebugMsg, false); // also see QT_NO_*_OUTPUT in the Logger.pro
    qCWarning(category) << "A warning message";
    qCDebug(category) << "This is not logged";
    qCWarning(aWarning) << "Another warning message";
    qCInfo(anInfo) << "Another info message";
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    SimpleDebugMessages();
    QMessageLogger(__FILE__, __LINE__, Q_FUNC_INFO).debug() << "=================================================================";
    DebugWithCategories();
    QMessageLogger(__FILE__, __LINE__, Q_FUNC_INFO).debug() << "=================================================================";

    app.dumpObjectInfo();
    QMessageLogger(__FILE__, __LINE__, Q_FUNC_INFO).debug() << "=================================================================";
    app.dumpObjectTree();
    QMessageLogger(__FILE__, __LINE__, Q_FUNC_INFO).debug() << "=================================================================";

    qFatal("Fatal message aborts the application");

    return app.exec();
}
