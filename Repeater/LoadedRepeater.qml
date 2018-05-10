import QtQuick 2.0

Item {
    id: root

    property var entries: null

    Component {
        id: component
        Row {
            id: _rowItem

            Repeater {
                model: root.entries
                Loader {
                    sourceComponent: subComponent(root.entries[index])
                }
            }
        }
    }

    Component {
        id: one
        Text{
            anchors.centerIn: parent
            text: "One"
            font.pixelSize: 15
            color: "red"
        }
    }

    Component {
        id: two
        Text{
            anchors.centerIn: parent
            text: "Two"
            font.pixelSize: 15
            color: "green"
        }
    }

    Component {
        id: three
        Text{
            anchors.centerIn: parent
            text: "Three"
            font.pixelSize: 15
            color: "blue"
        }
    }

    Loader { sourceComponent: component }

    function subComponent(type)
    {
        switch(type)
        {
        case "one":
            return one
        case "two":
            return two
        case "three":
            return three
        }
    }
}
