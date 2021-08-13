import QtQuick 2.0

import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Rectangle {
    id: rectangle

    property int size: 193

    width: size
    height: size
    border.width: 1
    border.color: "light gray"

    property int margin: 3
    property int bottomPlate: 50

    property string tiptext: "Owner: \nItem Type: \nCreated: \nModified: \nViews: \nTags: \nCredits: "
    property string titleicon: "file:///C:/Users/akuluiev/Documents/add_data/gear-50.png"
    property string titletext: "Bundesländergrenzen 2018"
    property string titlelink: "http://www.arcgis.com/home/item.html?id=d3a78deedc0749eeb3ed9069773d5551/"
    property string imagepath: "file:///C:/Users/akuluiev/Documents/add_data/Imagery.png"

    MouseArea {
        id: mousearea
        hoverEnabled: true
        anchors.fill: parent
    }

    ToolTip {
        id: tooltip
             parent: mousearea
             visible: mousearea.containsMouse || imagemouseArea.containsMouse
             text: rectangle.tiptext
             delay: 2000
             background: Rectangle{
                  opacity: 0
                  border.color: "black"
             }
                // containsMouse ? Qt.PointingHandCursor : Qt.ArrowCursor

             NumberAnimation on background.opacity {
                     running: tooltip.visible
                     from: 0; to: 1
                     duration: 50
                 }

         }




    Image {
            id: sdsdsd

            //anchors.centerIn: rectangle
            anchors.horizontalCenter: rectangle.horizontalCenter
            anchors.verticalCenter: rectangle.verticalCenter


            //anchors.centerIn: name
            source: rectangle.imagepath

            property int w: rectangle.width - rectangle.margin- rectangle.margin
            property int h: rectangle.height - rectangle.margin - bottomPlate
            property bool startAnnimation: false


            anchors.verticalCenterOffset: -((rectangle.height - sdsdsd.h)/2)+margin

            width: sdsdsd.w
            height: sdsdsd.h

            Rectangle {
                id: rect
                opacity: 0
                anchors.fill: parent
                color: "blue"

                PropertyAnimation {
                    target: rect
                    properties: "opacity"
                    running: sdsdsd.startAnnimation;
                    to: 0.5;
                    duration: 200
                }

                PropertyAnimation {
                    target: rect
                    properties: "opacity"
                    running: !sdsdsd.startAnnimation;
                    to: 0;
                    duration: 200
                }
            }

            Text {
                id: sdsd
                opacity: 0
                anchors.centerIn: parent
                text: qsTr("+ Add layer to map")
                color: "white"
                font.bold :true
                font.pointSize : 10

                PropertyAnimation {
                    target: sdsd
                    properties: "opacity"
                    running: sdsdsd.startAnnimation;
                    to: 1;
                    duration: 500
                }

                PropertyAnimation {
                    target: sdsd
                    properties: "opacity"
                    running: !sdsdsd.startAnnimation;
                    to: 0;
                    duration: 500
                }
            }

            MouseArea {
                id: imagemouseArea
                hoverEnabled: true
                anchors.fill: parent
                onContainsMouseChanged: {
                    sdsdsd.startAnnimation = containsMouse
                }

                onClicked: {
                    console.log("title uploading")
                }
            }
        }




    Rectangle {
        id: rect2
        width: sdsdsd.width
        height: parent.bottomPlate-margin
        anchors.horizontalCenter: sdsdsd.horizontalCenter
        anchors.top:  sdsdsd.bottom
        color: "light gray"




        Item {
            id: parentRect
            anchors.verticalCenter:  rect2.verticalCenter
            anchors.left: rect2.left

            height: bottomPlate
            width: 30

            Image {
                id: imagename
                source: rectangle.titleicon
                sourceSize.width: 15
                anchors.centerIn: parentRect
            }


        }

        //https://www.arcgis.com/home/item.html?id=d3a78deedc0749eeb3ed9069773d5551

        Text {
            id: nametext
            //text: qsTr("USA ZIP Code Points")


            width: rect2.width - parentRect.width - 10
            elide: Text.ElideRight

            anchors.verticalCenter: parentRect.verticalCenter
            anchors.left:  parentRect.right

            //anchors.centerIn: parent
            //baseUrl: 'https://www.arcgis.com/home/item.html?id=d3a78deedc0749eeb3ed9069773d5551'
            text:  rectangle.titletext
            //onLinkActivated: Qt.openUrlExternally('https://www.arcgis.com/home/item.html?id=d3a78deedc0749eeb3ed9069773d5551')
            font.underline: nametextmousearea.containsMouse & !nametextmousearea.pressed//nametextmousearea.containsMouse
            color: "blue"

            MouseArea {
                id:nametextmousearea
                anchors.fill: nametext
                //acceptedButtons: Qt.NoButton // we don't want to eat clicks on the Text
                cursorShape: containsMouse ? Qt.PointingHandCursor : Qt.ArrowCursor

                hoverEnabled: true

                onClicked: {
                    Qt.openUrlExternally(rectangle.titlelink)
                }
            }

            ToolTip {
                 parent: nametextmousearea
                 visible: nametextmousearea.containsMouse
                 text: nametext.text
                 delay: 1000
            }
        }
    }
}
