import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    function getSizeGameField()
    {
        return Math.min(height,width);
    }
    Item {
        property int indent: 10;
        width: getSizeGameField() - indent;
        height: width;
        x: parent.x + indent;
        y: parent.y + indent;
        Rectangle {
            color: "darkkhaki"
            width: parent.width
            height: parent.height
        }
    }
}
