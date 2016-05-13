<!DOCTYPE HTML>
<html lang="pl">
<head>
	<meta charset="utf-8" />
</head>

<body>

	<h1> Kalkulator </h1>
	<form action="wynik.php" method="post">
		<table>
			<tr>
			<td>
				<input type="number" name="arg1"/>
			</td>
			<td>
				<input type="radio" name="op" value="+"> <b>+</b><br>
				<input type="radio" name="op" value="-"> <b>&minus;</b><br>
				<input type="radio" name="op" value="*"> <b>&middot;</b><br>
				<input type="radio" name="op" value="/"> <b>/</b><br>
			</td>
			<td>
				<input type="number" name="arg2" />
			</td>
			<td>
				<input type="submit" value="==">
			<td>
			</tr>
		</table>


</body>
</html>
