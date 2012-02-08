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
#include "hbbtvprofile.h"
#include "../../../application.h"

namespace tuner {
namespace app {

HbbtvProfile::HbbtvProfile( ApplicationExtension *ext )
	: Profile( ext )
{
}

HbbtvProfile::~HbbtvProfile( void )
{
}

bool HbbtvProfile::isSupported( ID /*type*/ ) const {
	return true;
}

bool HbbtvProfile::isProfileSupported( const ait::ApplicationProfile &/*appProfile*/ ) const {
	return true;
}

Application *HbbtvProfile::create( const ApplicationID &appID, const std::string &file ) const {
	return new Application( extension(), appID, file );
}

Application *HbbtvProfile::create( const ApplicationID &appID ) const {
	return new Application( extension(), appID );
}

}
}
