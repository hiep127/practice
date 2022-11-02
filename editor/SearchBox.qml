import QtQuick 2.15

Item {
    property alias textInput: input.text
    signal textChanged(string inp);
    id: searchBar
    width: 480
    Text {
        id: search
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.verticalCenter: parent.verticalCenter
        text: qsTr("Search Name:")
        font.pixelSize: 20
    }
    Rectangle {
        id: textBG
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: search.right
        anchors.leftMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10
        height: 30
        border.width: 3
        border.color: "green"
    }
    TextInput {
        id: input
        anchors.fill: textBG
        anchors.leftMargin: 5
        anchors.rightMargin: 5
        font.pixelSize: 25
        wrapMode: TextInput.WrapAnywhere
        cursorVisible: true
        maximumLength: 24
        onTextChanged: {
             searchBar.textChanged(text)
        }
    }

}
