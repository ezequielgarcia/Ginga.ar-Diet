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
#include "dii.h"
#include <boost/foreach.hpp>
#include <stdio.h>

namespace tuner {
namespace dsmcc {

DII::DII( DWORD downloadID, WORD blockSize,
	const compatibility::Descriptors &compatibilities,
	const module::Modules &modules, const Buffer &privateData )
	: _privateData( privateData )
{
	_downloadID = downloadID;
	_blockSize  = blockSize;
	_compatibilities = compatibilities;
	_modules = modules;
}

DII::~DII( void )
{
}

//	Getters
DWORD DII::downloadID() const {
	return _downloadID;
}

WORD  DII::blockSize() const {
	return _blockSize;
}

const compatibility::Descriptors &DII::compatibilities() const {
	return _compatibilities;
}

const module::Modules &DII::modules() const {
	return _modules;
}

const Buffer &DII::privateData() const {
	return _privateData;
}

void DII::show() const {
	printf( "[DII] downloadID=%lx, blockSize=%d, modules=%d, compatibilities=%d, priv=%d\n",
		_downloadID, _blockSize, _modules.size(), _compatibilities.size(),  _privateData.length() );

	BOOST_FOREACH(const module::Type &mod, _modules) {
		printf( "[DII]\t moduleID=%04x, size=%08ld, version=%02x, info=%d\n",
			mod.id, mod.size, mod.version, mod.info.length() );
	}
}

}
}
