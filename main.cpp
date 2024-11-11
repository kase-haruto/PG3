#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

/////////////////////////////////////////////////////////////////////////////////////////
//                  インターフェース
/////////////////////////////////////////////////////////////////////////////////////////

/// <summary>
/// 形状のインターフェースクラス
/// </summary>
class IShape{
public:
	virtual ~IShape() = default;

	// 面積計算
	virtual void Size() = 0;
	// 面積の表示
	virtual void Draw() const = 0;

protected:
	// 面積を保存するメンバ変数
	float area_ = 0.0f;
};

/////////////////////////////////////////////////////////////////////////////////////////
//                  派生クラス
/////////////////////////////////////////////////////////////////////////////////////////

/// <summary>
/// 円クラス
/// </summary>
class Circle : public IShape{
public:
	void Size() override;

	void Draw() const override{
		std::cout << "円の面積は " << area_ << " です。\n" << std::endl;
	}
};

/// <summary>
/// 長方形クラス
/// </summary>
class Rectangle : public IShape{
public:
	void Size() override;

	void Draw() const override{
		std::cout << "長方形の面積は " << area_ << " です。\n" << std::endl;
	}
};

/////////////////////////////////////////////////////////////////////////////////////////
//                  main
/////////////////////////////////////////////////////////////////////////////////////////

int main(){
	std::vector<std::unique_ptr<IShape>> shapes;

	// 円と長方形を追加
	shapes.emplace_back(std::make_unique<Circle>());
	shapes.emplace_back(std::make_unique<Rectangle>());

	// 各形状に対してSizeとDrawメソッドを呼び出す
	for (const auto& shape : shapes){
		shape->Size();
		shape->Draw();
	}

	// プログラム終了前に一時停止
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	return 0;
}


/////////////////////////////////////////////////////////////////////////////////////////
//                  function
/////////////////////////////////////////////////////////////////////////////////////////

void Circle::Size(){
	float radius;
	std::cout << "円の半径を入力してください: ";
	std::cin >> radius;

	// 円の面積を計算
	area_ = 3.14159f * std::pow(radius, 2);
}

void Rectangle::Size(){
	float width, height;
	std::cout << "長方形の幅を入力してください: ";
	std::cin >> width;
	std::cout << "長方形の高さを入力してください: ";
	std::cin >> height;

	// 長方形の面積を計算
	area_ = width * height;
}
