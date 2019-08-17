var cella="t";
var i=1;
var j=1;
while(i <= 10) {
    j=1;
    while (j <= 10) {
	cella = "t" + i + j;
	document.getElementById(cella).innerHTML = (i*j);
        j++;
    }
    i++;
}
