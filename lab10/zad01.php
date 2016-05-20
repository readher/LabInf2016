<?php	
error_reporting(0);
function wyswietlKlik()
{
	$file= @fopen("licznik.txt", "r+");
	fscanf($file, "%d", $count);
	rewind($file);
	fclose($file);
	echo $count;
}
function inkrementujKlik()
{
	$file= @fopen("licznik.txt", "r+");
	fscanf($file, "%d", $count);
	$count++;
	rewind($file);
	fputs($file, $count);
	fclose($file);
}
?>

<!DOCTYPE HTML>
<html lang="pl">
<head>
	<meta charset="utf-8" />
</head>

<body>
<div style="float:left; vertical-align:top;">

<h2>
<form action="" method="post">
	<input type="submit" value="Free porn! 100% legitne!" name="klik"><br>
</form>

<?php
$plik = 'licznik.txt';
if (file_exists($plik))
{
	if (isset($_POST["klik"]) AND isset($_COOKIE["kooki"]))
	{
		wyswietlKlik();
		echo "\r\nJuz dzisiaj kliknales!";
	}
	
	elseif (isset($_POST["klik"]))
	{
		setcookie("kooki", $_POST["klik"], time() + 10, "/");  //10 zamienic na 86400  - cala doba 
		inkrementujKlik();
		wyswietlKlik();
	}
}
else 
	echo "Nie ma pliku zliczajacego na serwerze!"
?>


</h2>

</body>
</html>
