#include "input_handler.h"

void InputHandler::handle() {
    int instruction = 0;
    printEditorInstructions();
    std::string checkInput;
    std::cin >> checkInput;
    // check the input is numerical or not
    while(!isNumber(checkInput)) {
        std::cout << "Invalid instruction. Please try again.\n";
        printEditorInstructions();
        std::cin >> checkInput;
    }

    instruction = std::stoi(checkInput);
    handleEditorInstructions(instruction);
}

void InputHandler::printEditorInstructions() {
    std::string question = "Please enter following instruction number to start building:\n"
                        "1. 'add circle': to add a circle\n"
                        "2. 'add rectangle': to add a rectangle\n"
                        "3. 'add triangle': to add a triangle\n"
                        "4. 'add compound': to add a compound\n"
                        "5. 'save': output shape to file\n"
                        "6. 'exit': to exit the program\n"; 
    std::cout << question;
}

void InputHandler::handleEditorInstructions(int instruction) {
    switch (instruction)
    {
    case 1:
        addCircle();
        handle();
        break;
    case 2:
        addRectangle();
        handle();
        break;
    case 3:
        addTriangle();
        handle();
        break;
    case 4:
        isContinued = false;
        addCompound();
        printCompoundInstructions();
        handle();
        break;
    case 5:
        save();
        handle();
        break;
    case 6:
        std::cout << "Terminiate this process.\n";
        exit(0);
        break;
    default:
        std::cout<< "Invalid instruction. Please try again.\n";
        handle();
        break;
    }
}

void InputHandler::save() {
    std::cout << "Please enter the file name to save the shape:\n";
    std::string filename;
    std::cin >> filename;

    ShapeInfoVisitor sv;
    std::ofstream file;
    file.open(filename);
    builder->getShape()->accept(&sv);
    file << sv.getResult();
    file.close();
    builder->reset();

    std::cout << "Save complete.\n";
}

void InputHandler::addCircle() {
    std::cout << "Radius of circle: ";
    double radius;
    std::cin >> radius;
    try{
        builder->buildCircle(radius);
        std::cout << "Circle added.\n";
    }catch(std::string ex){
        std::cout << "Invalid argument. Please try again.\n";
    }
}

void InputHandler::addRectangle() {
    std::cout << "Width of rectangle: ";
    double width;
    std::cin >> width;
    std::cout << "Height of rectangle: ";
    double height;
    std::cin >> height;
    try{
        builder->buildRectangle(width, height);
        std::cout << "Rectangle added.\n";
    }catch(std::string ex){
        std::cout << "Invalid argument. Please try again.\n";
    }
}

void InputHandler::addTriangle() {
    // input parameters
    std::cout << "X1 of triangle: ";
    double x1;
    std::cin >> x1;
    std::cout << "Y1 of triangle: ";
    double y1;
    std::cin >> y1;
    std::cout << "X2 of triangle: ";
    double x2;
    std::cin >> x2;
    std::cout << "Y2 of triangle: ";
    double y2;
    std::cin >> y2;

    try{
        builder->buildTriangle(x1, y1, x2, y2);
        std::cout << "Triangle added.\n";
    }catch(std::string ex){
        std::cout << "Invalid argument. Please try again.\n";
    }
}

void InputHandler::printCompoundInstructions() {
    std::string question = "Please enter the following instruction number to build the compound:\n"
                            "1. 'add circle': to add a circle\n"
                            "2. 'add rectangle': to add a rectangle\n"
                            "3. 'add triangle': to add a triangle\n"
                            "4. 'add compound': to add a compound\n"
                            "5. 'exit': to exit the program\n";
    std::cout << question;
    int instruction;
    std::string checkInput;
    std::cin >> checkInput;
    // check the input is numerical or not
    while(!isNumber(checkInput)) {
        std::cout << "Invalid instruction. Please try again.\n";
        std::cout << question;
        std::cin >> checkInput;
    }

    instruction = std::stoi(checkInput);
    handleCompoundInstructions(instruction);
}

void InputHandler::handleCompoundInstructions(int instruction) {
    switch (instruction)
    {
    case 1:
        std::cout<< "Please enter the information of circle:\n";
        addCircle();
        printCompoundInstructions();
        break;
    case 2:
        std::cout<< "Please enter the information of rectangle:\n";
        addRectangle();
        printCompoundInstructions();
        break;
    case 3:
        std::cout<< "Please enter the information of triangle:\n";
        addTriangle();
        printCompoundInstructions();
        break;
    case 4:
        addCompound();
        isContinued = true;
        printCompoundInstructions();
        break;
    case 5:
        builder->buildCompoundEnd();
        if(!isContinued){
            std::cout << "Compound added.\n";
            std::cout << "Finish to add a compound shape.\n";
        }else{
            std::cout << "Compound added.\n";
            isContinued = false;
            printCompoundInstructions();
        }
        break;
    default:
        std::cout<< "Invalid instruction. Please try again.\n";
        printCompoundInstructions();
        break;
    }
    
}

void InputHandler::addCompound() {
    builder->buildCompoundBegin();
}

bool isNumber(const std::string& str){
    for(char const &c : str){
        if(std::isdigit(c) == 0) return false;
    }
    return true;
}