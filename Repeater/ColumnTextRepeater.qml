import QtQuick 2.0

Column {
    Repeater {
        model: ["apples", "oranges", "pears"]
        Text { text: "Data: " + modelData }
    }
}
