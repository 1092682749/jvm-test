package com.dyz.jvm;

public class ClassFinal {
    public static void main(String[] args) {
        System.out.println(PrintStr.i);
        System.out.println(toStringHex1("3C696E69743E"));
    }

    public static String toStringHex1(String s) {
        byte[] baKeyword = new byte[s.length() / 2];
        for (int i = 0; i < baKeyword.length; i++) {
            try {
                baKeyword[i] = (byte) (0xff & Integer.parseInt(s.substring(
                        i * 2, i * 2 + 2), 16));
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        try {
            s = new String(baKeyword, "utf-8");// UTF-16le:Not
        } catch (Exception e1) {
            e1.printStackTrace();
        }
        return s;
    }
}
class PrintStr {
    public static final String str = "HW";
    public static int i = 128;
    static {
        System.out.println(str + "1");
    }
}
