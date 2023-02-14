gen: 
	cmake -S . -B out
	
run WEEK: gen
	make week{{WEEK}} -C out
	exec out/week{{WEEK}}

