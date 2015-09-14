#include <gtest/gtest.h>

#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int sum(const std::vector<int>& values)
{
	int init = 0;
	int sum = accumulate(values.begin(), values.end(), init);
	return sum;
}

// write the sum function
TEST(ex2, test1)
{
	{
		std::vector<int> values({0});
		EXPECT_EQ(sum(values),0);
	}
	{
		std::vector<int> values({4,1,3});
		EXPECT_EQ(sum(values),8);
	}
}

//***********************************************************

// sort integers
void sortFunction(
	std::vector<int>::iterator begin,
	std::vector<int>::iterator end)
{
	sort(begin, end);
}

// write the content of sort
TEST(ex2, test2)
{
	std::vector<int> values({4,8,10,6,1});
	std::vector<int> result({1,4,6,8,10});
	sortFunction(values.begin(),values.end());

	EXPECT_EQ(values,result);
}

//***********************************************************

class A
{
public:
	A(bool valid) :valid_(valid) {}
	bool isValid() const { return valid_; }

private:
	bool valid_;
};

bool isUnvalid(const A & a)
{
	return !a.isValid();
}

void removeInvalid(vector<A>&array)
{
	vector<A>::iterator it = array.begin();

}

TEST(ex2, test3)
{
	vector<A> array = { A(true), A(true), A(false), A(false), A(true), A(false) };

	EXPECT_EQ(6, array.size());
	removeInvalid(array);
	EXPECT_EQ(3, array.size());
}

//***********************************************************


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
