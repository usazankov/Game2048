import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3


ApplicationWindow {

    visible: true
    width: 640
    height: 480
    title: qsTr("Game2048")

    MainField{
        visible: true
        anchors.centerIn: parent
        function minimum(a, b)
        {
            return a < b ? a : b;
        }
        width: minimum(parent.height, parent.width)
        height: width
    }
}
