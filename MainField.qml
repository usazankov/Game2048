import QtQuick 2.7
import io.qt.Game2048 1.0
import "barCreation.js" as Code
Item{
    function div(val, by){
        return (val - val % by) / by;
    }
    function move(command)
    {
        if(command === "Up")
        {
            logic.up();
        }
        else if(command === "Down")
        {
            logic.down();
        }
        else if(command === "Right")
        {
            logic.right();
        }
        else if(command === "Left")
        {
            logic.left();
        }
        //logic.process();
        Code.setEnabledAnim(true);
        Code.updateModel();
        Code.setEnabledAnim(false);
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
            move("Up");

        }
        Keys.onDownPressed:
        {
            console.log("DOWN!");
            move("Down");
        }
        Keys.onRightPressed:
        {
            console.log("RIGHT!");
            move("Right");
        }
        Keys.onLeftPressed:
        {
            console.log("LEFT!");
            move("Left");
        }
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            logic.process();
            Code.setEnabledAnim(true);
            Code.updateModel();
            Code.setEnabledAnim(false);
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
