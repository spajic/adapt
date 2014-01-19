#include <QtCore/QCoreApplication>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "QTestsRunner.h"
#include <iostream>
#include <lemon/list_graph.h>

using ::testing::AtLeast;   
using ::testing::_;
using ::testing::Return;

using namespace lemon;
using namespace std;


class Turtle {
public:
	virtual ~Turtle() {}
	virtual void PenUp() = 0;
	virtual void PenDown() = 0;
	virtual void Forward(int distance) = 0;
	virtual void Turn(int degrees) = 0;
	virtual void GoTo(int x, int y) = 0;
	virtual int GetX() const = 0;
	virtual int GetY() const = 0;
};

class MockTurtle : public Turtle {
public:
  MOCK_METHOD0(PenUp, void());
	MOCK_METHOD0(PenDown, void());
	MOCK_METHOD1(Forward, void(int distance));
	MOCK_METHOD1(Turn, void(int degrees));
	MOCK_METHOD2(GoTo, void(int x, int y));
	MOCK_CONST_METHOD0(GetX, int());
	MOCK_CONST_METHOD0(GetY, int());
};

TEST(PainterTest, CanDrawSomething) {
	MockTurtle turtle;                          
	EXPECT_CALL(turtle, PenDown()).Times(AtLeast(2));
	turtle.PenDown();
	turtle.PenDown();
} 

TEST(FirstTest, Fail) {
	EXPECT_EQ(1, 1);
}

TEST(LemonTest, BasicUsage) {
	ListDigraph g;
	ListDigraph::Node u = g.addNode();
	ListDigraph::Node v = g.addNode();
	ListDigraph::Arc  a = g.addArc(u, v);
	EXPECT_EQ(2, countNodes(g));
	EXPECT_EQ(1, countArcs (g));
}

//-------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	// The following line causes Google Mock to throw an exception on failure,
	// which will be interpreted by your testing framework as a test failure.
	//::testing::GTEST_FLAG(throw_on_failure) = true;
	::testing::InitGoogleTest(&argc, argv);
	::testing::InitGoogleMock(&argc, argv);

	QCoreApplication a(argc, argv);
	QTestsRunner runner(&a);
	QObject::connect(&runner, SIGNAL(finished()), &a, SLOT(quit()));
	QTimer::singleShot(0, &runner, SLOT(run()));
	return a.exec();
}
