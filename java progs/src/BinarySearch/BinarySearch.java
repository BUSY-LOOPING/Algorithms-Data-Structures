package BinarySearch;

public class BinarySearch<T extends Comparable<T>>{

    private final T[] array;
    public BinarySearch (T[] array) {
        this.array = array;
    }

    private int search(T key, int l, int h) {

        int mid = (l + h) /2;
        if (h >= mid) {
            if (key == array[mid]) {
                return mid;
            } else if (array[mid].compareTo(key) > 0) {
                return search(key, l, mid - 1);
            } else return search(key, mid + 1, h);
        } else
            return -1;
    }

    public int search (T key) {
        return search(key, 0, array.length - 1);
    }

    public static void main(String[] args) {
        BinarySearch<Integer> binarySearch = new BinarySearch<>(new Integer[]{1, 2, 3});
        System.out.println(binarySearch.search(3));
    }
}
