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
		function begin(){if (document.getElementById("n").value == "") document.getElementById("n").value = <?php $n = filter_input(INPUT_GET, "n"); $handle = exec("START Collatz"); echo $n;?>;}
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
		document.getElementById("sec").innerHTML = myObj.n[0] + " " + myObj.n[1] + " " + myObj.n[2] + " " + myObj.n[3] + " " + myObj.n[4] + " " + myObj.n[5] + " " + myObj.n[6] + " " + myObj.n[7] + " " + myObj.n[8] + " " + myObj.n[9] + " " + myObj.n[10] + " " + myObj.n[11] + " " + myObj.n[12] + " " + myObj.n[13] + " " + myObj.n[14] + " " + myObj.n[15] + " " + myObj.n[16] + " " + myObj.n[17] + " " + myObj.n[18] + " " + myObj.n[19] + " " + myObj.n[20] + " " + myObj.n[21] + " " + myObj.n[22] + " " + myObj.n[23] + " " + myObj.n[24] + " " + myObj.n[25] + " " + myObj.n[26] + " " + myObj.n[27] + " " + myObj.n[28] + " " + myObj.n[29] + " " + myObj.n[30] + " " + myObj.n[31] + " " + myObj.n[32] + " " + myObj.n[33] + " " + myObj.n[34] + " " + myObj.n[35] + " " + myObj.n[36] + " " + myObj.n[37] + " " + myObj.n[38] + " " + myObj.n[39] + " " + myObj.n[40] + " " + myObj.n[41] + " " + myObj.n[42] + " " + myObj.n[43] + " " + myObj.n[44] + " " + myObj.n[45] + " " + myObj.n[46] + " " + myObj.n[47] + " " + myObj.n[48] + " " + myObj.n[49] + " " + myObj.n[50] + " " + myObj.n[51] + " " + myObj.n[52] + " " + myObj.n[53] + " " + myObj.n[54] + " " + myObj.n[55] + " " + myObj.n[56] + " " + myObj.n[57] + " " + myObj.n[58] + " " + myObj.n[59] + " " + myObj.n[60] + " " + myObj.n[61] + " " + myObj.n[62] + " " + myObj.n[63] + " " + myObj.n[64] + " " + myObj.n[65] + " " + myObj.n[66] + " " + myObj.n[67] + " " + myObj.n[68] + " " + myObj.n[69] + " " + myObj.n[70] + " " + myObj.n[71] + " " + myObj.n[72] + " " + myObj.n[73] + " " + myObj.n[74] + " " + myObj.n[75] + " " + myObj.n[76] + " " + myObj.n[77] + " " + myObj.n[78] + " " + myObj.n[79] + " " + myObj.n[80] + " " + myObj.n[81] + " " + myObj.n[82] + " " + myObj.n[83] + " " + myObj.n[84] + " " + myObj.n[85] + " " + myObj.n[86] + " " + myObj.n[87] + " " + myObj.n[88] + " " + myObj.n[89] + " " + myObj.n[90] + " " + myObj.n[91] + " " + myObj.n[92] + " " + myObj.n[93] + " " + myObj.n[94] + " " + myObj.n[95] + " " + myObj.n[96] + " " + myObj.n[97] + " " + myObj.n[98] + " " + myObj.n[99] + " " + myObj.n[100] + " " + myObj.n[101] + " " + myObj.n[102] + " " + myObj.n[103] + " " + myObj.n[104] + " " + myObj.n[105] + " " + myObj.n[106];
	</script>
</body>
</html>
