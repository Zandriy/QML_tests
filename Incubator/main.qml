import QtQuick 2.6
import QtQuick.Controls 1.5
import QtQuick.Dialogs 1.2

ApplicationWindow {
    visible: true
    width: 200
    height: 600
    title: qsTr("Hello Incubator")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    ColumnList
    {
        id: col1
        x: 0
        y: 0
        sync: true
    }

    ColumnList
    {
        id: col2
        x: col1.width + 10
        y: 0
    }
}