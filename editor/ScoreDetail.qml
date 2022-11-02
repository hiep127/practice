import QtQuick 2.15

Item {
    id: infoDelegate
    width: parent.width
    height: 60
    property alias score: scoreValue.score
    property alias skill : scoreName.skill
    property alias skillImage: scoreImage.sourceImage
    Row {
        spacing: 30
        Image {
            id: scoreImage
            property string sourceImage
            source: sourceImage
            width: 40
            height: 40
            smooth: true
            fillMode: Image.PreserveAspectFit
        }

        Text {
            id: scoreName
            property string skill: "None"
            text: skill
            font.pixelSize: 20
            anchors.verticalCenter: scoreImage.verticalCenter
            width: 150
        }

        TextEdit {
            id: scoreValue
            property int score: 0
            text: score
            font.pixelSize: 20
            anchors.verticalCenter: scoreImage.verticalCenter
            width: 50
            overwriteMode: true
            Text {
                text: '/5'
                font.pixelSize: 20
                anchors.verticalCenter: scoreValue.verticalCenter
                anchors.left: scoreValue.right
                anchors.leftMargin: -35
            }
            onTextChanged: {
                if (text > 1) {
                    remove((cursorPosition-(length-1)),cursorPosition)
                    score = text
                }
            }
        }


        Image {
            id: checkImage
            source: scoreValue.score >= 3 ? ":/../image/green.png" : ":/../image/red.png"
            width: 30
            height: 30
            smooth: true
            fillMode: Image.PreserveAspectCrop
        }
    }
}
