import QtQuick 2.6
import QtQuick.Controls 2.2
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.3
import QtQuick.Window 2.3

import io.az.backend 1.0

Window {
    width: 720
    height: 1024

    visible: true
    property color dark_color: Qt.hsva(2/3,0.97,0.13,1)
    property color light_color: Qt.hsva(0,0,0.89,1)
    property color main_color: Qt.hsva(67/360,0.76,0.61,1)
    property color main2_color: Qt.hsva(67/360,0.41,0.81,1)
    property color accent_color: Qt.hsva(67/360,0.9,0.4,1)

    BTDevice {
        id: btDevice

        onActiveChanged: btnActivate.button_name = name
        onVisibleChanged: {
            btnVisible.button_name = visible ? "Visible" : "Not visible"
        }
        onScanFinished: {
            busy.visible = false
            foundList.list_data = btDevice.foundDevices
        }
    }

    Rectangle {
        anchors.fill: parent
        width: 720
        height: 1024
        color: main_color

        Image {
            x: 5
            y: 5
            anchors.fill: parent
            source: "background_circle.png"
            fillMode: Image.Tile
            sourceSize {width: 10; height: 10}
        }

        Rectangle {
            id: rectangle
            x: 25
            y: 25
            width: parent.width - 50
            height: parent.height - 50
            color: light_color
            layer.enabled: true
            layer.effect: DropShadow {
                transparentBorder: true
                radius: 8
                horizontalOffset: 0
                verticalOffset: 0
            }

            ColumnLayout {
                spacing: 20
                x: 40
                y: 40
                width: parent.width - 80
                height: parent.height - 80

                BusyIndicator {
                    id: busy
                    Layout.alignment: Qt.AlignCenter
                    visible: false
                }

                TextArea {
                    Layout.alignment: Qt.AlignCenter
                    Layout.preferredWidth: parent.width
                    text: qsTr("Push on buttons below to see something happen. The buttons have obvious names, I hope you can figure out what they do by yourself")
                    color: accent_color
                    wrapMode: Text.WordWrap
                    font{family: "Helvetica";
                        pixelSize: parent.width * 0.035 }
                }

                RowLayout {
                    Layout.alignment: Qt.AlignCenter
                    Layout.preferredWidth: parent.width

                    MyListView {
                        id: connList
                        list_name: "Connected to:"
                        list_data: btDevice.connDevices
                    }

                    MyListView {
                        id: foundList
                        list_name: "Devices available:"
                        list_data: btDevice.foundDevices
                    }
                }

                MyButton {
                    id: btnActivate
                    button_name: qsTr("Activate")
                    onClicked: {
                        btDevice.switchPower()
                    }
                }

                MyButton {
                    id: btnVisible
                    button_name: qsTr("Not visible")
                    onClicked: {
                        btDevice.switchVisible()
                    }
                }

                MyButton {
                    id: btnScan
                    button_name: qsTr("Scan")
                    onClicked: {
                        busy.visible = true
                        btDevice.scan()
                    }
                }

                MyButton {
                    button_name: qsTr("Update connected list")
                    onClicked: {
                        connList.list_data = btDevice.connDevices
                    }
                }

                Rectangle {
                    Layout.alignment: Qt.AlignBottom
                    Layout.fillHeight: true
                    Layout.preferredWidth: parent.width
                }
            }
        }
    }
}
