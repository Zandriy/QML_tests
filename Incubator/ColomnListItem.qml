import QtQuick 2.0

Rectangle {
    id: r
    property int createID: 0

    width: 50
    height: 50

    Text{
        anchors.centerIn: parent
        text: createID
        font.pixelSize: 30
        color: "white"
    }

    Component.onCompleted: {
        console.log("Rectangle ", r.createID, " with ", r.color, " is completed")
    }
}
