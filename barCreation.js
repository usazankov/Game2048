var itemComponent = null;
var bars = new Array
var count = 0
var x_count = model.getLengthX();
var y_count = model.getLengthY();


function updateModel()
{
    var iter = model.createIterator();
    while(iter.hasNext())
    {
        var bar = iter.next();
        if( bar != null)
        {
            createBar(bar.ix, bar.iy, bar.identificator);
        }
    }
    iter.destroy();
}

function createBar(x_i, y_i, i)
{
    var step_x = mainfield.width/x_count;
    var step_y = mainfield.width/y_count;
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
    for (var i = 0; i < bars.length; i++) {
        if(bars[i].index == value)
            return 1;
    }
   return 0;
}

function createItem(x,y,i) {
    if (itemComponent.status == Component.Ready) {
        if(!contains(bars, i)){
            var item = itemComponent.createObject(gamerect, {
                                                  "x": x,
                                                  "y": y,
                                                  "width": mainfield.width/x_count,
                                                  "height": mainfield.height/y_count,
                                                  "index" : i,
                                                  "x_i": x * x_count/mainfield.width,
                                                  "y_i": y * y_count/mainfield.height
                                              });
            bars.push(item);
            //console.log("item created!");
        }
        //var iter = model.createIterator();
        //console.log("iter=", iter.hasNext());
        /*var newObject = Qt.createQmlObject('import io.qt.Game2048 1.0; Bar {color: "red"; width: 20; height: 20}',
                                           mainfield,
                                           "dynamicSnippet1");*/

        /*if(!contains(bars, item))
        {
            bars.push(item);
            console.log("item created!");
        }*/
        // make sure created item is above the ground layer
    } else if (itemComponent.status == Component.Error) {
        console.log("error creating component");
        console.log(itemComponent.errorString());
    }
}
function resizeGameField()
{
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
