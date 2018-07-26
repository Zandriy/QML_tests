import QtQuick 2.0
import QtTest 1.0

Rectangle {
    id: foo
    width: 640; height: 480
    color: "cyan"

    MouseArea {
        id: area
        anchors.fill: parent
    }

    MultiPointTouchArea {
        id: area1
        anchors.fill: parent
       focus: true

       minimumTouchPoints: 1
       maximumTouchPoints: 5
       touchPoints: [
           TouchPoint { id: touch0 },
           TouchPoint { id: touch1 },
           TouchPoint { id: touch2 },
           TouchPoint { id: touch3 },
           TouchPoint { id: touch4 }
       ]

        onPressed: {
            console.log("@@@@@@@@@@@@@@@@@@@@@ " + touch0.x + ", " + touch0.y + "; " + touch1.x + ", " + touch1.y);
        }
    }

    property bool bar: true

    SignalSpy {
            id: spy
            target: area1
            signalName: "pressed"
        }

    TestCase {
        name: "ItemTests"
        id: test1

        function test_pressed() {
            compare(spy.count, 0)
            area1.pressed([])
            compare(spy.count, 1)
            console.log("!!!!!!!!!######")
        }
    }

    TestCase {
        name: "ItemTests1"
        when: touch0.pressed
        id: test2

        function test_pressed() {
            console.log("!!!!!!!!!######")
        }
    }
}
