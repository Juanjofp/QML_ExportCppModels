import QtQuick

import "./pages"

Item {
    property int index: 0

    Item {
        anchors.fill: parent

        PageOne {
            anchors.fill: parent

            visible: index === 0
        }

        PageTwo {
            anchors.fill: parent

            visible: index === 1
        }
    }
}
