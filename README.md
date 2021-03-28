# 42seoul_practice

Exercise 00 : Z

- 설명 X

Exercise 01 : testShell00

- touch -t 202106012342 [파일명]
- chmod 4(r--) 5(r-x) 5(r-x) user group others
- mkfile 40 하면 40바이트 파일 생성
- tar -cf(create file)


Exercise 02 : Oh yeah, mooore...

- soft link : ln -s [소스파일] [새로만들파일] --> 바로가기 아이콘 생성. 소스 파일 내용은 바뀌지 않음.
- hard link : ln [소스파일] [새로만들파일] --> 이건 내용도 다 바뀐다.
- d- : directory
- d------ 2 : link의 갯수



Exercise 03 : Connect me!

- kinit(키 생성), klist(키 출력) 
- kinit -p your_principal



Exercise 04 : midLS

- 생성일 순서로 ~ : ls -t
- 콤마 생성 : ls -m
- 뒤에 역슬래싀포함 : ls -p

U를 왜 넣었을까? U는 생성 날짜 순 정렬인데 t를 이용하여 시간 순으로 정렬해준다.

Exercise 05 : GIT commit

- #! bin/bash : bash shell을 사용하겠다고 언급(굳이 않넣어도 됨)
- git log --pretty="%H" --> img file참조, pretty는 개행을 연속적으로 해주는 것.
- -(n) : 최근 n 개의 커밋만 조회한다.



Exercise 06 : gitignore

- 최상위 폴더 .git이 있는 file에 .gitignore 파일을 생성한다.(ls -a 명령으로만 보인다.)
- .gitignore에 git add . 을 사용했을 때 commit 하지 않을 파일들을 적음.
- git ls-files --other(untracking되는 file들을 출력) -ignore(그냥 출력만) --exclude-standard(.gitignore파일의 목록을 제외하는 것)
-->주의사항 : --exclude-standard 앞의 ignore을 빼면 .gitignore파일들만 제외하고 출력함.



Exercise 07 : diff

- patch -o b [source_file] >> [diff_file]
- 주어진 a 와 sw.diff파일로 b파일을 추적.
- patch를 이용하여 patch a sw.diff 명령어를 주면 a file에 b의 내용이 생성됨.



Exercise 08 : clean

- find . : 현 디렉토리와 하위 디렉토리 에서 파일을 찾음.
- -name "[찾을것]" : 조건에 맞는 파일이름 찾기.
- -o : 연결해서 조건을 붙임
- delete : 지정된 파일들을 삭제.
- find . -type f \( -name "*~" -o -name "#*#" \) -print -delete


Exercise 09

- 41 string 42 42seoul
 (offset type test message)

위의 문장은 FN개념이다.(whether the file contains certain “magic patterns”)

OFFSET에 있는 특정 BYTE의 값을 비교한다.(a particular offset in the file with a byte value)

비교값은 숫자 또는 문자이다.(a string or a numeric value)

>.예시
 0                 string       '
 MZ>0x18            leshort      >0x3f
 >>(0x3c.l)        string       PE\0\0 PE executable (MS-Windows)
실행문 : file -m [magic_file] [source_file]

ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ


Exercise 01

id -Gn $FT_USER | sed 's/ /,/g' | tr -d '\n'
FT_USER라는 환경변수의 그룹 NAME을 찾아라. ' '을 ','로 치환하고 개행을 없애라.

Exercise 02

find . -type f -name "*.sh" -exec basename -s ".sh" {} \;
현 디렉토리와 하위 디렉토리에서 타입이 파일인 것을 찾고 이름이 .sh로 끝나는 것을 찾아라.
그리고  뒤의 문장들을 -exec(excute) {} \ 실행하라. basename -s ".sh" = 접미사(suffix) .sh를 삭제하라 

Exercise 03

find . | wc -l | tr -d " "
모든 파일과 디렉토리를 찾고 라인의 갯수를 세고 공백을 삭제하라.

Exercise 04

ifconfig -a | grep "ether " | sed 's/.*ether //g' | tr -d ' '

ifconfig -a = MAC에 연결되어있는 모든 네트워크 정보가 뜸.
grep "ether " = ether만 찾아내서 출력
sed 's/.*ether //g' = .*ehter는 .은 문자 *(모든) ether니깐 ether와 함께 앞의 모든 문자 삭제
tr -d ' ' = 공백 삭제

Exercise 05

역 슬래시를 이용하여 파일 생성.
기본으로 개행이 들어가 있기 때문에 : set noendofline binary 입력 필요.

Exercise 06

ls -l | sed -n 'p;n'
목록을 출력하고 sed를 이용하여 입력 다음라인에 공백을 넣는 명령어 사용.
N : Write the pattern space to the standard output if the default output has not been suppressed, and replace the pattern space with the next line of input.
P : Write the pattern space to standard output.

Exercise 07 
cat /etc/passwd | sed '/#/d' | awk '{if (NR%2==0) print}' | sed 's/:.*//' | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | tr '\n' ',' | sed 's/,/, /g' | sed 's/, $/./' | tr -d '\n'

사용자파일불러오기 | 주석 삭제 |  짝수 줄 출력 | :(글자).(한 글자)*(뒤에 전체)를 지우겠다 | 각 행의 글자를 뒤집어줌 | 알파벳 역순정렬 | 기본 출력하라 FT1~FT2사이의 목록들을. |
개행은 쉼표로 바꿔줘라 | ,는 , 로 치환해라  | 마지막 줄 뒤에 붙는 ", %"표시를 마침표로 바꿔라. | 마지막 줄 개행 삭제

Exercise 08

echo $FT_NBR1 + $FT_NBR2 | sed "s/\'/0/g" | tr '\\\"\?\!' 1234 | tr 'mrdoc' 01234 | xargs echo 'obase=13; ibase=5;' | bc | tr 0123456789ABC 'gtaio luSnemf'
FT_NBR1과 FT_NBR2를 더한 것을 출력하고 문제에 나온 문자들을 01234로 치환한다. 그리고 xargs(앞의 명령들을 출력하라.) ibase(input base)=(5진법) obase(output base)=(13진법)으로 출력.bc(계산하라) 뒤의 문장과 같이.
