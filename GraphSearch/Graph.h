#pragma once
class Graph
{
protected:
	void extendMatrix(int extendAmount); // расширить матрицу
	void shrinkMatrix(int vertex); // сузить матрицу на 1 элемент
public:
	int vAmount;
	int** adjMatrix; // матрица смежности
	void displayMatrix(); // показать матрицу

	Graph() {};
	Graph(int vAmount);
	void addVertex(); // добавить УЗЕЛ
	int addEdge(int startV, int endV, int weight); // добавить ДУГУ 
	void delVertex(); // удалить УЗЕЛ
	int delEdge(int startV, int endV); // удалить ДУГУ
	void editVertex(); // изменить метку (маркировку) УЗЛА
	int editEdge(int startV, int endV, int newWeight); // изменить вес ДУГИ
	int first(int v); // возвращает индекс первой вершины, смежной с вершиной v.
	int next(int v, int i); // возвращает индекс вершины, смежной с вершиной v, следующий за индексом i.
	int vertex(int v, int i); // возвращает вершину с индексом i из множества вершин, смежных с v.
};

