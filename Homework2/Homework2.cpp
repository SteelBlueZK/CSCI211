#include <string>
#include <iostream>
using namespace std;

string topLevelDomain[5] = {".gov", ".edu", ".org", ".com", ".net" };


class Contact {
	private:
		string nameLast;
		string nameFirst;
		string address;
		string phone;
		string email;
		
	public:
		//constructors
		Contact(string nameLast, string nameFirst, string address, string phone, string email);
		Contact();

		//general functions
		void Input(); // spits into console and takes input
		void Output() const; // spits into console

		//set and get functs
		const string getFirst() const;
		const string getLast() const;
		const string getAddr() const;
		const string getPhone() const;
		const string getEmail() const;
		void setFirst(const string& set);
		void setLast(const string& set);
		void setAddr(const string& set);
		void setPhone(const string& set);
		void setEmail(const string& set);
		
		//statics
		static bool validatePhone(const string &num);
		static bool validateEmail(const string &num);
};

int main(){
	string loop;
	do {
		Contact 
			one("Sirname", "Givenname", "123 Wallaby Way Sidney Australia", "1234567890", "givenname.sirname23@self.info"),
			two,
			three,
			none;
	
		two.setFirst("Greene");
		two.setLast("Matthew");
		two.setAddr("1 Great Street");
		two.setPhone("7183212250");
		two.setEmail("test@gmail.com");
		three.Input();
	
		cout << one.getFirst() << one.getLast() 
			<< one.getAddr() << one.getPhone() 
			<< one.getEmail() <<endl;
		two.Output();
		three.Output();
		none.Output();
	
		cout << "Continue? Y/N";
		cin >> loop;
	} while (loop == "Y" || loop == "y");
	return 1;
}
