import QtQuick 2.6
import com.main.ui 1.0

MainWindow {

    visible: true
    width: 200
    height: 800
    title: qsTr("Hello Incubator")
    property bool clickCreate: false

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


    MouseArea {
        anchors.fill: parent
        onClicked: {
            if(!clickCreate)
            {
                col1.incubate()
                col2.incubate()
            }
            clickCreate = true
        }
    }
}
