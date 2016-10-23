#include <list>

#include <iostream>

#include <string>

using namespace std;



class AbstractFile {

	protected :

		string name;  // 文件或目录名称

	public:

		void printName() {
			cout << name;   // 打印文件或目录名称
		}

		virtual void addChild(AbstractFile  *file)=0;   // 给一个目录增加子目录或文件

		virtual void removeChild(AbstractFile *file)=0;   // 删除一个目录的子目录或文件

		virtual list<AbstractFile*> *getChildren()=0; // 获得一个目录的子目录或文件

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

		list <AbstractFile*> childList;  // 存储子目录或文件

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

	// 构造一个树形的文件/目录结构

	AbstractFile *rootFolder = new Folder("c:\\");

	AbstractFile *compositeFolder = new Folder("composite");

	AbstractFile *windowsFolder = new Folder("windows");

	AbstractFile *file = new File("TestComposite.java");

	rootFolder->addChild(compositeFolder);

	rootFolder->addChild(windowsFolder);

	compositeFolder->addChild(file);

}


