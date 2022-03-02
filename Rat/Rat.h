class Rat {
	private:
		int numerator;
		int denomonator;
		void setNum(int n);
		void setDenom(int d);
		void reduce();
	public:
		Rat();
		Rat(int);
		Rat(int, int);

		void input();
		void output() const;
		Rat add(const Rat& r) const;
		Rat sub(const Rat& r) const;
		Rat mult(const Rat& r) const;
		Rat div(const Rat& r) const;
		const int getNum() const;
		const int getDenom() const;
		
		static int lcm(int first, int second);
		static int gcf(int,int);
		static const int compare(const Rat&, const Rat&);
};
