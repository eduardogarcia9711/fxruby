/***********************************************************************
 * FXRuby -- the Ruby language bindings for the FOX GUI toolkit.
 * Copyright (c) 2001-2009 by Lyle Johnson. All Rights Reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * For further information please contact the author by e-mail
 * at "lyle@lylejohnson.name".
 ***********************************************************************/

/***********************************************************************
 * $Id: FXRbDrawable.h 2190 2005-08-24 07:58:47Z lyle $
 ***********************************************************************/

#ifndef FXRBDRAWABLE_H
#define FXRBDRAWABLE_H

#define DECLARE_FXDRAWABLE_STUBS(klass) \
inline void klass ## _resize(klass* self,FXint w,FXint h){ \
  self->klass::resize(w,h); \
  }


#define IMPLEMENT_FXDRAWABLE_STUBS(cls) \
  void cls::resize(FXint w,FXint h){ \
    FXRbCallVoidMethod(this, "resize", w, h); \
    }


class FXRbDrawable : public FXDrawable {
  FXDECLARE(FXRbDrawable)
#include "FXRbObjectVirtuals.h"
#include "FXRbIdVirtuals.h"
#include "FXRbDrawableVirtuals.h"
protected:
  // Default constructor
  FXRbDrawable(){}

public:
  // Construct with specified width and height
  FXRbDrawable(FXApp* a,FXint w,FXint h) : FXDrawable(a,w,h){}

  // Mark dependencies for the GC
  static void markfunc(FXDrawable* drawable);

  // Destructor
  virtual ~FXRbDrawable(){
    FXRbUnregisterRubyObj(this);
    }
  };

#endif
