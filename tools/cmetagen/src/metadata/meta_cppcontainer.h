/*@@cpgf@@*/
// Auto generated file, don't modify.

/*@cpgf@creations@@
createMetaClass_metagen_CppContainer
createMetaClass_metagen_namespace_cppcontainer
@@cpgf@creations@*/

#ifndef METADATA_META_CPPCONTAINER_H
#define METADATA_META_CPPCONTAINER_H

#include "cpgf/gmetadefine.h"
#include "cpgf/gmetapolicy.h"
#include "cpgf/gscopedinterface.h"
#include "cpgf/gselectFunctionByArity.h"
#include "cpgf/metadata/private/gmetadata_header.h"
#include "cpgf/metatraits/gmetaconverter_string.h"
#include "cpgf/scriptbind/gscriptbindutil.h"
#include "cpgf/scriptbind/gscriptwrapper.h"
#include "model/cppcontainer.h"

namespace metadata {

template <typename TsE1f>
metagen::CppContainer &oPeRat0rWrapPer_metagen_CppContainer_opAssign_0(TsE1f * sE1F, const metagen::CppContainer &pAr9_Am0)
{
    return (*sE1F) = pAr9_Am0;
}

template <typename D_d >
void buildMetaClass_metagen_namespace_cppcontainer(D_d & _d)
{
    using namespace cpgf;
    
    (void)_d;
    
    _d.CPGF_MD_TEMPLATE _method("getCppContainerInstantiationName", &metagen::getCppContainerInstantiationName);

}

template <typename D_d >
void buildMetaClass_metagen_CppContainer(D_d & _d)
{
    using namespace cpgf;
    
    (void)_d;
    
    _d.CPGF_MD_TEMPLATE _base<metagen::CppNamedItem >();

    _d.CPGF_MD_TEMPLATE _method("getItemList", &D_d::ClassType::getItemList);
    _d.CPGF_MD_TEMPLATE _method("getNamespaceList", &D_d::ClassType::getNamespaceList);
    _d.CPGF_MD_TEMPLATE _method("getClassList", &D_d::ClassType::getClassList);
    _d.CPGF_MD_TEMPLATE _method("getFieldList", &D_d::ClassType::getFieldList);
    _d.CPGF_MD_TEMPLATE _method("getMethodList", &D_d::ClassType::getMethodList);
    _d.CPGF_MD_TEMPLATE _method("getEnumList", &D_d::ClassType::getEnumList);
    _d.CPGF_MD_TEMPLATE _method("getOperatorList", &D_d::ClassType::getOperatorList);
    _d.CPGF_MD_TEMPLATE _method("getSameNamedItemCount", &D_d::ClassType::getSameNamedItemCount);
    _d.CPGF_MD_TEMPLATE _method("isContainer", &D_d::ClassType::isContainer);
    _d.CPGF_MD_TEMPLATE _method("dump", &D_d::ClassType::dump);

    _d.CPGF_MD_TEMPLATE _operator<metagen::CppContainer &(*)(cpgf::GMetaSelf, const metagen::CppContainer &)>(mopHolder = mopHolder, cpgf::MakePolicy<GMetaRuleCopyConstReference<0> >());
    _d.CPGF_MD_TEMPLATE _method("_opAssign", &oPeRat0rWrapPer_metagen_CppContainer_opAssign_0<typename D_d::ClassType >);

}

cpgf::GDefineMetaInfo createMetaClass_metagen_namespace_cppcontainer();
cpgf::GDefineMetaInfo createMetaClass_metagen_CppContainer();

} // namespace metadata
#include "cpgf/metadata/private/gmetadata_footer.h"

#endif
