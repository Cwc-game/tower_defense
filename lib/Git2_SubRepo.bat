@echo off
for /D %%G in ("%~dp0*") DO ( 
	cd %%~nxG
	MOVE .git_ .git
	cd..
)
REN "Git_=_Master_=_" "Git_=SubRepo=_"