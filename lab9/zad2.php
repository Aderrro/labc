//jeszcze nie do konca dziala w 100% -> nalezy wpisac probnie jeden argument/imie aby zaczelo poprawnie wypisywac...

<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
</head>
<body>
<div style="float:left; vertical-align:top;">
    <h2> Chetni na impreze : </h2>
    <?php
	
    if (isset($_GET['lista'])) 
	{
        $list = $_GET['lista'];
        $explode = explode(',', $list); 
        array_pop($explode);
        foreach($explode as $name)
		{
			echo $name.'<br>';
        }
    }
	
    ?>
	
</div>
<div style="float:right; vertical-align:top;">
    <h2> Nowa osoba : </h2>
    <form action="zad2.php" method="GET">
        <input type="text" name="nowy"><br>
        <input type="hidden" name="lista" value="
    <?php
        if (isset($_GET['lista'])) 
		{
            if (isset($_GET['nowy'])) 
			{
                echo $_GET['nowy'].','.$_GET['lista'];
            } 
			else 
			{
                echo ''; 
            }
        } 
		
		else
		{
            if (isset($_GET['nowy'])) 
			{
                echo $_GET['nowy'];
            } 
			else 
			{
                echo '';
            }
        }
 
 
        ?>">
        <input type="submit" name="send" value="ZAPISZ"><br>
    </form>
</div>
</body>
</html>
