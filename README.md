# SW-Mentoring

## TIL(Today I learend)

- 전공 관련이라면 무엇이든 어떤 주제든 상관 없다
- 최소 일주일의 3회 이상 Commit 한다.

### TIL 양식

- 공부한 내용만 명확하게 드러난다면 양식은 상관 없습니다.

#### Basic

```md
# [Title]

- Title은 오늘 배운 것의 주제를 짧게 적습니다

## [Findings]

- 공부한 것 위주로 정리합니다.
- 새로 알게된 내용
- 배운 것의 원리
- 참조한 레퍼런스 등등

## [Retrospective]

- 오늘 배우면서 느꼈던 점, 보완할 점을 기술합니다.
```

#### Algorithm

```md
# [문제 번호] [문제 이름]

## [간략한 문제 요약]

- 설명

## [풀이]

- 설명
```

## Init Setup

일단 [Github Client](https://desktop.github.com/)와 [Vscode](https://code.visualstudio.com/download)를 다운로드 받습니다.

### Visual Studio Code (vscode)

1. 확장 `Ctrl + Shift + x`을 누릅니다.
2. [Code-runner](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner) 검색 후 설치합니다
   ![image](https://user-images.githubusercontent.com/37897508/160076408-5de2f2bb-c3ea-4d50-9241-ff757b769e82.png)
3. 똑같이 Python 확장도 설치합니다
   ![image](https://user-images.githubusercontent.com/37897508/160076360-d02d68a0-b8ca-420c-bf86-12c5d37f32d4.png)
4. 파일 - 기본 설정 - 설정으로 들어가서 coderunner 검색합니다
   - `Ctrl + ,` 누르면 바로 갈 수 있습니다
5. Code-runner: Run In Terminal을 체크합니다
   알고리즘 문제 풀이시 입출력을 해야하는데 이 때 편의를 위해서 설정하는겁니다
   ![image](https://user-images.githubusercontent.com/37897508/160074419-7d4044fd-fb71-4c87-a7aa-30bc6bc77ef9.png)
6. Cod-runner: Excutormap에 들어가 아래 블록 내용을 추가합니다
   ![image](https://user-images.githubusercontent.com/37897508/160076032-c53b1b80-7df2-4e46-ac1d-2ac479068b09.png)

   ```json
   {
   "code-runner.executorMap": {
   "python": "set PYTHONIOENCODING=utf8 && python"
   }
   ```

7. 이제 설치가 끝났으니 임의로 python 파일을 만들어 `Ctrl + Alt + n` 커맨드로 파일을 실행시켜봅시다.

#### Reference

- [vscode에서 code-runner로 python 실행 시키기](https://codesyun.tistory.com/133)
- [vscode 처음 설치 후 설정 할 것들](https://www.crocus.co.kr/1469)

### Github Client

1. 멘토의 repository의 [SW-Mentoring](https://github.com/GoBeromsu/SW-Mentoring)에 들어가 fork를 클릭합니다.

   ![image](https://user-images.githubusercontent.com/37897508/160079746-269f4d9f-510f-45e4-94ca-1bb736555c2d.png)

   - 이제 자신의 깃허브 저장소(repository)로 돌아가면 fork 된 저장소가 뜹니다.

2. 자신의 깃허브 저장소의 url을 복사합니다.

   ![image](https://user-images.githubusercontent.com/37897508/160078167-c0276a91-2025-4981-89f1-636d821a28d8.png)

3. Github Desktop을 실행 후 `Ctrl + shift + O`를 누르고 복사한 URL을 입력하고 clone 합니다.
   - 단축키 대신 File - Clone a repository로 직접 찾아도 됩니다
     ![image](https://user-images.githubusercontent.com/37897508/160078931-fcdd58a9-38d0-4f99-a40b-e61783644b79.png)
   - clone 하기 자신의 PC 어디에 repository를 저장했는지 기억합시다

### Vscode로 clone한 저장소 다루기

1. 자신의 PC에서 Clone한 저장소 폴더에서 오른쪽 마우스 클릭 후 vscode를 실행시킵니다.
   ![image](https://user-images.githubusercontent.com/37897508/160080889-28f138b9-ff21-47d6-b18d-308879abae10.png)
2. 파일 탐색기(왼쪽 탭에서 파일들 많이 보이는 사각형)에서 오른쪽 마우스 클릭 후 임의로 새 파일을 만듭니다.
   - ![image](https://user-images.githubusercontent.com/37897508/160081349-7e0b8fc7-9b0d-4f95-aa07-87c7deb1b5f6.png)
   - 저는 test.py를 만들었습니다
     ![image](https://user-images.githubusercontent.com/37897508/160081796-101522fa-463c-4cf3-8c69-f7299c636133.png)
3. Github Desktop을 실행시킨 후 왼쪽 하단에 Summery (required)에 commit message를 작성하고 Commit to main 클릭합시다
   ![image](https://user-images.githubusercontent.com/37897508/160082123-b5023031-0dd8-4743-94cb-1d636095c414.png)
4. 오른쪽 상단의 fetch origin이 Push origin으로 바뀌었습니다. 클릭해주세요
5. 이제 끝났습니다. 자신의 깃허브 홈페이지에 들어가서 파일이 잘 올라가졌나 확인해봅시다
   - 아까 만든 test.py가 잘 올라가졌음을 알 수 있습니다
    ![image](https://user-images.githubusercontent.com/37897508/160082732-f857a135-a4b7-453a-84a5-78ac8f2f7833.png)
