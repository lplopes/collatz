#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
#include <time.h>
#include "/home/leandro/Desktop/rapidjson-master/include/rapidjson/document.h"
#include "/home/leandro/Desktop/rapidjson-master/include/rapidjson/writer.h"
#include "/home/leandro/Desktop/rapidjson-master/include/rapidjson/stringbuffer.h"

using namespace std;
using namespace rapidjson;

int main()
{
    //Declaracion de variables
    unsigned int *n, i, j;
    float cput;
    string a;
    clock_t start, endp;
    ofstream salida;
    Document d;

    //Alocar memoria
    n = (unsigned int *) malloc(sizeof(unsigned int));

    //Entrada del numero
    cout << "n: ";
    cin >> n[0];

    //Tiempo de procesameinto
    start = clock();

    //Definir la secuencia
    i = 0;
    while(n[i] != 1)
    {
        n = (unsigned int *) realloc(n, (++i + 1) * sizeof(unsigned int));
        if(n[i - 1] % 2)
            n[i] = n[i - 1] * 3 + 1;
        else
            n[i] = n[i - 1] / 2;
    }

    //Almacenar el arreglo JSON
    a = "{\"n\":[";
    for(j = 0; j < i; j++)
        a += to_string(n[j]) + ", ";
    a += to_string(n[i]) + "]}";
    salida.open("Arreglo.json");
    salida << a;
    salida.close();

    //Entrega del arreglo JSON
    const char* json = a.c_str();
    d.Parse(json);
    Value& s = d["n"];
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);
    cout << buffer.GetString() << endl;

    //Reportar el teste
    salida.open("reporte.php");
    salida << "<!DOCTYPE html>\n<html lang = \"es\">\n\n<head>" << endl;
    salida << "\t<meta charset = \"UTF-8\">" << endl;
    salida << "\t<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">" << endl;
    salida << "\t<title>Secuencia de Collatz</title>" << endl;
    salida << "\t<link href=\"https://fonts.googleapis.com/css?family=Roboto+Mono&display=swap\" rel=\"stylesheet\">" << endl;
    salida << "\t<style>" << endl;
    salida << "\t\tbody{font-family: 'Roboto Mono', monospace;}" << endl;
    salida << "\t\tinput[type=number]{padding: 10px; width: 30px; height: 24px; font-size: 1em; text-align: center;}" << endl;
    salida << "\t\tinput[type=number]::-webkit-inner-spin-button, input[type=number]::-webkit-outer-spin-button{-webkit-appearance: none}" << endl;
    salida << "\t</style>" << endl;
    salida << "\t<script  type = \"text/javascript\">" << endl;
    salida << "\t\tvar n;" << endl;
    salida << "\t\tfunction inputFocus(i){n = i.value;\ti.value = \"\";}" << endl;
    salida << "\t\tfunction inputBlur(i){if (i.value == \"\") i.value = n; else document.getElementById(\"entrada\").submit();}" << endl;
    salida << "\t\tfunction begin(){if (document.getElementById(\"n\").value == \"\") document.getElementById(\"n\").value = <?php $n = filter_input(INPUT_GET, \"n\"); $handle = exec(\"START Collatz\"); echo $n;?>;}" << endl;
    salida << "\t</script>" << endl;
    salida << "</head>\n" << endl;
    salida << "<body onload = \"begin()\">" << endl;
    salida << "\t<form id = \"entrada\" action = \"reporte.php\" method = \"get\" target = \"_self\">" << endl;
    salida << "\t\t<h2>" << endl;
    salida << "\t\t\t<span>Secuencia de Collatz para n =&nbsp;</span>" << endl;
    salida << "\t\t\t<span>" << endl;
    salida << "\t\t\t\t<input type = \"number\" id = \"n\" name = \"n\" title = \"Numero\" onfocus = \"inputFocus(this)\" onblur = \"inputBlur(this)\" />" << endl;
    salida << "\t\t\t</span>" << endl;
    salida << "\t\t</h2>" << endl;
    salida << "\t</form>" << endl;
    salida << "\t<p id=\"sec\"></p>" << endl;
    salida << "\t<script>" << endl;
    salida << "\t\tvar myJSON;" << endl;
    salida << "\t\tfunction readTextFile(file){" << endl;
    salida << "\t\t\tvar rawFile = new XMLHttpRequest();" << endl;
    salida << "\t\t\trawFile.open(\"GET\", file, false);" << endl;
    salida << "\t\t\trawFile.onreadystatechange = function(){" << endl;
    salida << "\t\t\t\tif(rawFile.readyState === 4)" << endl;
    salida << "\t\t\t\t\tif(rawFile.status === 200 || rawFile.status == 0)" << endl;
    salida << "\t\t\t\t\t\tmyJSON = rawFile.responseText;\n\t\t\t}" << endl;
    salida << "\t\t\trawFile.send(null);\n\t\t}" << endl;
    salida << "\t\treadTextFile(\"Arreglo.json\");" << endl;
    salida << "\t\tvar myObj = JSON.parse(myJSON);" << endl;
    salida << "\t\tdocument.getElementById(\"sec\").innerHTML = myObj.n[";
    for(j = 0; j < i; j++)
        salida << j << "] + \" \" + myObj.n[";
    salida << i << "];" << endl;
    salida << "\t</script>" << endl;
    salida << "</body>" << endl;
    salida << "</html>" << endl;
    salida.close();

    //Liberar memoria
    free(n);

    //Calcula o tempo de processamento e imprime na tela
    endp = clock();
    cput = ((float)(endp - start)) / CLOCKS_PER_SEC;
    cout << "Tiempo de procesamiento: " << setprecision(3) << cput << " s.\n";

    return 0;
}
