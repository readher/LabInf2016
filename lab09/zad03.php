<!DOCTYPE HTML>
<html lang="pl">
<head>
	<meta charset="utf-8" />
</head>

<body>
<div style="float:left; vertical-align:top;">

<h2>
Licznik odwiedzin :

<?php
	$file= @fopen("licznik.txt", "w+");
	fscanf($file, "%d", $count);
	$count++;
	rewind($file);
	fputs($file, $count);
	fclose($file);
	echo $count;
?>

</h2>

</body>
</html>
