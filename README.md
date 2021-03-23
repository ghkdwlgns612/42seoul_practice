# 42seoul_practice

Exercise 00 : Z

- 설명 X

Exercise 01 : testShell00

- touch -t 202106012342 [파일명]
- chmod 4(r--) 5(r-x) 5(r-x) user group others


Exercise 02 : Oh yeah, mooore...

- soft link : ln -s [소스파일] [새로만들파일] --> 바로가기랑 비슷함. 소스 파일 내용은 바뀌지 않음.
- hard link : ln [소스파일] [새로만들파일] --> 이건 내용도 다 바뀐다.
- d- : directory
- d------ 2 : link의 갯수


Exercise 03 : Connect me!

- kinit(키 생성), klist(키 출력) 


Exercise 04 : midLS

- 생성일 순서로 ~ : ls -t
- 콤마 생성 : ls -m
- 뒤에 역슬래싀포함 : ls -p


Exercise 05 : GIT commit

- #! bin/bash : bash shell을 사용하겠다고 언급(굳이 않넣어도 됨)
- git log --format="%H" --> img file참조
- -(n) : 최근 n 개의 커밋만 조회한다.



Exercise 06 : gitignore

- 최상위 폴더 .git이 있는 file에 .gitignore 파일을 생성한다.(ls -a 명령으로만 보인다.)
- .gitignore에 git add . 을 사용했을 때 commit 하지 않을 파일들을 적음.
- git ls-files --other(untracking되는 file들을 출력) -ignore(그냥 출력만) --exclude-standard(.gitignore파일의 목록을 제외하는 것)
-->주의사항 : --exclude-standard 앞의 ignore을 빼면 .gitignore파일들만 제외하고 출력함.



Exercise 07 : diff


- 주어진 a 와 sw.diff파일로 b파일을 추적.
- patch를 이용하여 patch a sw.diff 명령어를 주면 a file에 b의 내용이 생성됨.



Exercise 08 : clean

- find . : 현 디렉토리와 하위 디렉토리 에서 파일을 찾음.
- -name "[찾을것]" : 조건에 맞는 파일이름 찾기.
- -o : 연결해서 조건을 붙임
- delete : 지정된 파일들을 삭제.


