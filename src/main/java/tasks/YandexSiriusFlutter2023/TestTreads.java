//package tasks.YandexSiriusFlutter;
//
//class Parent_2 {
//    public final void m1() {
//        System.out.println("m1()");
//    }
//
//    private void m2() {
//        System.out.println("m2() parent");
//    }
//}
//
//// Невозможно переопределить конечный метод из Parent_2
//class Child_2 extends Parent_2 {
//
//    public void m2() {
//        System.out.println("m2() of child");
//    }
//}
//
//public class FinalandprivateOverriden {
//    public static void main(String[] args) {
//        Parent_2 child_2 = new Child_2();
//        child_2.m1();
//        // Метод m2 () из типа Parent_2 не отображается
//        child_2.m2();
//    }
//}
