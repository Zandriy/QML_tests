import QtQuick 2.0

Column {
    Repeater {
        model: 10
        Text { text: "I'm item " + index }
    }
}
