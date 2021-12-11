
#include <iostream>
using namespace std;


class Rational{

	int num;
	int denum;
	int oldnum=0;
	int olddenum=0;
public:
	Rational(int valueNum=0, int valueDeNum=1){
		num = valueNum;
		denum = valueDeNum;
	}
	
	bool operator == (const Rational& other) {
		cout << "==\n";
		simpl();
		if (this->denum == other.denum && this->num==other.num) {
			return 1;
		}
		else {
			return 0;
		}
	}

	bool operator != (const Rational& other) {
		cout << "!=\n";
		simpl();
		if (this->denum != other.denum || this->num != other.num) {
			return 1;
		}
		else {
			return 0;
		}
	}


	bool operator > (const Rational& other) {
		cout << ">\n";		
		return this->num * other.denum > other.num * this->denum;
	}
	bool operator < (const Rational& other) {
		cout << "<\n";
		return this->num * other.denum < other.num * this->denum;
	}

	Rational operator + (const Rational& other) {
		cout << "+\n";

		if (this->denum == other.denum) {	
			return Rational((this->num + other.num), this->denum);
		}
		else {
			oldnum = this->num;
			olddenum = this->denum;
			this->denum = this->denum * other.denum;
			return Rational((this->num * other.denum) + (other.num * olddenum),denum);
		}
	}

	void operator += (const Rational& other) {
		if (this->denum == other.denum) {
			this->num += other.num;
		}
		else {
			int oldnum = this->num;
			int olddenum = this->denum;
			this->denum = this->denum * other.denum;
			this->num =(this->num * other.denum) + (other.num * olddenum);
			
		}
		cout << "+=\n";
		
	}

	Rational operator - (const Rational& other) {
		cout << "-\n";
		if (this->denum == other.denum) {
			return Rational((this->num - other.num), this->denum);
		}
		else {
			int oldnum = this->num;
			int olddenum = this->denum;
			this->denum = this->denum * other.denum;
			return Rational((this->num * other.denum) - (other.num * olddenum), denum);
		}
	}

	void operator -= (const Rational& other) {
		if (this->denum == other.denum) {
			this->num -= other.num;
		}
		else {
			int oldnum = this->num;
			int olddenum = this->denum;
			this->denum = this->denum * other.denum;
			this->num = (this->num * other.denum) - (other.num * olddenum);

		}
		cout << "-=\n";
		
	}

	Rational operator / (const Rational& other) {
		
		return Rational(denum, num).operator*(other);
	}
	

	Rational operator * (const Rational& other) {
		cout << "*\n";
			return Replace(Rational(this->num *= other.num , this->denum *= other.denum));
		
	}

	Rational operator /= (const Rational& other) {
		cout << "/=\n";
		Rational x =Rational(other.denum,other.num)*Rational(this->num,this->denum);
		int buf = x.num;
		x.num = x.denum;
		x.denum = buf;
		return x;
	}
	

	void operator *= (const Rational& other) {
		
		
		
		this->denum = this->denum *= other.denum;
		this->num = this->num *= other.num;

		
		cout << "*=\n";
		
	}







	Rational Replace(const Rational& other) {
		return Rational(this->denum, this->num);
	}

	void Print() {
		cout << this->num << " / " << this->denum << "\n";
	}

	Rational simpl() {
		for (int i = this->num; i > 1; i--) {
			if (this->num % i == 0 && this->denum % i == 0) {
				num /= i;
				denum /= i;
			}
		}
		return Rational(num, denum);
	}

	~Rational() {
		//destroy
	}
};

int main()
{
	Rational rational1(15, 50); //
	Rational rational2(2, 7); //   /=  
	Rational rational3=rational1/=rational2;
	//rational3 = rational1 / rational2;
	rational3.simpl();
	rational3.Print();

	//rational1 /= rational2;

	//rational1.Print();
	//rational2.Print();

	//rational1 *= rational2;
	//rational1.Print();

}