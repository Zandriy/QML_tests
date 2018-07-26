import QtQuick 2.0
import QtQuick.Controls 2.2
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.3

Rectangle {
    property alias list_data: m_data.model

    property string list_name: ""

    color: "transparent"
    border.color: main_color
    border.width: 1

    Layout.alignment: Qt.AlignCenter
    Layout.preferredWidth: parent.width/2.2
    Layout.preferredHeight: 150
    Text {
        x: 10
        y: 10
        text: list_name
        color: accent_color
        font.bold: true
        font.pixelSize: rectangle.width * 0.035
    }

    Rectangle {
        x: 10
        y: 35
        width: parent.width - 20
        height: parent.height - 45
        color: "transparent"

            ListView {
                id: m_data
                anchors.fill: parent
                delegate: Text {
                    text: modelData
                    color: dark_color
                    font.pixelSize: rectangle.width * 0.03
                }
            }
        }
    }
