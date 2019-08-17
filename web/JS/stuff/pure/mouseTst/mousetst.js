function mouseyFunction() {
    var x;
    x = rnd(0,255);
    document.getElementById("test").innerHTML = x;
}

function rnd(min, max) {
    return Math.floor(Math.random() * (max-min+1)+min);
}
