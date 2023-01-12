import QtQuick 2.9
import QtQuick.Controls 2.2
import Monty 1.0

Page {
    width: 600
    height: 400
    header: txtSecond.anchors.fill

    title: qsTr("Page 1")
    SomeClass {
        id: someClass
    }

    Label {
        id: lblInfor
        text: someClass.percentValue + "%"
        anchors.verticalCenterOffset: -5
        anchors.horizontalCenterOffset: -136
        anchors.centerIn: parent
    }

    BtnChangeText {
        id: btnChangeText
        autoRepeat: false
        checkable: true
        checked: true
        x: 240
        y: 300
        text: qsTr("set value")
    }

    TextEdit {
        id: txtSecond
        x: 250
        y: 187
        width: 80
        height: 20
        text: qsTr("50")
        font.pixelSize: 12
    }

    ProgressBar {
        id: progressBar
        x: 222
        y: 234
        width: 200
        height: 28
        from: 0.0
        to: 100.0
        value: 0
    }

    Connections {
        target: btnChangeText
        onClicked: {
            progressBar.value = 0
            someClass.callMe(500)
        }
    }
    Connections {
        target: someClass
        onPercentValueChanged: {
            progressBar.value = someClass.percentValue
            if (someClass.percentValue === 100){
                print("FUll 100%")
            }else{
                print("not full")
            }
        }
    }
}
