/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* Virtual Reality Simulation Lab
*
* This file is part of Virtual Reality Simulation Lab software; you can redistribute 
* it and/or modify it under the terms of the GNU Lesser General Public License as 
* published by the Free Software Foundation; either version 2.1 of the License, or 
* (at your option) any later version.
*
* By the GNU LGP License any changes or modification you made must be sent back 
* to the original owner of the file, and appropriate credit given.
*
* This file is distributed WITHOUT ANY WARRANTY; without even the implied warranty 
* of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General 
* Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library; if not, write to the Free Software Foundation, Inc.,
* 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
* This software was developed by Maxim Serebrennik for various projects he worked on. 
* For more information e-mail him at MaximSter@gmail.com
*
* @author Maxim Serebrennik
*////////////////////////////////////////////////////////////////////////////////

#ifndef UFVG_KDTREE_H
#define UFVG_KDTREE_H

#pragma warning( disable : 4396 )  //disable warning: "the inline specifier cannot be used when a friend declaration refers to a specialization of a function template"

#include <dtUtil/KDTree.h>
namespace vrsUFVG
{	
	struct KDHolder
	{
		typedef float value_type;

		KDHolder(const osg::Vec3& pos)
		{
			d[0] = pos[0];
			d[1] = pos[1];
			d[2] = pos[2];
		}

		KDHolder(const osg::Vec3& pos, int id)
		{
			d[0] = pos[0];
			d[1] = pos[1];
			d[2] = pos[2];

			mID = id;
		}
/*
		KDHolder(value_type a, value_type b, value_type c)
		{
			d[0] = a;
			d[1] = b;
			d[2] = c;
		}

		KDHolder(const KDHolder& x)
		{
			d[0] = x.d[0];
			d[1] = x.d[1];
			d[2] = x.d[2];
			mID = x.mID;
		}

		operator osg::Vec3()
		{
			return osg::Vec3(d[0], d[1], d[2]);
		}
*/
		inline value_type operator[](size_t const N) const { return d[N]; }

		int mID;
		value_type d[3];      
	};

	inline float KDHolderIndexFunc(KDHolder t, size_t k ) { return t[k]; }

	typedef std::pointer_to_binary_function<KDHolder, size_t, float> tree_search_func;
	typedef dtUtil::KDTree<3, KDHolder, tree_search_func> ColumnKDTree;
	typedef std::pair<ColumnKDTree::const_iterator, float> find_result;

}

#endif //UFVG_KDTREE_H