import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    property int count: 0
    objectName: "bg"
    id: bg
    width: 480
    height: width * 3
    visible: true

    property variant score : [-1, -1, -1, -1, -1]
    property var skill: {
        "Assembly": 0,
        "C++" : 1,
        "Java Script" : 2,
        "QML": 3,
        "OpenGL": 4
    }

    Text {
        id: currentName
        font.pixelSize: 30
        font.bold: true
        anchors.horizontalCenter: parent.horizontalCenter
        y: 50
        text: "Test"
    }

    ListModel {
        id: scoreModel
        ListElement {
            name: "Assembly"
        }
        ListElement {
            name: "C++"
        }
        ListElement {
            name: "Java Script"
        }
        ListElement {
            name: "QML"
        }
        ListElement {
            name: "OpenGL"
        }
    }

    ListView {
        id: info
        anchors.top:  currentName.bottom
        anchors.topMargin: 40
        anchors.horizontalCenter: parent.horizontalCenter
        height: 250
        width: bg.width - 100
        model: scoreModel
        interactive: false

        delegate :Item {
            id: infoDelegate
            width: parent.width
            height: 50
            Row {
                spacing: 30
                Image {

                }

                Text {
                    id: scoreName
                    text: model.name
                    font.pixelSize: 20
                }

                Text {
                    id: scoreValue
                    text: score[skill[scoreName.text]] + '/5'
                    font.pixelSize: 20
                }

                Image {

                }
            }
        }
    }

    SearchBox {
        id: searchBox
        anchors.left: parent.left
        anchors.top: info.bottom
        anchors.topMargin: 30
        onTextInputChanged: {
            console.log(textInput)
            appMain.listSearch(textInput)
        }
    }

    Text {
        anchors.left: parent.left
        anchors.leftMargin: 40
        anchors.top: searchBox.bottom
        anchors.topMargin: 30
        text: "NAME"
        font.pixelSize: 25
        font.bold: true
    }

    Text {
        id: textAverage
        anchors.right: parent.right
        anchors.rightMargin: 40
        anchors.top: searchBox.bottom
        anchors.topMargin: 30
        text: "AVERAGE"
        font.pixelSize: 25
        font.bold: true

    }

    ListView {
        id: listEmployee
        objectName: "listEmployee"

        model: employeeModel

        anchors.left: parent.left
        anchors.leftMargin: 40
        anchors.right: textAverage.right
        anchors.top: searchBox.bottom
        anchors.topMargin: 100
        anchors.bottom: parent.bottom
        spacing: 10
        clip:true
        snapMode: ListView.SnapToItem

        delegate: Item {
            id: listDelegate
            width: 400
            height: 50

            Rectangle {
                id: delegateBG
                visible: listEmployee.currentIndex === index
                color: "lightblue"
                anchors.fill: parent
            }

            Text {
                id: eemployeeName
                text: model.employeeName
                font.pixelSize: 30
                color: listEmployee.currentIndex === index ? "white" : "black"
                anchors.verticalCenter: delegateBG.verticalCenter
            }

            Text {
                id: average
                text: model.average
                font.pixelSize: 30
                anchors.right: parent.right
                color: listEmployee.currentIndex === index ? "white" : "black"
                anchors.rightMargin: textAverage.width/2
                anchors.verticalCenter: delegateBG.verticalCenter
            }

            MouseArea {
                id: area
                anchors.fill: parent
                onClicked: {
                    listEmployee.currentIndex = index;
                }
            }
        }
    }
}
