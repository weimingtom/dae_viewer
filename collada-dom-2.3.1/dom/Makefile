CPP := g++
RM := rm -f

CPPFLAGS := -Wall -pedantic -std=gnu++0x
CPPFLAGS += -DCOLLADA14 
#CPPFLAGS += -DDOM_DYNAMIC 
#CPPFLAGS += -DDOM_EXPORT 
CPPFLAGS += -DDOM_INCLUDE_LIBXML 
CPPFLAGS += -DPCRE_STATIC
CPPFLAGS += -Iinclude -Iinclude/1.4 
CPPFLAGS += -I../../libxml2-2.7.8/include 
CPPFLAGS += -I../../pcre-8.20 
CPPFLAGS += -I../../boost_1_47_0
CPPFLAGS += -I../../minizip

# -Wall -O2 -DNDEBUG -mno-cygwin
# -DBOOST_NO_STD_LOCALE
# -DTINYXML
# libtinyxml.a

# colladaVersion := 1.4
# domMajorVersion := 2
# domMinorVersion := 2 
BIN := libcollada14dom.a
OBJS := 

OBJS += src/dae/dae.o 
OBJS += src/dae/daeArray.o 
OBJS += src/dae/daeAtomicType.o 
OBJS += src/dae/daeDatabase.o 
OBJS += src/dae/daeDocument.o 
OBJS += src/dae/daeDom.o 
OBJS += src/dae/daeElement.o 
OBJS += src/dae/daeError.o 
OBJS += src/dae/daeErrorHandler.o 
OBJS += src/dae/daeIDRef.o 
OBJS += src/dae/daeIOPluginCommon.o 
OBJS += src/dae/daeMemorySystem.o 
OBJS += src/dae/daeMetaAny.o 
OBJS += src/dae/daeMetaAttribute.o 
OBJS += src/dae/daeMetaCMPolicy.o 
OBJS += src/dae/daeMetaChoice.o 
OBJS += src/dae/daeMetaElement.o 
OBJS += src/dae/daeMetaElementAttribute.o 
OBJS += src/dae/daeMetaGroup.o 
OBJS += src/dae/daeMetaSequence.o 
OBJS += src/dae/daeRawResolver.o 
OBJS += src/dae/daeRefCountedObj.o 
OBJS += src/dae/daeSIDResolver.o 
OBJS += src/dae/daeStandardURIResolver.o 
OBJS += src/dae/daeStringRef.o 
OBJS += src/dae/daeStringTable.o 
OBJS += src/dae/daeTinyXMLPlugin.o 
OBJS += src/dae/daeURI.o 
OBJS += src/dae/daeUtils.o 
OBJS += src/dae/daeZAEUncompressHandler.o 
OBJS += src/dae/domAny.o

OBJS += src/modules/stdErrPlugin/stdErrPlugin.o 
OBJS += src/modules/STLDatabase/daeSTLDatabase.o 
OBJS += src/modules/LIBXMLPlugin/daeLIBXMLPlugin.o 

OBJS += src/1.4/dom/domAccessor.o 
OBJS += src/1.4/dom/domAnimation.o 
OBJS += src/1.4/dom/domAnimation_clip.o 
OBJS += src/1.4/dom/domAsset.o 
OBJS += src/1.4/dom/domBind_material.o 
OBJS += src/1.4/dom/domBool_array.o 
OBJS += src/1.4/dom/domBox.o 
OBJS += src/1.4/dom/domCOLLADA.o 
OBJS += src/1.4/dom/domCamera.o 
OBJS += src/1.4/dom/domCapsule.o 
OBJS += src/1.4/dom/domCg_connect_param.o 
OBJS += src/1.4/dom/domCg_newarray_type.o 
OBJS += src/1.4/dom/domCg_newparam.o 
OBJS += src/1.4/dom/domCg_param_type.o 
OBJS += src/1.4/dom/domCg_sampler1D.o 
OBJS += src/1.4/dom/domCg_sampler2D.o 
OBJS += src/1.4/dom/domCg_sampler3D.o 
OBJS += src/1.4/dom/domCg_samplerCUBE.o 
OBJS += src/1.4/dom/domCg_samplerDEPTH.o 
OBJS += src/1.4/dom/domCg_samplerRECT.o 
OBJS += src/1.4/dom/domCg_setarray_type.o 
OBJS += src/1.4/dom/domCg_setparam.o 
OBJS += src/1.4/dom/domCg_setparam_simple.o 
OBJS += src/1.4/dom/domCg_setuser_type.o 
OBJS += src/1.4/dom/domCg_surface_type.o 
OBJS += src/1.4/dom/domChannel.o 
OBJS += src/1.4/dom/domCommon_color_or_texture_type.o 
OBJS += src/1.4/dom/domCommon_float_or_param_type.o 
OBJS += src/1.4/dom/domCommon_newparam_type.o 
OBJS += src/1.4/dom/domCommon_transparent_type.o 
OBJS += src/1.4/dom/domConstants.o 
OBJS += src/1.4/dom/domController.o 
OBJS += src/1.4/dom/domConvex_mesh.o 
OBJS += src/1.4/dom/domCylinder.o 
OBJS += src/1.4/dom/domEffect.o 
OBJS += src/1.4/dom/domEllipsoid.o 
OBJS += src/1.4/dom/domExtra.o 
OBJS += src/1.4/dom/domFloat_array.o 
OBJS += src/1.4/dom/domForce_field.o 
OBJS += src/1.4/dom/domFx_annotate_common.o 
OBJS += src/1.4/dom/domFx_annotate_type_common.o 
OBJS += src/1.4/dom/domFx_basic_type_common.o 
OBJS += src/1.4/dom/domFx_clearcolor_common.o 
OBJS += src/1.4/dom/domFx_cleardepth_common.o 
OBJS += src/1.4/dom/domFx_clearstencil_common.o 
OBJS += src/1.4/dom/domFx_code_profile.o 
OBJS += src/1.4/dom/domFx_colortarget_common.o 
OBJS += src/1.4/dom/domFx_depthtarget_common.o 
OBJS += src/1.4/dom/domFx_include_common.o 
OBJS += src/1.4/dom/domFx_newparam_common.o 
OBJS += src/1.4/dom/domFx_profile_abstract.o 
OBJS += src/1.4/dom/domFx_sampler1D_common.o 
OBJS += src/1.4/dom/domFx_sampler2D_common.o 
OBJS += src/1.4/dom/domFx_sampler3D_common.o 
OBJS += src/1.4/dom/domFx_samplerCUBE_common.o 
OBJS += src/1.4/dom/domFx_samplerDEPTH_common.o 
OBJS += src/1.4/dom/domFx_samplerRECT_common.o 
OBJS += src/1.4/dom/domFx_stenciltarget_common.o 
OBJS += src/1.4/dom/domFx_surface_common.o 
OBJS += src/1.4/dom/domFx_surface_format_hint_common.o 
OBJS += src/1.4/dom/domFx_surface_init_common.o 
OBJS += src/1.4/dom/domFx_surface_init_cube_common.o 
OBJS += src/1.4/dom/domFx_surface_init_from_common.o 
OBJS += src/1.4/dom/domFx_surface_init_planar_common.o 
OBJS += src/1.4/dom/domFx_surface_init_volume_common.o 
OBJS += src/1.4/dom/domGeometry.o 
OBJS += src/1.4/dom/domGl_hook_abstract.o 
OBJS += src/1.4/dom/domGl_pipeline_settings.o 
OBJS += src/1.4/dom/domGl_sampler1D.o 
OBJS += src/1.4/dom/domGl_sampler2D.o 
OBJS += src/1.4/dom/domGl_sampler3D.o 
OBJS += src/1.4/dom/domGl_samplerCUBE.o 
OBJS += src/1.4/dom/domGl_samplerDEPTH.o 
OBJS += src/1.4/dom/domGl_samplerRECT.o 
OBJS += src/1.4/dom/domGles_basic_type_common.o 
OBJS += src/1.4/dom/domGles_newparam.o 
OBJS += src/1.4/dom/domGles_pipeline_settings.o 
OBJS += src/1.4/dom/domGles_sampler_state.o 
OBJS += src/1.4/dom/domGles_texcombiner_argumentAlpha_type.o 
OBJS += src/1.4/dom/domGles_texcombiner_argumentRGB_type.o 
OBJS += src/1.4/dom/domGles_texcombiner_commandAlpha_type.o 
OBJS += src/1.4/dom/domGles_texcombiner_commandRGB_type.o 
OBJS += src/1.4/dom/domGles_texcombiner_command_type.o 
OBJS += src/1.4/dom/domGles_texenv_command_type.o 
OBJS += src/1.4/dom/domGles_texture_constant_type.o 
OBJS += src/1.4/dom/domGles_texture_pipeline.o 
OBJS += src/1.4/dom/domGles_texture_unit.o 
OBJS += src/1.4/dom/domGlsl_newarray_type.o 
OBJS += src/1.4/dom/domGlsl_newparam.o 
OBJS += src/1.4/dom/domGlsl_param_type.o 
OBJS += src/1.4/dom/domGlsl_setarray_type.o 
OBJS += src/1.4/dom/domGlsl_setparam.o 
OBJS += src/1.4/dom/domGlsl_setparam_simple.o 
OBJS += src/1.4/dom/domGlsl_surface_type.o 
OBJS += src/1.4/dom/domIDREF_array.o 
OBJS += src/1.4/dom/domImage.o 
OBJS += src/1.4/dom/domInputGlobal.o 
OBJS += src/1.4/dom/domInputLocal.o 
OBJS += src/1.4/dom/domInputLocalOffset.o 
OBJS += src/1.4/dom/domInstanceWithExtra.o 
OBJS += src/1.4/dom/domInstance_camera.o 
OBJS += src/1.4/dom/domInstance_controller.o 
OBJS += src/1.4/dom/domInstance_effect.o 
OBJS += src/1.4/dom/domInstance_force_field.o 
OBJS += src/1.4/dom/domInstance_geometry.o 
OBJS += src/1.4/dom/domInstance_light.o 
OBJS += src/1.4/dom/domInstance_material.o 
OBJS += src/1.4/dom/domInstance_node.o 
OBJS += src/1.4/dom/domInstance_physics_material.o 
OBJS += src/1.4/dom/domInstance_physics_model.o 
OBJS += src/1.4/dom/domInstance_rigid_body.o 
OBJS += src/1.4/dom/domInstance_rigid_constraint.o 
OBJS += src/1.4/dom/domInt_array.o 
OBJS += src/1.4/dom/domLibrary_animation_clips.o 
OBJS += src/1.4/dom/domLibrary_animations.o 
OBJS += src/1.4/dom/domLibrary_cameras.o 
OBJS += src/1.4/dom/domLibrary_controllers.o 
OBJS += src/1.4/dom/domLibrary_effects.o 
OBJS += src/1.4/dom/domLibrary_force_fields.o 
OBJS += src/1.4/dom/domLibrary_geometries.o 
OBJS += src/1.4/dom/domLibrary_images.o 
OBJS += src/1.4/dom/domLibrary_lights.o 
OBJS += src/1.4/dom/domLibrary_materials.o 
OBJS += src/1.4/dom/domLibrary_nodes.o 
OBJS += src/1.4/dom/domLibrary_physics_materials.o 
OBJS += src/1.4/dom/domLibrary_physics_models.o 
OBJS += src/1.4/dom/domLibrary_physics_scenes.o 
OBJS += src/1.4/dom/domLibrary_visual_scenes.o 
OBJS += src/1.4/dom/domLight.o 
OBJS += src/1.4/dom/domLines.o 
OBJS += src/1.4/dom/domLinestrips.o 
OBJS += src/1.4/dom/domLookat.o 
OBJS += src/1.4/dom/domMaterial.o 
OBJS += src/1.4/dom/domMatrix.o 
OBJS += src/1.4/dom/domMesh.o 
OBJS += src/1.4/dom/domMorph.o 
OBJS += src/1.4/dom/domName_array.o 
OBJS += src/1.4/dom/domNode.o 
OBJS += src/1.4/dom/domP.o 
OBJS += src/1.4/dom/domParam.o 
OBJS += src/1.4/dom/domPhysics_material.o 
OBJS += src/1.4/dom/domPhysics_model.o 
OBJS += src/1.4/dom/domPhysics_scene.o 
OBJS += src/1.4/dom/domPlane.o 
OBJS += src/1.4/dom/domPolygons.o 
OBJS += src/1.4/dom/domPolylist.o 
OBJS += src/1.4/dom/domProfile_CG.o 
OBJS += src/1.4/dom/domProfile_COMMON.o 
OBJS += src/1.4/dom/domProfile_GLES.o 
OBJS += src/1.4/dom/domProfile_GLSL.o 
OBJS += src/1.4/dom/domRigid_body.o 
OBJS += src/1.4/dom/domRigid_constraint.o 
OBJS += src/1.4/dom/domRotate.o 
OBJS += src/1.4/dom/domSampler.o 
OBJS += src/1.4/dom/domScale.o 
OBJS += src/1.4/dom/domSkew.o 
OBJS += src/1.4/dom/domSkin.o 
OBJS += src/1.4/dom/domSource.o 
OBJS += src/1.4/dom/domSphere.o 
OBJS += src/1.4/dom/domSpline.o 
OBJS += src/1.4/dom/domTapered_capsule.o 
OBJS += src/1.4/dom/domTapered_cylinder.o 
OBJS += src/1.4/dom/domTargetableFloat.o 
OBJS += src/1.4/dom/domTargetableFloat3.o 
OBJS += src/1.4/dom/domTechnique.o 
OBJS += src/1.4/dom/domTranslate.o 
OBJS += src/1.4/dom/domTriangles.o 
OBJS += src/1.4/dom/domTrifans.o 
OBJS += src/1.4/dom/domTristrips.o 
OBJS += src/1.4/dom/domTypes.o 
OBJS += src/1.4/dom/domVertices.o 
OBJS += src/1.4/dom/domVisual_scene.o

all: $(BIN)

$(BIN) : $(OBJS)
	ar r $@ $^
	ranlib $@

%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o $@ -c $^

.PHONY: clean

clean:
	$(RM) $(BIN) $(OBJS)
