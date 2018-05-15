import QtQuick 2.6
import com.main.ui 1.0

MainWindow {

    visible: true
    width: 800
    height: 800
    title: qsTr("Hello Incubator")
    property bool clickCreate: false

    ColumnList {
        id: col1
        x: 0
        y: 0
        sync: false
    }

    ColumnList {
        id: col2
        x: col1.width + 10
        y: 0
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            if(!clickCreate)
            {
                col1.incubate()
                col2.incubate()
                lr1.incubate()
                lr2.incubate()
            }
            else
            {
                lr1.incubate()
                lr2.incubate()
            }

            clickCreate = true
        }
    }

    ListRepeater {
        id: lr1
        x: col2.x + col2.width + 10
        y: 0

    }

    ListRepeater {
        id: lr2
        x: lr1.x + col2.width*5 + 10
        y: 0

    }
}
