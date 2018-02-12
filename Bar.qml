import QtQuick 2.7
import "constants.js" as Const

Rectangle{
    id:barrect
    color: "#eee4da"
    property int index: 0
    property int x_i: 0
    property int y_i: 0
    property bool isDel: false
    property int anim_duration: 150
    property alias numeric: txt.text;
    property alias text_color: txt.color;
    property bool anim_enabled: true
    property bool anim_opacity: true
    property int margin: Const.MARGIN_FIELD
    z: 10;
    radius: appwindow.dp(10.0)
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
        color: "#776e65";
        font.pixelSize: appwindow.dp(30)
        text: "2";
        font.bold: true
        Behavior on text {
            SequentialAnimation{
                PauseAnimation {
                    duration: anim_duration
                }
                NumberAnimation {
                    duration: 0
                }
            }
        }
        Behavior on color {
            SequentialAnimation{
                PauseAnimation {
                    duration: anim_duration
                }
                ColorAnimation {
                    duration: 0
                }
            }
        }
    }
    Behavior on color {
        SequentialAnimation{
            PauseAnimation {
                duration: anim_duration
            }
            ColorAnimation {
                duration: 0
            }
        }
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
