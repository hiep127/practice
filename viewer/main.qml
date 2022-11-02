import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    property int count: 0
    objectName: "root"
    id: root
    width: 480
    height: 900
    visible: true

    property int assemblyScore : 1
    property int cScore: 0
    property int jsSCore: 0
    property int qmlScore: 0
    property int openGlScore: 0
    property string searchText

    signal sigUpdateDataOnQML(string name, int assemScore, int cScore, int jsScore, int qmlScore, int openGlScore, int id )
    signal sigListChangedOnQML()

    function roundFloat(num) {
        var res = num.toFixed(2)
        return res
    }

    onSigUpdateDataOnQML: {
        currentName.text = name
        root.assemblyScore = assemScore
        root.cScore = cScore
        root.jsSCore = jsScore
        root.qmlScore = qmlScore
        root.openGlScore = openGlScore
    }

    onSigListChangedOnQML: {
        loading.visible = false
        listEmployee.visible = true
    }

    Text {
        id: currentName
        font.pixelSize: 30
        font.bold: true
        anchors.horizontalCenter: parent.horizontalCenter
        y: 20
        text: "Test"
    }

    Column {
        id: info
        anchors.top:  currentName.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
        height: 440
        width: root.width - 100
        spacing: 10

        ScoreDetail {
            id: assembly
            score: assemblyScore
            skillImage: ":/../image/assembly.png"
            skill: "Assembly"
        }

        ScoreDetail {
            id: cPlus
            score: cScore
            skillImage: ":/../image/C++.png"
            skill: "C++"
        }

        ScoreDetail {
            id: java
            score: jsSCore
            skillImage: ":/../image/JS.png"
            skill: "JavaScript"
        }

        ScoreDetail {
            id: qml
            score: qmlScore
            skillImage: ":/../image/QT.png"
            skill: "QML"
        }

        ScoreDetail {
            id: openGL
            score: openGlScore
            skillImage: ":/../image/openGL.png"
            skill: "openGL"
        }
    }

    Timer {
        id: timerSearch
        interval: 500
        onTriggered: {
            appMain.listSearch(searchText)
            console.log(searchText)
        }
    }

    SearchBox {
        id: searchBox
        anchors.left: parent.left
        anchors.top: info.bottom
        anchors.topMargin: 30
        onTextInputChanged: {
            listEmployee.currentIndex = -1
            searchText = textInput
            timerSearch.stop()
            timerSearch.start()
            if (textInput !== "") {
                loading.visible = true
                listEmployee.visible = false
            }
            else {
                loading.visible = false
                listEmployee.visible = true
                timerSearch.stop()
                appMain.requestFullList()
            }

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
        visible: true
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
                text: roundFloat(model.average)
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
                    console.log(model.id)
                    listEmployee.currentIndex = index;
                    appMain.queryData(model.id)
                }
            }
        }
    }

    Loading {
        id: loading
        anchors.fill: listEmployee
    }
}
