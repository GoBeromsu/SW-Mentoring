# Webserver 제작

## Web server 구조

1. socket 생성
2. 바인딩 서버 생성
3. 청취 청취
4. 연결 연결
5. 수신 요청 승인-> 승인
6. 전송/수신

### socket 생성

```c
SOCKET WSAAPI socket(
  int af,
  int type,
  int protocol
);

socket(PF_INET,SOCK_STREAM,0);
```

- af : IP 주소 유형
- PF_INET : IPV4
  - SOCK_sTREAM : TCP
- type : 통신 유형

### Binding Server

### 모니터링 수신

### 요청 받기

### 요청 처리 계층 작성
