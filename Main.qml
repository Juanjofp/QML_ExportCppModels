import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Advanced QML")

    Tabbar {
        id: tabbarId

        onClicked: function (index) {
            pagesId.index = index
        }
    }

    Pages {
        id: pagesId

        anchors {
            top: tabbarId.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }
    }
}
