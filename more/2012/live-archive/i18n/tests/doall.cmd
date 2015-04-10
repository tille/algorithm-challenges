@echo off
for %%i in (??.t) do (
  copy %%i ?? >nul
)
for %%i in (*.java) do (
  call javac %%i
)
for %%i in (??.1) do (
  call java -cp . gen1 %%i %%~ni
)

call java -cp . gen2 words.txt 11
call java -cp . gen3 words.txt 12

call java -cp . randwords 1000 randwords.out
call java -cp . gen2 randwords.out 14
call java -cp . gen3 randwords.out 15
del randwords.out >nul
