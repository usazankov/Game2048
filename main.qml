import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    onActiveChanged:
    {
        mainField.created = true;
    }
    visible: true
    width: 480
    height: 640
    minimumWidth: 400
    minimumHeight: 600
    title: qsTr("Game2048")
    color: "#faf8ef"
    Item{
        id:mainItem
        anchors.horizontalCenter: parent.horizontalCenter
        height: parent.height
        width: parent.width - 20
        Item{
            id:menutopitem;
                Rectangle
                {
                    id: bestResult
                    anchors.verticalCenter: parent.verticalCenter
                    width: 150
                    anchors.right: parent.right
                    color:"#bbada0";
                    height: 60
                    radius: 10
                    Text {
                        id: txtHbestresult;
                        anchors.top: parent.top
                        anchors.topMargin: 10
                        horizontalAlignment: Text.AlignHCenter
                        text: qsTr("ЛУЧШИЙ РЕЗУЛЬТАТ");
                        color: "#d6cdc4";
                        height:10
                        font.bold: true
                        width: parent.width
                        font.pointSize: 8
                    }
                    Text {
                        id: txtbestresult;
                        anchors.top: txtHbestresult.bottom
                        anchors.topMargin: 10
                        horizontalAlignment: Text.AlignHCenter
                        text: qsTr("3985");
                        color: "#f9f6f2";
                        height:20
                        font.bold: true
                        width: parent.width
                        font.pointSize: 12
                    }
                }
                Rectangle
                {
                    id: result
                    anchors.verticalCenter: parent.verticalCenter
                    width: 100
                    anchors.right: bestResult.left
                    anchors.rightMargin: 10
                    color:"#bbada0";
                    height: 60
                    radius: 10
                    Text {
                        id: txtHresult;
                        anchors.top: parent.top
                        anchors.topMargin: 10
                        horizontalAlignment: Text.AlignHCenter
                        text: qsTr("РЕЗУЛЬТАТ");
                        color: "#d6cdc4";
                        height:10
                        font.bold: true
                        width: parent.width
                        font.pointSize: 8
                    }
                    Text {
                        id: txtresult;
                        anchors.top: txtHresult.bottom
                        anchors.topMargin: 10
                        horizontalAlignment: Text.AlignHCenter
                        text: qsTr("0");
                        color: "#f9f6f2";
                        height:20
                        font.bold: true
                        width: parent.width
                        font.pointSize: 12
                    }
                }
                Item
                {
                    id: currentTarget
                    anchors.verticalCenter: parent.verticalCenter
                    width: parent.width/2 - 20
                    anchors.left: parent.left
                    height: 60
                    Text {
                        id: txtTarget;
                        text: qsTr("2048");
                        color: "#776e65";
                        anchors.verticalCenter: parent.verticalCenter
                        font.bold: true
                        font.pointSize: 34
                    }
                }

            height: 80
            width: mainField.width
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: menuitem.top
            anchors.bottomMargin: 5
            anchors.topMargin: 5
        }
        Item{
            id:menuitem;
                Rectangle
                {
                    id:btnreset
                    anchors.verticalCenter: parent.verticalCenter
                    width: 40
                    anchors.right: parent.right
                    color:"#bbada0";
                    height: 40
                    radius: 10
                    Image{
                        width:32
                        height:32
                        anchors.centerIn: parent
                        source: "images/refresh.png";
                    }
                }
                Rectangle
                {
                    id: btnrevert
                    anchors.verticalCenter: parent.verticalCenter
                    width: 40
                    anchors.right: btnreset.left
                    anchors.rightMargin: 40
                    color:"#bbada0";
                    height: 40
                    radius: 10
                    Image{
                        width:24
                        height:24
                        anchors.centerIn: parent
                        source: "images/reset.png";
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            mainField.model_revert();
                        }
                    }
                }


            height: 50
            width: mainField.width
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: mainField.top
            anchors.bottomMargin: 5
            anchors.topMargin: 5
        }
        MainField{
            id: mainField
            visible: true
            anchors.centerIn: parent
            anchors.verticalCenterOffset: 43
            function minimum(a, b)
            {
                return a < b ? a : b;
            }
            width: minimum(parent.height - menuitem.height - menubottomitem.height - 80 - 30, parent.width);
            height: width
        }
        Item{
            id:menubottomitem;
            Item
            {
                id:inform
                anchors.top: parent.top
                width: parent.width
                height: 40
                Text {
                    id: informtxt;
                    text: qsTr("2 + 2 = 4. Получи плитку 2048!");
                    color: "#776e65";
                    font.bold: true
                    font.pointSize: 14
                }
            }
            height: 50
            width: mainField.width
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: mainField.bottom
            anchors.bottomMargin: 5
            anchors.topMargin: 5
        }
    }
}
