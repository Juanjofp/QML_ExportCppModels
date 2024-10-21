import QtQuick 2.15

Item {
    property alias gitUserModel: listId.model

    ListView {
        id: listId

        spacing: 5

        anchors.fill: parent

        delegate: GitUserDelegate {}
    }
}
