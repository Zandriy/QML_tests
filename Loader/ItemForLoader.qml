import QtQuick 2.0

Rectangle {
    id: root
    anchors.fill: parent
    color: "blue"

    Text {
        id: rectText
        anchors.right: parent.right
        text: "Z: " + root.z
        font.pixelSize: 30
        color: "white"
    }

    Component.onCompleted:
    {
        console.log("ItemForLoader is completed")
    }
}
