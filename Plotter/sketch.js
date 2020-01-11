let arr = [];
function setup(){
    input = createFileInput(handleFiles)
    input.position(0,825);
    createCanvas(800,800);
    angleMode(DEGREES);
}
function draw(){
    background(220);
    for(i=0;i<arr.length;i++){
        pnt = arr[i];
        x=cos(pnt[0])*pnt[1];
        y=sin(pnt[0])*pnt[1];
        ellipse(x+400,y+400,2,2);      
    }
}

function handleFiles(file){
    print(file);
    arr = file.data.split("\r\n");
    for(i=0;i<arr.length;i++){
        pnt = arr[i].split(",");
        if(pnt.length == 2){
            pnt[0]=parseFloat(pnt[0]);
            pnt[1]=parseFloat(pnt[1]);
            arr[i] = pnt;
        }
        else{
            arr[i] = [0,11111]; //lines w/o proper data, off screen
        }
    }
    arr=arr.sort();
}