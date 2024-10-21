import QtQuick 2.15
import QtQuick.Controls
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
            height: 2
            color: "green"
        }

        ListGitUser {
            Layout.fillWidth: true
            Layout.fillHeight: true

            gitUserModel: UIManager.userModel
        }

        Rectangle {
            Layout.fillWidth: true
            height: 2
            color: "green"
        }

        Text {
            id: userCountId
            text: UIManager.userModel.gitUserCount
        }
    }
}
