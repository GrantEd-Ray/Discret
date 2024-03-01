struct Complex
{
    double Re = 0;
    double Im = 0;

    Complex(double Real, double Imaginary)
    {
        Re = Real;
        Im = Imaginary;
    }

    void pow(int n)
    {
        Complex temp(1, 0);
        for (int i = 0; i < n; i++)
        {
            temp.Re = this->Re * temp.Re - this->Im * this->Im;
            temp.Im = this->Re * temp.Im + this->Im * this->Re;
        }
        this->Re = temp.Re;
        this->Im = temp.Im;
    }
};



int main() {
    Complex c1(2, 3);
    c1.pow(100);
    Complex c2(2, -3);
    c2.pow(100);

    std::cout << c1.Re;

    return 0;
}
