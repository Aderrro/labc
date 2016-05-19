<?php
	
	session_start();
	
	if(!isset($_SESSION['udane']) OR $_SESSION['udane'] == false)
		header('Location: zad1i2.php');
	
	function checkTimeout($timeout) 
	{
		if ($timeout !== 0 && isset($_SESSION['last_time']) && time() - $_SESSION['last_time'] > $timeout) 
			{
				// Wylogowac uzytkownika.
				session_unset();
				header('Location: zad1i2.php');
			}

		$_SESSION['last_time'] = time();
	}
		
?>

<!DOCTYPE HTML>
<html lang="pl">
<head>
	<meta charset="utf-8" />
	<title> Twoja strona domowa! </title>
	<meta name="description" content="Welcome <?php echo $_SESSION['username']; ?>" />
	<meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1" /> 

</head>

<body>
		<h1> Witaj <?php echo $_SESSION['username']; ?> ! </h1>
		<form action="" method="post">
		<table border="1" cellpadding="10" cellspacing="0">
			<tr>
			<td>
				Twój e-mail to : <?php echo $_SESSION['email']; ?>
			</td>
			<tr>
		</table>
				<input type="submit" name="logout" value="LOGOUT">
		</form>
<?php

	checkTimeout(600);
	
?>
		
<?php
	
	if(isset($_POST['logout']))
	{
		session_unset();
		header('Location: zad1i2.php');
	}
	
?>
		
		
</body>
</html>