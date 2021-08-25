import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import Tile 1.0

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


    GridView {
        id: grid
        anchors.bottom: interanalFrame.bottom
        anchors.horizontalCenter: interanalFrame.horizontalCenter

        width: 400; height: 600
        cellWidth: 200; cellHeight: 200

        ScrollBar.vertical: ScrollBar {}

        model: TileModel {
            list: tileList
        }
        delegate: Tile {
            tiptext: model.description
            titleicon: "qrc:/icons/Map.png"
            titletext: model.title
            titlelink: model.link
            imagepath: model.picture

            onClicked:{
                console.log(titletext)
            }

            //imagemouseArea.onClicked: {
             //   console.log("title uploading")
            //}
        }
    }

}
