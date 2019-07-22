#include "QueryResult.h"

string make_plural(size_t ctr, const string& word, const string& ending) {
	return (ctr == 1) ? word : word + ending;
}

ostream& print(ostream& os, const QueryResult& qr) {
	//如果找到了单词，打印出现次数和所有出现的位置
	os << qr.sought << " occurs " << qr.lines->size() << " " << make_plural(qr.lines->size(), "time", "s") << endl;
	//打印单词出现的每一行
	for (auto num : *qr.lines)	//对 set 中每个单词
		//避免行号从0开始给用户带来的困惑
		os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
	return os;
}