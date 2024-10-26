import QtQuick 2.15

Item {
    property alias gitUserModel: listId.model

    signal deleteUser(string name, string email, int index)

    ListView {
        id: listId

        spacing: 5

        clip: true

        anchors.fill: parent

        delegate: GitUserDelegate {
            onDeleteMe: function (name, email, index) {
                console.log("Delete from ListView", name, email, index)

                deleteUser(name, email, index)
            }
        }
    }
}
