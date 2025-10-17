class Static{
   private static int Age;
    static void main(){
        Age=35;
        System.out.println(Age);
    } 
    void dun1(){
        System.out.println("Mr.Biswaranjan Swain");
    }
}
 class Privatestatic {
public static void main(String[] args) {
    System.out.println("Mr.Bijayalaxmi Swain");
Static.main();
//Static yy = new Static();
//System.out.println("Finally Age is 35");
}
    
}
//we can call a private static member variable (i) if the function is static then classname.functionname();
//                                             (ii) if the function is not static first create a object then call the member object or referenced variabel.variable;
// in a class if the class member is private then in the same class we can access the data but not access in another class...
