import QtQuick
import QtQuick.Layouts

import com.jjfp
import "./pageone"

Item {
    anchors.margins: 16

    ColumnLayout {
        anchors.fill: parent

        InputGitUser {
            Layout.fillWidth: true

            onUserInserted: function (name, email) {
                UIManager.addGitUser(name, email)
            }
        }

        Rectangle {
            Layout.fillWidth: true
            implicitHeight: 2
            color: "green"
        }

        ListGitUser {
            Layout.fillWidth: true
            Layout.fillHeight: true

            gitUserModel: UIManager.userModel

            onDeleteUser: function deleteUser(name, email, index) {
                UIManager.removeGitUser(name, email, index)
            }
        }

        Rectangle {
            Layout.fillWidth: true
            implicitHeight: 2
            color: "green"
        }

        Text {
            id: userCountId
            text: UIManager.userModel.gitUserCount
        }
    }
}
