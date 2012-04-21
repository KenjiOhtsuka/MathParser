#ifndef _MATH_TOKEN_H_
#define _MATH_TOKEN_H_

using namespace std;

class MathToken {

private:
public:
	virtual ~MathToken() {}
	virtual int getType() { return -1; }
};

#endif /* _MATH_TOKEN_H_ */
