/*****************************************************************************

 @(#) $Id: strmain.h,v 1.1.2.1 2009-06-21 11:37:25 brian Exp $

 -----------------------------------------------------------------------------

 Copyright (c) 2008-2009  Monavacon Limited <http://www.monavacon.com/>
 Copyright (c) 2001-2008  OpenSS7 Corporation <http://www.openss7.com/>
 Copyright (c) 1997-2001  Brian F. G. Bidulock <bidulock@openss7.org>

 All Rights Reserved.

 This program is free software; you can redistribute it and/or modify it under
 the terms of the GNU Affero General Public License as published by the Free
 Software Foundation; version 3 of the License.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more
 details.

 You should have received a copy of the GNU Affero General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>, or
 write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA
 02139, USA.

 -----------------------------------------------------------------------------

 U.S. GOVERNMENT RESTRICTED RIGHTS.  If you are licensing this Software on
 behalf of the U.S. Government ("Government"), the following provisions apply
 to you.  If the Software is supplied by the Department of Defense ("DoD"), it
 is classified as "Commercial Computer Software" under paragraph 252.227-7014
 of the DoD Supplement to the Federal Acquisition Regulations ("DFARS") (or any
 successor regulations) and the Government is acquiring only the license rights
 granted herein (the license rights customarily provided to non-Government
 users).  If the Software is supplied to any unit or agency of the Government
 other than DoD, it is classified as "Restricted Computer Software" and the
 Government's rights in the Software are defined in paragraph 52.227-19 of the
 Federal Acquisition Regulations ("FAR") (or any successor regulations) or, in
 the cases of NASA, in paragraph 18.52.227-86 of the NASA Supplement to the FAR
 (or any successor regulations).

 -----------------------------------------------------------------------------

 Commercial licensing and support of this software is available from OpenSS7
 Corporation at a fee.  See http://www.openss7.com/

 -----------------------------------------------------------------------------

 Last Modified $Date: 2009-06-21 11:37:25 $ by $Author: brian $

 -----------------------------------------------------------------------------

 $Log: strmain.h,v $
 Revision 1.1.2.1  2009-06-21 11:37:25  brian
 - added files to new distro

 *****************************************************************************/

#ifndef __LOCAL_STRMAIN_H__
#define __LOCAL_STRMAIN_H__

#ident "@(#) $RCSfile: strmain.h,v $ $Name:  $($Revision: 1.1.2.1 $) Copyright (c) 2008-2009 Monavacon Limited."

typedef struct module_config {
	char cnf_name[FMNAMESZ + 1];
	struct streamtab *cnf_str;
	char cnf_objname[FMNAMESZ + 1];
	int (*cnf_init) (void);
	void (*cnf_term) (void);
	int cnf_qlock_option;
} module_config_t;

typedef struct driver_config {
	char cnf_name[FMNAMESZ + 1];
	struct streamtab *cnf_str;
	int *cnf_major;
	int cnf_n_majors;
	int cnf_n_minors;
	int (*cnf_init) (void);
	void (*cnf_term) (void);
	int cnf_qlock_option;
} driver_config_t;

typedef struct device_config {
	char *name;
	char *prefix;
	struct streamtab *strtb;
	void *handler;
	int unit;
	long port;
	int nports;
	int irq_share;
	int irq;
	long mem;
	long mem_size;
	int dma1;
	int dma2;
	int major;
	int minor;
} device_config_t;

#ifdef LFS_LOADABLE_SUPPORT

typedef struct driver_obj_name {
	const int *major;
	const int nmajors;
	const char *initname;
	const char *objname;
} driver_obj_name_t;

#endif				/* LFS_LOADABLE_SUPPORT */

typedef struct autopush_init {
	const int major;
	const int minor;
	const int lastminor;
	const int npush;
	const char mods[MAXAPUSH][FMNAMESZ + 1];
} autopush_init_t;

#endif				/* __LOCAL_STRMAIN_H__ */