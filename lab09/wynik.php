<!DOCTYPE HTML>
<html lang="pl">
<head>
	<meta charset ="utf-8" />
	<title>Wynik</title>
</head>

<body>

<?php
	$arg1 = $_POST["arg1"];
	$op = $_POST["op"];
	$arg2 = $_POST["arg2"];

	if(isset($arg1) AND isset($op) AND isset($arg2))
	{
		if ($op == "+"){
			$wyliczenie = $arg1 + $arg2;
			echo "Suma : $wyliczenie";
		}

		elseif ($op == "-"){
			$wyliczenie = $arg1 - $arg2;
			echo "Różnica : $wyliczenie";
		}

		elseif($op == "*"){
			$wyliczenie = $arg1 * $arg2;
			echo "Mnożenie : $wyliczenie";
		}

		elseif($op == "/"){
			$wyliczenie = $arg1 / $arg2;
			echo "Dzielenie : $wyliczenie";
		}
	}

	else
		echo "Jakaś zmienna nie została użyta! Spróbój ponownie!"
?>
	
