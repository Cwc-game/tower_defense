@echo off
for /D %%G in ("%~dp0*") DO ( 
	cd %%~nxG
	MOVE .git .git_
	cd..
)
REN "Git_=SubRepo=_" "Git_=_Master_=_"