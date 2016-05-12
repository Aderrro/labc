<?php
 if (isset($_REQUEST['funkcja'])) 
 {
  $wydruk = '';
  $wydruk .= '#!/bin/bash'.PHP_EOL;
  $wydruk .= 'gnuplot << EOF'.PHP_EOL;
  $wydruk .= 'set terminal png truecolor enhanced'.PHP_EOL;
  $wydruk .= 'set output "rys.png"'.PHP_EOL;
  if($_REQUEST['ile']==1)
  {
	  $wydruk .= 'plot ' . $_REQUEST['funkcja'].PHP_EOL;
  }else
  {
	  $wydruk .= 'splot ' . $_REQUEST['funkcja'].PHP_EOL;
  }
  $wydruk .= 'EOF'.PHP_EOL;
  $pl = fopen("rysunek.sh", "w");
  fprintf($pl, "%s", $wydruk);
  fclose($pl);
  exec('chmod 755 rysunek.sh');
  exec('./rysunek.sh');
  exec('chmod 644 rys.png');
  print('<img src="rys.png"><br><br>'.PHP_EOL);
 }
?>

<!doctype html>
<html>
<body>
 <form action="index.html">
  <input type="submit" value="Powrot">
 </form>
</body>
</html>