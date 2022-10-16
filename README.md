# f09f
###  pronounced fonf; is a simple statically typed language with simple but powerful syntax

<img src="https://github.com/JakeRoggenbuck/f09f/blob/main/f09f.png?raw=true" alt="f09f"/>

#### Include
```c++
include standio;

```
#### Byte
```c++
byte name = 10000000;

```
#### Byte array
```c++
byte[] name;
byte name = [10000000, 10000001];

```
#### Char
```c++
char letter = 'A';

```
#### Char array
```c++
char[] letter;
char letter = ['A', 'B', 'C'];

```
#### Int
```c++
int number = 4;

```
#### Int array
```c++
int[] numbers;
int numbers = [2, 5, 4];

```
#### Prec
```c++
prec percent = 3.4;

```
#### Prec array
```c++
prec[] precise_numbers;
prec precise_numbers = [3.14, 2.71828, 4.222];

```
#### Ptr
```c++
ptr my_variable = 0x494949;

```
#### String
```c++
string name = "Jake";

```
#### Bool
```c++
isRunning = True;

```
#### If
```c++
if (num > 0) {
	~ do thing ~
}

```
#### Else if
```c++
if (name == "Jake") {
	~ do thing ~
} else {
	~ do other things ~
}

```
#### If
```c++
if (val < physics.gravity) {
	~ val is less than gravity ~
} else if (val < physics.gravity / 2) {
	~ val is less than half gravity ~
} else {
	~ val is greater than gravity ~
}

```
#### Function
```c++
function foo (int age, int height) returns string {
	return(age ^ height);
}

```
#### Return
```c++
return(4);

```
#### Entry
```c++
while () {
	~ Looped code ~
}

```
#### Exit
```c++
do {
	~ Looped code ~
} while still ();

```
#### For
```c++
loop for item in array {
	~ Looped code ~
}

```
#### Classes
```c++
class Lang (string name) {
  	~ constructor ~
	self.name = name;
} : Main {
	~ main body ~
	function hello_lang () returns string {
		return("Hello " + self.name());
	}
}

```
#### Static
```c++
static byte name = 10101010;
static char letter = 'A';
static ptr = 0x494949;

```
#### Burn
```c++
burn string name = "Jake";

```

