import QtQuick 2.0

Item {
    property bool sync: false
    property variant colors: ["red", "green", "blue", "gray", "black"]
    property int i: 0

    ListModel {
        id: imageModel

        ListElement { _id: "tile0"; _color: "red" }
        ListElement { _id: "tile1"; _color: "green" }
        ListElement { _id: "tile2"; _color: "blue" }
        ListElement { _id: "tile3"; _color: "gray" }
        ListElement { _id: "tile4"; _color: "black" }
    }

    Grid {
        id: imageGrid
        columns: 5
        spacing: 2

        Repeater {
            model: imageModel
            delegate: ColumnListItem {
                color: _color
                createID: index*-1
            }
        }
    }

    function incubate() {
        console.log("============== ", sync ? " Sync " : "Async", " begin")
        Qt.createComponent("ColumnListItem.qml").incubateObject(imageGrid, {"color": colors[i%5], "createID": i++}, sync ? Qt.Synchronous : Qt.Asynchronous);
        Qt.createComponent("ColumnListItem.qml").incubateObject(imageGrid, {"color": colors[i%5], "createID": i++}, sync ? Qt.Synchronous : Qt.Asynchronous);
        Qt.createComponent("ColumnListItem.qml").incubateObject(imageGrid, {"color": colors[i%5], "createID": i++}, sync ? Qt.Synchronous : Qt.Asynchronous);
        Qt.createComponent("ColumnListItem.qml").incubateObject(imageGrid, {"color": colors[i%5], "createID": i++}, sync ? Qt.Synchronous : Qt.Asynchronous);
        Qt.createComponent("ColumnListItem.qml").incubateObject(imageGrid, {"color": colors[i%5], "createID": i++}, sync ? Qt.Synchronous : Qt.Asynchronous);
        console.log("============== ", sync ? " Sync " : "Async", " end")
    }
}
