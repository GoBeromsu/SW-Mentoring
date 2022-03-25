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
   - 알고리즘 문제 풀이시 입출력을 해야하는데 이 때 편의를 위해서 설정하는겁니다
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
