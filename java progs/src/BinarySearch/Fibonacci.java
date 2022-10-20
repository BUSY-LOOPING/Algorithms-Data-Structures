public class Fibonacci {
    private static int fibonacci(int n) {
        /***
         * For the first term n = 1, so we return the seed value of fibonacci(1) = 0
         */
        if (n == 1) {
            return 0;
        }
        /***
         * For the second term n = 2, so we return the seed value of fibonacci(2) = 1
         */
        else if (n == 2) {
            return 1;
        }

        /***
         * This calls the fibonacci function recursively to add previous two preceeding terms in the series
         */
        return fibonacci(n - 1) + fibonacci(n - 2);
    }

    public static void main(String[] args) {
        System.out.println(fibonacci(5));
    }
}