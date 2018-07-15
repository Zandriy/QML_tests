import QtQuick 2.10
import QtQuick.Window 2.3
import QtQuick.Controls 2.2
import io.az.backend 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    BTDevice {
        id: btDevice

        onActiveChanged: btnActivate.text = name
        onVisibleChanged: {
            btnVisible.text = visible ? "visible" : "not visible"
            connList.model = btDevice.connDevices
        }
        onScanFinished: {
            //btnScan.text = "scan"
            foundList.model = btDevice.foundDevices
        }
    }

    ListView {
        id: connList
        x: 0
        y: 0
        width: parent.width/2
        height: parent.height/2

        model: btDevice.connDevices
        delegate: Text {text: modelData }
    }

    ListView {
        id: foundList
        x: parent.width/2
        y: 0
        width: parent.width/2
        height: parent.height/2

        model: btDevice.foundDevices
        delegate: Text {text: modelData }
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

    BorderImage {
        id: btnScan

        MouseArea{
            anchors.fill: parent
            onClicked: {
              //  text = "###"
                btDevice.scan()
            }
        }
                //text: "scan"
                x: 0
                y: parent.height/2 + 150
                width: parent.width/2
                source: "perfectBUTTON.png"
                //width: parent.width; height: parent.height
                border.left: 25; border.top: 25
                border.right: 25; border.bottom: 25
                horizontalTileMode: BorderImage.Round
                verticalTileMode: BorderImage.Round
            }

//    Button {
//        id: btnScan
//        text: "scan"
//        x: 0
//        y: parent.height/2 + 150
//        width: parent.width/2
//        onClicked: {
//            text = "###"
//            btDevice.scan()
//        }
//    }

}
