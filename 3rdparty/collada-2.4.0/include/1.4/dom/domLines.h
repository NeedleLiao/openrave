/*
* Copyright 2006 Sony Computer Entertainment Inc.
*
* Licensed under the MIT Open Source License, for details please see license.txt or the website
* http://www.opensource.org/licenses/mit-license.php
*
*/ 

#ifndef __dom141Lines_h__
#define __dom141Lines_h__

#include <dae/daeDocument.h>
#include <1.4/dom/domTypes.h>
#include <1.4/dom/domElements.h>

#include <1.4/dom/domP.h>
#include <1.4/dom/domExtra.h>
#include <1.4/dom/domInputLocalOffset.h>

class DAE;
namespace ColladaDOM141 {

/**
 * The lines element provides the information needed to bind vertex attributes
 * together and then  organize those vertices into individual lines. Each
 * line described by the mesh has two vertices.  The first line is formed
 * from first and second vertices. The second line is formed from the  third
 * and fourth vertices and so on.
 */
class domLines : public daeElement
{
public:
	virtual COLLADA_TYPE::TypeEnum getElementType() const { return COLLADA_TYPE::LINES; }
	static daeInt ID() { return 618; }
	virtual daeInt typeID() const { return ID(); }
protected:  // Attributes
/**
 *  The name attribute is the text string name of this element. Optional attribute.
 */
	xsNCName attrName;
/**
 *  The count attribute indicates the number of line primitives. Required
 * attribute. 
 */
	domUint attrCount;
/**
 *  The material attribute declares a symbol for a material. This symbol is
 * bound to a material at  the time of instantiation. If the material attribute
 * is not specified then the lighting and  shading results are application
 * defined. Optional attribute. 
 */
	xsNCName attrMaterial;

protected:  // Elements
/**
 * The input element may occur any number of times. This input is a local
 * input with the offset  and set attributes. @see domInput
 */
	domInputLocalOffset_Array elemInput_array;
/**
 *  The p element may occur once.  @see domP
 */
	domPRef elemP;
/**
 *  The extra element may appear any number of times.  @see domExtra
 */
	domExtra_Array elemExtra_array;

public:	//Accessors and Mutators
	/**
	 * Gets the name attribute.
	 * @return Returns a xsNCName of the name attribute.
	 */
	xsNCName getName() const { return attrName; }
	/**
	 * Sets the name attribute.
	 * @param atName The new value for the name attribute.
	 */
	void setName( xsNCName atName ) { *(daeStringRef*)&attrName = atName; _validAttributeArray[0] = true; }

	/**
	 * Gets the count attribute.
	 * @return Returns a domUint of the count attribute.
	 */
	domUint getCount() const { return attrCount; }
	/**
	 * Sets the count attribute.
	 * @param atCount The new value for the count attribute.
	 */
	void setCount( domUint atCount ) { attrCount = atCount; _validAttributeArray[1] = true; }

	/**
	 * Gets the material attribute.
	 * @return Returns a xsNCName of the material attribute.
	 */
	xsNCName getMaterial() const { return attrMaterial; }
	/**
	 * Sets the material attribute.
	 * @param atMaterial The new value for the material attribute.
	 */
	void setMaterial( xsNCName atMaterial ) { *(daeStringRef*)&attrMaterial = atMaterial; _validAttributeArray[2] = true; }

	/**
	 * Gets the input element array.
	 * @return Returns a reference to the array of input elements.
	 */
	domInputLocalOffset_Array &getInput_array() { return elemInput_array; }
	/**
	 * Gets the input element array.
	 * @return Returns a constant reference to the array of input elements.
	 */
	const domInputLocalOffset_Array &getInput_array() const { return elemInput_array; }
	/**
	 * Gets the p element.
	 * @return a daeSmartRef to the p element.
	 */
	const domPRef getP() const { return elemP; }
	/**
	 * Gets the extra element array.
	 * @return Returns a reference to the array of extra elements.
	 */
	domExtra_Array &getExtra_array() { return elemExtra_array; }
	/**
	 * Gets the extra element array.
	 * @return Returns a constant reference to the array of extra elements.
	 */
	const domExtra_Array &getExtra_array() const { return elemExtra_array; }
protected:
	/**
	 * Constructor
	 */
	domLines(DAE& dae) : daeElement(dae), attrName(), attrCount(), attrMaterial(), elemInput_array(), elemP(), elemExtra_array() {}
	/**
	 * Destructor
	 */
	virtual ~domLines() {}
	/**
	 * Overloaded assignment operator
	 */
	virtual domLines &operator=( const domLines &cpy ) { (void)cpy; return *this; }

public: // STATIC METHODS
	/**
	 * Creates an instance of this class and returns a daeElementRef referencing it.
	 * @return a daeElementRef referencing an instance of this object.
	 */
	static DLLSPEC daeElementRef create(DAE& dae);
	/**
	 * Creates a daeMetaElement object that describes this element in the meta object reflection framework.
	 * If a daeMetaElement already exists it will return that instead of creating a new one. 
	 * @return A daeMetaElement describing this COLLADA element.
	 */
	static DLLSPEC daeMetaElement* registerElement(DAE& dae);
};


} // ColladaDOM141
#endif
