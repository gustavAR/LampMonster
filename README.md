LampMonster
===========

Vad ?
Deadlines
I slutet veckan (Fredag):
	Naive Bayes fungerande.
	Good/bad & kategorier
	Logo (very important).
	
Lampmonster

Statistics
	% R�tt
	Testdata antal
	Vilka som anv�nds
	Lista alla succeed/fail
	Word weights
	Category trained on
	Algorithm Naive Bayes
	Runtime
	Concrete values of NB
	Ascii loading bar
	
Filsystemet
	H�mta X Test ur kategori y
	Tr�na naive bayes p� dessa
	K�r nave bayes och skriv ut resultat
	Alla textfiler anv�nder timestamp och git repo (Commit)
	
GUI i C# winforms
	
Command line argument
	--All
	-a=NB
	-e 1/2/3 --posneg (evaluate) (andra dataset)
	-t=Books (category name) (train) (indomain)
	-o=Software (out-of-domain category) (output) OBS Aldrig samma filer som -t
	-nt=trainsize
	-no=evalsize
	--testsize=N
	-d --console
	-h (help)
	-r=y/n/1/0 --random
	
------------------------------------------------------
Bygg testfil: |
---------------
1. L�s fil (f�r en str�m) och g�r om till en mapp (givet en mapp och en fil, fyll mappen)		//Gustav g�r detta
2. H�mta alla testfiler och mata dessa (som str�m (filestream)) till funktion fr�n 1.

3. K�r naive bayes p� alla filer 
4. Bayes-funktionen

NaiveBayes: Algorithm 
{
	public NaiveBayes (map<string,Int> bagOfWords){}
	private map<string,Int> bagOfWords;
	double evaluate()