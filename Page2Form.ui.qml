import QtQuick 2.9
import QtQuick.Controls 2.2

Page {
    width: 600
    height: 400
    property alias btnChangetext: btnChangetext

    title: qsTr("Page 2")

    Label {
        id: lblInfor
        text: qsTr("You are on Page 2.")
        anchors.centerIn: parent
    }

    Button {
        id: btnChangetext
        x: 250
        y: 235
        text: qsTr("Change text 2")
    }

    Connections {
        target: btnChangetext
        onClicked: lblInfor.text = "Ban dang o trang 2"
    }
}
