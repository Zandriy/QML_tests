import QtQuick 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3

Item {
    width: 100
    height: 150
    property alias title: title
    property alias text: title.text
    property alias mouseArea: mouseArea
    property alias source: image.source
    opacity: 1

    ColumnLayout {
        id: columnLayout
        height: 120
        anchors.fill: parent

        Image {
            id: image
            width: 100
            height: 100
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            visible: true
            source: "res/0.png"
            fillMode: Image.PreserveAspectFit
        }

        Text {
            id: title
            y: 0
            width: 100
            height: 30
            color: "#ffffff"
            text: qsTr("Text")
            font.italic: true
            font.bold: true
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            Layout.fillWidth: true
            Layout.fillHeight: false
            horizontalAlignment: Text.AlignHCenter
            transformOrigin: Item.Center
            font.pixelSize: 15
        }
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }
}
