class Puja{     // non static member variable or instance member variable or object member variale 
    int x;
    int y;
    void ops1(){
        System.out.println("Java Program Is ready");
    }
    void ops2(){
        System.out.println("Progra Is Finished");
    }
}
class Biswa{
    public static void main(String[] args) {
    System.out.println("Something went wrong . please try again after sometimes");
    Puja p=new Puja();//Object is created /*here puja is class ,p is referenced variable i.e object ,new is a keyword through which a new memory is created new kii madat se object create hoga*/
    p.x=500;// x and y store value /*P is a type of object Puja is a datatype which is user defined class kii madat se banaya geya datatype*/
    System.out.println(p.x);  // the datatype which are not created by class i.e int ,float,double,char etc is called predefined datatype
    // the  datatype which are created by class i.e puja,mahesh,a,b,c,varun is called userdefined datatype
    p.ops1();
    p.ops2();
        
    }
}
// ** AboveWe will study about how we can call non static function  which is also called Instance Member variable or object member variable** //
