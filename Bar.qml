import QtQuick 2.7

Rectangle{
    id:barrect
    color: "#ff8438"
    property int index: 0
    property int p_value: 2
    property int x_i: 0
    property int y_i: 0
    Text{
        anchors.centerIn: parent
        text: p_value
    }
}
