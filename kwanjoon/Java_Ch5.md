# 상속

## 상속의 개념

객체 지향에서 상속은 부모 클래스에 만들어진 필드와 메소드를 자식 클래스가 물려 받는 것이다. 상속은 코드 중복을 제거하여 클래스를 간결하게 구현할 수 있다.

## 클래스 상속과 객체

자바에서는 부모 클래스를 super class, 상속받는 자식 클래스를 sub class라고 부르며, 상속을 선언할 때 확장한다는 뜻을 가진 extends 키워드를 사용한다.

    public class Person{
       ...
    }
    public class Student extends Person{ // Person을 상속받는 클래스 Student 선언
        ...
    public class StudentWorker extends Student{ // Student를 상속받는 클래스 StudentWorker 선언
        ...
    }

### 상속과 객체

    class Point{
        private int x, y; // 한 점을 구성하는 x, y 좌표
        public void set(int x, int y){
            this.x = x, this.y = y;
        }
        public void showPoint(){ // 점의 좌표 출력
            System.out.println("(" + x + "," + y + ")");
        }
    }

    class ColorPoint extends Point{ // Point를 상속
        private String color; // 점의 색
        public void setColor(String color){
            this.color = color;
        }
        public void showColorPoint(){ // 컬러 점의 좌표 출력
            System.out.print(color);
            showPoint(); // Point 클래스의 showPoint() 호출
        }
    }

    public class ColorPointEx{
        public static void main(String args[]){
            Point p = new Point(); // Point 객체 생성
            p.set(1,2); // Point 클래스의 set() 호출
            p.showPoint();

            ColorPoint cp = new ColorPoint(); // ColorPoint 객체 생성
            cp.set(3,4); // Point 클래스의 set() 호출
            cp.setColor("red"); // ColorPoint 클래스의 setColor() 호출
            cp.showColorPoint();
        }
    }
    /* 실행결과:
        (1,2)
        red(3,4) */

- 상속 선언
- 서브 클래스 객체 생성
- 서브 클래스 객체 활용
  
  ColorPointEx 클래스의 main() 메소드에서는 cp 객체를 구성하는 ColorPoint 클래스의 public 멤버와 슈퍼 클래스인 Point 클래스의 public 멤버를 모두 접근할 수 있다. 그러나 x, y, color 필드는 private 속성이어서 접근할 수 없다.

        cp.x = 10; // private 멤버 x 접근불가
        cp.color = "red"; // private 멤버 color 접근 불가

- 서브 클래스에서 슈퍼 클래서 멤버 접근
  
### 자바 상속의 특징

- 자바에서는 클래스의 다중 상속을 지원하지 않는다.
- 자바에서는 상속의 횟수에 제한을 두지 않는다.
- 자바에서 계층 구조의 최상위에 java.lang.Object 클래스가 있다.

## 상속과 생성자

### 서브 클래스와 슈퍼 클래스의 생성자 호출 및 실행

- 서브 클래스와 슈퍼 클래스는 각각 생성자를 가지고 있다.
- 서브 클래스 객체가 생성될 때 서브 클래스의 생성자와 슈퍼 클래스의 생성자가 모두 실행된다.
- 순서는 슈퍼 클래스의 생성자가 먼저 실행된 후 서브 클래스의 생성자가 실행된다.

        class A{
            public A(){
                System.out.println("생성자 A"); // 슈퍼 클래스의 생성자가 제일 먼저 실행된다.
            }
        }
        class B extends A{
            public B(){
                System.out.println("생성자 B"); // 서브 클래스의 생성자는 나중에 실행된다.
            }
        }
        public class ConstructorEx{
            public static void main(String args[]){
                B b = new B();
            }
        }
        /* 실행결과:
            생성자 A
            생성자 B */

### 서브 클래스에서 슈퍼 클래스 생성자 선택

- 원칙적으로 서브 클래스의 개발자가 서브 클래스의 각 생성자에 대해 함께 실행될 슈퍼 클래스의 생성자를 지정한다.

- 개발자가 슈퍼 클래스의 생성자를 명시적으로 지정하지 않는 경우 컴파일러는 자동으로 슈퍼 클래스의 기본 생성자를 호출하도록 컴파일 한다.

          class A{
            public A(int x){ // 기본생성자 A()가 없다.
                System.out.println("생성자 A"); 
            }
        }
        class B extends A{
            public B(){ // B()에 대한 짝, A()를 찾을 수 없어 오류 발생
                System.out.println("생성자 B");
            }
        }
        public class ConstructorEx{
            public static void main(String args[]){
                B b = new B();
            }
        }

- 슈퍼클래스의 매개변수를 가진 생성자를 호출하는 경우도 있다.

        class A{
            public A(){
                System.out.println("생성자A");
            }
            public A(int x){
                System.out.println("매개변수생성자A");
            }
        }
        class B extends A{
            public B(){
                System.out.println("생성자B");
            }
            public B(int x){ // 기본생성자 A()를 호출
                System.out.println("매개변수생성자B");
            }
        }
        public class ConstructorEx{
            public static void main(String args[]){
                B b = b new B(5); // 생성자 B(int x)를 호출
            }
        }
        /* 실행결과:
            생성자A
            매개변수생성자B */

### super( )를 이용하여 명시적으로 슈퍼클래스의 생성자 선택

super( )는 반드시 생성자의 첫 라인에 사용되어아 한다.

    class A{
        public A(){
            System.out.println("생성자A");
        }
        public A(int x){
            System.out.println("매개변수생성자" + x);
        }
    }
    class B extends A{
        public B(){
            System.out.println("생성자B");
        }
        public B(int x){
            super(x); // 생성자 A(int x) 호출
            System.out.println("매개변수생성자B" + x);
        }
    }
    public class ConstructorEx{
        public static void main(String Args[]){
            B b = new B(5);
        }
    }
    /* 실행결과:
        매개변수생성자A5
        매개변수생성자B5 */

## 업캐스팅과 instanceof 연산자

캐스팅이란 '타입 변환'을 말한다. 자바에서 클래스에 대한 캐스팅(casting)은 업캐스팅과 다운캐스팅으로 나뉜다.

### 업캐스팅(upcasting)

업캐스팅: 서브 클래스의 객체에 대한 레퍼런스를 슈퍼 클래스 타입으로 변환하는 것을 업캐스팅이라고 한다. 업캐스팅은 슈퍼 클래스의 레퍼런스로 서브 를래스의 객체를 가리키게 한다.

    class Person{
        String name;
        String id;

        public Person(String name){
            this.name = name;
        }
    }
    class Student extends Person{
        String grade;
        String department;

        public Student(String name){
            super(name);
        }
    }
    public class UpcastingEx{
        public static void main(String Args[]){
            Person p; // 레퍼런스 변수 p 선언
            Student s = new Student("박관준"); // Student 객체 s 생성
            p = s; // 업캐스팅

            System.out.println(p.name); // s.name도 같은 것을 출력
        }
    }
    /* 실행결과:
        박관준 */

- 업캐스팅을 통해 Peroson 타입의 p는 Student 객체를 가리킨다.
- 래퍼런스 p로는 Person 클래스의 멤버만 접근할 수 있다.

        p.grade = "A" // 컴파일 오류
        p.department = "Com" // 컴파일 오류

### 다운캐스팅(downcasting)

다운캐스팅: 슈퍼 클래스의 객체에 대한 레퍼런스를 서브 클래스 타입으로 변환하는 것을 다운캐스팅이라고 한다. 다운캐스팅은 서브 클래스의 레퍼런스로 슈퍼 를래스의 객체를 가리키게 한다.

    public class DowncastingEx{
        public static void main(String args[]){
            Person p = new Student("박관준"); // 업캐스팅

            Student s;
            s = (Student)p; // 다운캐스팅, (Student)의 타입변환을 반드시 표기

            System.out.println(s.name);
            s.grade = "A"; // 오류 없음
        }
    }
    /* 실행결과:
        박관준 */

### 업캐스팅과 instanceof 연산자

    Person p = new Person();
    Person p = new Student(); // 업캐스팅
    Person p = new Researcher(); // 업캐스팅
    Person p = new Professor(); // 업캐스팅

Person 클래스를 상속받은 객체들을 업캐스팅을 통해 Person 클래스의 레퍼런스 p로 가리킨다. 그렇다면 Person 타입의 레퍼런스 p가 있을 때, p가 Person 객체를 가리키는지 Student 객체를 가리키는지, Researcher 객체를 가리키는지, Professor 객체를 가리키는지 알 수 없다.

#### instanceof 연산자

    /* 레퍼런스 instanceof 클래스명 */
    Person jee = new Student();
    Person kin = new Professor();
    Person lee = new Researcher();
    if(jee instanceof Person) // jee는 Person 타입이므로 true
    if(jee instanceof Student) // jee Student 타입이므로 true
    if(kim instanceof Student) // kim은 Student 타입이 아니므로 false

- instanceof는 클래스에만 적용된다.

## 메소드 오버라이딩

메소드 오버라이딩: 슈퍼 클래스와 서브 클래스의 메소드 사이에 발생하는 관계로서, 슈퍼 클래스에 선언된 메소드와 같은 이름, 같은 리턴 타입, 같은 매개 변수 리스트를 갖는 메소드를 서브 클래스에서 재작성 하는 것이다.

메소드 오버리아딩은 '슈퍼 클래스 메소드 무시하기 혹은 덮어쓰기'로 표현할 수 있다.

    class Shape{
        public void draw(){
            System.out.println("Shape");
        }
    }
    class Line extends Shape{
        public void draw(){ // 오버라이딩
            System.out.println("Line");
        }
    }
    class Circle extends Shape{
        public void draw(){ // 오버라이딩
            System.out.println("Circle");
        }
    }

### 동적 바인딩

동적 바인딩: 슈퍼 클래스의 메소드를 무시하고 서브 클래스에서 오버라이딩된 메소드가 무조건 실행되도록 하는 것.

### 서브 클래스 레퍼런스로 오버라이딩된 메소드 호출

    public class OverridingEx1{
        public staitc void main(String args[]){
            Line line = new Line();
            line.draw(); // Line class의 draw()가 호출된다.
        }
    }

### 업캐스팅에 의해 슈퍼 클래스 레퍼런스로 오버라이딩된 메소드 호출

    public class OverridingEx2{
        public static void main(String Args[]){
            Shape shape = new Line(); // 업캐스팅
            shape.draw(); // Line class의 draw()가 호출된다.(동적 바인딩)
        }
    }

### 오버라이딩의 목적, 다형성 실현

오버라이딩은 상속을 통해 '하나의 인터페이스에 서로 다른 내용 구현' 이라는 객체 지향의 다형성을 실현하는 도구이다.

### 메소드 오버라이딩의 제약 사항

- 슈퍼 클래스의 메소드와 동일한 원형으로 작성한다. (동일한 이름, 매개변수 타입과 개수, 동일한 리턴 타입)
- 슈퍼 클래스 메소드의 접근 지정자보다 접근의 범위를 좁혀 오버라이딩 할 수 없다.
- static이나 private 또는 final로 선언된 메소드는 서브 클래스에서 오버라이딩할 수 없다.

## 추상 클래스

### 추상 메소드(abstract method)

추상 메소드: 선언은 되어 있으나 코드가 구현되어 있지 않은, 즉 껍데기만 있는 메소드이다.

추상 메소드를 작성하려면 abstract 키워드와 함께 원형만 선언하고 코드는 작성하지 않는다.

    public abstract String getName();
    public abstract void setName(String s);

    public abstract String fail(){return "Good Bye"}; // 컴파일 오류, 코드가 작성되어 있기 때문에 추상 메소드가 될 수 없다.

### 추상클래스 만들기

- 추상 메소드를 포함하는 클래스

        abstract class Shape{ // 추상 클래스 선언
            public shape(){}
            public void paint(){draw();}
            abstract pubilc void draw(); // 추상 메소드 선언
        }

- 추상 메소드는 없지만 abstract로 선언한 클래스

        abstract class MyComponent{ // 추상 클래스 선언
            String name;
            public void load(String name){
                this.name = name;
            }
        }

- 추상 메소드를 가지고 있으면 반드시 추상 클래스로 선언

        class Fault{ // 오류, 추상 클래스로 선언되지 않았음.
            abstract public void f(); // 추상 메소드
        }

- 추상 클래스는 객체를 생성할 수 없다.

        public class AbstractError{
            public static void main(String args[]){
                Shape shape;
                shape = new shape(); // 컴파일 오류, Shape는 추상 클래스
            }
        }

### 추상 클래스의 상속

    abstract class Shape{ // 추상 클래스
        public shape(){}
        public void paint(){draw();}
        abstract public void draw(); // 추상 메소드
    }
    abstract class Line extends Shape{ // 추상 클래스, draw()를 상속 받기 때문
        public String toString{return "Line";}
    }

- 서브 클래스에 abstract를 붙여 추상 클래스임을 명시해야 한다.
- 추상 클래스 Shape를 상속받는 Line 클래스에서 추상 메소드인 draw()를 오버라이딩하지 않으면 자동으로 추상 클래스가 된다.

### 추상 클래스의 구현과 목적

- 추상 클래스의 구현이란, 슈퍼 클래스에서 선언된 모든 추상 메소드를 서브 클래스에서 오버라이딩하여 실행 가능한 코드로 구현하는 것을 말한다.
- 추상 클래스는 추상 메소드를 통해 서브 클래스가 구현할 메소드를 목적에 맞게 구현하는 다형성을 실현할 수 있다.
- 추상 클래스는 계층적 상속 관계를 가지는 클래스들의 구조를 만들 때 적합하다.

        abstract class Calculator{
            public abstract int add(int a, int b); // 두 정수의 합
            pubilc abstract int subtract(int a, int b); // 두 정수의 차
            public abstract double average(int a[]); // 정수들의 평균값
        }
        public class GoodCalc extends Calculator{
            @Override
            public int add(int a, int b){ // 추상 메소드 구현
                return a + b;
            }
            @Override
            public int subtract(int a, int b){ // 추상 메소드 구현
                return a - b;
            }
            @Override
            public double average(int a[]){
                double sum = 0;
                for(int i = 0; i < a.length; i++)
                    sum += a[i];
                return sum/a.length;
            }
            pubilc static void main(String args[]){ // 추상 메소드 구현
                GoodCalc c = new GoodCalc();
                System.out.println(c.add(2,3));
                System.out.println(c.subtract(2,3));
                System.out.println(c.average(new int[]{2,3,4}));
            }
        }
        /* 실행결과:
            5
            -1
            3.0 */

## 인터페이스

인터페이스: 서로 다른 하드웨어 장치들이 상호 데이터를 주고받을 수 있는 규격을 의미한다.

### 인터페이스 구성

- 상수와 추상메소드
- default 메소드
- private 메소드
- static 메소드

### Java의 인터페이스

    interface PhoneInterface{ // 인터페이스 선언
        public static final int TIMEOUT = 10000; // 상수 필드
        public abstract void sendCall(); // 추상 메소드
        public abstract void receiveCall(); // 추상 메소드
        public default void printLogo(){ // default 메소드
            System.out.println("** Phone **");
        }
    }

- 인터페이스는 필드(멤버 변수)를 만들 수 없다.
- 인터페이스는 객체를 생성할 수 없다.

        new PhoneInterface(); // 오류
- 인터페이스 타입의 레퍼런스 변수는 선언 가능하다.

        PhoneInterface galaxy; // galaxy는 인터페이스에 대한 레퍼런스 변수
- 인터페이스끼리 상속된다.
- 인터페이스를 상속받아 클래스를 작성하면 인터페이스의 모든 추상 메소드를 구현하여야 한다.

### 인터페이스 구현

인터페이스 구현이란 implements 키워드를 사용하여 인터페이스의 모든 추상 메소드를 구현한 클래스를 작성하는 것을 말한다.

        class SamsungPhone implements PhoneInterface{ // 인터페이스 구현
        /* PhoneInterface의 모든 추상 메소드 구현 */
            public void sendCall(){System.out.println("Ring ring");}
            public void receiveCall(){System.out.println("전화가 왔습니다.");}

        /* 메소드 추가 작성 */
            pubilc void flash(){System.out.println("전화기에 불이 켜졌습니다.");}
        }

        public class InterfaceEx{
            public static void main(String args[]){
                SamsungPhone phone = new SamsungPhone();
                phone.printLogo();
                phone.sendCall();
                phone.receiveCall();
                phone.flash();
            }
        }
        
    /* 실행결과:
        ** Phone **
        Ring ring
        전화가 왔습니다.
        전화기에 불이 켜졌습니다. */

### 인터페이스 상속

클래스는 인터페이스를 상속받을 수 없고, 인터페이스끼리만 상속이 가능하다. 상속을 통해 기존 인터페이스에 새로운 규격을 추가한 새로운 인터페이스를 만들 수 있으며, 인터페이스의 상속은 extends 키워드를 사용한다.(자바는 인터페이스의 다중상속을 허용한다.)

    interface MobilePhoneInterface extends PhoneInterface{
        void sendSMS(); // 추상 메소드
        void receiveSMS(); // 추상 메소드
    }

### 다중 인터페이스 구현

    interface AIInterface{
        void recognizeSpeech(); // 음성 인식
        void synthesizeSpeech(); // 음성 합성
    }
    class AIPhone implements MobilePhoneInterface, AIInterface{ // 인터페이스 구현
    /* MobilePhoneInterface의 모든 메소드를 구현한다.
        public void sendCall(){...}
        public void receiveCall(){...}
        public void sendSMS(){...}
        public void receiveSMS(){...}

    /* AIInterface의 모든 메소드를 구현한다.
        public void recognizeSpeech(){...} // 음성 인식
        public void systhesizeSpeech(){...} // 음성 합성
    
    /* 추가적으로 다른 메소드들을 작성 */
        public int touch(){...}
    }

- 각 인터페이스에 선언된 모든 추상 메소드를 구현하여야 한다.

### 인터페이스와 추상 클래스 비교

#### 유사점

- 객체를 생성할 수 없고, 상속을 위한 슈퍼 클래스로만 사용된다.
- 클래스의 다형성을 실현하기 위한 목적이다.

#### 차이점

추상 클래스: 추상 메소드와 일반 메소드 모두 포함. 상수, 변수 필드 포함

인터페이스: 변수 필드(멤버 변수)는 포함되지 않음. 다중 상속 지원