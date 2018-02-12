import QtQuick 2.7
import io.qt.Game2048 1.0
import "barCreation.js" as Code
import "constants.js" as Const
import "dialogs.js" as Dialogs

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
        if(model.state() === IBaseModel.GameOver)
        {
            isBlocked = true;
            Dialogs.createDialog("Игра окончена");
        }
        else if(model.state() === IBaseModel.Win)
        {
            isBlocked = true;
            Dialogs.createDialog("Вы победили!");
        }
        else if(model.state() === IBaseModel.WaitCommand && isBlocked)
        {
            Dialogs.deleteDialog();
        }

        Code.updateModel();
        Code.setEnabledAnim(false);
        logic.saveBestScore(model.score());

    }
    function model_revert()
    {
        isBlocked = false;
        logic.revert();
        if(model.state() === IBaseModel.WaitCommand)
        {
            Dialogs.deleteDialog();
        }
        Code.removeDelay = false;
        Code.setEnabledAnim(true);
        Code.updateModel();
        Code.removeDelay = true;
    }
    function model_newGame()
    {
        isBlocked = false;
        Code.deleteAllBars();
        logic.newGame();
        console.log("model.state = ",model.state());
        if(model.state() === IBaseModel.WaitCommand)
        {
            Dialogs.deleteDialog();
        }
        Code.updateModel();
    }
    id: mainfield
    property int x_i: model.getLengthX()
    property int y_i: model.getLengthY()
    property int width_m: width - Const.MARGIN_FIELD;
    property int height_m: height - Const.MARGIN_FIELD;
    property bool created: false
    property bool isBlocked: false;
    onCreatedChanged:
    {
        for(var i = 0; i < model.getLengthX(); ++i)
        {
            for(var j = 0; j < model.getLengthY(); ++j)
            {
                Code.loadComponent_p(i*width_m/model.getLengthX(), j*height_m/model.getLengthY());
            }
        }
        Code.init();
        Code.removeDelay = false;
        if(model.state() === IBaseModel.GameOver)
        {
            isBlocked = true;
            Dialogs.createDialog("Игра окончена");
        }
        else if(model.state() === IBaseModel.Win)
        {
            isBlocked = true;
            Dialogs.createDialog("Вы победили!");
        }
        Code.updateModel();
        Code.removeDelay = true;
    }
    Rectangle {
        id: gamerect
        anchors.fill: parent;
        color: "#beb0a3"
        radius: 10
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
        property int minDiff: 25
        property int xPressed: 0
        property int yPressed: 0
        property bool isPressed: false
        onPressed:
        {
            isPressed = 1;
            xPressed = mouseX;
            yPressed = mouseY;
        }
        onPositionChanged: {
            if(isPressed)
            {
                if(mouseX - xPressed > minDiff)
                {
                    move("Right");
                    isPressed = 0;
                }
                else if(xPressed - mouseX > minDiff)
                {

                    move("Left");
                    isPressed = 0;
                }
                else if(mouseY - yPressed > minDiff)
                {
                    move("Down");
                    isPressed = 0;
                }
                else if(yPressed - mouseY > minDiff)
                {
                    move("Up");
                    isPressed = 0;
                }
            }

        }
        onReleased: {
            isPressed = 0;
        }

    }
    onWidth_mChanged:
    {
        console.log("onWidthChanged:");
        //height_m = height - Const.MARGIN_FIELD;
        Code.setEnabledAnim(false);
        Code.resizeGameField();
    }
    onHeight_mChanged:
    {
        console.log("onHeightChanged:");
        //width_m = width - Const.MARGIN_FIELD;
        Code.setEnabledAnim(false);
        Code.resizeGameField();
    }
    onHeightChanged: {

    }
    onWidthChanged: {

    }
}
