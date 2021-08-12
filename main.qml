import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Window {
    title: qsTr("Add data")
    width: 800
    height: 800
    visible: true

    Rectangle {
        id: frame
        anchors.centerIn: parent

        width: 415
        height: 670
        border.width: 1
        border.color: "light gray"
    }

    Item {
        id: interanalFrame
        anchors.centerIn: parent
        width: frame.width - 15
        height: frame.height - 15
    }

    Text {
        anchors.top: interanalFrame.top
        anchors.left: interanalFrame.left

        verticalAlignment: Text.AlignVCenter
        color: "gray"

        font {
            pointSize: 20
        }

        text: qsTr("Living Atlas")
    }

    Grid {
        anchors.bottom: interanalFrame.bottom
        anchors.horizontalCenter: interanalFrame.horizontalCenter

        columns: 2
        spacing: 5
        Tile {}
        Tile {}
        Tile {}
        Tile {}
        Tile {}
        Tile {}
    }
}
