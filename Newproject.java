class Biswa{
    static int x;
    static void fun1()     /* if your function is not static then you can't call the function or method or operation */
   {
        System.out.println("Also I am Fine");
    }
    static void fun2()  // function-method-operation ----> all are same
    {
        System.out.println("What are the Problem You have Faced");
    }
}
class Newproject{
    static void fun1(){
        System.out.println("I am Fine");
    }
    static void main(){
        System.out.println("How are you Mr. Kishor Kumar");
    }
    public static void main(String Args[]){
        System.out.println("Hello Mr.");
    fun1();   // also you can Write Newproject.fun1(); Don't Confuse about that
    main();  // if we want to call a member of another class then write Classname.Function name or method name();
    Biswa.fun1();   // call the another  class with classname dot function name i.e Biswa.Fun1();
    Biswa.fun2();
    Biswa.x=90;
    System.out.println(Biswa.x);
}
}
// **This is a program of static method call or static functin call ** //
// ** Below We will study about how we can call non static function  which is also called Instance Member variable or object member variable** //
// NOTE :-  IN JAVA CLASS NAME "OBJECT" IS AVILABLE WHEN JAVA CREATED WHICH IS PRE DEFINED CLASS .BUT WE CAN CREATE A CLASS OBJECT1 2 3 4 ETC...//
