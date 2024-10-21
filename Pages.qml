import QtQuick

import "./pages"

Item {
    id: rootId
    property int index: 0

    Item {
        anchors.fill: parent

        PageOne {
            anchors.fill: parent

            visible: rootId.index === 0
        }

        PageTwo {
            anchors.fill: parent

            visible: rootId.index === 1
        }
    }
}
