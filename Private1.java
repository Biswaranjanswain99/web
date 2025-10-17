class A{
    private int x;
    private static int y;
    int z=90;
    void fun1()
    {
        y=50;
        x=20;
    System.out.println(y);
    }
    void fun2()
    {
        System.out.println(x);
    }
    void fun3(){
        System.out.println(z);
    }
}
public class Private1{
    public static void main(String [] args){
        System.out.println("Harry Porter");
        A kk1=new A();
        A kk2=new A();
        kk1.fun1();
        kk2.fun2();
        kk1.fun3();

    }
    
}
