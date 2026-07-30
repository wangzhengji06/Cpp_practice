class Shape {
public:
  virtual ~Shape() = default;
};

class Circle : public Shape {
public:
  virtual ~Circle() override { delete id; }

private:
  int *id{new int{}};
};

class Rectangle : public Shape {
public:
  virtual ~Rectangle() override { delete no; }

private:
  int *no{new int{}};
};

int main() {
  Shape *shapes[]{new Circle{}, new Rectangle{}};

  for (Shape *shape : shapes) {
    delete shape;
  }
}
