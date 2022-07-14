#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <someclas.h>
#include <QQmlContext>
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    //Test call class
    qmlRegisterType<SomeClass> ("Monty", 1, 0, "SomeClass");
    //SomeClas testClass;

    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    //engine.rootContext()->setContextProperty("classA", &testClass);

    engine.load(url);

    return app.exec();
}
