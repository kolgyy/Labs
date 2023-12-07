#include <iostream>
#include <string>
#include <vector>

// Базовый класс контроллов
class Control {
public:
    virtual void setPosition(int x, int y) = 0;
    virtual std::pair<int, int> getPosition() const = 0;
};

// Контролл Form
class Form : public Control {
public:
    void setPosition(int x, int y) override {
        std::cout << "Setting position of Form to (" << x << ", " << y << ")" << std::endl;
        position_ = std::make_pair(x, y);
    }

    std::pair<int, int> getPosition() const override {
        return position_;
    }

    void addControl(Control* control) {
        controls_.push_back(control);
    }

private:
    std::pair<int, int> position_;
    std::vector<Control*> controls_;
};

// Контролл Label
class Label : public Control {
public:
    void setPosition(int x, int y) override {
        std::cout << "Setting position of Label to (" << x << ", " << y << ")" << std::endl;
        position_ = std::make_pair(x, y);
    }

    std::pair<int, int> getPosition() const override {
        return position_;
    }

    void setText(const std::string& text) {
        std::cout << "Setting text of Label to \"" << text << "\"" << std::endl;
        text_ = text;
    }

    std::string getText() const {
        return text_;
    }

private:
    std::pair<int, int> position_;
    std::string text_;
};

// Контролл TextBox
class TextBox : public Control {
public:
    void setPosition(int x, int y) override {
        std::cout << "Setting position of TextBox to (" << x << ", " << y << ")" << std::endl;
        position_ = std::make_pair(x, y);
    }

    std::pair<int, int> getPosition() const override {
        return position_;
    }

    void setText(const std::string& text) {
        std::cout << "Setting text of TextBox to \"" << text << "\"" << std::endl;
        text_ = text;
    }

    std::string getText() const {
        return text_;
    }

    void onValueChanged() {
        std::cout << "TextBox value has changed" << std::endl;
    }

private:
    std::pair<int, int> position_;
    std::string text_;
};

// Контролл ComboBox
class ComboBox : public Control {
public:
    void setPosition(int x, int y) override {
        std::cout << "Setting position of ComboBox to (" << x << ", " << y << ")" << std::endl;
        position_ = std::make_pair(x, y);
    }

    std::pair<int, int> getPosition() const override {
        return position_;
    }

    void setSelectedIndex(int index) {
        std::cout << "Setting selected index of ComboBox to " << index << std::endl;
        selectedIndex_ = index;
    }

    int getSelectedIndex() const {
        return selectedIndex_;
    }

    void setItems(const std::vector<std::string>& items) {
        std::cout << "Setting items of ComboBox" << std::endl;
        items_ = items;
    }

    std::vector<std::string> getItems() const {
        return items_;
    }

private:
    std::pair<int, int> position_;
    int selectedIndex_;
    std::vector<std::string> items_;
};

// Контролл Button
class Button : public Control {
public:
    void setPosition(int x, int y) override {
        std::cout << "Setting position of Button to (" << x << ", " << y << ")" << std::endl;
        position_ = std::make_pair(x, y);
    }

    std::pair<int, int> getPosition() const override {
        return position_;
    }

    void setText(const std::string& text) {
        std::cout << "Setting text of Button to \"" << text << "\"" << std::endl;
        text_ = text;
    }

    std::string getText() const {
        return text_;
    }

    void click() {
        std::cout << "Button has been clicked" << std::endl;
    }

private:
    std::pair<int, int> position_;
    std::string text_;
};

// Абстрактная фабрика контролов
class ControlFactory {
public:
    virtual Form* createForm() = 0;
    virtual Label* createLabel() = 0;
    virtual TextBox* createTextBox() = 0;
    virtual ComboBox* createComboBox() = 0;
    virtual Button* createButton() = 0;
};

// Фабрика для Windows
class WindowsControlFactory : public ControlFactory {
public:
    Form* createForm() override {
        std::cout << "Creating Windows Form" << std::endl;
        return new Form();
    }

    Label* createLabel() override {
        std::cout << "Creating Windows Label" << std::endl;
        return new Label();
    }

    TextBox* createTextBox() override {
        std::cout << "Creating Windows TextBox" << std::endl;
        return new TextBox();
    }

    ComboBox* createComboBox() override {
        std::cout << "Creating Windows ComboBox" << std::endl;
        return new ComboBox();
    }

    Button* createButton() override {
        std::cout << "Creating Windows Button" << std::endl;
        return new Button();
    }
};

// Фабрика для Linux
class LinuxControlFactory : public ControlFactory {
public:
    Form* createForm() override {
        std::cout << "Creating Linux Form" << std::endl;
        return new Form();
    }

    Label* createLabel() override {
        std::cout << "Creating Linux Label" << std::endl;
        return new Label();
    }

    TextBox* createTextBox() override {
        std::cout << "Creating Linux TextBox" << std::endl;
        return new TextBox();
    }

    ComboBox* createComboBox() override {
        std::cout << "Creating Linux ComboBox" << std::endl;
        return new ComboBox();
    }

    Button* createButton() override {
        std::cout << "Creating Linux Button" << std::endl;
        return new Button();
    }
};

// Фабрика для MacOS
class MacOSControlFactory : public ControlFactory {
public:
    Form* createForm() override {
        std::cout << "Creating MacOS Form" << std::endl;
        return new Form();
    }

    Label* createLabel() override {
        std::cout << "Creating MacOS Label" << std::endl;
        return new Label();
    }

    TextBox* createTextBox() override {
        std::cout << "Creating MacOS TextBox" << std::endl;
        return new TextBox();
    }

    ComboBox* createComboBox() override {
        std::cout << "Creating MacOS ComboBox" << std::endl;
        return new ComboBox();
    }

    Button* createButton() override {
        std::cout << "Creating MacOS Button" << std::endl;
        return new Button();
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    // Выбор операционной системы
    std::string os;
    std::cout << "Выберите операционную систему (Windows, Linux, MacOS): ";
    std::cin >> os;

    ControlFactory* factory = nullptr;

    // Создание соответствующей фабрики контролов в зависимости от выбранной ОС
    if (os == "Windows") {
        factory = new WindowsControlFactory();
    }
    else if (os == "Linux") {
        factory = new LinuxControlFactory();
    }
    else if (os == "MacOS") {
        factory = new MacOSControlFactory();
    }
    else {
        std::cerr << "Неизвестная операционная система!" << std::endl;
        return 1;
    }

    // Создание контролов
    Form* form = factory->createForm();
    Label* label = factory->createLabel();
    TextBox* textBox = factory->createTextBox();
    ComboBox* comboBox = factory->createComboBox();
    Button* button = factory->createButton();

    // Размещение контролов и выполнение методов
    form->addControl(label);
    form->addControl(textBox);
    form->addControl(comboBox);
    form->addControl(button);

    label->setPosition(10, 10);
    textBox->setPosition(10, 50);
    comboBox->setPosition(10, 90);
    button->setPosition(10, 130);

    label->setText("Привет, мир!");
    textBox->setText("Текст в TextBox");
    comboBox->setSelectedIndex(2);
    comboBox->setItems({ "Item 1", "Item 2", "Item 3" });
    button->setText("Нажми меня!");

    std::cout << std::endl;
    std::cout << "Позиция формы: (" << form->getPosition().first << ", " << form->getPosition().second << ")" << std::endl;
    std::cout << "Текст на Label: " << label->getText() << std::endl;
    std::cout << "Текст в TextBox: " << textBox->getText() << std::endl;
    std::cout << "Выбранный элемент ComboBox : " << comboBox->getSelectedIndex() << std::endl;
        std::cout << "Элементы ComboBox: ";
    for (const auto& item : comboBox->getItems()) {
        std::cout << item << ", ";
    }
    std::cout << std::endl;

    // Освобождение памяти
    delete label;
    delete textBox;
    delete comboBox;
    delete button;
    delete form;
    delete factory;

    return 0;
}