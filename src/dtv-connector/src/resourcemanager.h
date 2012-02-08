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
#pragma once

#include "types.h"

namespace tuner {

class ResourceManager {
public:
	ResourceManager( const std::string &root, int memoryblocks, int maxModules, DWORD maxModuleSize );
	virtual ~ResourceManager( void );

	//	Paths
	const std::string &rootPath( void ) const;
	std::string applicationsPath( void ) const;
	std::string temporaryPath( void ) const;	
	std::string downloadPath( void ) const;

	//	Utils
	std::string mkTempFileName( const std::string &nameTemplate, bool useTempPath=true ) const;
	FILE *openTempFileName( const std::string &templateFileName, std::string &filename ) const;
	void clean();

	//	Resources
	int memoryblocks() const;
	int maxModules() const;
	DWORD maxModuleSize() const;

protected:
	int mkTemp( const std::string &templateFileName ) const;

private:
	std::string _root;
	int _memoryBlocks;
	int _maxModules;
	DWORD _maxModuleSize;
};
	
}
