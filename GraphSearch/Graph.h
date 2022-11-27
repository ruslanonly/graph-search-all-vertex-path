#pragma once
class Graph
{
protected:
	void extendMatrix(int extendAmount); // ��������� �������
	void shrinkMatrix(int vertex); // ������ ������� �� 1 �������
public:
	int vAmount;
	int** adjMatrix; // ������� ���������
	void displayMatrix(); // �������� �������

	Graph() {};
	Graph(int vAmount);
	void addVertex(); // �������� ����
	int addEdge(int startV, int endV, int weight); // �������� ���� 
	void delVertex(); // ������� ����
	int delEdge(int startV, int endV); // ������� ����
	void editVertex(); // �������� ����� (����������) ����
	int editEdge(int startV, int endV, int newWeight); // �������� ��� ����
	int first(int v); // ���������� ������ ������ �������, ������� � �������� v.
	int next(int v, int i); // ���������� ������ �������, ������� � �������� v, ��������� �� �������� i.
	int vertex(int v, int i); // ���������� ������� � �������� i �� ��������� ������, ������� � v.
};

