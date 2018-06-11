import QtQuick 2.4
import QtQuick.Controls 2.2

Item {
    width: 400
    height: 400
    property alias rect2: rect2
    property alias button: button
    property alias dial: dial
    property alias rect: rect
    property alias rect1: rect1

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
        wheelEnabled: true
        clip: false
    }

    Rect {
        id: rect
        x: 80
        y: 80
    }

    Rect {
        id: rect1
        x: 157
        y: 62
    }

    Rect {
        id: rect2
        x: 229
        y: 40
    }
}
