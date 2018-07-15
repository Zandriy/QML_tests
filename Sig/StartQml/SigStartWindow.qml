import QtQuick 2.10
import QtQuick.Window 2.10
import "Menu" 1.0

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello Sig")
    color: "blue"

    Component {
        id: delegate
        SigStartMenuItem10 {
            source: icon
            text: name
            height: (root.height > root.width ? root.height : root.width)/10
            width: height
            Connections {
                target: mouseArea
                onClicked: {
                    title.color = "#00ffff"
                    pathView.currentIndex = index
                }
            }
        }
    }

    PathView {
        id: pathView
        model: SigMainMenuModel{}
        delegate: delegate
        path: Path {
            startX: width/2; startY: height*0.8
            PathQuad { x: width*0.5; y: height*0.2; controlX: width*1.2; controlY: height*0.3 }
            PathQuad { x: width/2; y: height*0.8; controlX: -width*0.2; controlY: height*0.3 }
        }
    }
}
