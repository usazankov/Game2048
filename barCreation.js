var itemComponent = null;
var tileComponent = null;
var bars = {};
var tiles = [];
var count = 0;
var x_count = model.getLengthX();
var y_count = model.getLengthY();
var timer = null;

function init()
{
    createTimer();
}

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
            if(bar.numeric > 2)
            {
                bars[bar.identificator].color = Const.colorsBar[String(bar.numeric)];
                if(bar.numeric > 4)
                {
                    bars[bar.identificator].text_color = "#f9f6f2";
                }
            }
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
    txtresult.text = String(model.score());
    txtbestresult.text = String(model.bestScore());
}

function deleteAllBars()
{
    for(var key in bars) {
        bars[key].destroy();
        delete bars[key];
    }
}

function createTimer() {
    timer = Qt.createQmlObject("import QtQuick 2.0; Timer {}", mainfield);
    timer.interval = 300;
    timer.repeat = false;
    timer.triggered.connect(function () {
        for(var key in bars) {
            if(bars[key].isDel === true)
            {
                model.remove(key);
                bars[key].destroy();
                delete bars[key];
            }
        }
    });
}

function removeisDeletedBars()
{
    timer.start();
}
function updatePositionBars()
{
    for(var key in bars) {
        bars[key].x = bars[key].x_i * mainfield.width_m/x_count + Const.MARGIN_FIELD;
        bars[key].y = bars[key].y_i * mainfield.height_m/y_count + Const.MARGIN_FIELD;
    }
}

function createBar(x_i, y_i, num, i)
{
    loadComponent(x_i * mainfield.width_m/x_count, y_i * mainfield.height_m/y_count, num, i);
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

function loadComponent_p(x,y) {
    if (tileComponent != null) { // component has been previously loaded
        createTile(x,y);
        return;
    }

    tileComponent = Qt.createComponent("Tile.qml");
    if (tileComponent.status == Component.Loading)  //Depending on the content, it can be ready or error immediately
        component.statusChanged.connect(createTile);
    else
        createTile(x,y);
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

function createTile(x,y) {
    if (tileComponent.status == Component.Ready) {
        var item = tileComponent.createObject(gamerect, {
                                                  "x": x + Const.MARGIN_FIELD,
                                                  "y": y + Const.MARGIN_FIELD,
                                                  "width": (mainfield.width_m)/x_count - Const.MARGIN_FIELD,
                                                  "height": (mainfield.height_m)/y_count - Const.MARGIN_FIELD,
                                                  "x_i": Math.round(x * x_count/mainfield.width_m),
                                                  "y_i": Math.round(y * y_count/mainfield.height_m)
                                              });
        tiles.push(item);
        // make sure created item is above the ground layer
    } else if (tileComponent.status == Component.Error) {
        console.log("error creating component");
        console.log(tileComponent.errorString());
    }
}

function createItem(x,y,num,i) {
    if (itemComponent.status == Component.Ready) {
        if(!contains(bars, i)){
            var item = itemComponent.createObject(gamerect, {
                                                  "x": x  + (mainfield.width_m/x_count)/2,
                                                  "y": y  + (mainfield.height_m/y_count)/2,
                                                  "width": 0,
                                                  "height": 0,
                                                  "index" : i,
                                                  "x_i": Math.round(x * x_count/mainfield.width_m),
                                                  "y_i": Math.round(y * y_count/mainfield.height_m),
                                                  "numeric": String(num)
                                                  });
            bars[i] = item;
            bars[i].anim_enabled = true;
            bars[i].width = (mainfield.width_m)/x_count - Const.MARGIN_FIELD;
            bars[i].height = (mainfield.height_m)/y_count - Const.MARGIN_FIELD;
            bars[i].x = x + Const.MARGIN_FIELD;
            bars[i].y = y + Const.MARGIN_FIELD;
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
        bars[i].anim_enabled = enabled;
    }
}
function resizeGameField()
{
    for(var i in bars) {
        bars[i].width = mainfield.width_m/x_count - Const.MARGIN_FIELD;
        bars[i].height = mainfield.height_m/y_count - Const.MARGIN_FIELD;
        bars[i].x = (bars[i].x_i) * (mainfield.width_m/x_count) + Const.MARGIN_FIELD;
        bars[i].y = (bars[i].y_i) * (mainfield.height_m/y_count) + Const.MARGIN_FIELD;
    }
    for (var j = 0; j < tiles.length; j++) {
        tiles[j].width = mainfield.width_m/x_count - Const.MARGIN_FIELD;
        tiles[j].height = mainfield.height_m/y_count - Const.MARGIN_FIELD;
        tiles[j].x = (tiles[j].x_i) * (mainfield.width_m/x_count) + Const.MARGIN_FIELD;
        tiles[j].y = (tiles[j].y_i) * (mainfield.height_m/y_count) + Const.MARGIN_FIELD;
    }
}
