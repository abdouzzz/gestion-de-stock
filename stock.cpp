#include "stock.h"
#include<algorithm>

stock::stock(const char* n) {
	int lg = strlen(n) + 1;
	nomdustockage = new char[lg];
	strcpy_s(nomdustockage, lg, n);
}
void stock::addMat�riel(const char *n) {
	Mat�riel* z = new Mat�riel(n);
	stockage.push_back(z);
}
Mat�riel * stock::trouveMateriel(const char* n) {
	for (size_t i = 0; i < stockage.size(); i++) {
		if (stockage[i]->getnommat() == n) {
			return stockage[i];
		}

	}
	return nullptr;
}
stock::~stock() {
	if (nomdustockage != nullptr) {
		delete nomdustockage;
	}
	for (size_t i = 0; i < stockage.size(); i++) {
		delete(stockage[i]);
	}
	stockage.clear();
}

void stock::rendremat�riel(const char* n) {
	for (auto it = mmapPrets.begin(); it != mmapPrets.end(); ) {
		if ((*it).second->getmat()==n) {
			mmapPrets.erase(it);
		}
		else {
			it++;
		}
	}
}
void stock::retireStock(const char* n) {
	for (auto it = stockage.begin(); it != stockage.end();) {
		if (n == (*it)->getnommat()) {
			stockage.erase(it);
		}
		else {
			it++;
		}
	}
}

void stock::Affiche_Stock() const {
	cout << "Stock ("<< getnomdustock()<<")  :" << endl;
	for (size_t i = 0; i < stockage.size(); i++) {
		stockage[i]->Affiche_mat();
	}
}
void stock::emprunte(prof* p, personne* e, const char* mat, const char* emp, const char* ret) {
	Mat�riel* z = new Mat�riel(mat);
	pret* t = new pret(p, e, z, emp, ret);
    mmapPrets.emplace(ret, t);
	//mmapPrets.insert(pair<char*, pret*>(ret, t));
	z->setemprunt(true);
}
void stock::Affiche_map() {
	for (auto it = mmapPrets.begin(); it != mmapPrets.end(); it++) {
		cout << (*it).first << " / " << (*it).second->getmat()<<endl;
	}
}
void stock::addmat(Mat�riel* n) {
	stockage.push_back(n);
}
void stock::verif() {
	/*for (auto it = mmapPrets.begin(); it != mmapPrets.end(); it++) {
		if (atoi((*it).second->getdateretour()) - atoi((*it).second->getdateemprunt()) > 30) {
			cout <<"Bonjour  "<< (*it).second->getpersonne()<<endl;
			cout << "Vous aviez emprunte le materiel suivant :" << (*it).second->getmat() << "et vous deviez le rendre avant le " << (*it).second->getdateretour() <<"." << endl<<"Ce delai est depasse Veuillez ramener ce materiel dans les plus brefs delais."<<endl<<endl;
		}
	}*/
}
void stock::trouver(const char* n) {
	int equal = 
}

//ostream& operator<<(ostream& o, const stock & e) {
//	
//}