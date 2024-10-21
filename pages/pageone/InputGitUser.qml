import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Controls

Item {
    height: childrenRect.height

    signal userInserted(string name, string email)

    RowLayout {
        width: parent.width

        TextField {
            id: nameId

            Layout.fillWidth: true
        }

        TextField {
            id: emailId
            Layout.fillWidth: true
        }

        Button {
            text: 'Add'

            onClicked: function () {
                if (nameId.text === '' || emailId.text === '') {
                    return
                }

                userInserted(nameId.text, emailId.text)

                nameId.text = ''
                emailId.text = ''

                nameId.forceActiveFocus()
            }
        }
    }
}
