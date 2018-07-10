import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Controls 1.4

import io.az.backend 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    BTDevice {
        id: btDevice

        onActiveChanged: btnActivate.text = name
        onVisibleChanged: btnVisible.text = visible ? "visible" : "not visible"
    }

    TextArea {
        x: 0
        y: 0
        width: parent.width
        height: parent.height/2
        text:
            "Lorem ipsum dolor sit amet, consectetur adipisicing elit, " +
            "sed do eiusmod tempor incididunt ut labore et dolore magna " +
            "aliqua. Ut enim ad minim veniam, quis nostrud exercitation " +
            "ullamco laboris nisi ut aliquip ex ea commodo cosnsequat. ";
    }

    Button {
        id: btnActivate
        text: "activate"
        x: 0
        y: parent.height/2
        width: parent.width/2
        onClicked: {
            btDevice.switchPower()
        }
    }

    Button {
        id: btnVisible
        text: "not visible"
        x: parent.width/2
        y: parent.height/2
        width: parent.width/2
        onClicked: {
            btDevice.switchVisible()
        }
    }


}
