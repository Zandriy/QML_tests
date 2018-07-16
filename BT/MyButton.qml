import QtQuick 2.0
import QtQuick.Controls 2.2
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.3

Button {
    property string button_name: "Button"
    Layout.alignment: Qt.AlignCenter
    Layout.preferredWidth: parent.width/2 - 20

    Rectangle{
        anchors.fill: parent
        color: parent.pressed ? main2_color : (enabled ? main_color : main2_color)
        Text {
            text: button_name
            color: light_color
            anchors.centerIn: parent
            font.pixelSize: parent.width * 0.1
        }
    }
}
