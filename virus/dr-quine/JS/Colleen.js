/*
	First Comment
*/
function Colleen(){console.log("//42")}
function main() {
	/*
		Second Comment
	*/
	return "/*\n\tFirst Comment\n*/\n" + Colleen.toString()+ "\n" + main.toString() + "\nconsole.log(main());\nColleen()";
}
console.log(main());
Colleen()
//42
