$(document).ready(function () {
//    $("#text").text('test').css("color", "red").fadeOut("slow")
    $("#butt1").click(function (){
	$("#text").fadeOut("slow")
	$("#swoosh").text("TEST1 Clicked")
    })
    $("#butt2").click(function(){
	$("#text").fadeIn("slow")
	$("#swoosh").text("TEST2 Clicked")
    })
})
