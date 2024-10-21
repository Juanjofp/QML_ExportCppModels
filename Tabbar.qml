import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: rootId

    implicitWidth: parent.width
    implicitHeight: childrenRect.height

    signal clicked(int index)

    Rectangle {
        width: parent.width
        height: childrenRect.height

        color: 'blue'

        RowLayout {
            width: parent.width

            Button {
                Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter

                text: "List One"

                onClicked: function () {
                    rootId.clicked(0)
                }
            }

            Button {
                Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter

                text: 'List Two'

                onClicked: function () {
                    rootId.clicked(1)
                }
            }
        }
    }
}
