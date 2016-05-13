<!doctype html>

<html>

<head>
 <title>chetni na impreze</title>
</head>

<body>

<div style="float:left; vertical-align:top; background-color:yellow">
 <h3>Chetni na impreze:</h3>
 <h5>
 <?php
 if ($_REQUEST['ile'] != NULL)
 {
	for ($i = 0; $i <= $_REQUEST['ile']; $i++)
	{
		if($i< $_REQUEST['ile'] )
		{
			$a= $_REQUEST['imie'.$i] ;
			echo $i+1 .". ".$a."<br>";
		}else
		{
			echo $i+1 .". ".$_REQUEST['nowy']."<br>" ;
		}
	}
}
 ?>
 </h5>

 </div>
<div style="float:right; vertical-align:top">
 <h3>Nowa osoba:</h3>

  <form action="">
  <input type="text" name="nowy">
  <?php
  if($_REQUEST['ile']!=NULL)
  {
	for($i=0;$i<=$_REQUEST['ile'];$i++)
	{
		if($i< $_REQUEST['ile'] )
		{
			$a=$_REQUEST['imie'.$i];
			echo '<input type="hidden" name="imie'.$i.'" value="'.$a.'" />'."\n";
		}else
		{
			echo '<input type="hidden" name="imie'.$i.'" value="'.$_REQUEST['nowy'].'" />'."\n";
		}
	}
 }
?>
  <input type ="hidden" name="ile" value="<?php if($_REQUEST['ile']==NULL){ echo "0";}if($_REQUEST['ile']!=NULL){ $a= $_REQUEST['ile']; echo $a+1;}?>">
 </form>
</div>

</body>

</html>
