#include "translation.h"
#include <iostream>

using namespace std;

template <class A, class B>
void equal(A a, B b)
{
	if (a == b)
		cout << "ok" << endl;
	else
	{
		cout << "FAIL: " << a << " != " << b << endl;
//		exit(1);
	}
}

int main(int argc, char const *argv[])
{
	{
		Translation tr;
		string r;
		tr.translate("ACT", 0, r);
		equal(r, "T");

		string human = "GGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGAGGATCGCTTGAGCCCAGGAGTTCGAGACCAGCCTGGGCAACATAGCGAGACCCCGTCTCTACAAAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAGTCCCAGCTACTCGGGAGGCTGAGGCAGGAGGATCGCTTGAGCCCAGGAGTTCGAGGCTGCAGTGAGCTATGATCGCGCCACTGCACTCCAGCCTGGGCGACAGAGCGAGACCCTGTCTC";

		string frame0, frame1, frame2;
		tr.translate(human, 0, frame0);
		tr.translate(human, 1, frame1);
		tr.translate(human, 2, frame2);

		equal(frame0, "GRARWLTPVIPALWEAEAGGSLEPRSSRPAWAT*RDPVSTKNTKISRAWWRAPVVPATREAEAGGSLEPRSSRLQ*AMIAPLHSSLGDRARPCL");
		equal(frame1, "AGRGGSRL*SQHFGRPRREDRLSPGVRDQPGQHSETPSLQKIQKLAGRGGARL*SQLLGRLRQEDRLSPGVRGCSEL*SRHCTPAWATERDPV");
		equal(frame2, "PGAVAHACNPSTLGGRGGRIA*AQEFETSLGNIARPRLYKKYKN*PGVVARACSPSYSGG*GRRIA*AQEFEAAVSYDRATALQPGRQSETLS");
	}

}
