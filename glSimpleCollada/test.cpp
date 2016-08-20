#include <dae.h>

/*
http://collada.org/mediawiki/index.php/COLLADA_DOM_user_guide
http://collada.org/mediawiki/index.php/DOM_guide:_Setting_up
http://collada.org/mediawiki/index.php/DOM_guide:_Creating_documents
*/
int main() {
	DAE dae;
	dae.add("simple.dae");
	dae.writeAll();
	return 0;
}
