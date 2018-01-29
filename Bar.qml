import QtQuick 2.7

Rectangle{
    id:barrect
    color: "#ff8438"
    property int index: 0
    property int x_i: 0
    property int y_i: 0
    property bool isDel: false
    property int anim_duration: 300
    property alias numeric: txt.text;
    property alias anim_x: behx.enabled
    property alias anim_y: behy.enabled
    property bool anim_opacity: true
    onAnim_opacityChanged:
    {
        behheight.enabled = anim_opacity;
        behwidth.enabled = anim_opacity;
    }
    Text{
        id: txt;
        anchors.centerIn: parent
        text: "2";
    }
    Behavior on x {
        id: behx;
        enabled: false
        NumberAnimation {
            duration: anim_duration
            easing.type: Easing.Linear
        }
    }
    Behavior on y {
        id: behy;
        enabled: false
        NumberAnimation {
            duration: anim_duration
            easing.type:  Easing.Linear
        }
    }
    Behavior on width {
        id: behwidth
        enabled: true
        NumberAnimation {
            duration: anim_duration
            easing.type: Easing.Linear
        }
    }
    Behavior on height {
        id: behheight
        enabled: true
        NumberAnimation {
            duration: anim_duration
            easing.type: Easing.Linear
        }
    }
    /*Behavior on opacity {
        id: behopacity;
        enabled: true
        NumberAnimation {
            duration: 500
            easing.type: Easing.InCubic
        }
    }*/
}
