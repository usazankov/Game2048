var itemComponent = null;
var bars = {};
var count = 0;
var x_count = model.getLengthX();
var y_count = model.getLengthY();


function updateModel()
{
    var iter = model.createIterator();
    while(iter.hasNext())
    {
        var bar = iter.next();
        //Проверяем, есть ли элемент бар из ранее созданных
        if(contains(bars, bar.identificator))
        {
            bars[bar.identificator].x_i = bar.ix;
            bars[bar.identificator].y_i = bar.iy;
            bars[bar.identificator].numeric = String(bar.numeric);
            bars[bar.identificator].isDel = bar.isDeleted;
        }
        else
        {
            createBar(bar.ix, bar.iy, bar.numeric, bar.identificator);
        }
    }
    updatePositionBars();
    removeisDeletedBars();
    iter.destroy();
}

function removeisDeletedBars()
{
    for(var key in bars) {
        if(bars[key].isDel === true)
        {
            model.remove(key);
            delete bars[key];

        }
    }
}
function updatePositionBars()
{
    for(var key in bars) {
        bars[key].x = bars[key].x_i * mainfield.width/x_count;
        bars[key].y = bars[key].y_i * mainfield.height/y_count;
    }
}

function createBar(x_i, y_i, num, i)
{
    var step_x = mainfield.width/x_count;
    var step_y = mainfield.height/y_count;
    loadComponent(x_i * step_x, y_i * step_y, num, i);
}
function loadComponent(x,y,num,i) {
    if (itemComponent != null) { // component has been previously loaded
        createItem(x,y,num,i);
        return;
    }

    itemComponent = Qt.createComponent("Bar.qml");
    if (itemComponent.status == Component.Loading)  //Depending on the content, it can be ready or error immediately
        component.statusChanged.connect(createItem);
    else
        createItem(x,y,num,i);
}

function contains(arr, value) {
    if (value in arr)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

function createItem(x,y,num,i) {
    if (itemComponent.status == Component.Ready) {
        console.log("i: ",i,"x: ",x,"y: ",y, "x_i: ",x * x_count/mainfield.width,"y_i: ",y * y_count/mainfield.height);
        if(!contains(bars, i)){
            var item = itemComponent.createObject(gamerect, {
                                                  "x": x,
                                                  "y": y,
                                                  "width": mainfield.width/x_count,
                                                  "height": mainfield.height/y_count,
                                                  "index" : i,
                                                  "x_i": Math.round(x * x_count/mainfield.width),
                                                  "y_i": Math.round(y * y_count/mainfield.height),
                                                  "numeric": String(num)
                                              });
            bars[i] = item;
            bars[i].opacity = 1.0;
            bars[i].anim_opacity = false;
        }
        // make sure created item is above the ground layer
    } else if (itemComponent.status == Component.Error) {
        console.log("error creating component");
        console.log(itemComponent.errorString());
    }
}
function setEnabledAnim(enabled)
{
    for(var i in bars) {
        bars[i].anim_x = enabled;
        bars[i].anim_y = enabled;
    }
}
function resizeGameField()
{
    for(var i in bars) {
        bars[i].width = mainfield.width/x_count;
        bars[i].height = mainfield.height/y_count;
        bars[i].x = bars[i].x_i * (mainfield.width/x_count);
        bars[i].y = bars[i].y_i * (mainfield.height/y_count);
    }
}
