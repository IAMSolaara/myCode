function prefix ($prefix) {
	(Get-ChildItem -Exclude $prefix*) | Rename-Item -NewName { $prefix + $_.Name }
}
#WIP
#function suffix ($suffix) {
#	(Get-ChildItem -Exclude *$suffix) | Rename-Item -NewName { $_.Name + $suffix }
#}

if ($args[0] -eq "prefix" ) {
	prefix $args[1]
}
else {
	if ($args[0] -eq "suffix") {
		#suffix $args[1]
		Write-Host "Work in progress."
	}
	else {
		Write-Host "No acceptable parameters passed."
		exit
	}
}