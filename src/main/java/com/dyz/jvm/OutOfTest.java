package com.dyz.jvm;

import java.util.LinkedList;
import java.util.List;

public class OutOfTest {
    static List<Object> objects = new LinkedList<Object>();
    public static void main(String[] args) {
        while (true) {
            objects.add(new OutOfTest());
        }
    }
}
