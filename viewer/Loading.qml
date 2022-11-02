import QtQuick 2.15

Rectangle {
    id: bg
    anchors.fill: parent
    visible: false

    onVisibleChanged: {
        if (visible === false) {
            loadingAnimation.stop();
        }
    }


    Text {
        id: loading
        text: "Loading"
        font.pixelSize: 50
        anchors.centerIn: parent
    }
    Text {
        id: firstDot
        text: "."
        font.pixelSize: 50
        anchors.left: loading.right
        anchors.top: loading.top
        visible: false
    }

    Text {
        id: secondDot
        text: "."
        font.pixelSize: 50
        anchors.left: firstDot.right
        anchors.top: loading.top
        visible: false
    }

    Text {
        id: thirdDot
        text: "."
        font.pixelSize: 50
        anchors.left: secondDot.right
        anchors.top: loading.top
        visible: false
    }

    Timer {
        id: timerAnim
        interval: 500
        repeat: false
        onTriggered: {
            firstDot.visible = false
            secondDot.visible = false
            thirdDot.visible = false
            loadingAnimation.start()
        }
    }

    SequentialAnimation {
        id: loadingAnimation
        running: bg.visible

        onFinished: {
            timerAnim.start()
        }

        PropertyAnimation {
            target: firstDot
            property: "visible"
            from: false
            to: true
            duration: 500
        }
        PropertyAnimation {
            target: secondDot
            property: "visible"
            from: false
            to: true
            duration: 500
        }
        PropertyAnimation {
            target: thirdDot
            property: "visible"
            from: false
            to: true
            duration: 500
        }
    }
}
