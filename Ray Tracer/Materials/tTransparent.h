//
// tTransparent.h
//

#ifndef ___TTRANSPARENT_H___
#define ___TTRANSPARENT_H___

#include "../BRDFs/tPerfectSpecular.h"
#include "../BTDFs/tPerfectTransmitter.h"
#include "tPhong.h"

//
// tTransparent
//
class tTransparent: public tPhong
{	
	public:
	
		// constructor()
		tTransparent();										

		// destructor()
		~tTransparent();										
		
		// set_kr()
		void set_kr( const float k ) { 	reflective_brdf->set_kr( k ); }
		
		// set_cr()
		void set_cr( const tColor& c ) { reflective_brdf->set_cr( c ); };
		
		// shade()
		tColor shade( tShadeRecord& s );
		
		// set_kt()
		void set_kt( const float k ) { specular_btdf->set_kt( k ); }

		// set_ior()
		void set_ior( const float ior ) { specular_btdf->set_ior( ior ); }

	private:
	
		tPerfectSpecular* reflective_brdf;
		tPerfectTransmitter* specular_btdf;
};

#endif
