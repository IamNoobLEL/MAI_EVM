BEGIN {
	FS = "," 
	k = 0 
}

{
	if ($6 = "Single Player" && $17 > 75 && $18 = "Strong" && $5 != "null") { 
		k++
		print $2 " " $3 " " $5 
	}
}

END {
	print k
}
