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
    title: qsTr("Game2048")
    Item{
        id:menutopitem;
        Rectangle
        {
            anchors.fill: parent;
            color:"#ffff00";
        }
        height: 80
        width: parent.width
        anchors.top: parent.top
        anchors.bottomMargin: 5
        anchors.topMargin: 5
    }
    Item{
        id:mainItem
        anchors.horizontalCenter: parent.horizontalCenter
        /*function minimum(a, b)
        {
            return a < b ? a : b;
        }
        width: minimum(parent.height, parent.width);*/
        height: parent.height + menutopitem.height
        width: parent.width
        Item{
            id:menuitem;
            Rectangle
            {
                anchors.fill: parent;
                color:"#ffff00";
            }
            height: 50
            width: parent.width
            anchors.bottom: mainField.top
            anchors.bottomMargin: 5
            anchors.topMargin: 5
        }
        MainField{
            id: mainField
            visible: true
            anchors.centerIn: parent
            function minimum(a, b)
            {
                return a < b ? a : b;
            }
            width: minimum(parent.height - menuitem.height - menubottomitem.height - 30, parent.width);
            height: width
        }
        Item{
            id:menubottomitem;
            Rectangle
            {
                anchors.fill: parent;
                color:"#ffff00";
            }
            height: 50
            width: parent.width
            anchors.top: mainField.bottom
            anchors.bottomMargin: 5
            anchors.topMargin: 5
        }
    }
}
