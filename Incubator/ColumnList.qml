import QtQuick 2.0

Column {
    id: root
    spacing: 2
    property bool sync: false

    Repeater {
        model: ["red", "green", "blue", "gray", "black"]
        ColomnListItem {
            color: modelData
            createID: index
        }
    }

    Component.onCompleted: {
        console.log("============== ", sync ? " Sync " : "Async", " begin")
        var i = 0;
        Qt.createComponent("ColomnListItem.qml").incubateObject(root, {"color": "red", "createID": i++}, sync ? Qt.Synchronous : Qt.Asynchronous);
        Qt.createComponent("ColomnListItem.qml").incubateObject(root, {"color": "green", "createID": i++}, sync ? Qt.Synchronous : Qt.Asynchronous);
        Qt.createComponent("ColomnListItem.qml").incubateObject(root, {"color": "blue", "createID": i++}, sync ? Qt.Synchronous : Qt.Asynchronous);
        Qt.createComponent("ColomnListItem.qml").incubateObject(root, {"color": "gray", "createID": i++}, sync ? Qt.Synchronous : Qt.Asynchronous);
        Qt.createComponent("ColomnListItem.qml").incubateObject(root, {"color": "black", "createID": i++}, sync ? Qt.Synchronous : Qt.Asynchronous);
        console.log("============== ", sync ? " Sync " : "Async", " end")
    }
}
