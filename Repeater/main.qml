import QtQuick 2.10
import QtQuick.Window 2.10

Window {
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
}
