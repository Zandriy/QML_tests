import QtQuick 2.7

Rectangle {
    id: rectangle
    width: 40
    height: 40
    color: focus ? "blue" : "lightgray"
    antialiasing: true
    rotation: 0
    transformOrigin: Item.BottomLeft
    property alias mouseArea: mouseArea
    property alias txt: txt

    MouseArea {
        id: mouseArea
        transformOrigin: Item.Center
        anchors.fill: parent

        Text {
            id: txt
            color: "#ffffff"
            text: qsTr("R")
            font.italic: false
            font.bold: true
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: parent.height*0.75
        }
    }
}

