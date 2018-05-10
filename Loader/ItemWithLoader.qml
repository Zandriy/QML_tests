import QtQuick 2.0

Item {
    anchors.fill: parent

    Rectangle {
        id: rect
        color: "red"
        x: parent.x
        y: parent.y
        width: parent.width/2
        height: parent.height/2
        MouseArea {
            anchors.fill: parent
            onClicked:
            {
                rect.z = -1
            }
        }
        Text {
            id: rectText
            anchors.centerIn: parent
            text: "Z: " + rect.z
            font.pixelSize: 30
            color: "white"
        }
    }

    Loader {
        id: loadedRect
        x: parent.x + parent.width/3
        y: parent.y + parent.height/3
        width: parent.width/2
        height: parent.height/2
    }

    MouseArea {
        anchors.fill: parent
        onClicked:
        {
            rect.z = 1
            loadedRect.source = "ItemForLoader.qml"
        }
    }
}
