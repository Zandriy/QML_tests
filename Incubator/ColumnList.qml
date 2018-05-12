import QtQuick 2.0

Column {
    id: root
    spacing: 2
    property bool sync: false
    property variant colors: ["red", "green", "blue", "gray", "black"]

    Repeater {
        model: 5
        ColumnListItem {
            color: colors[index%5]
            createID: index
        }
    }

    Component.onCompleted: {
        incubate()
    }

    function incubate() {
        console.log("============== ", sync ? " Sync " : "Async", " begin")
        var i = 0;
        Qt.createComponent("ColumnListItem.qml").incubateObject(root, {"color": colors[i%5], "createID": i++}, sync ? Qt.Synchronous : Qt.Asynchronous);
        Qt.createComponent("ColumnListItem.qml").incubateObject(root, {"color": colors[i%5], "createID": i++}, sync ? Qt.Synchronous : Qt.Asynchronous);
        Qt.createComponent("ColumnListItem.qml").incubateObject(root, {"color": colors[i%5], "createID": i++}, sync ? Qt.Synchronous : Qt.Asynchronous);
        Qt.createComponent("ColumnListItem.qml").incubateObject(root, {"color": colors[i%5], "createID": i++}, sync ? Qt.Synchronous : Qt.Asynchronous);
        Qt.createComponent("ColumnListItem.qml").incubateObject(root, {"color": colors[i%5], "createID": i++}, sync ? Qt.Synchronous : Qt.Asynchronous);
        console.log("============== ", sync ? " Sync " : "Async", " end")
    }
}
