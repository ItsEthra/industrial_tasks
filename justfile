generate:
	cmake -S . -B out
	
run WEEK: generate
	make week{{WEEK}} -C out
	exec out/week{{WEEK}}

