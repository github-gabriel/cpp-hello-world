# C++ Basics

Mit diesem Projekt habe ich nach [dieser Tutorialserie](https://www.youtube.com/watch?v=ETAEYfSeDGc&list=PL58qjcU5nk8tzPn77IDRLpj_kL1IxmT_2&index=2&ab_channel=Brotcrunsher) C++ gelerent. Die Tutorialserie enthält noch fortgeschrittenere C++ Folgen, jedoch sollen in dieser Repo erstmal die C++ Grundlagen festgehalten werden. Um auch alles aus der Serie zu behalten habe ich mir Notizen gemacht, die [hier](https://github.com/github-gabriel/cpp-hello-world/blob/main/C%2B%2B.docx) zu finden sind. Insgesamt sind die Notizen 117 Seiten lang (was vielleicht an der etwas größeren Schriftgröße liegen kann) und sie bestehen aus ca. 10500 Wörtern. Als nächstes möchte ich zuerst mein eigenes C++ Projekt starten und danach werde ich mir die fortgeschritteneren C++ Videos der Serie anschauen. 

# Bank-Projekt

Das "Bank-Projekt" ist mein erstes CPP Projekt. Die grundlegenden Sachen habe ich selber programmiert, jedoch hat mir jemand bei den "Feinheiten" geholfen. Überall wo geholfen wurde, habe ich auch noch einen Kommentar geschrieben, was diese Änderung macht. Da merkt man, dass nur weil man die Theorie kann, sie noch lange nicht in der Praxis anwenden kann bzw. man vergisst sie anzuwenden, auch wenn es nur logisch ist wie z.B. [hier](https://github.com/github-gabriel/cpp-hello-world/blob/main/Bank/Bank.hpp?plain=1#L26), wo man Referenzen verwenden muss, damit die Kunden auch geupdatet werden, was ich jedoch vergessen habe (deswegen dort nochmal als Kommentar). Hier eine kleine Dokumentation meines ersten Projektes:

## Bank:
```cpp
void addKunde(const Kunde &kunde);
```
Diese Methode sorgt dafür, dass ein Kunde (const Referenz) dem Vector ```std::vector<Kunde> kunden;``` hinzugefügt wird.

```cpp
const std::vector<Kunde>& getKunden() const;
```
Diese Methode gibt eine Referenz auf ```std::vector<Kunde> kunden;``` zurück.

```cpp
int getAnzahlKunden() const;
```
Diese Methode gibt die Anzahl der Kunden der Bank zurück.

```cpp
std::string getName() const;
```
Diese Methode gibt den Namen der Bank als einen ```std::string``` zurück.

## Kunde:
```cpp
std::string getName() const;
```
Diese Methode gibt den Namen des Kunden als einen ```std::string``` zurück.

```cpp
float getKontostand() const;
```
Diese Methode gibt den Kontostand des Kunden als einen float zurück.

```cpp
Bank& getBank();
```
Diese Methode gibt eine Referenz auf die Bank des Kunden zurück, damit keine unnötige Kopie angelegt wird.

```cpp
void setKontostand(float betrag);
```
Diese Methode erhöht/reduziert den Kontostand des Kunden um einen bestimmten Betrag betrag, sollten in der Transaktion folgende Bedingungen erfüllt worden sein:
- Der Kunde darf ins Minus
- Der Betrag ist < 0 (also wird dem Konto Geld abgezogen) und der Kontostand minus den Betrag ist trotzdem > 0
- Der Betrag ist > 0

```cpp
bool verify();
```
Diese Methode liest den PIN des Kunden (auf den die Methode aufgerufen wird) ein und verifiziert (bzw. falsifiziert) den Kunden. Wird der Kunde verifiziert wird ein ```true``` zurückgegeben, in allen anderen Fällen wird ```false``` zurückgegeben.

```cpp
void changeBank(Bank *bank_);
```
Diese Methode erwartet einen Pointer auf eine Bank und ändert die aktuelle Bank zu dieser Bank.

```cpp
std::string toString();
```
Diese Methode liefert einen String mit allen Infos über den Kunden.

```cpp
void ueberweisen(Kunde& kunde2, float betrag);
```
Diese Methode erwartet eine Referenz auf einen anderen Kunden und einen Betrag als float. Danach wird der Kontostand des Kunden auf den die Methode ausgeführt wird um den Betrag betrag reduziert und der Kontostand des anderen Kunden um den Betrag betrag erhöht. Außerdem wird am Ende der Überweisung Info über beiden Kunden über die ```toString()``` Methode ausgegeben
