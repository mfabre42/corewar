.name "lbich le conquerant"
.comment "j'ai eu un degat des eaux"

aff: ld %82,r2
	aff r2
	ld %69,r2
	aff r2
	ld %75,r2
	aff r2
	ld %84,r2
	aff r2
	ld %32,r2
	aff r2
	ld %90,r2
	aff r2
	ld %79,r2
	aff r2
	ld %82,r2
	aff r2
	ld %75,r2
	aff r2
	ld %32,r2
	aff r2
	and r3, r4, r5
	sti r1, %:live, %1

live:	live %1
		zjmp %480
