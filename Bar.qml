import QtQuick 2.7
import "constants.js" as Const

Rectangle{
    id:barrect
    color: "#ff8438"
    property int index: 0
    property int x_i: 0
    property int y_i: 0
    property bool isDel: false
    property int anim_duration: 300
    property alias numeric: txt.text;
    property bool anim_enabled: true
    property bool anim_opacity: true
    property int margin: Const.MARGIN_FIELD
    z: 10;
    radius: 10.0
    onAnim_opacityChanged:
    {
        behheight.enabled = anim_opacity;
        behwidth.enabled = anim_opacity;

    }
    onAnim_enabledChanged:
    {
        behy.enabled = anim_enabled;
        behx.enabled = anim_enabled;
        behwidth.enabled = anim_enabled;
        behheight.enabled = anim_enabled;
    }
    Text{
        id: txt;
        anchors.centerIn: parent
        text: "2";
    }
    Behavior on x {
        id: behx;
        enabled: true
        NumberAnimation {
            duration: anim_duration
            easing.type: Easing.InQuad
        }
    }
    Behavior on y {
        id: behy;
        enabled: true
        NumberAnimation {
            duration: anim_duration
            easing.type:  Easing.InQuad
        }
    }
    Behavior on width {
        id: behwidth
        enabled: true
        NumberAnimation {
            duration: anim_duration
            easing.type: Easing.InQuad
        }
    }
    Behavior on height {
        id: behheight
        enabled: true
        NumberAnimation {
            duration: anim_duration
            easing.type: Easing.InQuad
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
