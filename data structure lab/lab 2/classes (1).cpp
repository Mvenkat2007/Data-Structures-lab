#include <stdio.h>
#include <stdbool.h>

//class to calculate according to shape
class Shape{
    //declaring dimensions
    private:
        float length;
        float breadth;
        float height;
        float area;
    
    public:
        void calculateSquareArea()
        {
            printf("Enter the value of the side of the square:");
            scanf("%f",&length);

            area=length*length;
            printf("The area of the Square is %f",area);
        }
        void calculateCubeArea()
        {
            printf("Enter the value of the side of the cube:");
            scanf("%f",&length);

            area=length*length*length;
            printf("The surface area of the cube is %f",area);
        }
        void calculateRectangleArea()
        {
            printf("Enter the value of the length:");
            scanf("%f",&length);

            printf("Enter the value of the breadth:");
            scanf("%f",&breadth);

            area=length*breadth;
            printf("The area of the rectangle is %f",area);
        }
        void calculateCuboidArea()
        {
            printf("Enter the value of the length:");
            scanf("%f",&length);

            printf("Enter the value of the breadth:");
            scanf("%f",&breadth);
            
            printf("Enter the value of the height:");
            scanf("%f",&height);

            area=2*(length*breadth+breadth*height+length*height);
            printf("The surface area of the Cuboid is %f",area);
        }
};


int main()
{
    //declaring variables
    char choice;
    bool condition=true;
    Shape shape;
    //creating menu
    do
    {
        printf("MENU:\n");
        printf("enter the shape:\n");
        printf("a.Square\n");
        printf("b.Cube\n");
        printf("c.Rectangle\n");
        printf("d.Cuboid\n");
        printf("e.exit\n");
        
        printf("enter your choice:");
        scanf(" %c",&choice);

        switch(choice)
        {
            case 'a':
            {
                shape.calculateSquareArea();
                printf("\n");
                break;
            }
            case 'b':
            {
                shape.calculateCubeArea();
                printf("\n");
                break;
            }
            case 'c':
            {
                shape.calculateRectangleArea();
                printf("\n");
                break;
            }
            case 'd':
            {
                shape.calculateCuboidArea();
                printf("\n");
                break;
            }
            case 'e':
            {
                condition=false;
                break;
            }
            default:
            {
                printf("Enter a valid character\n");
                break;
            }

        }
    }while(condition);
}