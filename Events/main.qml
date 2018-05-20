import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Controls 1.4
import custom.app 1.0

Window {
    id: root
    visible: true
    width: 300
    height: 200
    title: "Window for Events"

    CustomItem
    {
        id: customItem
        x: 0
        y: 0
        width: parent.width/2
        height: parent.height/4
        Button {
            anchors.fill: parent
            text: "Post & Send Events"
            onClicked: {
                customItem.postCustomEvent()
                customItem.sendCustomEvent()
            }
        }
    }
    Button {
        x: customItem.width
        y: 0
        width: parent.width/2
        height: parent.height/4
        text: "Open Modal Dialog"
        onClicked: {
            modalLoader.source = "ModalDia.qml"
        }
    }

    Loader { id: modalLoader }
}

