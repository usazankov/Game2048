import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Window 2.0

ApplicationWindow {
    id:appwindow
    onActiveChanged:
    {
        mainField.created = true;
    }
    property int dpi: Screen.pixelDensity * 25.4;
    function dp(value)
    {
        if(dpi < 120) {
            return value; // Для обычного монитора компьютера
        } else {
            return value*(dpi/160);
        }
    }
    visible: true
    width: dp(480)
    height: dp(640)
    minimumWidth: dp(480)
    minimumHeight: dp(640)
    title: qsTr("Game2048")
    color: "#faf8ef"
    Item{
        id:mainItem
        anchors.horizontalCenter: parent.horizontalCenter
        height: parent.height
        width: parent.width - dp(20);
        Item{
            id:menutopitem;
                Rectangle
                {
                    id: bestResult
                    anchors.verticalCenter: parent.verticalCenter
                    width: dp(150)
                    anchors.right: parent.right
                    color:"#bbada0";
                    height: dp(60)
                    radius: dp(10)
                    Text {
                        id: txtHbestresult;
                        anchors.top: parent.top
                        anchors.topMargin: dp(10)
                        horizontalAlignment: Text.AlignHCenter
                        text: qsTr("ЛУЧШИЙ РЕЗУЛЬТАТ");
                        color: "#d6cdc4";
                        height:dp(10);
                        font.bold: true
                        width: parent.width
                        font.pixelSize: dp(12)
                    }
                    Text {
                        id: txtbestresult;
                        anchors.top: txtHbestresult.bottom
                        anchors.topMargin: dp(10)
                        horizontalAlignment: Text.AlignHCenter
                        text: qsTr("3985");
                        color: "#f9f6f2";
                        height:dp(20)
                        font.bold: true
                        width: parent.width
                        font.pixelSize: dp(24)
                    }
                }
                Rectangle
                {
                    id: result
                    anchors.verticalCenter: parent.verticalCenter
                    width: dp(100)
                    anchors.right: bestResult.left
                    anchors.rightMargin: dp(10)
                    color:"#bbada0";
                    height: dp(60);
                    radius: dp(10);
                    Text {
                        id: txtHresult;
                        anchors.top: parent.top
                        anchors.topMargin: dp(10)
                        horizontalAlignment: Text.AlignHCenter
                        text: qsTr("РЕЗУЛЬТАТ");
                        color: "#d6cdc4";
                        height:dp(10)
                        font.bold: true
                        width: parent.width
                        font.pixelSize: dp(12)
                    }
                    Text {
                        id: txtresult;
                        anchors.top: txtHresult.bottom
                        anchors.topMargin: dp(10)
                        horizontalAlignment: Text.AlignHCenter
                        text: qsTr("0");
                        color: "#f9f6f2";
                        height:dp(20)
                        font.bold: true
                        width: parent.width
                        font.pixelSize: dp(24)
                    }
                }
                Item
                {
                    id: currentTarget
                    anchors.verticalCenter: parent.verticalCenter
                    width: parent.width/2 - dp(20)
                    anchors.left: parent.left
                    height: dp(60)
                    Text {
                        id: txtTarget;
                        text: qsTr("2048");
                        color: "#776e65";
                        anchors.verticalCenter: parent.verticalCenter
                        font.bold: true
                        font.pixelSize: dp(60)

                    }
                }

            height: dp(80)
            width: mainField.width
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: menuitem.top
            anchors.bottomMargin: dp(5)
            anchors.topMargin: dp(5)
        }
        Item{
            id:menuitem;
                Rectangle
                {
                    id:btnreset
                    anchors.verticalCenter: parent.verticalCenter
                    width: dp(40)
                    anchors.right: parent.right
                    color:"#bbada0";
                    height: dp(40)
                    radius: dp(10)
                    Image{
                        width:dp(32)
                        height:dp(32)
                        anchors.centerIn: parent
                        source: "images/refresh.png";
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            mainField.model_newGame();
                        }
                    }
                }
                Rectangle
                {
                    id: btnrevert
                    anchors.verticalCenter: parent.verticalCenter
                    width: dp(40)
                    anchors.right: btnreset.left
                    anchors.rightMargin: dp(40)
                    color:"#bbada0";
                    height: dp(40)
                    radius: dp(10)
                    Image{
                        width:dp(24)
                        height:dp(24)
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


            height: dp(50)
            width: mainField.width
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: mainField.top
            anchors.bottomMargin: dp(5)
            anchors.topMargin: dp(5)
        }
        MainField{
            id: mainField
            visible: true
            anchors.centerIn: parent
            anchors.verticalCenterOffset: dp(43)
            function minimum(a, b)
            {
                return a < b ? a : b;
            }
            width: minimum(parent.height - menuitem.height - menubottomitem.height - dp(80) - dp(30), parent.width);
            height: width
        }
        Item{
            id:menubottomitem;
            Item
            {
                id:inform
                anchors.top: parent.top
                width: parent.width
                height: dp(40)
                Text {
                    id: informtxt;
                    text: qsTr("2 + 2 = 4. Получи плитку 2048!");
                    color: "#776e65";
                    font.bold: true
                    font.pixelSize: dp(28)
                }
            }
            height: dp(50)
            width: mainField.width
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: mainField.bottom
            anchors.bottomMargin: dp(5)
            anchors.topMargin: dp(5)
        }
    }
}
