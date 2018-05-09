import QtQuick 2.0

Item {
    property Component mycomponent: comp1
    Component.onCompleted: console.log("Completed 1 Running!")

    QtObject {
        Component.onCompleted: console.log("Completed 2 Running!")
        id: internalSettings
        property color color: "green"
    }

    Component {
        id: comp1
        Rectangle {
            Component.onCompleted: console.log("Completed 3 Running!")
            color: internalSettings.color; width: 400; height: 15
        }
    }

    Loader { sourceComponent: mycomponent; x: 40; y: 20 }
}
