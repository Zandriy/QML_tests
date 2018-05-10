import QtQuick 2.0

Rectangle {
    anchors.fill: parent
    color: "blue"

    Component.onCompleted:
    {
        console.log("ItemForLoader is completed")
    }
}
