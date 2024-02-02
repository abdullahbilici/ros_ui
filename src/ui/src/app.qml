import QtQuick
import QtQuick.Controls

ApplicationWindow {
    visible: true
    width: 600
    height: 400
    title: qsTr("ITU ROV")

    Rectangle {
        width: parent.width
        height: parent.height
        color: "deepskyblue"

        Label {
            text: "Initial Text"
            id: myLabel
            objectName: "vaybee"
            anchors.centerIn: parent
        }
        
        Row {
            anchors.top: myLabel.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 40 

            Rectangle {
                width: 30 
                height: 30 
                color: "deepskyblue" 
                objectName: "rectangle_1"

                Label {
                    text: "s"
                    anchors.centerIn: parent
                    objectName: "text_1"
                }
            }

            Rectangle {
                width: 30 
                height: 30 
                color: "deepskyblue" 
                objectName: "rectangle_2"

                Label {
                    text: "+"
                    anchors.centerIn: parent
                    objectName: "text_2"
                }
            }

            Rectangle {
                width: 30 
                height: 30 
                color: "deepskyblue" 
                objectName: "rectangle_3"

                Label {
                    text: "s"
                    anchors.centerIn: parent
                    objectName: "text_3"
                }
            }

            Rectangle {
                width: 30 
                height: 30 
                color: "deepskyblue" 
                objectName: "rectangle_4"

                Label {
                    text: "="
                    anchors.centerIn: parent
                    objectName: "text_4"
                }
            }

            Rectangle {
                width: 30 
                height: 30 
                color: "deepskyblue" 
                objectName: "rectangle_5"

                Label {
                    text: "s"
                    anchors.centerIn: parent
                    objectName: "text_5"
                }
            }

            
        }
    }
}
