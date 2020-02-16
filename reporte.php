<!DOCTYPE html>
<html lang = "es">

<head>
	<meta charset = "UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Secuencia de Collatz</title>
	<link href="https://fonts.googleapis.com/css?family=Roboto+Mono&display=swap" rel="stylesheet">
	<style>
		body{font-family: 'Roboto Mono', monospace;}
		input[type=number]{padding: 10px; width: 30px; height: 24px; font-size: 1em; text-align: center;}
		input[type=number]::-webkit-inner-spin-button, input[type=number]::-webkit-outer-spin-button{-webkit-appearance: none}
	</style>
	<script  type = "text/javascript">
		var n;
		function inputFocus(i){n = i.value;	i.value = "";}
		function inputBlur(i){if (i.value == "") i.value = n; else document.getElementById("entrada").submit();}
		function begin(){if (document.getElementById("n").value == "") document.getElementById("n").value = <?php $n = filter_input(INPUT_GET, "n"); $handle = exec("Collatz"); echo $n;?>;}
	</script>
</head>

<body onload = "begin()">
	<form id = "entrada" action = "reporte.php" method = "get" target = "_self">
		<h2>
			<span>Secuencia de Collatz para n =&nbsp;</span>
			<span>
				<input type = "number" id = "n" name = "n" title = "Numero" onfocus = "inputFocus(this)" onblur = "inputBlur(this)" />
			</span>
		</h2>
	</form>
	<p id="sec"></p>
	<script>
		var myJSON;
		function readTextFile(file){
			var rawFile = new XMLHttpRequest();
			rawFile.open("GET", file, false);
			rawFile.onreadystatechange = function(){
				if(rawFile.readyState === 4)
					if(rawFile.status === 200 || rawFile.status == 0)
						myJSON = rawFile.responseText;
			}
			rawFile.send(null);
		}
		readTextFile("Arreglo.json");
		var myObj = JSON.parse(myJSON);
		document.getElementById("sec").innerHTML = myObj.n[0] + " " + myObj.n[1] + " " + myObj.n[2] + " " + myObj.n[3] + " " + myObj.n[4] + " " + myObj.n[5] + " " + myObj.n[6] + " " + myObj.n[7] + " " + myObj.n[8] + " " + myObj.n[9] + " " + myObj.n[10] + " " + myObj.n[11] + " " + myObj.n[12] + " " + myObj.n[13] + " " + myObj.n[14] + " " + myObj.n[15] + " " + myObj.n[16] + " " + myObj.n[17] + " " + myObj.n[18] + " " + myObj.n[19] + " " + myObj.n[20];
	</script>
</body>
</html>
