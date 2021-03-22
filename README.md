# f09f
###  pronounced fonf; is a simple statically typed language with simple but powerful syntax

#### Include
```c++
include standio;

```
#### Byte
```c++
byte name = 10000000;

```
#### Byte
```c++
byte[] name;
byte name = [10000000, 10000001];

```
#### Char
```c++
char letter = 'A';

```
#### Char
```c++
char[] letter;
char letter = ['A', 'B', 'C'];

```
#### Int
```c++
int number = 4;

```
#### Prec
```c++
prec percent = 3.4;

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
#### Modifiers
```c++
static byte name = 10101010;
static char letter = 'A';
static ptr = 0x494949;

```

