import QtQuick 2.15

Item {
    id: infoDelegate
    width: parent.width
    height: 80
    property alias score: scoreValue.score
    property alias skill : scoreName.skill
    property alias skillImage: scoreImage.sourceImage
    Row {
        spacing: 30
        Image {
            id: scoreImage
            property string sourceImage
            source: sourceImage
            width: 50
            height: 50
            smooth: true
            fillMode: Image.PreserveAspectFit
        }

        Text {
            id: scoreName
            property string skill: "None"
            text: skill
            font.pixelSize: 30
            anchors.verticalCenter: scoreImage.verticalCenter
            width: 150
        }

        Text {
            id: scoreValue
            property int score: 0
            text: score + '/5'
            font.pixelSize: 30
            anchors.verticalCenter: scoreImage.verticalCenter
            width: 50
        }

        Image {
            id: checkImage
            source: scoreValue.score >= 3 ? ":/../image/green.png" : ":/../image/red.png"
            width: 50
            height: 50
            smooth: true
            fillMode: Image.PreserveAspectCrop
        }
    }
}
