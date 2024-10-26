import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

Control {

    padding: 16

    signal deleteMe(string name, string email, int index)

    background: Rectangle {
        color: 'dodgerblue'

        opacity: 0.7

        radius: 12
    }

    contentItem: ColumnLayout {

        spacing: 5

        Text {
            id: nameId
            text: name
        }

        Text {
            id: emailId

            text: email
        }

        Button {
            text: 'Remove'

            onClicked: {
                console.log("Delete me", name, email, index)

                deleteMe(name, email, index)
            }
        }
    }
}
