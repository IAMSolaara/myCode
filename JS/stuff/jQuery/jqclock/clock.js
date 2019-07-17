$(document).ready( function() {
    clock();
    setInterval(clock, 1000);
});

function clock() {
    var date = new Date();
    $("#hour").text(date.getHours());
    $("#min").text(date.getMinutes());
    $("#sec").text(date.getSeconds());
}


