import QtQuick 2.0
Item{
    property int anim_dur: 1000;
    property bool anim_enabled: true;
    property alias text_mes: dialogTxt.text;
    property alias dialog_opacity: dialogRect.opacity;
    property alias text_opacity: dialogTxt.opacity;
    Rectangle{
        id: dialogRect;
        anchors.fill: parent;
        color: "#beb0a3";
        opacity: 0;
        radius: 10;
        z: 20;
        Behavior on opacity {
            id: behdialogrect;
            enabled: anim_enabled
            NumberAnimation {
                duration: anim_dur
                easing.type:  Easing.Linear;
            }
        }
    }
    Text{
        id:dialogTxt;
        text:"Игра окончена";
        opacity: 0;
        anchors.centerIn: dialogRect;
        horizontalAlignment: Text.AlignHCenter;
        verticalAlignment: Text.AlignVCenter;
        width: dialogRect.width;
        height: dialogRect.height;
        color: "#776e65";
        font.pointSize: 26;
        font.bold: true
        z: 21;
        Behavior on opacity {
            id: behdialogtext;
            enabled: anim_enabled
            NumberAnimation {
                duration: anim_dur
                easing.type:  Easing.Linear;
            }
        }
    }
}

