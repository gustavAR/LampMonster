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
	% Rätt
	Testdata antal
	Vilka som används
	Lista alla succeed/fail
	Word weights
	Category trained on
	Algorithm Naive Bayes
	Runtime
	Concrete values of NB
	Ascii loading bar
	
Filsystemet
	Hämta X Test ur kategori y
	Träna naive bayes på dessa
	Kör nave bayes och skriv ut resultat
	Alla textfiler använder timestamp och git repo (Commit)
	
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
1. Läs fil (får en ström) och gör om till en mapp (givet en mapp och en fil, fyll mappen)		//Gustav gör detta
2. Hämta alla testfiler och mata dessa (som ström (filestream)) till funktion från 1.

3. Kör naive bayes på alla filer 
4. Bayes-funktionen

NaiveBayes: Algorithm 
{
	public NaiveBayes (map<string,Int> bagOfWords){}
	private map<string,Int> bagOfWords;
	double evaluate()