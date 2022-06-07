# 클래스와 객체

    캡슐화: 객체를 캡슐로 싸서 내부를 보호하고 볼 수 없게 하는 것으로 객체의 가장 기본적인 특징이다.
클래스라는 캡슐을 사용하며, 필드(멤버변수)와 메소드(멤버함수)로 구성된다.

## 클래스

클래스는 객체를 만들어내기 위한 설계도 혹은 틀이며, 클래스 모양 그대로 생성된 실체가 객체이다. 이에 따라 객체를 클래스의 인스턴스라고도 부른다.

### 클래스 구성

    public class Human{
        public int age; // 사람 나이 필드
        public String name; // 사람 이름 필드

        public Human(){ // 사람 생성자 메소드
        }
        public int getAge(){ // 사람 나이 메소드
            return age;
        }
    }

### new 연산자와 객체생성

    public static void main (Strings args[]){
        Human KJ; // 래퍼런스 변수 pizza 선언
        KJ = new Human(); // Human 객체 생성
        /* Human KJ = new Human(); 래퍼런스 변수 선언과 객체 생성 동시에 실행 */

        KJ.age = 20; // age 필드에 20 저장
        KJ.name = "박관준"; // name 필드에 "박관준" 저장
        int age = KJ.getAge();
    }

### 객체 멤버 접근

객체 멤버에 접근할 때는 다음과 같이 래퍼런스 변수 뒤에 점(.) 연산자를 붙인다.

    KJ.age = 20;
    int age = KJ.getAge();

## 생성자

객체가 생성될 때 객체의 초기화를 위해 실행되는 클래스의 이름과 동일한 메소드

    public class Human{
        int age;
        String name;

        public Human(){ // 매개변수가 없는 생성자
            age = 0;
            name = "김민수"; // 필드 초기화 기능
        }

        public Human(ing a, String n){ // 매개변수를 가진 생성자
            age = a;
            n = name; // 매개변수로 필드 초기화 기능
        }

        pubilc static void main(Strings args[]){
            Human KJ = new Human(20, "박관준"); // 매개변수로 필드 초기화
            System.out.println(KJ.name + "의 나이는" + KJ.age); // 박관준의 나이는 20

            Human MS = new Human(); // 필드 초기화
            System.out.println(MS.name + "의 나이는" + MS.age); // 김민수의 나이는 0
        }
    }

- 생성자는 여러 개 작성(오버로딩) 할 수 있다.
- 생성자는 new를 통해 객체를 생성할 때 한 번만 호출된다.
- 생성자에 리턴 타입을 지정할 수 없다. 하지만 return문은 사용할 수 있다.
- 생성자의 목적은 객체가 생성될 때, 필요한 초기작업을 위함이다.

### 기본생성자

매개변수와 실행코드가 없어 아무 일도 하지 않고 단순 리턴하는 생성자이다. 디폴트 생성자라고도 부른다. 클래스에 생성자가 하나도 존재하지 않을 때 자바 컴파일러에 의해 자동으로 삽입된다.

## this 래퍼런스

this는 현재 객체 자신에 대한 레퍼런스이다. 보다 정확히 말하면 현재 실행되고 있는 메소드가 속한 객체에 대한 레퍼런스이다.

    public class Circle{
        int radius // 멤버
        public Circle(int radius){
            this.radius = radius; // 멤버 radius에 매개변수 radius를 대입
        }
    }

## this( ) 로 다른 생성자 호출

this( )는 클래스 내에서 생성자가 다른 생성자를 호출할 때 사용하는 자바코드이다.

    public class Human{
        int age;
        String name;

        public Human(int age, String name){
            this.age = age;
            this.name = name;
        }

        public Human(int age){
            this(age, "김민수"); // 생성자 Human(int age, String name) 호출함
        }

        public Human(){
            this(0, "김민수"); // 생성자 Human(int age, String name) 호출함
        }
    }

- this( )는 반드시 생성자의 첫 번째 문장이 되어야 한다.
- this( )는 반드시 같은 클래스 내 다른 생성자를 호출할 때 사용된다.