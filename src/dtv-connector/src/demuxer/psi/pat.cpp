/*******************************************************************************

  Copyright (C) 2010, 2011 LIFIA - Facultad de Informatica - Univ. Nacional de La Plata

********************************************************************************

  This file is part of DTV-connector implementation.

    DTV-connector is free software: you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License as published by the Free
  Software Foundation, either version 2 of the License.

    DTV-connector is distributed in the hope that it will be useful, but WITHOUT ANY
  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
  A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License along with
  this program. If not, see <http://www.gnu.org/licenses/>.

********************************************************************************

  Este archivo es parte de la implementación de DTV-connector.

    DTV-connector es Software Libre: Ud. puede redistribuirlo y/o modificarlo
  bajo los términos de la Licencia Pública General Reducida GNU como es publicada por la
  Free Software Foundation, según la versión 2 de la licencia.

    DTV-connector se distribuye esperando que resulte de utilidad, pero SIN NINGUNA
  GARANTÍA; ni siquiera la garantía implícita de COMERCIALIZACIÓN o ADECUACIÓN
  PARA ALGÚN PROPÓSITO PARTICULAR. Para más detalles, revise la Licencia Pública
  General Reducida GNU.

    Ud. debería haber recibido una copia de la Licencia Pública General Reducida GNU
  junto a este programa. Si no, puede verla en <http://www.gnu.org/licenses/>.

*******************************************************************************/
#include "pat.h"
#include "../ts.h"
#include <set>
#include <stdio.h>

namespace tuner {

Pat::Pat( Version version, ID tsID, ID nitPID, Programs &programs )
{
	_version  = version;
	_tsID     = tsID;
	_nitPid   = nitPID;
	_programs = programs;
}

Pat::~Pat( void )
{
}

//  Getters
Version Pat::version() const {
	return _version;
}

ID Pat::tsID() const {
	return _tsID;
}

ID Pat::nitPid() const {
	return _nitPid;
}

Pat::Programs &Pat::programs() {
	return _programs;
}

void Pat::show() const {
	printf( "[Pat] PAT: nit=%04x, tsID=%04x, version=%04x\n", _nitPid, _tsID, _version );

	Pat::Programs::const_iterator it;	
    for (it=_programs.begin(); it!=_programs.end(); ++it) {
        printf( "[Pat]\tprogram=%04x, pid=%04x\n", (*it).program, (*it).pid );
    }	
}

}
