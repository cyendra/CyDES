#pragma once

/*
	禁止复制操作的基类
	继承此类的派生类将不能进行拷贝构造
*/
class Uncopyable {
protected:
	Uncopyable() {}
	~Uncopyable() {}
private:
	Uncopyable(const Uncopyable&);
	Uncopyable& operator=(const Uncopyable&);
};