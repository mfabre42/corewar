.name "lbich"
.comment "j'ai eu un degat des eaux"

sti:	sti r1, %:livi, %1
		and r4, %0, r3

livi:		live %1

live:	zjmp %:livi
