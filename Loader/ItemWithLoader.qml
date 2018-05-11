import QtQuick 2.0

Item {
    anchors.fill: parent

    ItemForLoader {
        id: rect
        color: "red"
        anchors.fill: null
        x: parent.x
        y: parent.y
        width: parent.width/2
        height: parent.height/2
        MouseArea {
            anchors.fill: parent
            onClicked:
            {
                rect.z = -1
            }
        }
    }

    Loader {
        id: loadedRect
        x: parent.x + parent.width/3
        y: parent.y + parent.height/3
        width: parent.width/2
        height: parent.height/2
    }

    Loader {
        id: loadedRectComp
        x: parent.x + parent.width/2
        y: parent.y + parent.height/2
        width: parent.width/2
        height: parent.height/2
    }

    MouseArea {
        anchors.fill: parent
        onClicked:
        {
            rect.z = 1
            loadedRect.source = "ItemForLoader.qml"
            loadedRectComp.sourceComponent = rectComp
        }
    }    

    Component {
        id: rectComp
        ItemForLoader {
            color: "green"
        }
    }
}
