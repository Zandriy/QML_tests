import QtQuick 2.4
import QtQuick.Controls 2.2

Item {
    width: 400
    height: 400

    Button {
        id: button
        x: 37
        y: 33
        text: qsTr("Button")
    }

    Dial {
        id: dial
        x: 149
        y: 117
    }
}
