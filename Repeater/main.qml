import QtQuick 2.0
import QtQuick.Window 2.0

Window {
    id: window

    visible: true
    width: 640
    height: 480
    title: qsTr("Hello Repeater")

    RowRepeater{
        x: 10
        y: 10
    }

    RowMixRepeater{
        x: 30
        y: 70
    }

    ColumnRepeater{
        x: 10
        y: 100
    }

    ColumnTextRepeater{
        x: 340
        y: 10
    }

    Component.onCompleted: {
        var component = Qt.createComponent("LoadedRepeater.qml");
        var incubator = component.incubateObject(window, {"x": 400, "y": 100, "entries": ["one", "two", "three"]});
    }
}
