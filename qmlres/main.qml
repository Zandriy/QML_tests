import QtQuick 2.1
import "uicomp" as UIComp

import com.az.windows 1.0
import com.az.items 1.0

AZWindow {
    visible: true
    width:640; height: 480

    Row {
        anchors.centerIn: parent
        spacing: 20

        AZItem {
            id: aAZItem
            //anchors.centerIn: parent
            width: 100; height: 100
            name: "A simple AZ item"
            color: "blue"

            onCleared: console.log("The AZItem cleared")
        }

        AZItem {
            id: aAZItem2
            width: aAZItem.width; height: aAZItem.height
            color: aAZItem.color
        }

        AZDia {
            id: aAZItem3
            width: 100; height: 100

           slices: [
                AZSlice {
                    anchors.fill: parent
                    color: "red"
                    fromAngle: 0; angleSpan: 110
                },
                AZSlice {
                    anchors.fill: parent
                    color: "yellow"
                    fromAngle: 110; angleSpan: 50
                },
                AZSlice {
                    anchors.fill: parent
                    color: "green"
                    fromAngle: 160; angleSpan: 200
                }
            ]
        }
    }

    MouseArea {
        anchors.fill: parent
        onWheel: aAZItem.clear()
        onClicked: { aAZItem.color = "green" }
    }

    Text{
        anchors{bottom: parent.bottom; horizontalCenter: parent.horizontalCenter; bottomMargin: 20}
        text: aAZItem.name + ": Click anywere"
    }

    //Component.onCompleted: console.log("The item 3 is colored " + aAZItem3.itemSlice.color)

    UIComp.RectRed{id:rectRed}
    UIComp.RectGreen{id:rectGreen}
}
