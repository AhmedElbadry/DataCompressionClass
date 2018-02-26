# DataCompressionClass


### Team
Ahmed El Badry - Khaled Mohamed - Remon Fawzy

### -


# Assignment_1
HTML code compression using RLE on bit level.



## Introduction
Run length encoding (RLE) is a lossless data compression algorithm where we represent equal consecutive blocks of data in ``count`` + ``data``, for example ``aaaaa`` will be ``5a``.

In our case we will perform RLE on bit level. There is a problem, ASCII codes usually don't have a big number of equal consecutive bits. So, our "compressed" file will mostly be bigger than the original file.

## Algorithm
Before we get into RLE, lets do some optimizations.

##### The input is valid HTML code
Knowing that the input is a valid HTML code, we can do some abbreviations. We know that if we open a tag, the next closing tag must be for that opened tag. So we can remove the closing tags and substitute for every closing tag with ``<>``

##### Are we going to use the whole ASCII characters?
Of course, we will not do that. Lets create a map and put the alphabet characters and symbols that are often used in an HTML document ``<`` , ``>`` and spaces. Lets map the ``endl`` also, it takes 3 bytes normally and mapping it will be a good optimization.

We have around 55 characters mapped in our map, 55 characters can be represented in 6 bits.

What if we encountered a character that wasn't mapped, six bits of zero will be added as a flag and the ASCII code for that character will be added.


##### RLE

To avoid the problem of negative compression discussed above, we will perform RLE twice, once for counting zeros between ones and once for the counting the ones between zeros. Then, we will compare the sizes of the first RLE and the second RLE string and the original string. We will go with the smallest string.

To determine which type of compressing we applied on a string, we will add a 2-bits flag in the beginning of each string.

``00`` means we didn't use RLE

``01`` means we used RLE to count the ones

``11`` means we used RLE to count the zeros



## Input and output samples

##### input
```
<!DOCTYPE html>
<html>
<head>
</head>
<body>

<h2>HTML Table</h2>

<table>
  <tr>
    <th>Company</th>
    <th>Contact</th>
    <th>Country</th>
  </tr>
  <tr>
    <td>Alfreds Futterkiste</td>
    <td>Maria Anders</td>
    <td>Germany</td>
  </tr>
  <tr>
    <td>Centro comercial Moctezuma</td>
    <td>Francisco Chang</td>
    <td>Mexico</td>
  </tr>
  <tr>
    <td>Ernst Handel</td>
    <td>Roland Mendel</td>
    <td>Austria</td>
  </tr>
  <tr>
    <td>Island Trading</td>
    <td>Helen Bennett</td>
    <td>UK</td>
  </tr>
  <tr>
    <td>Laughing Bacchus Winecellars</td>
    <td>Yoshi Tannamuri</td>
    <td>Canada</td>
  </tr>
  <tr>
    <td>Magazzini Alimentari Riuniti</td>
    <td>Giovanni Rovelli</td>
    <td>Italy</td>
  </tr>
</table>
</body>
</html>


```


##### output

```
4.1#&[FW\/J`=B1UT'
2.3&$4.#
2.3"12.#
2/!
2.1DR'>#
4.3!$,;+[?<?Y%)Q8)
2.6!1D">#
2.^^6%N#
2.^^^^6#.H4T5!4G?!
2.^^^^6#.H4TF!1V/!
2.^^^^6#.H4V4F%G?!
5;X1
2.^^6%N#
2.^^^^6".GT"EB2%^Y&6&"5CS5V"?!
2.^^^^6".JQ5C1>WTB"5E_!
2.^^^^6".I25D14G?!
5;X1
2.^^6%N#
2.^^^^6".H24F%D^QTT25AS14.ZTQV"7F41?!
2.^^^^6".I%A4AS5QT^X3!4B_!
2.^^^^6".JR7#1T_!
5;X1
2.^^6%N#
2.^^^^6".HUDEV.YA4B"4/!
2.^^^^6".L$T!4B.ZR4B"4/!
2.^^^^6".GV5V%C1?!
5;X1
2.^^6%N#
2.^^^^6".IUT!4B.\EA2#4B_!
2.^^^^6".IB4"4NX"4DB6&/!
2.^^^^6".LZ?!
5;X1
2.^^6%N#
2.^^^^6".JA62S#4B^X!1QS&5^]34B1R4$!5E_!
2.^^^^6".MTUS#>\A4DA465C?!
2.^^^^6".H14A2!?!
5;X1
2.^^6%N#
2.^^^^6".JQ2Q7GC4C>WT#424F!5C>\#64C6#?!
2.^^^^6".I34VA4DC>\$VB4$#?!
2.^^^^6".IV!4'?!
5;X1
2/!
2/!
2/!

```


## Conclusion
We have a compression ratio of .92 so far
