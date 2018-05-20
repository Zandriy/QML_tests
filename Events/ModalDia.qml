import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.2
import custom.app 1.0

CustomModalItem {
    id: root
    Dialog {
        id: dia
        visible: true
        title: "Blue sky dialog"
        modality: Qt.WindowMaximized

        contentItem: Rectangle {
            width: 400
            height: 100
            Text {
                text: "Hello blue sky!"
                color: "navy"
                anchors.centerIn: parent
            }
        }
    }

    Component.onCompleted: root.makeModal()
}
