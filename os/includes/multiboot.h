/*
 *  multiboot.h - Multiboot header file.
 *  Copyright (C) 2003,2007,2008,2009  Free Software Foundation, Inc.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to
 *  deal in the Software without restriction, including without limitation the
 *  rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 *  sell copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL ANY
 *  DEVELOPER OR DISTRIBUTOR BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
 *  IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef MULTIBOOT_HEADER
#define MULTIBOOT_HEADER 1

/* How many bytes from the start of the file we search for the header.  */
#define MULTIBOOT_SEARCH                 8192

/* The magic field should contain this.  */
#define MULTIBOOT_MAGIC                  0x1BADB002

/* This should be in %eax.  */
#define MULTIBOOT_MAGIC2                 0x2BADB002

/* The bits in the required part of flags field we don't support.  */
#define MULTIBOOT_UNSUPPORTED            0x0000fffc

/* Alignment of multiboot modules.  */
#define MULTIBOOT_MOD_ALIGN              0x00001000

/* Alignment of the multiboot info structure.  */
#define MULTIBOOT_INFO_ALIGN		 0x00000004

/*
 * Flags set in the 'flags' member of the multiboot header.
 */

/* Align all boot modules on i386 page (4KB) boundaries.  */
#define MULTIBOOT_PAGE_ALIGN		0x00000001

/* Must pass memory information to OS.  */
#define MULTIBOOT_MEMORY_INFO		0x00000002

/* Must pass video information to OS.  */
#define MULTIBOOT_VIDEO_MODE		0x00000004

/* This flag indicates the use of the address fields in the header.  */
#define MULTIBOOT_AOUT_KLUDGE		0x00010000

/*
 *  Flags to be set in the 'flags' member of the multiboot info structure.
 */

/* is there basic lower/upper memory information? */
#define MULTIBOOT_INFO_MEMORY		0x00000001
/* is there a boot device set? */
#define MULTIBOOT_INFO_BOOTDEV		0x00000002
/* is the command-line defined? */
#define MULTIBOOT_INFO_CMDLINE		0x00000004
/* are there modules to do something with? */
#define MULTIBOOT_INFO_MODS		0x00000008

/* These next two are mutually exclusive */

/* is there a symbol table loaded? */
#define MULTIBOOT_INFO_AOUT_SYMS		0x00000010
/* is there an ELF section header table? */
#define MULTIBOOT_INFO_ELF_SHDR		0x00000020

/* is there a full memory map? */
#define MULTIBOOT_INFO_MEM_MAP		0x00000040

/* Is there drive info?  */
#define MULTIBOOT_INFO_DRIVE_INFO		0x00000080

/* Is there a config table?  */
#define MULTIBOOT_INFO_CONFIG_TABLE	0x00000100

/* Is there a boot loader name?  */
#define MULTIBOOT_INFO_BOOT_LOADER_NAME	0x00000200

/* Is there a APM table?  */
#define MULTIBOOT_INFO_APM_TABLE		0x00000400

/* Is there video information?  */
#define MULTIBOOT_INFO_VIDEO_INFO		0x00000800

#ifndef ASM_FILE

/* we define our own grub_uintXX_t types so
we don't have to include the GPL licensed one */
#include "grubtypes.h"

struct multiboot_header
{
  /* Must be MULTIBOOT_MAGIC - see above.  */
  grub_uint32_t magic;

  /* Feature flags.  */
  grub_uint32_t flags;

  /* The above fields plus this one must equal 0 mod 2^32. */
  grub_uint32_t checksum;

  /* These are only valid if MULTIBOOT_AOUT_KLUDGE is set.  */
  grub_uint32_t header_addr;
  grub_uint32_t load_addr;
  grub_uint32_t load_end_addr;
  grub_uint32_t bss_end_addr;
  grub_uint32_t entry_addr;

  /* These are only valid if MULTIBOOT_VIDEO_MODE is set.  */
  grub_uint32_t mode_type;
  grub_uint32_t width;
  grub_uint32_t height;
  grub_uint32_t depth;
};

struct multiboot_info
{
  /* Multiboot info version number */
  grub_uint32_t flags;

  /* Available memory from BIOS */
  grub_uint32_t mem_lower;
  grub_uint32_t mem_upper;

  /* "root" partition */
  grub_uint32_t boot_device;

  /* Kernel command line */
  grub_uint32_t cmdline;

  /* Boot-Module list */
  grub_uint32_t mods_count;
  grub_uint32_t mods_addr;

  grub_uint32_t syms[4];

  /* Memory Mapping buffer */
  grub_uint32_t mmap_length;
  grub_uint32_t mmap_addr;

  /* Drive Info buffer */
  grub_uint32_t drives_length;
  grub_uint32_t drives_addr;

  /* ROM configuration table */
  grub_uint32_t config_table;

  /* Boot Loader Name */
  grub_uint32_t boot_loader_name;

  /* APM table */
  grub_uint32_t apm_table;

  /* Video */
  grub_uint32_t vbe_control_info;
  grub_uint32_t vbe_mode_info;
  grub_uint16_t vbe_mode;
  grub_uint16_t vbe_interface_seg;
  grub_uint16_t vbe_interface_off;
  grub_uint16_t vbe_interface_len;
};

struct multiboot_mmap_entry
{
  grub_uint32_t size;
  grub_uint64_t addr;
  grub_uint64_t len;
#define MULTIBOOT_MEMORY_AVAILABLE		1
#define MULTIBOOT_MEMORY_RESERVED		2
  grub_uint32_t type;
} __attribute__((packed));

struct multiboot_mod_list
{
  /* the memory used goes from bytes 'mod_start' to 'mod_end-1' inclusive */
  grub_uint32_t mod_start;
  grub_uint32_t mod_end;

  /* Module command line */
  grub_uint32_t cmdline;

  /* padding to take it to 16 bytes (must be zero) */
  grub_uint32_t pad;
};

#endif /* ! ASM_FILE */

#endif /* ! MULTIBOOT_HEADER */
