import QtQuick 2.4
import "Demo.js" as DemoJS

DemoForm {
    button.onClicked: {
        DemoJS.func(button)
    }
    dial.onValueChanged: {
        DemoJS.func(dial)
        console.log("Dial value: ", dial.value)
    }

    rect.onRot: dial.value = angle/90
    rect1.onRot: button.rotation = angle
    rect2.onRot: rect2.rotation = Qt.binding(function() {return dial.value * 360})
}
