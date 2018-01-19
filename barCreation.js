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
        }
        else
        {
            createBar(bar.ix, bar.iy, bar.identificator);
        }
    }
    updatePositionBars();
    iter.destroy();
}
function updatePositionBars()
{
    console.log("updatePositionBars()");
    for(var key in bars) {
        bars[key].x = bars[key].x_i * mainfield.width/x_count;
        bars[key].y = bars[key].y_i * mainfield.height/y_count;
    }
}

function createBar(x_i, y_i, i)
{
    var step_x = mainfield.width/x_count;
    var step_y = mainfield.height/y_count;
    loadComponent(x_i * step_x, y_i * step_y,i);
}
function loadComponent(x,y,i) {
    if (itemComponent != null) { // component has been previously loaded
        createItem(x,y,i);
        return;
    }

    itemComponent = Qt.createComponent("Bar.qml");
    if (itemComponent.status == Component.Loading)  //Depending on the content, it can be ready or error immediately
        component.statusChanged.connect(createItem);
    else
        createItem(x,y,i);
}

function contains(arr, value) {
    if (value in arr)
    {
        console.log("Contains!");
        return 1;
    }
    else
    {
        console.log("No contains");
        return 0;
    }
}

function createItem(x,y,i) {
    if (itemComponent.status == Component.Ready) {
        console.log("createItem x:",x," y:",y);
        if(!contains(bars, i)){
            console.log("createItem x:",x," y:",y);
            var item = itemComponent.createObject(gamerect, {
                                                  "x": x,
                                                  "y": y,
                                                  "width": mainfield.width/x_count,
                                                  "height": mainfield.height/y_count,
                                                  "index" : i,
                                                  "x_i": x * x_count/mainfield.width,
                                                  "y_i": y * y_count/mainfield.height
                                              });
            bars[i] = item;
        }
        // make sure created item is above the ground layer
    } else if (itemComponent.status == Component.Error) {
        console.log("error creating component");
        console.log(itemComponent.errorString());
    }
}
function resizeGameField()
{
    console.log("resizeGameField()");
    for (var i = 0; i < bars.length; i++) {
        bars[i].width = mainfield.width/x_count;
        bars[i].height = mainfield.height/y_count;
        bars[i].x = bars[i].x_i * (mainfield.width/x_count);
        bars[i].y = bars[i].y_i * (mainfield.height/y_count);
    }
}
function print_t(){
    for (var i = 0; i < bars.length; i++) {
        console.log("i=", bars[i].index);

    }
}
