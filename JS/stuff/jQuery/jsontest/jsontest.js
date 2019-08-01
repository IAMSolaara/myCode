var json;

$(document).ready(function(){
    var toLoad;
    $.getJSON("./test.json", function(data) {
	$("#json1").text(data.test[0])
    })
    console.log(json);
    
})
