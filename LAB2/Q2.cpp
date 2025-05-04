#include <cstdio>

class Area {
private:
    double length, breadth, width;
public:
    Area() {
        length = breadth = width = 1;
    }

    double area_square(int length) {
        return length * length;
    }

    double area_cube(int length) {
        return 6 * length * length;
    }

    double area_rectangle(int length, int breadth) {
        return length * breadth;
    }

    double area_cuboid(int length, int breadth, int width) {
        return 2 * (length * breadth + breadth * width + width * length);
    }
};

int main() {
    int choice, length, breadth, width;
    Area obj;

    while (true) {
        printf("\n=== Area Calculator ===\n");
        printf("1. Area of a square\n");
        printf("2. Surface area of a cube\n");
        printf("3. Area of a rectangle\n");
        printf("4. Surface area of a cuboid\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the length of the square: ");
            scanf("%d", &length);
            if (length <= 0) {
                printf("Invalid input! Length must be positive.\n");
                break;
            }
            printf("Area of the square = %.2f\n", obj.area_square(length));
            break;

        case 2:
            printf("Enter the side length of the cube: ");
            scanf("%d", &length);
            if (length <= 0) {
                printf("Invalid input! Length must be positive.\n");
                break;
            }
            printf("Surface area of the cube = %.2f\n", obj.area_cube(length));
            break;

        case 3:
            printf("Enter the length of the rectangle: ");
            scanf("%d", &length);
            printf("Enter the breadth of the rectangle: ");
            scanf("%d", &breadth);
            if (length <= 0 || breadth <= 0) {
                printf("Invalid input! Dimensions must be positive.\n");
                break;
            }
            printf("Area of the rectangle = %.2f\n", obj.area_rectangle(length, breadth));
            break;

        case 4:
            printf("Enter the length of the cuboid: ");
            scanf("%d", &length);
            printf("Enter the breadth of the cuboid: ");
            scanf("%d", &breadth);
            printf("Enter the width of the cuboid: ");
            scanf("%d", &width);
            if (length <= 0 || breadth <= 0 || width <= 0) {
                printf("Invalid input! Dimensions must be positive.\n");
                break;
            }
            printf("Surface area of the cuboid = %.2f\n", obj.area_cuboid(length, breadth, width));
            break;

        case 5:
            printf("Exiting the program. Goodbye!\n");
            return 0;

        default:
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
            break;
        }
    }

    return 0;
}
