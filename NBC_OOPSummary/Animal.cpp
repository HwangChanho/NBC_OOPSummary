#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Animal {
public:
	// 랜덤 동물을 생성하는 함수
	// - 0, 1, 2 중 하나의 난수를 생성하여 각각 Dog, Cat, Cow 객체 중 하나를 동적으로 생성합니다.
	// - 생성된 객체는 Animal 타입의 포인터로 반환됩니다.
	// - 입력 매개변수: 없음
	// - 반환값: Animal* (생성된 동물 객체의 포인터)
	Animal* createRandomAnimal();

private:

};