/********************************************************************
**                 COMPUTER ENGINEERING
**
**             ALEXANDER KİBAROV(İSKENDER)
********************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <locale.h>
#include <iomanip>
using namespace std;
int boolKontrol;
int gelismisSayiKontrol(string alinan);
string noktaBoslukCevirici(string alinan);
string boslukNoktaCevirici(string alinan);
string yemekler[20] = { "Adana Kebap","Magnolya","Cikolatali Pasta","Karisik Pizza","Sucuklu Pizza",
	"Baton Pasta","Tiramisu","Kasarli Tost","Sucuklu Tost","Karisik Tost","Beyran","Urfa Kebabi","Tavuk sis",
	"Ayran","Kunefe","Kadayif","Halka Tatlisi","Soslu Makarna","Biftek","Ekmek" };
string malzamelerim[21] = { "Domates","Sogan","Cikolata","Ekmek","Et","Tavuk","Salca","Su","Tuz","Kadayif","Un",
		"Sucuk","Salam","Krema","Muz","Cilek","Peynir","Kahve","Biskuvi","Maya","Biber" };
//Burada gerekli fonksiyon prototiplerini, dizileri ve degerleri tanimliyoruz.
class Urun
{
private:
	string urunAdi;
	string gun;
	string ay;
	string yil;
	string kaloriGram;
	string fiyat;
	string alisFiyat;
public:
	Urun()
	{
		urunAdi = "Bilinmiyor";
		gun = "0";
		ay = "0";
		yil = "0";
		kaloriGram = "0";
		fiyat = "0";
		alisFiyat = "0";
		//Kurucu fonksiyon yazdik
	}
	void setUrunAdi()
	{
		int dogruluk = 1;
		do
		{
			cout << "Urun adini giriniz(Sadece Menude Olan Yemekler Girilebilir): ";
			getline(cin, urunAdi);
			for (int i = 0; i < 20; i++)
			{
				if (noktaBoslukCevirici(urunAdi) == noktaBoslukCevirici(yemekler[i]))
				{
					urunAdi = noktaBoslukCevirici(urunAdi);
					dogruluk = 1;
					break;
				}
				else
				{
					dogruluk = 0;
				}
			}
		} while (dogruluk == 0);
		//Kullanici menude olan bir yemegi girene kadar bekliyoruz.
	}
	void setGun()
	{
		do
		{
			cout << "Son kullanma tarihinin gunu: ";
			getline(cin, gun);
		} while (gelismisSayiKontrol(gun) == 1);
		//Kullanici sadece sayi girene kadar bekliyoruz.
	}
	void setAy()
	{
		do
		{
			cout << "Son kullanma tarihinin ayi: ";
			getline(cin, ay);
		} while (gelismisSayiKontrol(ay) == 1);
		//Kullanici sadece sayi girene kadar bekliyoruz.
	}
	void setYil()
	{
		do
		{
			cout << "Son kullanma tarihinin yili: ";
			getline(cin, yil);
		} while (gelismisSayiKontrol(yil) == 1);
		//Kullanici sadece sayi girene kadar bekliyoruz.
	}
	void setKalori()
	{
		do
		{
			cout << "Kalorisini giriniz: ";
			getline(cin, kaloriGram);
		} while (gelismisSayiKontrol(kaloriGram) == 1);
		//Kullanici sadece sayi girene kadar bekliyoruz.
	}
	void setFiyat()
	{
		do
		{
			cout << "Fiyat giriniz: ";
			getline(cin, fiyat);
		} while (gelismisSayiKontrol(fiyat) == 1);
		//Kullanici sadece sayi girene kadar bekliyoruz.
	}
	void setAlisFiyat()
	{
		do
		{
			cout << "Alis fiyatini giriniz: ";
			getline(cin, alisFiyat);
		} while (gelismisSayiKontrol(alisFiyat) == 1);
		//Kullanici sadece sayi girene kadar bekliyoruz.
	}
	string getUrunAdi()
	{
		return urunAdi;
	}
	string getGun()
	{
		return gun;
	}
	string getAy()
	{
		return ay;
	}
	string getYil()
	{
		return yil;
	}
	string getKalori()
	{
		return kaloriGram;
	}
	string getFiyat()
	{
		return fiyat;
	}
	string getAlisFiyat()
	{
		return alisFiyat;
	}
};
Urun urun;
int main()
{
	cout << "				&&&&Iskender Musaoglu&&&&				\n";
	system("Pause");
	system("cls");
	cout << "Program kullanimi: Oncelikle magazada sinirsiz kullanim yerine daha gercekci olmasi icin bir stok belirlenmistir.\n";
	cout << "Yemekler 20 depo 21 stok alabilmektedir. Yemek satisi yapabilemek icin oncelikle depoyu doldurmak gereklidir.\n";
	cout << "Yapmazsaniz program sizi uyaracaktir. Ayrica siparis geldikten sonra hazira gonderilmeyen yemek satisi da\nHazirlanmadigi icin yapilamaz. "; 
	cout << "Bunu da ilk basta yemek hazirlama kismindan yapiniz. Yapmazsaniz program zaten\nTekrardan sizi uyaracaktir. Guncellemek ";
	cout << "istediginiz yemek icin iki guncelleme turu vardir: Bunlardan ilki direk\nMenuden yemek guncellemektir, digeri ise hazira gonderilmis yemegi guncellemektir. ";
	cout << "Birincisi yemek ile ilgili\nBilgilere daha cok muhadahele etme hakki verir.Yapilan satis sonrasi kariniz kaydedilir ve rapor kisminda\nSize gosterilir. ";
	cout << "Yapilan satis sonrasi malzamelerden bir birim urunler azaltilir eger urun sifirken satis yapilmaz\nVe eksik urun olarak eklenir. Depo dolduruldugunda eksik listesi temizlenir. ";
	cout << "Programin genel kullanimi bu sekildedir.\n";
	system("Pause");
	system("cls");
	string islem, urunAdi, gun, ay, yil, kaloriGram, fiyat, alisFiyat, guncellemeAdi, yeniGun, yeniAy, yeniYil, yeniKalori, yeniFiyat, yeniAlisFiyat, silUrun,
		malzame1, malzame2, malzame3, malzame1Kontrol, malzame2Kontrol, malzame3Kontrol, satilacakUrun, depodakiAd, depodakiStok, malzameAdet1, malzameAdet2, malzameAdet3,
		urunAdiDepo, urunStoguDepo, eksikMalzamelerEkrana, urunAdiEkrana, urunGunuEkrana, urunAyiEkrana, urunYiliEkrana, urunKaloriGramEkrana, urunFiyatEkrana, urunAlisFiyatEkrana
		, malzame1Ekrana, malzame2Ekrana, malzame3Ekrana, maliyetHesabi, kisiSayisi, kisiBasiMalzame1, kisiBasiMalzame2, kisiBasiMalzame3, menuDegisecek, menudekiYeni, menudekiMalzame1, menudekiMalzame2,
		menudekiMalzame3, menudekiMalzame1Kontrol, menudekiMalzame2Kontrol, menudekiMalzame3Kontrol, menudeki1MalzameFiyat, menudeki2MalzameFiyat, menudeki3MalzameFiyat, menudekiGun, menudekiAy, menudekiYil,
		menudekiKaloriGram, menudekiFiyat, menudekiAlisFiyat, menudekiAdKontrol, menudekiGunKontrol, menudekiAyKontrol, menudekiYilKontrol, menudekiKaloriGramKontrol, menudekiFiyatKontrol, menudekiAlisFiyatKontrol,
		m1Kontrol, m2Kontrol, m3Kontrol, d1Kontrol, d2Kontrol, eKontrol;
	string malzameFiyatlari[21] = { "1", "1", "3", "2", "10", "8", "2", "1", "1", "8", "2", "4", "3", "2", "3", "3", "4", "2", "1", "1", "2" };
	string yemekMalzameleri[20][3] = { {"Domates","Sogan","Et"},{"Krema","Muz","Cilek"},{"Cikolata","Un","Muz"}
	,{"Sucuk", "Salam", "Un"},{"Sucuk","Peynir","Un"},{"Cikolata","Cilek","Un"},{"Kahve","Biskuvi","Krema"},{"Peynir","Ekmek","Salca"},{"Sucuk","Ekmek","Salca"},
		{"Peynir","Sucuk","Ekmek"},{"Et","Salca","Su"},{"Et","Un","Tuz"},{"Tavuk","Domates","Salca"},{"Su","Tuz","Biber"},{"Kadayif","Peynir","Un"},{"Kadayif","Un","Su"},
		{"Un","Su","Tuz"},{"Salca","Un","Tuz"},{"Et","Tuz","Sogan"},{"Un","Tuz","Su"} };
	string yemekKisiBasiMaliyeti[20] = { "12","8","8","9","10","8","5","8","8","10","13","13","11","4","14","11","4","5","12","4" };
	int fiyatsal = 0, alisFiyatsal = 0;
	for (;;)
	{
		int toplam = 0, toplamaIslemi = 0, alisToplam = 0, alisToplamaIslemi = 0;
		ofstream depoDosyasi;
		ofstream yemekCesit;
		ofstream malzame;
		ofstream eksikMalzame;
		depoDosyasi.open("Depo.txt", ios::app);
		yemekCesit.open("Yemekcesit.txt", ios::app);
		malzame.open("Malzame.txt", ios::app);
		eksikMalzame.open("Eksikmalzame.txt", ios::app);
		//Dosyalarımızı olusturduk
		cout << "1)Yemegi Hazirla\n2)Yemegi Silme\n3)Guncelleme\n4)Yemek Satis\n5)Rapor Alma\n6)Yapilan Satisi Sifirla\n7)Menuyu Yazdir\n8)Porsiyon Maliyet Hesabi\n9)Ekrani Temizleme\n10)Uygulamayi Kapat\n";
		cout << "---------------------------------------------\n";
		cout << "Lutfen turkce karakter kullanmayiniz!\n";
		cout << "---------------------------------------------\n";
		do
		{
			cout << "Islem seciniz: ";
			getline(cin, islem);
		} while (gelismisSayiKontrol(islem) == 1);
		//Kullanici sadece sayi girene kadar bekliyoruz.
		if (stoi(islem) == 1)
		{
			cout << "---------------------------------------------\n";
			urun.setUrunAdi();
			urunAdi = urun.getUrunAdi();
			cout << "---------------------------------------------\n";
			urun.setGun();
			gun = urun.getGun();
			cout << "---------------------------------------------\n";
			urun.setAy();
			ay = urun.getAy();
			cout << "---------------------------------------------\n";
			urun.setYil();
			yil = urun.getYil();
			cout << "---------------------------------------------\n";
			urun.setKalori();
			kaloriGram = urun.getKalori();
			cout << "---------------------------------------------\n";
			urun.setFiyat();
			fiyat = urun.getFiyat();
			cout << "---------------------------------------------\n";
			urun.setAlisFiyat();
			alisFiyat = urun.getAlisFiyat();
			cout << "---------------------------------------------\n";
			yemekCesit << noktaBoslukCevirici(urunAdi) << "    " << gun << "    " << ay << "    " << yil << "    " << kaloriGram << "    " << fiyat << "    " << alisFiyat << endl;
			//Yemekcesit dosyasina degerlerimizi yazdiriyoruz.
			int iterasyon = 0;
			for (; iterasyon < 20; iterasyon++)
			{
				if (noktaBoslukCevirici(urunAdi) == noktaBoslukCevirici(yemekler[iterasyon]))
				{
					break;
				}
				//Bu dosyanin menude hangi sirada olduguna bakiyoruz.
			}
			for (int j = 0; j < 3; j++)
			{
				malzame << yemekMalzameleri[iterasyon][j] << "    ";
				//Bu siraya gore malzamelerini malzameler dosyanina yaziyoruz.
			}
			malzame << endl;
		}
		else if (stoi(islem) == 2)
		{
			ifstream yemekCesitOku2("Yemekcesit.txt");
			ifstream malzameOku("Malzame.txt");
			ofstream gecici3("Gecici3.txt", ios::app);
			ofstream gecici4("Gecici4.txt", ios::app);
			cout << "---------------------------------------------\n";
			int kontrolDegeri2 = 0;
			do
			{
				cout << "---------------------------------------------\n";
				cout << "Hangi urunu sileceksiniz: ";
				getline(cin, silUrun);
				cout << "---------------------------------------------\n";
				for (int i = 0; i < 20; i++)
				{
					if (noktaBoslukCevirici(silUrun) == noktaBoslukCevirici(yemekler[i]))
					{
						kontrolDegeri2 = 1;
						break;
					}
					else
					{
						kontrolDegeri2 = 0;
					}
				}
				//Silmesini istedgi urunun menude olup olmadigina bakiyoruz.
			} while (kontrolDegeri2 == 0);
			cout << "---------------------------------------------\n";
			while (yemekCesitOku2 >> urunAdi >> gun >> ay >> yil >> kaloriGram >> fiyat >> alisFiyat)
			{
				if (noktaBoslukCevirici(silUrun) == urunAdi)
				{
					cout << "---------------------------------------------\n";
					cout << "Urun silindi\n";
					cout << "---------------------------------------------\n";
				}
				else
				{
					gecici3 << urunAdi << "    " << gun << "    " << ay << "    " << yil << "    " << kaloriGram << "    " << fiyat << "    " << alisFiyat << endl;
				}
			}
			//Bu urunu yemekcesit dosyasindan siliyoruz.
			int iterasyon2 = 0;
			for (; iterasyon2 < 20; iterasyon2++)
			{
				if (noktaBoslukCevirici(silUrun) == noktaBoslukCevirici(yemekler[iterasyon2]))
				{
					break;
				}
			}
			//Bu urunun menude hangi sirada oldugunu buluyoruz.
			malzame1Kontrol = yemekMalzameleri[iterasyon2][0];
			malzame2Kontrol = yemekMalzameleri[iterasyon2][1];
			malzame3Kontrol = yemekMalzameleri[iterasyon2][2];
			while (malzameOku >> malzame1 >> malzame2 >> malzame3)
			{
				if ((malzame1 == malzame1Kontrol) && (malzame2 == malzame2Kontrol) && (malzame3 == malzame3Kontrol))
				{
					cout << "---------------------------------------------\n";
					cout << "Bu urun icin malzame kalkti\n";
					cout << "---------------------------------------------\n";
				}
				else
				{
					gecici4 << malzame1 << "    " << malzame2 << "    " << malzame3 << endl;
				}
			}//Bu siraya gore malzameler listesinden kaldiriyoruz.
			malzame.close();
			malzameOku.close();
			gecici4.close();
			remove("Malzame.txt");
			rename("Gecici4.txt", "Malzame.txt");
			yemekCesitOku2.close();
			yemekCesit.close();
			gecici3.close();
			remove("Yemekcesit.txt");
			rename("Gecici3.txt", "Yemekcesit.txt");
			//Dosyalari kapattik
		}
		else if (stoi(islem) == 3)
		{
			cout << "1)Bilgi Guncelleme\n2)Depoyu doldur\n3)Menuden Yemek Guncelleme\n";
			cout << "---------------------------------------------\n";
			do
			{
				cout << "Islem seciniz: ";
				getline(cin, islem);
			} while (gelismisSayiKontrol(islem) == 1);
			//Kullanici sadece sayi girene kadar bekliyoruz.
			cout << "---------------------------------------------\n";
			if (stoi(islem) == 1)
			{
				ifstream yemekCesitOku("Yemekcesit.txt");
				ofstream gecici2("Gecici2.txt", ios::app);
				int kontrolDegeri = 0;
				do
				{
					cout << "---------------------------------------------\n";
					cout << "Hangi urunu guncelleyeceksiniz: ";
					getline(cin, guncellemeAdi);
					cout << "---------------------------------------------\n";
					for (int i = 0; i < 20; i++)
					{
						if (noktaBoslukCevirici(guncellemeAdi) == noktaBoslukCevirici(yemekler[i]))
						{
							kontrolDegeri = 1;
							break;
						}
						else
						{
							kontrolDegeri = 0;
						}
					}
				} while (kontrolDegeri == 0);
				//Guncelleyecegi urunun menude var olup olmadigina bakiyoruz.
				do
				{
					cout << "Yeni gunu giriniz: ";
					getline(cin, yeniGun);
				} while (gelismisSayiKontrol(yeniGun) == 1);
				//Kullanici sadece sayi girene kadar bekliyoruz.
				cout << "---------------------------------------------\n";
				do
				{
					cout << "Yeni ayi giriniz: ";
					getline(cin, yeniAy);
				} while (gelismisSayiKontrol(yeniAy) == 1);
				//Kullanici sadece sayi girene kadar bekliyoruz.
				cout << "---------------------------------------------\n";
				do
				{
					cout << "Yeni yili giriniz: ";
					getline(cin, yeniYil);
				} while (gelismisSayiKontrol(yeniYil) == 1);
				//Kullanici sadece sayi girene kadar bekliyoruz.
				cout << "---------------------------------------------\n";
				do
				{
					cout << "Yeni kaloriyi giriniz: ";
					getline(cin, yeniKalori);
				} while (gelismisSayiKontrol(yeniKalori) == 1);
				//Kullanici sadece sayi girene kadar bekliyoruz.
				cout << "---------------------------------------------\n";
				do
				{
					cout << "Yeni fiyati giriniz: ";
					getline(cin, yeniFiyat);
				} while (gelismisSayiKontrol(yeniFiyat) == 1);
				//Kullanici sadece sayi girene kadar bekliyoruz.
				cout << "---------------------------------------------\n";
				do
				{
					cout << "Yeni alis fiyati giriniz: ";
					getline(cin, yeniAlisFiyat);
				} while (gelismisSayiKontrol(yeniAlisFiyat) == 1);
				//Kullanici sadece sayi girene kadar bekliyoruz.
				cout << "---------------------------------------------\n";
				while (yemekCesitOku >> urunAdi >> gun >> ay >> yil >> kaloriGram >> fiyat >> alisFiyat)
				{
					if (noktaBoslukCevirici(guncellemeAdi) == urunAdi)
					{
						gecici2 << urunAdi << "    " << yeniGun << "    " << yeniAy << "    " << yeniYil << "    " << yeniKalori << "    " << yeniFiyat << "    " << yeniAlisFiyat << endl;
						cout << "---------------------------------------------\n";
						cout << "Guncelleme Yapildi\n";
						cout << "---------------------------------------------\n";
					}
					else
					{
						gecici2 << urunAdi << "    " << gun << "    " << ay << "    " << yil << "    " << kaloriGram << "    " << fiyat << "    " << alisFiyat << endl;
					}
				}
				//Urunun bilgilerini degistiriyoruz.
				yemekCesit.close();
				yemekCesitOku.close();
				gecici2.close();
				remove("Yemekcesit.txt");
				rename("Gecici2.txt", "Yemekcesit.txt");
				//Dosyalari kapatiyoruz
			}
			if (stoi(islem) == 2)
			{
				ofstream gecici("Gecici.txt", ios::app);
				ofstream gecici6("Gecici6.txt", ios::app);
				for (int i = 0; i < 21; i++)
				{
					gecici << malzamelerim[i] << "    " << "20" << endl;
				}
				depoDosyasi.close();
				gecici.close();
				remove("Depo.txt");
				rename("Gecici.txt", "Depo.txt");
				cout << "Depo dolduruldu\n";
				cout << "---------------------------------------------\n";
				eksikMalzame.close();
				gecici6.close();
				remove("Eksikmalzame.txt");
				rename("Gecici6.txt", "Eksikmalzame.txt");
				//Depodaki malzamelerin stoklarini dolduruyoruz ve eksik malzemeleri temizliyoruz.
			}
			if (stoi(islem)==3)
			{
				int iterasyonMenu = 0;
				cout << "---------------------------------------------\n";
				cout << "Menuedeki hangi yemegi degistireceksiniz: \nBu guncelleme islemi direk olarak menuyu guncelleme yapar depodaki malzameleriniz de guncellenir.\n:";
				getline(cin, menuDegisecek);
				cout << "---------------------------------------------\n";
				for (; iterasyonMenu < 20; iterasyonMenu++)
				{
					if (noktaBoslukCevirici(menuDegisecek) == noktaBoslukCevirici(yemekler[iterasyonMenu]))
					{
						break;
					}
				}
				cout << "Yeni girilecek yemek ismi: ";
				getline(cin, menudekiYeni);
				yemekler[iterasyonMenu] = menudekiYeni;
				cout << "---------------------------------------------\n";
				menudekiMalzame1Kontrol = yemekMalzameleri[iterasyonMenu][0];
				menudekiMalzame2Kontrol = yemekMalzameleri[iterasyonMenu][1];
				menudekiMalzame3Kontrol = yemekMalzameleri[iterasyonMenu][2];
				cout << "Yemegin yeni malzamesi 1: ";
				getline(cin, menudekiMalzame1);
				cout << "Yemegin yeni malzamesi 2: ";
				getline(cin, menudekiMalzame2);
				cout << "Yemegin yeni malzamesi 3: ";
				getline(cin, menudekiMalzame3);
				yemekMalzameleri[iterasyonMenu][0] = menudekiMalzame1;
				yemekMalzameleri[iterasyonMenu][1] = menudekiMalzame2;
				yemekMalzameleri[iterasyonMenu][2] = menudekiMalzame3;
				int malzamelerin1Iterasyon = 0;
				int malzamelerin2Iterasyon = 0;
				int malzamelerin3Iterasyon = 0;
				for (; malzamelerin1Iterasyon < 21; malzamelerin1Iterasyon++)
				{
					if (menudekiMalzame1Kontrol == malzamelerim[malzamelerin1Iterasyon])
					{
						malzamelerim[malzamelerin1Iterasyon] = menudekiMalzame1;
						break;
					}
				}
				for (; malzamelerin2Iterasyon < 21; malzamelerin2Iterasyon++)
				{
					if (menudekiMalzame2Kontrol == malzamelerim[malzamelerin2Iterasyon])
					{
						malzamelerim[malzamelerin2Iterasyon] = menudekiMalzame2;
						break;
					}
				}
				for (; malzamelerin3Iterasyon < 21; malzamelerin3Iterasyon++)
				{
					if (menudekiMalzame3Kontrol == malzamelerim[malzamelerin3Iterasyon])
					{
						malzamelerim[malzamelerin3Iterasyon] = menudekiMalzame3;
						break;
					}
				}
				do
				{
					cout << "---------------------------------------------\n";
					cout << "Ilk malzamenin fiyati: ";
					getline(cin, menudeki1MalzameFiyat);
					cout << "---------------------------------------------\n";
				} while (gelismisSayiKontrol(menudeki1MalzameFiyat) == 1);
				malzameFiyatlari[malzamelerin1Iterasyon] = menudeki1MalzameFiyat;
				do
				{
					cout << "---------------------------------------------\n";
					cout << "Ikinci malzamenin fiyati: ";
					getline(cin, menudeki2MalzameFiyat);
					cout << "---------------------------------------------\n";
				} while (gelismisSayiKontrol(menudeki2MalzameFiyat) == 1);
				malzameFiyatlari[malzamelerin2Iterasyon] = menudeki2MalzameFiyat;
				do
				{
					cout << "---------------------------------------------\n";
					cout << "Ucuncu malzamenin fiyati: ";
					getline(cin, menudeki3MalzameFiyat);
					cout << "---------------------------------------------\n";
				} while (gelismisSayiKontrol(menudeki3MalzameFiyat) == 1);
				malzameFiyatlari[malzamelerin3Iterasyon] = menudeki3MalzameFiyat;
				yemekKisiBasiMaliyeti[iterasyonMenu] = to_string(stoi(menudeki1MalzameFiyat)+stoi(menudeki2MalzameFiyat)+stoi(menudeki3MalzameFiyat));
				do
				{
					cout << "Yeni gunu giriniz: ";
					getline(cin, menudekiGun);
				} while (gelismisSayiKontrol(menudekiGun) == 1);
				do
				{
					cout << "Yeni ayi giriniz: ";
					getline(cin, menudekiAy);
				} while (gelismisSayiKontrol(menudekiAy) == 1);
				do
				{
					cout << "Yeni yili giriniz: ";
					getline(cin, menudekiYil);
				} while (gelismisSayiKontrol(menudekiYil) == 1);
				do
				{
					cout << "Yeni kalori grami giriniz: ";
					getline(cin, menudekiKaloriGram);
				} while (gelismisSayiKontrol(menudekiKaloriGram) == 1);
				do
				{
					cout << "Yeni fiyati giriniz: ";
					getline(cin, menudekiFiyat);
				} while (gelismisSayiKontrol(menudekiFiyat) == 1);
				do
				{
					cout << "Yeni alis fiyatini giriniz: ";
					getline(cin, menudekiAlisFiyat);
				} while (gelismisSayiKontrol(menudekiAlisFiyat) == 1);
				ifstream menuIcinDegisecek("Yemekcesit.txt");
				ofstream menuDegisecekYeniCesitGecici("Gecici10.txt", ios::app);
				while (menuIcinDegisecek >> menudekiAdKontrol >> menudekiGunKontrol >> menudekiAyKontrol >> menudekiYilKontrol >> menudekiKaloriGramKontrol >> menudekiFiyatKontrol >> menudekiAlisFiyatKontrol)
				{
					if (noktaBoslukCevirici(menuDegisecek) == noktaBoslukCevirici(menudekiAdKontrol))
					{
						menuDegisecekYeniCesitGecici << noktaBoslukCevirici(menudekiYeni) << "    " << menudekiGun << "    " << menudekiAy << "    " 
							<< menudekiYil << "    " << menudekiKaloriGram << "    " << menudekiFiyat << "    " << menudekiAlisFiyat << endl;
					}
					else
					{
						menuDegisecekYeniCesitGecici << menudekiAdKontrol << "    " << menudekiGunKontrol << "    " << menudekiAyKontrol << "    " << menudekiYilKontrol <<
							"    " << menudekiKaloriGramKontrol << "    " << menudekiFiyatKontrol << "    " << menudekiAlisFiyatKontrol << endl;
					}
				}
				yemekCesit.close();
				menuIcinDegisecek.close();
				menuDegisecekYeniCesitGecici.close();
				remove("Yemekcesit.txt");
				rename("Gecici10.txt", "Yemekcesit.txt");
				ifstream malzameIcinOkuma("Malzame.txt");
				ofstream malzameIcinDegisecek("Gecici11.txt", ios::app);
				while (malzameIcinOkuma >> m1Kontrol >> m2Kontrol >> m3Kontrol)
				{
					if (m1Kontrol == menudekiMalzame1Kontrol && m2Kontrol == menudekiMalzame2Kontrol && m3Kontrol == menudekiMalzame3Kontrol)
					{
						malzameIcinDegisecek << menudekiMalzame1 << "    " << menudekiMalzame2 << "    " << menudekiMalzame3 << endl;
					}
					else
					{
						malzameIcinDegisecek << m1Kontrol << "    " << m2Kontrol << "    " << m3Kontrol << endl;
					}
				}
				malzame.close();
				malzameIcinOkuma.close();
				malzameIcinDegisecek.close();
				remove("Malzame.txt");
				rename("Gecici11.txt", "Malzame.txt");
				ifstream depoMenuIcinOkuma("Depo.txt");
				ofstream depoMenuIcinGecici("Gecici12.txt", ios::app);
				while (depoMenuIcinOkuma >> d1Kontrol >> d2Kontrol)
				{
					if (d1Kontrol == menudekiMalzame1Kontrol)
					{
						depoMenuIcinGecici << menudekiMalzame1 << "    " << "20" << endl;
					}
					else if (d1Kontrol == menudekiMalzame2Kontrol)
					{
						depoMenuIcinGecici << menudekiMalzame2 << "    " << "20" << endl;
					}
					else if (d1Kontrol == menudekiMalzame3Kontrol)
					{
						depoMenuIcinGecici << menudekiMalzame3 << "    " << "20" << endl;
					}
					else
					{
						depoMenuIcinGecici << d1Kontrol << "    " << d2Kontrol << endl;
					}
				}
				depoDosyasi.close();
				depoMenuIcinOkuma.close();
				depoMenuIcinGecici.close();
				remove("Depo.txt");
				rename("Gecici12.txt", "Depo.txt");
				ifstream eksikMalzameDepoOkuma("Eksikmalzame.txt");
				ofstream eksikMalzameDepoGecici("Gecici13.txt", ios::app);
				while (eksikMalzameDepoOkuma >> eKontrol)
				{
					if (eKontrol == menudekiMalzame1Kontrol)
					{

					}
					else if (eKontrol == menudekiMalzame2Kontrol)
					{

					}
					else if (eKontrol == menudekiMalzame3Kontrol)
					{

					}
					else
					{
						eksikMalzameDepoGecici << eKontrol << endl;
					}
				}
				eksikMalzame.close();
				eksikMalzameDepoOkuma.close();
				eksikMalzameDepoGecici.close();
				remove("Eksikmalzame.txt");
				rename("Gecici13.txt", "Eksikmalzame.txt");
				cout << "---------------------------------------------\n";
			}
		}
		else if (stoi(islem) == 4)
		{
			int dogrulukKontrolumuz = 0;
			ifstream depoyuOku("Depo.txt");
			ifstream yemekDosyasiniOku("Yemekcesit.txt");
			ifstream yemekDosyasiniOku2("Yemekcesit.txt");
			cout << "---------------------------------------------\n";
			int kontrolDegeri2 = 0;
			int kontrolDegeri3 = 0;
			do
			{
				cout << "---------------------------------------------\n";
				cout << "Hangi urunu satacaksiniz: ";
				getline(cin, satilacakUrun);
				cout << "---------------------------------------------\n";
				for (int i = 0; i < 20; i++)
				{
					if (noktaBoslukCevirici(satilacakUrun) == noktaBoslukCevirici(yemekler[i]))
					{
						kontrolDegeri2 = 1;
						break;
					}
					else
					{
						kontrolDegeri2 = 0;
					}
				}
			} while (kontrolDegeri2 == 0);
			//Girdigi yemegin menude olup olmadigina bakiyoruz
			while (yemekDosyasiniOku2 >> urunAdi >> gun >> ay >> yil >> kaloriGram >> fiyat >> alisFiyat)
			{
				if (noktaBoslukCevirici(urunAdi) == noktaBoslukCevirici(satilacakUrun))
				{
					kontrolDegeri3 = 1;
					break;
				}
			}
			//BBu yemegin daha once hazirlanmaya gonderilip gonderilmedigine bakiyoruz
			if (kontrolDegeri3 == 1)
			{
				cout << "---------------------------------------------\n";
				depoyuOku.seekg(0L, ios::end);
				if (depoyuOku.tellg() == 0)
				{
					cout << "---------------------------------------------\n";
					cout << "Depoyu daha once doldurmamisiniz stoklari menude bulunan ucuncu kisimdan dolurabilirsiniz\n";
					cout << "---------------------------------------------\n";
				}
				//Depoda malzamelerin daha once doldurulup doldurulmadigina bakiyoruz. Doldurulmadiysa hata veriyoruz
				else
				{
					depoyuOku.seekg(0);
					int iterasyon3 = 0;
					for (; iterasyon3 < 20; iterasyon3++)
					{
						if (noktaBoslukCevirici(satilacakUrun) == noktaBoslukCevirici(yemekler[iterasyon3]))
						{
							break;
						}
					}
					//Dosyainin imlecini en basa cekiyoruz ve urunun menudeki sirasini ogreniyoruz.
					malzame1Kontrol = yemekMalzameleri[iterasyon3][0];
					malzame2Kontrol = yemekMalzameleri[iterasyon3][1];
					malzame3Kontrol = yemekMalzameleri[iterasyon3][2];

					while (depoyuOku >> depodakiAd >> depodakiStok)
					{
						if (depodakiAd == malzame1Kontrol)
						{
							malzameAdet1 = depodakiStok;
						}
						else if (depodakiAd == malzame2Kontrol)
						{
							malzameAdet2 = depodakiStok;
						}
						else if (depodakiAd == malzame3Kontrol)
						{
							malzameAdet3 = depodakiStok;
						}
					}
					//Depodaki malzamelerin stoklarini kontrol ediyoruz.
					if ((stoi(malzameAdet1) > 0) && (stoi(malzameAdet2) > 0) && (stoi(malzameAdet3) > 0))
					{
						dogrulukKontrolumuz = 1;
					}
					//Stok varsa
					else
					{
						cout << "---------------------------------------------\n";
						cout << "Malzame yetersiz depoyu doldurun(eksik stoga eklendi)\n";
						cout << "---------------------------------------------\n";
						if (stoi(malzameAdet1) <= 0)
						{
							eksikMalzame << malzame1Kontrol << endl;
						}
						if (stoi(malzameAdet2) <= 0)
						{
							eksikMalzame << malzame2Kontrol << endl;
						}
						if (stoi(malzameAdet3) <= 0)
						{
							eksikMalzame << malzame3Kontrol << endl;
						}
						eksikMalzame.close();
					}
					//Stok yoksa bu malzameyi eksik malzame listesine ekliyoruz.
				}
				if (dogrulukKontrolumuz == 1)
				{
					ifstream depoOkuyucu("Depo.txt");
					ofstream gecici("Gecici.txt", ios::app);
					while (depoOkuyucu >> depodakiAd >> depodakiStok)
					{
						if (depodakiAd == malzame1Kontrol)
						{
							gecici << depodakiAd << "    " << to_string(stoi(depodakiStok) - 1) << endl;
						}
						else if (depodakiAd == malzame2Kontrol)
						{
							gecici << depodakiAd << "    " << to_string(stoi(depodakiStok) - 1) << endl;
						}
						else if (depodakiAd == malzame3Kontrol)
						{
							gecici << depodakiAd << "    " << to_string(stoi(depodakiStok) - 1) << endl;
						}
						else
						{
							gecici << depodakiAd << "    " << depodakiStok << endl;
						}
					}
					depoyuOku.close();
					depoOkuyucu.close();
					depoDosyasi.close();
					gecici.close();
					remove("Depo.txt");
					rename("Gecici.txt", "Depo.txt");
					//Varsa kullandigimiz malzameleri eksiltiyoruz.
				}
				if (dogrulukKontrolumuz == 1)
				{
					cout << "---------------------------------------------\n";
					cout << "Urun satisi yapildi\n";
					cout << "---------------------------------------------\n";
					while (yemekDosyasiniOku >> urunAdi >> gun >> ay >> yil >> kaloriGram >> fiyat >> alisFiyat)
					{
						if (noktaBoslukCevirici(satilacakUrun) == noktaBoslukCevirici(urunAdi))
						{
							fiyatsal += stoi(fiyat);
							alisFiyatsal += stoi(alisFiyat);
						}
					}
				}
				//Urunun satisinin yapildigini soyluyoruz ve fiyatlari aliyoruz.
			}
			else
			{
				cout << "---------------------------------------------\n";
				cout << "Bu yemek hazirlanmaya siparis icin gonderilmemis. Hazirlanmamis yemek satisi yapilamaz. Lutfen menude bulunan yemeklerden birini siparis icin hazira gonderin\n";
				cout << "---------------------------------------------\n";
			}
			//Bu yemek ekli degilse hata gosterimi yapiyoruz.
			if (depoDosyasi.is_open())
			{
				depoDosyasi.close();
			}
			//Dosya aciksa kapatiyoruz.
		}
		else if (stoi(islem) == 5)
		{
			cout << "---------------------------------------------\n";
			cout << "Depo: " << endl;
			ifstream depoOkumak("Depo.txt");
			while (depoOkumak >> urunAdiDepo >> urunStoguDepo)
			{
				cout << "Urun Adi: " << urunAdiDepo << "        Stok:  " << urunStoguDepo << endl;
			}
			depoOkumak.close();
			cout << "---------------------------------------------\n";
			cout << "Eksik Malzameler: " << endl;
			ifstream eksikMalzameOkumak("Eksikmalzame.txt");
			while (eksikMalzameOkumak >> eksikMalzamelerEkrana)
			{
				cout << "Eksik Malzame: " << eksikMalzamelerEkrana << endl;
			}
			eksikMalzameOkumak.close();
			cout << "---------------------------------------------\n";
			cout << "Yemek cesitleri:" << endl;
			ifstream yemekCesitOkunurBurada("Yemekcesit.txt");
			while (yemekCesitOkunurBurada >> urunAdiEkrana >> urunGunuEkrana >> urunAyiEkrana >> urunYiliEkrana >> urunKaloriGramEkrana >> urunFiyatEkrana >> urunAlisFiyatEkrana)
			{
				cout << "Urun adi: " << boslukNoktaCevirici(urunAdiEkrana) << "    Urun tarihi: " << urunGunuEkrana << "." << urunAyiEkrana << "." << urunYiliEkrana << "    Urun kalori: " << urunKaloriGramEkrana << "    Urun fiyat: " << urunFiyatEkrana << "    Urun alis fiyati: " << urunAlisFiyatEkrana << endl;
			}
			yemekCesitOkunurBurada.close();
			cout << "---------------------------------------------\n";
			cout << "Malzamaler:\n";
			ifstream malzameOkuyucu("Malzame.txt");
			while (malzameOkuyucu >> malzame1Ekrana >> malzame2Ekrana >> malzame3Ekrana)
			{
				cout << "Malzameler: " << malzame1Ekrana << "    " << malzame2Ekrana << "    " << malzame3Ekrana << endl;
			}
			malzameOkuyucu.close();
			cout << "---------------------------------------------\n";
			cout << "---------------------------------------------\n";
			cout << "Toplam satis: " << fiyatsal << endl;
			cout << "Toplam kar: " << fiyatsal - alisFiyatsal << endl;
			cout << "---------------------------------------------\n";
			//Ekrana rapor bilgilerini yazdiriyoruz.
		}
		else if (stoi(islem) == 6)
		{
			fiyatsal = 0;
			alisFiyatsal = 0;
		}
		//Satis bilgisini sifirliyoruz
		else if (stoi(islem) == 7)
		{
			cout << "-------------------------------------------------------\n";
			cout << "Restoran Menumuz: " << endl;
			cout << "-------------------------------------------------------\n";
			cout << "-------------------------------------------------------\n";
			for (int i = 0; i < 20; i++)
			{
				cout << i + 1 << ")" << yemekler[i] << endl;
			}
			cout << "-------------------------------------------------------\n";
			cout << "-------------------------------------------------------\n";
		}
		//Menumuzu ekrana yazdiriyoruz
		else if (stoi(islem) == 8)
		{
			cout << "Maliyet hesabi yapilmasini istediginiz yemek: ";
			getline(cin, maliyetHesabi);
			do
			{
				cout << "Kac kisi icin: ";
				getline(cin, kisiSayisi);
			} while (gelismisSayiKontrol(kisiSayisi) == 1);
			//Kullanici sadece sayi girene kadar bekliyoruz.
			int belirleyici = 0;
			int belirleyiciKontrol = 0;
			for (; belirleyici < 20; belirleyici++)
			{
				if (noktaBoslukCevirici(maliyetHesabi) == noktaBoslukCevirici(yemekler[belirleyici]))
				{
					belirleyiciKontrol = 1;
					break;
				}
			}
			if (belirleyiciKontrol == 1)
			{
				int buradakiToplam = 0;
				cout << "-------------------------------------------------------\n";
				cout << kisiSayisi << " kisilik bir yemegin malzame gider fiyati: " << stoi(kisiSayisi) * stoi(yemekKisiBasiMaliyeti[belirleyici]) << "\n";
				cout << "-------------------------------------------------------\n";
				cout << "Gerekli malzameler: \n";
				cout << "-------------------------------------------------------\n";
				cout << kisiSayisi << " Tane " << yemekMalzameleri[belirleyici][0] << "    " << kisiSayisi << " Tane "
					<< yemekMalzameleri[belirleyici][1] << "    " << kisiSayisi << " Tane " << yemekMalzameleri[belirleyici][2]
					<< "    Bu yemek icin gereklidir." << endl;
				cout << "-------------------------------------------------------\n";
			}
			else
			{
				cout << "-------------------------------------------------------\n";
				cout << "Menude bu yemek yok\n";
				cout << "-------------------------------------------------------\n";
			}
			//Yemek menude var malzamelerinden maliyet fiyatini yapiyoruz
		}
		else if (stoi(islem) == 9)
		{
			system("cls");
		}
		//Ekrani temizliyoruz
		else if (stoi(islem) == 10)
		{
			break;
		}
		//Uygulamadan cikiyoruz
		else
		{
			cout << "-------------------------------------------------------\n";
			cout << "Bulunamadi\n";
			cout << "-------------------------------------------------------\n";
		}
		//İslem yoksa bulunamadi diyoruz
	}
}
string noktaBoslukCevirici(string alinan)
{
	string yeniAlinan = "";
	int i;
	for (i = 0; i < alinan.length(); i++)
	{
		if (isspace(alinan[i]) == 0)
		{
			yeniAlinan += alinan[i];
		}
		else
		{
			alinan[i] = '.';
			yeniAlinan += alinan[i];
		}
	}
	yeniAlinan[i] = '\0';
	return yeniAlinan;
	//Aldigimiz kelimede txt dosyasina yazdirilirken bosluklar sikinti cikarmasin diye bosluklari nokta yapiyoruz.
}
string boslukNoktaCevirici(string alinan)
{
	string yeniAlinan = "";
	int i;
	for (i = 0; i < alinan.length(); i++)
	{
		if (!(alinan[i] == '.'))
		{
			yeniAlinan += alinan[i];
		}
		else
		{
			alinan[i] = ' ';
			yeniAlinan += alinan[i];
		}
	}
	yeniAlinan[i] = '\0';
	return yeniAlinan;
	//Nokta olan kisimlari bosluk yapiyoruz.
}
int gelismisSayiKontrol(string alinan)
{
	string yeni;
	string yeni2;
	string simdilikYeni;
	string simdilikYeni2;
	string kontrolYeni;
	int kontrol = 0;
	int i;
	//noktayı görene kadar kontrol edip nokta olmayanları yeni bir stringe ekliyoruz.
	for (i = 0; i < alinan.length(); )
	{
		if (alinan[i] == '.')
		{
			kontrol = 1;
			break;
		}
		else
		{
			yeni2 = alinan[i];
			yeni.append(yeni2);
			i++;
		}
	}
	//noktadan sonraki karekterleri yeni stringe ekliyoruz.
	for (int j = i + 1; j < alinan.length(); j++)
	{
		simdilikYeni2 = alinan[j];
		simdilikYeni.append(simdilikYeni2);
	}
	//Bu ifade(karekter katarlarını) yeni bir string de birleştiriyoruz.
	kontrolYeni.append(yeni);
	kontrolYeni.append(simdilikYeni);
	//İlk karekter - ise bunun negatif olduğunu anlatıyoruz.
	if (kontrolYeni[0] == '-')
	{
		//Bunun dışında olanlarda sayı dışında karekter varsa 1 yoksa sıfır döndürüyoruz.
		for (int i = 1; i < kontrolYeni.length(); i++)
		{
			if (isalnum(kontrolYeni[i]) == 0)
			{
				boolKontrol = 1;
				break;
			}
			else
			{
				if (isalpha(kontrolYeni[i]) == 0)
				{
					boolKontrol = 0;
					continue;
				}
				else
				{
					boolKontrol = 1;
					break;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < kontrolYeni.length(); i++)
		{
			//İlk karekter - değilse direkilk ifadeden başlıyoruz kontrole.
			if (isalnum(kontrolYeni[i]) == 0)
			{
				boolKontrol = 1;
				break;
			}
			else
			{
				if (isalpha(kontrolYeni[i]) == 0)
				{
					boolKontrol = 0;
					continue;
				}
				else
				{
					boolKontrol = 1;
					break;
				}
			}
		}
		//Kontrolümüz sonuucu sayıdan başka ifade varsa 1 yoksa 0 döndürüyoruz.
		if (boolKontrol == 1)
		{
			return 1;
		}
		else if (boolKontrol == 0)
		{
			return 0;
		}
	}
	//Kontrolümüz sonuucu sayıdan başka ifade varsa 1 yoksa 0 döndürüyoruz.
	if (boolKontrol == 1)
	{
		return 1;
	}
	else if (boolKontrol == 0)
	{
		return 0;
	}
}
