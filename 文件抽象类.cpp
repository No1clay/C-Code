#include <list>

#include <iostream>

#include <string>

using namespace std;



class AbstractFile {

	protected :

		string name;  // �ļ���Ŀ¼����

	public:

		void printName() {
			cout << name;   // ��ӡ�ļ���Ŀ¼����
		}

		virtual void addChild(AbstractFile  *file)=0;   // ��һ��Ŀ¼������Ŀ¼���ļ�

		virtual void removeChild(AbstractFile *file)=0;   // ɾ��һ��Ŀ¼����Ŀ¼���ļ�

		virtual list<AbstractFile*> *getChildren()=0; // ���һ��Ŀ¼����Ŀ¼���ļ�

};

class File : public AbstractFile {

	public :

		File(string name) {
			this->name = name;
		}

		void addChild(AbstractFile  *file) {
			return ;
		}

		void removeChild(AbstractFile *file) {
			return ;
		}

		list <AbstractFile*>* getChildren() {
			return  NULL;
		}

};

class Folder :public AbstractFile {

	private :

		list <AbstractFile*> childList;  // �洢��Ŀ¼���ļ�

	public :

		Folder(string name) {
			this->name = name;
		}

		void addChild(AbstractFile *file) {
			childList.push_back(file);
		}

		void removeChild(AbstractFile *file) {
			childList.remove(file);
		}

		list<AbstractFile*> *getChildren() {
			return  &childList;
		}

};



int main() {

	// ����һ�����ε��ļ�/Ŀ¼�ṹ

	AbstractFile *rootFolder = new Folder("c:\\");

	AbstractFile *compositeFolder = new Folder("composite");

	AbstractFile *windowsFolder = new Folder("windows");

	AbstractFile *file = new File("TestComposite.java");

	rootFolder->addChild(compositeFolder);

	rootFolder->addChild(windowsFolder);

	compositeFolder->addChild(file);

}


