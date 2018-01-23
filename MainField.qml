import QtQuick 2.7
import io.qt.Game2048 1.0
import "barCreation.js" as Code
Item{
    function div(val, by){
        return (val - val % by) / by;
    }
    id: mainfield
    property int x_i: model.getLengthX()
    property int y_i: model.getLengthY()
    width: parent.width
    height: parent.height
    Rectangle {
        id: gamerect
        anchors.fill: parent
        color: "#ffd7a8"
        focus: true

        Keys.onUpPressed: {
            console.log("UP!");
            logic.up();
            Code.setEnabledAnim(true);
            Code.updateModel();
            Code.setEnabledAnim(false);
        }
        Keys.onDownPressed:
        {
            console.log("DOWN!");
            logic.down();
            Code.setEnabledAnim(true);
            Code.updateModel();
            Code.setEnabledAnim(false);
        }
        Keys.onRightPressed:
        {
            console.log("RIGHT!");
            logic.right();
            Code.setEnabledAnim(true);
            Code.updateModel();
            Code.setEnabledAnim(false);
        }
        Keys.onLeftPressed:
        {
            console.log("LEFTT!");
            logic.left();
            Code.setEnabledAnim(true);
            Code.updateModel();
            Code.setEnabledAnim(false);
        }
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            logic.process();
            Code.updateModel();
            //Code.createBar(div(mouse.x, mainfield.width/model.getLengthX()),div(mouse.y, mainfield.height/model.getLengthY()));
            //Code.print_t();
        }
    }
    onHeightChanged: {
        Code.resizeGameField();
    }

    onWidthChanged: {
        Code.resizeGameField();
    }
}
