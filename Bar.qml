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
    Behavior on x {
        NumberAnimation {
            duration: 1000
            easing.type: Easing.OutBounce
        }
    }
    Behavior on y {
        NumberAnimation {
            duration: 1000
            easing.type: Easing.OutBounce
        }
    }
}
