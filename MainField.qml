import QtQuick 2.7
import io.qt.Game2048 1.0
import "barCreation.js" as Code
import "constants.js" as Const
import "gameFieldCreation.js" as CodeField
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
        logic.process();
        Code.updateModel();
        Code.setEnabledAnim(false);
    }

    id: mainfield
    property int x_i: model.getLengthX()
    property int y_i: model.getLengthY()
    property int width_m: width - Const.MARGIN_FIELD;
    property int height_m: height - Const.MARGIN_FIELD;
    property bool created: false
    onCreatedChanged:
    {
        console.log("x_i=",x_i," y_i=",y_i);
        for(var i = 0; i < model.getLengthX(); ++i)
        {
            for(var j = 0; j < model.getLengthY(); ++j)
            {
                Code.loadComponent_p(i*width_m/model.getLengthX(), j*height_m/model.getLengthY());
            }
        }
        Code.init();
        Code.updateModel();
    }
    Rectangle {
        id: gamerect
        anchors.fill: parent;
        color: "#beb0a3"
        focus: true
        Keys.onUpPressed: {
            move("Up");
        }
        Keys.onDownPressed:
        {
            move("Down");
        }
        Keys.onRightPressed:
        {
            move("Right");
        }
        Keys.onLeftPressed:
        {
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
