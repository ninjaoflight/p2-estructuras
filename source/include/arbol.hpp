#pragma once
#include <memory> // unique_ptr
#include <vector>

template <typename T> struct Arbol {
	struct Nodo {
		std::unique_ptr<T> valor = nullptr;
		Nodo* padre = nullptr;
		std::vector<Nodo> hijos;

	  public:
		Nodo() = default;
		Nodo(T *valor, Nodo* padre = nullptr) : valor(valor), padre(padre) {}
		Nodo(T&& valor) : valor(new T(valor)) {}
	};
	std::unique_ptr<Nodo> raiz = std::make_unique<Nodo>(Nodo());
	Arbol() = default;
	Arbol(T* raiz) : raiz(std::make_unique<Nodo>(raiz)) {}
};
