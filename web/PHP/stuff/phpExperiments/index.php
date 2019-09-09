<?php
	$file = fopen("intst.txt", "r") or die("Can't open file....");
	echo fread($file, filesize("intst.txt"));
	fclose($file);
	echo "Welcome to my PHP experiments! Today is ";
	echo date("d-m-Y");
#	echo readfile("inLineHT.html");
?>
