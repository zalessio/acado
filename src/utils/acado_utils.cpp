/*
 *    This file is part of ACADO Toolkit.
 *
 *    ACADO Toolkit -- A Toolkit for Automatic Control and Dynamic Optimization.
 *    Copyright (C) 2008-2011 by Boris Houska and Hans Joachim Ferreau, K.U.Leuven.
 *    Developed within the Optimization in Engineering Center (OPTEC) under
 *    supervision of Moritz Diehl. All rights reserved.
 *
 *    ACADO Toolkit is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 3 of the License, or (at your option) any later version.
 *
 *    ACADO Toolkit is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with ACADO Toolkit; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */


/**
 *    \file src/utils/acado_utils.cpp
 *    \author Hans Joachim Ferreau, Boris Houska
 *    \date 31.05.2008
 */


#if defined(__WIN32__) || defined(WIN32)
  #include <windows.h>
#elif defined(LINUX)
  #include <sys/stat.h>
  #include <sys/time.h>
#endif


#include <acado/utils/acado_utils.hpp>

#include <iostream>
#include <fstream>

BEGIN_NAMESPACE_ACADO



/*
 *	p r i n t C o p y r i g h t N o t i c e
 */
returnValue acadoPrintCopyrightNotice(	const char* subpackage
										)
{
	if ( subpackage == 0 )
		return ((returnValue) acadoPrintf(
				"\nACADO Toolkit -- A Toolkit for Automatic Control and Dynamic Optimization.\n" \
				"Copyright (C) 2008-2013 by Boris Houska and Hans Joachim Ferreau et al, KU Leuven.\n" \
				"Developed within the Optimization in Engineering Center (OPTEC) under\n" \
				"supervision of Moritz Diehl. All rights reserved.\n\n" \
				"ACADO Toolkit is distributed under the terms of the GNU Lesser\n" \
				"General Public License 3 in the hope that it will be useful,\n" \
				"but WITHOUT ANY WARRANTY; without even the implied warranty of\n" \
				"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the\n" \
				"GNU Lesser General Public License for more details.\n\n" ) );
	else
		return ((returnValue) acadoPrintf(
				"\nACADO Toolkit::%s\n" \
				"Copyright (C) 2008-2013 by Boris Houska and Hans Joachim Ferreau et al, KU Leuven.\n" \
				"Developed within the Optimization in Engineering Center (OPTEC) under\n" \
				"supervision of Moritz Diehl. All rights reserved.\n\n" \
				"ACADO Toolkit is distributed under the terms of the GNU Lesser\n" \
				"General Public License 3 in the hope that it will be useful,\n" \
				"but WITHOUT ANY WARRANTY; without even the implied warranty of\n" \
				"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the\n" \
				"GNU Lesser General Public License for more details.\n\n", subpackage ));
}


returnValue acadoPrintAutoGenerationNotice(	FILE* file,
											const char* commentString
											)
{
	if ( commentString == 0 )
	{
		acadoFPrintf( file,"/*\n" );
		acadoFPrintf( file," *    This file was auto-generated by ACADO Code Generation Tool.\n" );
		acadoFPrintf( file," *\n" );
		acadoFPrintf( file," *    ACADO Code Generation tool is a sub-package of ACADO toolkit --\n" );
		acadoFPrintf( file," *    A Toolkit for Automatic Control and Dynamic Optimization.\n" );
		acadoFPrintf( file," *    Copyright (C) 2008 - 2013 by Boris Houska, Hans Joachim Ferreau,\n" );
		acadoFPrintf( file," *    Milan Vukov and Rien Quirynen.\n" );
		acadoFPrintf( file," *    Developed within the Optimization in Engineering Center (OPTEC) under\n" );
		acadoFPrintf( file," *    supervision of Moritz Diehl. All rights reserved.\n" );
		acadoFPrintf( file," *\n" );
		acadoFPrintf( file," *    ACADO Toolkit is free software; you can redistribute it and/or\n" );
		acadoFPrintf( file," *    modify it under the terms of the GNU Lesser General Public\n" );
		acadoFPrintf( file," *    License as published by the Free Software Foundation; either\n" );
		acadoFPrintf( file," *    version 3 of the License, or (at your option) any later version.\n" );
		acadoFPrintf( file," *\n" );
		acadoFPrintf( file," *    ACADO Toolkit is distributed in the hope that it will be useful,\n" );
		acadoFPrintf( file," *    but WITHOUT ANY WARRANTY; without even the implied warranty of\n" );
		acadoFPrintf( file," *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU\n" );
		acadoFPrintf( file," *    Lesser General Public License for more details.\n" );
		acadoFPrintf( file," *\n" );
		acadoFPrintf( file," *    You should have received a copy of the GNU Lesser General Public\n" );
		acadoFPrintf( file," *    License along with ACADO Toolkit; if not, write to the Free Software\n" );
		acadoFPrintf( file," *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA\n" );
		acadoFPrintf( file," *\n" );
		acadoFPrintf( file," */\n" );
	}
	else
	{
		acadoFPrintf( file,"%s\n", commentString);
		acadoFPrintf( file,"%s    This file was auto-generated by ACADO Code Generation Tool.\n", commentString);
		acadoFPrintf( file,"%s\n", commentString);
		acadoFPrintf( file,"%s    ACADO Code Generation tool is a sub-package of ACADO toolkit --\n", commentString);
		acadoFPrintf( file,"%s    A Toolkit for Automatic Control and Dynamic Optimization.\n", commentString);
		acadoFPrintf( file,"%s    Copyright (C) 2008 - 2013 by Boris Houska, Hans Joachim Ferreau,\n", commentString);
		acadoFPrintf( file,"%s    Milan Vukov and Rien Quirynen.\n", commentString);
		acadoFPrintf( file,"%s    Developed within the Optimization in Engineering Center (OPTEC) under\n", commentString);
		acadoFPrintf( file,"%s    supervision of Moritz Diehl. All rights reserved.\n", commentString);
		acadoFPrintf( file,"%s\n", commentString);
		acadoFPrintf( file,"%s    ACADO Toolkit is free software; you can redistribute it and/or\n", commentString);
		acadoFPrintf( file,"%s    modify it under the terms of the GNU Lesser General Public\n", commentString);
		acadoFPrintf( file,"%s    License as published by the Free Software Foundation; either\n", commentString);
		acadoFPrintf( file,"%s    version 3 of the License, or (at your option) any later version.\n", commentString);
		acadoFPrintf( file,"%s\n", commentString);
		acadoFPrintf( file,"%s    ACADO Toolkit is distributed in the hope that it will be useful,\n", commentString);
		acadoFPrintf( file,"%s    but WITHOUT ANY WARRANTY; without even the implied warranty of\n", commentString);
		acadoFPrintf( file,"%s    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU\n", commentString);
		acadoFPrintf( file,"%s    Lesser General Public License for more details.\n", commentString);
		acadoFPrintf( file,"%s\n", commentString);
		acadoFPrintf( file,"%s    You should have received a copy of the GNU Lesser General Public\n", commentString);
		acadoFPrintf( file,"%s    License along with ACADO Toolkit; if not, write to the Free Software\n", commentString);
		acadoFPrintf( file,"%s    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA\n", commentString);
		acadoFPrintf( file,"%s\n", commentString);
		acadoFPrintf( file,"%s/\n", commentString);
	}

	acadoFPrintf(file,"\n");
	acadoFPrintf(file,"\n");

    return SUCCESSFUL_RETURN;
}



/*
 *	g e t C P U t i m e
 */
double acadoGetTime( )
{
	double current_time = 0.0;

	#if defined(__WIN32__) || defined(WIN32)
	LARGE_INTEGER counter, frequency;
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&counter);
	current_time = ((double) counter.QuadPart) / ((double) frequency.QuadPart);
	#elif defined(LINUX)
	struct timeval theclock;
	gettimeofday( &theclock,0 );
	current_time = 1.0*theclock.tv_sec + 1.0e-6*theclock.tv_usec;
	#endif

	return current_time;
}


BooleanType acadoIsInteger( double x )
{
	//if ( fabs( x - floor( x + 0.5) ) < 10000.0*EPS )
	if ( fabs( x - floor( x + 0.5) ) < 1.0e-5 )
		return BT_TRUE;
	else
		return BT_FALSE;
}


double acadoDiv( double nom, double den )
{
	if ( acadoIsInteger( nom/den ) == BT_TRUE )
		return floor( nom/den + 0.5 );
	else
		return floor( nom/den );
}


double acadoMod( double nom, double den )
{
	if ( acadoIsInteger( nom/den ) == BT_TRUE )
		return 0.0;
	else
		return ( nom/den ) - floor( nom/den );
}


int acadoMax( const int x, const int y ){

    return (y<x)?x:y;
}


double acadoMax( const double x, const double y ){

    return (y<x)?x:y;
}


int acadoMin( const int x, const int y ){

    return (y>x)?x:y;
}


double acadoMin( const double x, const double y ){

    return (y>x)?x:y;
}


BooleanType acadoIsEqual( const char* str1, const char* str2 )
{
	if ( ( str1 == 0 ) && ( str2 == 0 ) )
		return BT_TRUE;

	if ( ( str1 == 0 ) && ( str2 != 0 ) )
		return BT_FALSE;

	if ( ( str1 != 0 ) && ( str2 == 0 ) )
		return BT_FALSE;

	if ( strcmp( str1,str2 ) == 0 )
		return BT_TRUE;
	else
		return BT_FALSE;
}


BooleanType acadoIsEqual( double x, double y, double TOL ){

	if( acadoMax(x,y) > 1)
	{
		// use relative error
		if ( fabs( x-y )/acadoMax(x,y) >= 10.0*TOL ) return BT_FALSE;
		else                      return BT_TRUE ;
	}
	else
	{
		// use absolute error
		if ( fabs( x-y ) >= 10.0*TOL ) return BT_FALSE;
		else                      return BT_TRUE ;
	}
}


BooleanType acadoIsGreater( double x, double y, double TOL ){

    if ( x >= y - TOL ) return BT_TRUE ;
    else                return BT_FALSE;
}


BooleanType acadoIsSmaller( double x, double y, double TOL ){

    if ( x <= y + TOL ) return BT_TRUE ;
    else                return BT_FALSE;
}


BooleanType acadoIsStrictlyGreater( double x, double y, double TOL ){

    if ( x > y + TOL ) return BT_TRUE ;
    else                return BT_FALSE;
}


BooleanType acadoIsStrictlySmaller( double x, double y, double TOL ){

    if ( x < y - TOL ) return BT_TRUE ;
    else                return BT_FALSE;
}


BooleanType acadoIsPositive( double x, double TOL ){

    if ( x >= TOL ) return BT_TRUE ;
    else            return BT_FALSE;
}


BooleanType acadoIsNegative( double x, double TOL ){

    if ( x <= -TOL ) return BT_TRUE ;
    else             return BT_FALSE;
}


BooleanType acadoIsZero( double x, double TOL ){

    return acadoIsEqual( x, 0.0, TOL );
}


BooleanType acadoIsInfty( double x, double TOL )
{
	if ( ( acadoIsGreater( x, INFTY, TOL ) == BT_TRUE ) ||
		 ( acadoIsSmaller( x,-INFTY, TOL ) == BT_TRUE ) )
		return BT_TRUE;
	else
		return BT_FALSE;
}


BooleanType acadoIsFinite( double x, double TOL )
{
	if ( ( acadoIsStrictlySmaller( x, INFTY, TOL ) == BT_TRUE ) &&
		 ( acadoIsStrictlyGreater( x,-INFTY, TOL ) == BT_TRUE ) )
		return BT_TRUE;
	else
		return BT_FALSE;
}


BooleanType acadoIsNaN(	double x
						)
{
	if ( ( x > -1.0 ) || ( x < 1.0 ) )
		return BT_FALSE;
	else
		return BT_TRUE;
}



int acadoRound (double x){

	if (x - floor(x) > 0.5)
		return (int)ceil(x);
	else
		return (int)floor(x);

}



int acadoRoundAway (double x) {

	return x < 0 ? floor(x) : ceil(x);
}


returnValue acadoAssignString(	char** toString,
								const char* const fromString,
								const char* const defaultString
								)
{
	if ( *toString == 0 )
		*toString = new char[MAX_LENGTH_NAME+1];

	if ( fromString != 0 )
	{
		for( uint i=0; i<=MAX_LENGTH_NAME; ++i )
		{
			(*toString)[i] = fromString[i];

			if ( fromString[i] == '\0' )
				break;
		}
	}
	else
	{
		/* if fromString is empty, use defaultString */
		if ( defaultString != 0 )
		{
			for( uint i=0; i<=MAX_LENGTH_NAME; ++i )
			{
				(*toString)[i] = defaultString[i];

				if ( defaultString[i] == '\0' )
					break;
			}
		}
		else
			return ACADOERROR( RET_UNKNOWN_BUG );
	}

	return SUCCESSFUL_RETURN;
}

returnValue acadoCopyFile(	const char* source,
							const char* destination
							)
{
	std::ifstream  src( source );
	if (src.is_open() == false)
		return ACADOERRORTEXT(RET_INVALID_ARGUMENTS, "Could not open the input file");

	std::ofstream  dst( destination );
	if (dst.is_open() == false)
			return ACADOERRORTEXT(RET_INVALID_ARGUMENTS, "Could not open the output file");

	dst << src.rdbuf();

	return SUCCESSFUL_RETURN;
}

CLOSE_NAMESPACE_ACADO


/*
 *	end of file
 */
