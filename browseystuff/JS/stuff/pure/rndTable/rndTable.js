var str = 1;
var el="t";
var i=0;
var j=0;

while (str < 2000) {
    j =  rnd(1,3);
    i =  rnd(1,3);

    el = "t" + j + i;
    document.getElementById(el).innerHTML = (rnd(0,14));
    str++;
    console.log("cycle.");
}

function rnd(min, max) {
    return Math.floor(Math.random() * (max-min+1)+min);
}
