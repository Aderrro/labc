<?php
	
	session_start();
	if(isset($_SESSION['udane']) AND $_SESSION['udane'] == true)
		header("Location: login.php");
	
?>

<!DOCTYPE HTML>
<html lang="pl">
<head>
	<meta charset="utf-8" />
	<title> Logowanie do serwisu </title>
	<meta name="description" content="Podaj swoj login oraz haslo" />
	<meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1" />


	
</head>



<body>
		<h1> Dane : </h1>
		<form action="" method="post">
		<table border="1" cellpadding="10" cellspacing="0">
			<tr>
			<td>
				Username <input type="text" size="25" name="user"/> <br> </br>
				Password &nbsp<input type="password" size="25" name="pass"/> <br>
			</td>
			<tr>
		</table>
				<input type="submit" name="login" value="LOGIN">
		</form>
	
	
<?php

	
	if(isset($_POST['user']) AND isset($_POST['pass']))
	{
		$_SESSION['username'] = $_POST['user'];
		$_SESSION['password'] = $_POST['pass'];
		$userlist = file('users.txt');
		
		$_SESSION['email'] = "";
		
		$_SESSION['udane'] = false;
		foreach($userlist as $user)
		{
			$daneusera = explode('|',$user);
			if($daneusera[0] == $_SESSION['username'] && $daneusera[1] == $_SESSION['password'])
			{
				$_SESSION['udane'] = true;
				$_SESSION['email'] = $daneusera[2];
				header("Location: login.php");
			}
		}
		if($_SESSION['udane'] == false)
			echo "<span style = 'color: red'> Niepoprawny login lub haslo! </span>";
	}


?>







</body>
</html>
