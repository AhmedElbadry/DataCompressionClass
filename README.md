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

6.1#&[FW\/J`=B1UT<H5B1UT<H5A5%4<HDH5)]2H<H5A!SWCOHGXO"#-&YZV5"#-&WZXXV53WZXXXXV5)W>0.1"/:YZXXXXV5)W>0/5"$5YZXXXXV5)W>06/53:YZXXYZXXV53WZXXXXV5%W<-'3&%4XA655&3,*45&YZXXXXV5%WH"3*"X</%&34YZXXXXV5%WB&3."/:YZXXYZXXV53WZXXXXV5%W>&/530X$0.&3$*"-XH0$5&;6."YZXXXXV5%WA3"/$*4$0X>)"/(YZXXXXV5%WH&9*$0YZXXYZXXV53WZXXXXV5%W@3/45XC"/%&-YZXXXXV5%WM0-"/%XH&/%&-YZXXXXV5%W<6453*"YZXXYZXXV53WZXXXXV5%WD4-"/%XO3"%*/(YZXXXXV5%WC&-&/X=&//&55YZXXXXV5%WPFYZXXYZXXV53WZXXXXV5%WG"6()*/(X="$$)64XR*/&$&--"34YZXXXXV5%WT04)*XO"//".63*YZXXXXV5%W>"/"%"YZXXYZXXV53WZXXXXV5%WH"(";;*/*X<-*.&/5"3*XM*6/*5*YZXXXXV5%WB*07"//*XM07&--*YZXXXXV5%WD5"-:YZXXYZYZYZY

```


## Conclusion
We have a compression ratio of .76
