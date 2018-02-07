var dialogComponent = null;
var dialogitem = null
var anim_enabled = true;
function createDialog(text)
{
    loadComponent_dialog(text);
}
function deleteDialog()
{
    if(dialogitem != null)
    {
        dialogitem.destroy();
        delete dialogitem;
        dialogitem = null;
    }
}

function loadComponent_dialog(text) {
    if (dialogComponent  != null) { // component has been previously loaded
        createDialogComp(text);
        return;
    }

    dialogComponent  = Qt.createComponent("InformDialog.qml");
    if (dialogComponent .status == Component.Loading)  //Depending on the content, it can be ready or error immediately
        component.statusChanged.connect(createDialogComp);
    else
        createDialogComp(text);
}

function createDialogComp(text) {
    if (dialogComponent.status == Component.Ready) {
        if(dialogitem != null)
        {
            dialogitem.text_mes = text;
        }
        else
        {
            dialogitem = dialogComponent.createObject(mainItem, {
                                                      "width": mainField.width,
                                                      "height": mainField.height,
                                                      "x": mainField.x,
                                                      "y":mainField.y,
                                                      "z": 20,
                                                      "text_mes": text,
                                                      "anim_enabled": anim_enabled
                                                  });
        dialogitem.dialog_opacity = 0.5;
        dialogitem.text_opacity = 1;
        }
        // make sure created item is above the ground layer
    } else if (dialogComponent.status == Component.Error) {
        console.log("error creating component");
        console.log(dialogComponent.errorString());
    }
}
