import QtQuick 2.4
import "Demo.js" as DemoJS

RectForm {
    id: rect
    signal rot(var angle)

    mouseArea.onClicked: {
        DemoJS.func(rect)
        rect.focus = true
        txt.font.pixelSize = Qt.binding(function() { return rect.focus ? DemoJS.hei50(rect) : DemoJS.hei75(rect) })
        rect.rotation = Qt.binding(function() { return rect.focus ? 45 : 0 })
    }

    onRotationChanged: rot(rotation)
}
