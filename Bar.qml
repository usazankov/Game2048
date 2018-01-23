import QtQuick 2.7

Rectangle{
    id:barrect
    color: "#ff8438"
    opacity: 0
    property int index: 0
    property int p_value: 2
    property int x_i: 0
    property int y_i: 0
    property alias anim_x: behx.enabled
    property alias anim_y: behy.enabled
    property alias anim_opacity: behopacity.enabled
    Text{
        anchors.centerIn: parent
        text: p_value
    }
    Behavior on x {
        id: behx;
        enabled: false
        NumberAnimation {
            duration: 300
            easing.type: Easing.InCubic
        }
    }
    Behavior on y {
        id: behy;
        enabled: false
        NumberAnimation {
            duration: 300
            easing.type: Easing.InCubic
        }
    }
    Behavior on opacity {
        id: behopacity;
        enabled: true
        NumberAnimation {
            duration: 150
            easing.type: Easing.InCubic
        }
    }
}
