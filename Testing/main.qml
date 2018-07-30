import QtQuick 2.0
import QtTest 1.0

import ntg.test.backend 1.0

TestWindow {
    id: testWindow
    width: 640; height: 480
    visible: true

    GestureArea {
       id: area1
       anchors.fill: parent
    }
}
