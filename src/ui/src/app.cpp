#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QLabel>
#include <QTimer>
#include <QString>

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int16.h>

#include <thread>

// topicten gelen veriyi saklamak için
std_msgs::String hello_world_msg;
std_msgs::Int16 num1_msg;
std_msgs::Int16 num2_msg;

// ###########################################################################
// subscriber sürekli bu fonksiyonları çağırıp değişkeni güncelliyor

void hello_world_handle(const std_msgs::String::ConstPtr& msg) {
    hello_world_msg = *msg;
}

void num1_handle(const std_msgs::Int16::ConstPtr& msg){
    num1_msg = *msg;
}

void num2_handle(const std_msgs::Int16::ConstPtr& msg){
    num2_msg = *msg;
}
// ###########################################################################

// .qml tarafindaki objeleri ismiyle bulup text propertysini güncelliyor 
void updateLabel(QObject* object) {
    QObject *obj;
    
    obj = object->findChild<QObject*>("text_1"); // use parent to find child
    obj->setProperty("text", QVariant(QString::number(num1_msg.data))); // update text property


    obj = object->findChild<QObject*>("text_3");
    obj->setProperty("text", QVariant(QString::number(num2_msg.data)));



    obj = object->findChild<QObject*>("text_5");
    obj->setProperty("text", QVariant(QString::number(num1_msg.data + num2_msg.data)));


    obj = object->findChild<QObject*>("vaybee");
    obj->setProperty("text", QVariant("Received Text: " + QString::fromStdString(hello_world_msg.data)));


}

int main(int argc, char *argv[]) {
    ros::init(argc, argv, "itu_rov_monitor"); // itu_rov_monitor subscriberın adı
    ros::NodeHandle nh;

    // birden faza subscriber birden fazla topicten bilgi alıyor
    ros::Subscriber topic_sub = nh.subscribe("hello_world", 10, hello_world_handle); // hello_world topic adı.
    ros::Subscriber num1_sub = nh.subscribe("num1", 10, num1_handle);
    ros::Subscriber num2_sub = nh.subscribe("num2", 10, num2_handle);

    // Start ROS spinner in a separate thread
    std::thread rosSpinner([]() {
        ros::AsyncSpinner spinner(1); // Use 1 thread
        spinner.start();
        ros::waitForShutdown();
    });

    // Qt application
    QGuiApplication app(argc, argv);

    // QQmlApplicationEngine -- bu sanırım .qml ile iletişim kurmak için. template olarak alıyor qmli
    QQmlApplicationEngine engine;

    // FILE PATH RELATİVE BURADA. ONU CMAKEDE BELİRTMEK LAZIM OLABİLİR
    engine.load(QUrl(QStringLiteral("app.qml")));  // ui_ws folderından runlamamız lazım şuan

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    // ------------UYGULAMADAKI BUTUN UPDATE MEVZUSU BURADA DONUYOR------------

    // Create a QTimer to update the label periodically
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&engine]() {
        
        QObject *rootObject = engine.rootObjects().first();

        updateLabel(rootObject);

    });
    timer.start(100); // Update every 100 milliseconds (.1 second)

    // --------------------------------------------------------------------------


    // Qt event loop
    int qtResult = app.exec();

    // Shutdown ROS when the Qt application exits
    ros::shutdown();

    // Wait for the ROS spinner thread to finish
    rosSpinner.join();

    return qtResult;
}
