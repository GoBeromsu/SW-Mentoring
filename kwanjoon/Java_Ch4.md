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

    public static void main (String args[]){
        Human KJ; // 래퍼런스 변수 KJ 선언
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

        pubilc static void main(String args[]){
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

## 객체 배열

    class Circle{
        int radius;
        public Circle(int radius){ // 클래스 Circle의 생성자
            this.radius = radius;
        }

        public static void main(String args[]){
            Circle c[]; // 배열 Circle에 대한 래퍼런스 변수 c 선언
            c = new Circle[5]; // 래퍼런스 배열 생성

            for(int i = 0; i < c.length; i++)
                c[i] = new Circle(i); // 배열의 각 원소 객체 생성
        }
    }

## 메소드 활용

### 메소드 형식

    public int getSum(int i, int j){
        int sum;
        sum = i + j;
        return sum;
    }

- 접근지정자: public
- 리턴타입: int
- 메소드 이름: getSum
- 메소드 인자: i, j

### 인자전달

값에 의한 호출(call-by-value): 호출하는 실인자의 값이 복사되어 메소드의 매개 변수에 전달된다.

1) 기본타입의 값이 전달되는 경우

    호출자가 건네는 값이 매개변수에 복사되어 전달된다.

        public class ValuePassing{
            static void increase(int m){
                m = m + 1;
            }

            public static void main(String args[]){
                int n = 10;
                increase(n); // n의 값이 복사되는 것일뿐 n의 값은 조금도 변하지 않는다.
                System.out.println(n); // 10이 출력된다.
            }
        }

2) 객체가 전달되는 경우

    메소드의 매개변수가 클래스 타입인 경우, 객체가 아니라 객체의 레퍼런스 값이 전달된다.

        public class RefererncePassing{
            static void increase(Circle m){
                m.radius++;
            }

            public static void main(String args[]){
                Circle pizza = new Circle(10);

                increase(pizza); // 매개변수 m은 pizza가 가리키는 객체를 함께 가리키게 된다. 따라서 m.radius 값이 증가하면서 pizza.radius 값 또한 증가하게 된다.

                System.out.println(pizza.radius); // 11이 출력된다.
            }
        }

3) 배열이 전달되는 경우

    배열이 통째로 전달되는 것이 아니라 배열에 대한 레퍼런스만 전달된다.

        public class ArrayPassing{
            static void increase(int array[]){
                for(int i = 0; i < array.length; i++)
                    array i++;
            }

            public static void main(String args[]){
                int a[] = {1,2,3,4,5};

                increase(a); // 매개변수 array는 a가 가리키는 배열을 가리키게 된다. 따라서 배열의 각 원소가 1씩 증가하게 된다.
                
                for(int i = 0; i < a.length; i++)
                    System.out.print(a[i] + " "); // 2 3 4 5 6이 출력된다.
            }
        }

### 메소드 오버로딩

메소드 오버로딩: 한 클래스 내에 이름이 같지만 매개변수의 타입이나 개수가 서로 다른 여러개의 메소드를 중복 작성할 수 있다.

- 메소드 이름이 동일해야 한다.
- 매개변수의 개수나 타입이 서로 달라야 한다.
- 메소드의 리턴타입이나 접근 지정자는 메소드 오버로딩과 관계없다.

        class MethodOverloadingFail{
            public int getSum(int j, int i){
                return i + j;
            }
            public int getSum(int j, int i, int k){ // 오버로딩 성공
                return i + j + k;
            }
            public double getSum(int j, int i){ // 오버로딩 실패, 매개변수의 개수와 타입이 모두 같다.
                return (double)(i + j);
            }
            public double getSum(double j, double i){ // 오버로딩 성공, 매개변수의 타입이 다르다.
                return i + j;
            }
        }

## 가비지

가비지란 자바 응용 프로그램에서 더 이상 사용되지 않게 된 객체나 배열 메모리이다.

    a = new Person("괜준");
    b = new Person("괜춘");

    b = a;

레퍼런스 b는 a가 가리키던 객체를 가리키게 되어 b가 가리키던 객체 Person("괜춘")은 접근이 불가하게 되어 가비지 값이 된다.

### 가비지 컬렉션

가비지 컬렉션: 가용 메모리가 일정 크기 이하로 줄어들면 자동으로 가비지를 회수하여 가용 메모리를 늘린다.

## 접근 지정자

패키지: 디렉터리 혹은 폴더와 같은 개념, 클래스 파일들을 여러 패키지에 분산 관리하는 것이 일반적이다.

### 클래스 접근 지정

다른 클래스에서 이 클래스를 활용할 수 있는지 허용 여부를 지정하는 것으로 말한다.

1) public 클래스: 패키지에 상관없이 다른 어떤 클래스에게도 허용된다.

        public class World{...} // public 클래스
2) 디폴트 클래스(접근 지정자 생략): 같은 패키지 내의 클래스들에게만 사용이 허용된다.

        class Local{...} // 디폴트 클래스

### 멤버 접근 지정

![image](https://user-images.githubusercontent.com/102643841/172561595-5beb8859-0ed5-492a-84c1-10c8972bb316.png)

private -> default(접근 지정자 생략) -> protected -> public 순으로 공개범위가 넓어진다

## static 멤버

교제의 말을 빌리자면 non-static 멤버는 사람이 태어날 때 부터 가지는 눈과 같고, static 멤버는 사람이 태어나기 전부터 있었고 모든 사람이 공유하는 공기와도 같다. 여기서 사람은 객체를 나타낸다.

    class StaticSample{
        int n; // non-static 필드
        void g(){...} // non-static 메소드

        static int m; // static 필드
        static void f(){...} // static 메소드
    }

## final

1) final 클래스

   final이 클래스 이름 앞에 사용되면 클래스를 상속받을 수 없음을 지정한다.

        final class FinalClass{ // 이 클래스는 상속 불가
        ...
        }
        class Subclass extends FinalClass{ // 컴파일 오류 발생. FinalClass 상석불가
        ...
        }

2) final 메소드

    final로 메소드를 선언하면 오버라이딩할 수 없는 메소드임을 선언한다.

    (자식 클래스가 부모 클래스의 특정 메소드를 오버라이딩하지 못하게 하고 무조건 상속받아 사용하도록 하고자 한다면 다음과 같이 final로 지정하면 된다.)

        public class SuperClass{
            protected final int finalMethod(){...} // finalMethod()는 자식이 오버라이딩 불가
        }
        class SubClass extends SuperClass{
            protected int finalMethod(){...} // 컴파일 오류, finalMethod는 자식이 오버라이딩 불가
        }

3) final 필드

   1) final로 필드를 선언하면 필드는 상수가 된다

            public class FinalFieldClass{
                final int ROWS = 10; // 상수 선언, 초깃값(10) 지정
                void f(){
                    int intArray[] = new int[ROWS]; // 상수 활용
                    ROWS = 30; // 컴파일 오류, final 필드 값은 변경할 수 없다.
                }
            }

   2) final 키워드를 public static과 함께 선언하면, 프로그램 전체에서 사용할 수 있는 상수가 된다.

            class SharedClass{
                public static final double PI = 3.14;
            }
            /* C에서 #define PI 3.14 와 같은 기능인거 같다. 하지만 다른 클래스 에서는 SharedClass.PI 로 사용할 수 있다. */
