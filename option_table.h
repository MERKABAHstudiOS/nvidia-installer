/*
 * nvidia-installer: A tool for installing/un-installing the
 * NVIDIA Linux graphics driver.
 *
 * Copyright (C) 2004-2010 NVIDIA Corporation
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses>.
 *
 *
 * option_table.h
 */

#ifndef __OPT_TABLE_H__
#define __OPT_TABLE_H__

#include "nvgetopt.h"
#include "nvidia-installer.h"

#define NVGETOPT_OPTION_APPLIES_TO_NVIDIA_UNINSTALL 0x00010000

/* make sure OPTION_APPLIES_TO_NVIDIA_UNINSTALL is in the approved range */
#if !(NVGETOPT_OPTION_APPLIES_TO_NVIDIA_UNINSTALL & NVGETOPT_UNUSED_FLAG_RANGE)
#error NVGETOPT_OPTION_APPLIES_TO_NVIDIA_UNINSTALL incorrectly defined
#endif


enum {
    XFREE86_PREFIX_OPTION = 1024,
    OPENGL_PREFIX_OPTION,
    OPENGL_LIBDIR_OPTION,
    WINE_PREFIX_OPTION,
    WINE_LIBDIR_OPTION,
    KERNEL_INCLUDE_PATH_OPTION,
    KERNEL_INSTALL_PATH_OPTION,
    UNINSTALL_OPTION,
    SKIP_MODULE_UNLOAD_OPTION,
    SKIP_MODULE_LOAD_OPTION,
    PROC_MOUNT_POINT_OPTION,
    USER_INTERFACE_OPTION,
    LOG_FILE_NAME_OPTION,
    HELP_ARGS_ONLY_OPTION,
    TMPDIR_OPTION,
    NO_NVIDIA_MODPROBE_OPTION,
    INSTALLER_PREFIX_OPTION,
    FORCE_TLS_OPTION,
    SANITY_OPTION,
    ADVANCED_OPTIONS_ARGS_ONLY_OPTION,
    UTILITY_PREFIX_OPTION,
    UTILITY_LIBDIR_OPTION,
    XDG_DATA_DIR_OPTION,
    ADD_THIS_KERNEL_OPTION,
    RPM_FILE_LIST_OPTION,
    NO_RUNLEVEL_CHECK_OPTION,
    PRECOMPILED_KERNEL_INTERFACES_PATH_OPTION,
    PRECOMPILED_KERNEL_INTERFACES_URL_OPTION,
    NO_ABI_NOTE_OPTION,
    KERNEL_SOURCE_PATH_OPTION,
    NO_RPMS_OPTION,
    X_PREFIX_OPTION,
    KERNEL_OUTPUT_PATH_OPTION,
    FORCE_TLS_COMPAT32_OPTION,
    COMPAT32_CHROOT_OPTION,
    COMPAT32_PREFIX_OPTION,
    COMPAT32_LIBDIR_OPTION,
    UPDATE_OPTION,
    FORCE_SELINUX_OPTION,
    SELINUX_CHCON_TYPE_OPTION,
    NO_SIGWINCH_WORKAROUND_OPTION,
    X_MODULE_PATH_OPTION,
    DOCUMENTATION_PREFIX_OPTION,
    APPLICATION_PROFILE_PATH_OPTION,
    X_LIBRARY_PATH_OPTION,
    NO_KERNEL_MODULES_OPTION,
    NO_X_CHECK_OPTION,
    NO_CC_VERSION_CHECK_OPTION,
    NO_DISTRO_SCRIPTS_OPTION,
    NO_OPENGL_FILES_OPTION,
    NO_WINE_FILES_OPTION,
    KERNEL_MODULE_SOURCE_PREFIX_OPTION,
    KERNEL_MODULE_SOURCE_DIR_OPTION,
    NO_KERNEL_MODULE_SOURCE_OPTION,
    DKMS_OPTION,
    MODULE_SIGNING_SECRET_KEY_OPTION,
    MODULE_SIGNING_PUBLIC_KEY_OPTION,
    MODULE_SIGNING_SCRIPT_OPTION,
    MODULE_SIGNING_KEY_PATH_OPTION,
    MODULE_SIGNING_HASH_OPTION,
    MODULE_SIGNING_X509_HASH_OPTION,
    INSTALL_VDPAU_WRAPPER_OPTION,
    NO_CHECK_FOR_ALTERNATE_INSTALLS_OPTION,
    NO_UVM_OPTION,
    NO_DRM_OPTION,
    NO_PEERMEM_OPTION,
    INSTALL_COMPAT32_LIBS_OPTION,
    X_SYSCONFIG_PATH_OPTION,
    FORCE_LIBGLX_INDIRECT,
    NO_LIBGLX_INDIRECT,
    INSTALL_LIBGLVND_OPTION,
    GLVND_GLX_CLIENT_OPTION,
    GLVND_EGL_CONFIG_FILE_PATH_OPTION,
    GLVND_EGL_CLIENT_OPTION,
    EGL_EXTERNAL_PLATFORM_CONFIG_FILE_PATH_OPTION,
    OVERRIDE_FILE_TYPE_DESTINATION_OPTION,
    SKIP_DEPMOD_OPTION,
    SYSTEMD_OPTION,
    SYSTEMD_UNIT_PREFIX_OPTION,
    SYSTEMD_SLEEP_PREFIX_OPTION,
    SYSTEMD_SYSCONF_PREFIX_OPTION,
    GBM_BACKEND_DIR_OPTION,
    GBM_BACKEND_DIR32_OPTION,
    ALLOW_INSTALLATION_WITH_RUNNING_DRIVER_OPTION,
    REBUILD_INITRAMFS_OPTION,
    PRINT_RECOMMENDED_MODULE_TYPE_OPTION,
};

static const NVGetoptOption __options[] = {
    /* These options are printed by "nvidia-installer --help" */

    { "version", 'v',
      NVGETOPT_HELP_ALWAYS | NVGETOPT_OPTION_APPLIES_TO_NVIDIA_UNINSTALL, NULL,
      "Print the nvidia-installer version and exit." },

    { "help", 'h',
      NVGETOPT_HELP_ALWAYS | NVGETOPT_OPTION_APPLIES_TO_NVIDIA_UNINSTALL, NULL,
      "Print usage information for the common commandline options "
      "and exit." },

    { "advanced-options", 'A',
      NVGETOPT_HELP_ALWAYS | NVGETOPT_OPTION_APPLIES_TO_NVIDIA_UNINSTALL, NULL,
      "Print usage information for the common commandline options "
      "as well as the advanced options, and then exit." },

    /* These options are only printed by "nvidia-installer --advanced-help" */

    { "accept-license", 'a', 0, NULL,
      "This option is obsolete and ignored by nvidia-installer.  It is "
      "provided for compatibility with older versions of nvidia-installer, "
      "which required this option for explicit license acceptance. "
      "Use of the NVIDIA driver implies acceptance of the NVIDIA Software "
      "License Agreement, contained in the file 'LICENSE' (in the top "
      "level directory of the driver package)." },

    { "driver-info", 'i', 0, NULL,
      "Print information about the currently installed NVIDIA "
      "driver version." },

    { "uninstall", UNINSTALL_OPTION, 0, NULL,
      "Uninstall the currently installed NVIDIA driver." },

    { "skip-module-unload", SKIP_MODULE_UNLOAD_OPTION,
      NVGETOPT_OPTION_APPLIES_TO_NVIDIA_UNINSTALL, NULL,
      "When uninstalling the driver, skip unloading of the NVIDIA kernel "
      "module. This option is ignored when the driver is being installed." },

    { "skip-module-load", SKIP_MODULE_LOAD_OPTION, 0, NULL,
      "Skip the test load of the NVIDIA kernel modules after the modules are "
      "built, and skip loading them after installation is complete."},

    { "sanity", SANITY_OPTION, 0, NULL,
      "Perform basic sanity tests on an existing NVIDIA "
      "driver installation." },

    { "expert", 'e', NVGETOPT_OPTION_APPLIES_TO_NVIDIA_UNINSTALL, NULL,
      "Enable 'expert' installation mode; more detailed questions "
      "will be asked, and more verbose output will be printed; "
      "intended for expert users.  The questions may be suppressed "
      "with the '--no-questions' commandline option." },

    { "no-questions", 'q', NVGETOPT_OPTION_APPLIES_TO_NVIDIA_UNINSTALL, NULL,
      "Do not ask any questions; the default (normally 'yes') "
      "is assumed for "
      "all yes/no questions, and the default string is assumed in "
      "any situation where the user is prompted for string input." },

    { "silent", 's', NVGETOPT_OPTION_APPLIES_TO_NVIDIA_UNINSTALL, NULL,
      "Run silently; no questions are asked and no output is "
      "printed, except for error messages to stderr.  This option "
      "implies '--ui=none --no-questions'." },

    { "x-prefix", X_PREFIX_OPTION, NVGETOPT_STRING_ARGUMENT, NULL,
      "The prefix under which the X components of the "
      "NVIDIA driver will be installed; the default is '" DEFAULT_X_PREFIX
      "' unless nvidia-installer detects that X.Org >= 7.0 is installed, "
      "in which case the default is '" XORG7_DEFAULT_X_PREFIX "'.  Only "
      "under rare circumstances should this option be used." },

    { "xfree86-prefix", XFREE86_PREFIX_OPTION, NVGETOPT_STRING_ARGUMENT, NULL,
      "This is a deprecated synonym for --x-prefix." },

    { "x-module-path", X_MODULE_PATH_OPTION, NVGETOPT_STRING_ARGUMENT, NULL,
      "The path under which the NVIDIA X server modules will be installed.  "
      "If this option is not specified, nvidia-installer uses the following "
      "search order and selects the first valid directory it finds: 1) "
      "`X -showDefaultModulePath`, 2) `pkg-config --variable=moduledir "
      "xorg-server`, or 3) the X library path (see the '--x-library-path' "
      "option) plus either '" DEFAULT_X_MODULEDIR "' (for X servers older "
      "than X.Org 7.0) or '" XORG7_DEFAULT_X_MODULEDIR "' (for X.Org 7.0 or "
      "later)." },

    { "x-library-path", X_LIBRARY_PATH_OPTION, NVGETOPT_STRING_ARGUMENT, NULL,
      "The path under which the NVIDIA X libraries will be installed.  "
      "If this option is not specified, nvidia-installer uses the following "
      "search order and selects the first valid directory it finds: 1) "
      "`X -showDefaultLibPath`, 2) `pkg-config --variable=libdir "
      "xorg-server`, or 3) the X prefix (see the '--x-prefix' option) "
      "plus '" DEFAULT_LIBDIR "' on 32bit systems, and either '"
      DEFAULT_64BIT_LIBDIR "' or '" DEFAULT_LIBDIR "' on 64bit systems, "
      "depending on the installed Linux distribution." },

    { "x-sysconfig-path", X_SYSCONFIG_PATH_OPTION, NVGETOPT_STRING_ARGUMENT, NULL,
      "The path under which X system configuration files will be installed.  "
      "If this option is not specified, nvidia-installer uses the following "
      "search order and selects the first valid directory it finds: 1) "
      "`pkg-config --variable=sysconfigdir xorg-server`, or 2) "
      DEFAULT_X_DATAROOT_PATH "/" DEFAULT_CONFDIR "." },

    { "opengl-prefix", OPENGL_PREFIX_OPTION, NVGETOPT_STRING_ARGUMENT, NULL,
      "The prefix under which the OpenGL components of the "
      "NVIDIA driver will be installed; the default is: '" DEFAULT_OPENGL_PREFIX
      "'.  Only under rare circumstances should this option be used.  "
      "The Linux OpenGL ABI (http://oss.sgi.com/projects/ogl-sample/ABI/) "
      "mandates this default value." },

    { "opengl-libdir", OPENGL_LIBDIR_OPTION, NVGETOPT_STRING_ARGUMENT, NULL,
      "The path relative to the OpenGL library installation prefix under "
      "which the NVIDIA OpenGL components will be installed.  The "
      "default is '" DEFAULT_LIBDIR "' on 32bit systems, and '"
      DEFAULT_64BIT_LIBDIR "' or '" DEFAULT_LIBDIR "' on 64bit systems, "
      "depending on the installed Linux distribution.  Only under very rare "
      "circumstances should this option be used." },

     { "wine-prefix", WINE_PREFIX_OPTION, NVGETOPT_STRING_ARGUMENT, NULL,
       "The prefix under which Wine components of the NVIDIA driver will be "
       "installed.  The default is '" DEFAULT_WINE_PREFIX "'."},

     { "wine-libdir", WINE_LIBDIR_OPTION, NVGETOPT_STRING_ARGUMENT, NULL,
       "The path relative to the Wine installation prefix under which Wine "
       "components of the NVIDIA driver will be installed.  "
       "The default is '<opengl-libdir>/" DEFAULT_WINE_LIBDIR_SUFFIX "', where "
       "<opengl-libdir> is the path determined for --opengl-libdir above."},

#if defined(NV_X86_64)
    { "compat32-chroot", COMPAT32_CHROOT_OPTION, NVGETOPT_STRING_ARGUMENT,
      NULL,
      "The top-level prefix (chroot) relative to which the 32bit "
      "compatibility libraries will be installed on Linux/x86-64 "
      "systems; this option is unset by default, the 32bit "
      "library installation prefix (see below) and the 32bit library "
      "path alone determine the target location.  Only under very rare "
      "circumstances should this option be used." },

    { "compat32-prefix", COMPAT32_PREFIX_OPTION, NVGETOPT_STRING_ARGUMENT,
      NULL,
      "The prefix under which the 32bit compatibility components "
      "of the NVIDIA driver will be installed; the default is: '"
      DEFAULT_OPENGL_PREFIX "'.  Only under rare circumstances should "
      "this option be used." },

    { "compat32-libdir", COMPAT32_LIBDIR_OPTION, NVGETOPT_STRING_ARGUMENT,
      NULL,
      "The path relative to the 32bit compatibility prefix under which the "
      "32bit compatibility components of the NVIDIA driver will "
      "be installed.  The default is '" DEFAULT_LIBDIR "' or '"
      DEFAULT_32BIT_LIBDIR "', depending on the installed Linux "
      "distribution.  Only under very rare circumstances should this "
      "option be used." },

    { "install-compat32-libs", INSTALL_COMPAT32_LIBS_OPTION,
      NVGETOPT_IS_BOOLEAN, NULL,
      "32-bit compatibility libraries may be optionally installed. Setting "
      "--install-compat32-libs will install these libraries. Setting "
      "--no-install-compat32-libs will skip installation of these libraries. "
      "Note: this option will have no effect on -no-compat32.run packages."  },
#endif /* NV_X86_64 */

    { "installer-prefix", INSTALLER_PREFIX_OPTION, NVGETOPT_STRING_ARGUMENT,
      NULL,
      "The prefix under which the installer binary will be "
      "installed; the default is: '" DEFAULT_UTILITY_PREFIX "'.  Note: please "
      "use the '--utility-prefix' option instead." },

    { "utility-prefix", UTILITY_PREFIX_OPTION, NVGETOPT_STRING_ARGUMENT, NULL,
      "The prefix under which the NVIDIA utilities (nvidia-installer, "
      "nvidia-settings, nvidia-xconfig, nvidia-bug-report.sh) and the NVIDIA "
      "utility libraries will be installed; the default is: '"
      DEFAULT_UTILITY_PREFIX "'." },

    { "utility-libdir", UTILITY_LIBDIR_OPTION, NVGETOPT_STRING_ARGUMENT, NULL,
      "The path relative to the utility installation prefix under which the "
      "NVIDIA utility libraries will be installed.  The default is '"
      DEFAULT_LIBDIR "' on 32bit systems, and '" DEFAULT_64BIT_LIBDIR
      "' or '" DEFAULT_LIBDIR "' on 64bit " "systems, depending on the "
      "installed Linux distribution." },

    { "xdg-data-dir", XDG_DATA_DIR_OPTION, NVGETOPT_STRING_ARGUMENT, NULL,
      "The prefix under which XDG data files (such as application .desktop "
      "files and icons) will be installed.  The default is '"
      DEFAULT_UTILITY_PREFIX "/" DEFAULT_XDG_DATA_DIR "'." },

    { "gbm-backend-dir", GBM_BACKEND_DIR_OPTION, NVGETOPT_STRING_ARGUMENT, NULL,
      "The path relative to the OpenGL library installation prefix under "
      "which the NVIDIA GBM backend library will be installed.  The "
      "default is '<libdir>/gbm', where '<libdir>' is '" DEFAULT_64BIT_LIBDIR
      "' or '" DEFAULT_LIBDIR "', depending on the installed Linux "
      "distribution.  Only under very rare circumstances should this option be "
      "used." },

    { "gbm-backend-dir32", GBM_BACKEND_DIR32_OPTION, NVGETOPT_STRING_ARGUMENT, NULL,
      "The path relative to the 32-bit OpenGL library installation prefix under "
      "which the 32-bit NVIDIA GBM backend library will be installed.  The "
      "default is '<libdir>/gbm', where <libdir>' is '" DEFAULT_LIBDIR
      "' or '" DEFAULT_32BIT_LIBDIR "', depending on the installed Linux "
      "distribution.  Only under very rare circumstances should this option be "
      "used." },

    { "documentation-prefix", DOCUMENTATION_PREFIX_OPTION,
      NVGETOPT_STRING_ARGUMENT,  NULL,
      "The prefix under which the documentation files for the NVIDIA "
      "driver will be installed.  The default is: '"
      DEFAULT_DOCUMENTATION_PREFIX "'." },

    { "application-profile-path", APPLICATION_PROFILE_PATH_OPTION,
        NVGETOPT_STRING_ARGUMENT, NULL,
        "The directory under which default application profiles for the NVIDIA "
        "driver will be installed. The default is: '"
        DEFAULT_APPLICATION_PROFILE_PATH "'." },

    { "kernel-include-path", KERNEL_INCLUDE_PATH_OPTION,
      NVGETOPT_STRING_ARGUMENT, NULL,
      "The directory containing the kernel include files that "
      "should be used when compiling the NVIDIA kernel module.  "
      "This option is deprecated; please use '--kernel-source-path' "
      "instead." },

    { "kernel-source-path", KERNEL_SOURCE_PATH_OPTION,
      NVGETOPT_STRING_ARGUMENT, NULL,
      "The directory containing the kernel source files that "
      "should be used when compiling the NVIDIA kernel module.  "
      "When not specified, the installer will use "
      "'/lib/modules/`uname -r`/build', if that "
      "directory exists.  Otherwise, it will use "
      "'/usr/src/linux'." },

    { "kernel-output-path", KERNEL_OUTPUT_PATH_OPTION,
      NVGETOPT_STRING_ARGUMENT, NULL,
      "The directory containing any KBUILD output files if "
       "either one of the 'KBUILD_OUTPUT' or 'O' parameters were "
       "passed to KBUILD when building the kernel image/modules.  "
       "When not specified, the installer will assume that no "
       "separate output directory was used." },

    { "kernel-install-path", KERNEL_INSTALL_PATH_OPTION,
      NVGETOPT_STRING_ARGUMENT, NULL,
      "The directory in which the NVIDIA kernel module should be "
      "installed.  The default value is either '/lib/modules/`uname "
      "-r`/kernel/drivers/video' (if '/lib/modules/`uname -r`/kernel' "
      "exists) or '/lib/modules/`uname -r`/video'." },

    { "proc-mount-point", PROC_MOUNT_POINT_OPTION, NVGETOPT_STRING_ARGUMENT,
      NULL,
      "The mount point for the proc file system; if not "
      "specified, then this value defaults to '" DEFAULT_PROC_MOUNT_POINT
      "' (which is normally "
      "correct).  The mount point of the proc filesystem is needed "
      "because the contents of '<proc filesystem>/version' is used when "
      "identifying if a precompiled kernel interface is available for "
      "the currently running kernel.  This option should only be needed "
      "in very rare circumstances." },

    { "log-file-name", LOG_FILE_NAME_OPTION,
      NVGETOPT_STRING_ARGUMENT | NVGETOPT_OPTION_APPLIES_TO_NVIDIA_UNINSTALL,
      NULL, "File name of the installation log file (the default is: "
      "'" DEFAULT_LOG_FILE_NAME "')." },

    { "tmpdir", TMPDIR_OPTION,
      NVGETOPT_STRING_ARGUMENT | NVGETOPT_OPTION_APPLIES_TO_NVIDIA_UNINSTALL,
      NULL, "Use the specified directory as a temporary directory when "
      "generating transient files used by the installer; "
      "if not given, then the following list will be searched, and "
      "the first one that exists will be used: $TMPDIR, /tmp, ., "
      "$HOME." },

    { "ui", USER_INTERFACE_OPTION,
      NVGETOPT_STRING_ARGUMENT | NVGETOPT_OPTION_APPLIES_TO_NVIDIA_UNINSTALL,
      NULL, "Specify what user interface to use, if available.  "
      "Valid values for &UI& are 'ncurses' (the default) or 'none'. "
      "If the ncurses interface fails to initialize, or 'none' "
      "is specified, then a simple printf/scanf interface will "
      "be used." },

    { "no-ncurses-color", 'c', NVGETOPT_OPTION_APPLIES_TO_NVIDIA_UNINSTALL,
      NULL, "Disable use of color in the ncurses user interface." },

    { "no-nvidia-modprobe", NO_NVIDIA_MODPROBE_OPTION, 0, NULL,
      "Skip installation of 'nvidia-modprobe', a setuid root utility which "
      "nvidia-installer installs by default.  nvidia-modprobe can be used by "
      "user-space NVIDIA driver components to load the NVIDIA kernel module, "
      "create the NVIDIA device files, and configure certain runtime settings "
      "in the kernel when those components run without sufficient privileges "
      "to do so on their own, e.g., the CUDA driver run within the permissions "
      "of a non-privileged user.  This utility is only needed if other means "
      "of performing these privileged operations are unavailable. See the "
      "nvidia-modprobe(1) man page for full details on the tasks performed by "
      "this utility." },

    { "kernel-name", 'k', NVGETOPT_STRING_ARGUMENT, NULL,
      "Build and install the NVIDIA kernel module for the "
      "non-running kernel specified by &KERNEL-NAME& (&KERNEL-NAME& "
      "should be the output of `uname -r` when the target kernel is "
      "actually running).  This option implies "
      "'--no-precompiled-interface'.  If the options "
      "'--kernel-install-path' and '--kernel-source-path' are not "
      "given, then they will be inferred from &KERNEL-NAME&; eg: "
      "'/lib/modules/&KERNEL-NAME&/kernel/drivers/video/' and "
      "'/lib/modules/&KERNEL-NAME&/build/', respectively." },

    { "no-precompiled-interface", 'n', 0, NULL,
      "Disable use of precompiled kernel interfaces." },

    { "no-abi-note", NO_ABI_NOTE_OPTION, 0, NULL,
      "The NVIDIA OpenGL libraries contain an OS ABI note tag, "
      "which identifies the minimum kernel version needed to use the "
      "library.  This option causes the installer to remove this note "
      "from the OpenGL libraries during installation." },

    { "no-rpms", NO_RPMS_OPTION, 0, NULL,
      "Normally, the installer will check for several rpms that "
      "conflict with the driver (specifically: NVIDIA_GLX and "
      "NVIDIA_kernel), and remove them if present.  This option "
      "disables this check." },

    { "no-backup", 'b', 0, NULL,
      "During driver installation, conflicting files are backed "
      "up, so that they can be restored when the driver is "
      "uninstalled.  This option causes the installer to simply delete "
      "conflicting files, rather than back them up." },

    { "no-recursion", 'r', 0, NULL,
      "Normally, nvidia-installer will recursively search for "
      "potentially conflicting libraries under the default OpenGL "
      "and X server installation locations.  With this option set, "
      "the installer will only search in the top-level directories." },

    /* alias for backwards compatibility */
    { "kernel-module-only", 'K',
      NVGETOPT_OPTION_APPLIES_TO_NVIDIA_UNINSTALL, NULL, NULL },

    { "kernel-modules-only", 'K',
      NVGETOPT_OPTION_APPLIES_TO_NVIDIA_UNINSTALL, NULL,
      "Install the kernel modules only, and do not uninstall the "
      "existing driver.  This is intended to be used to install kernel "
      "modules for additional kernels (in cases where you might boot "
      "between several different kernels).  To use this option, you "
      "must already have a driver installed, and the version of the "
      "installed driver must match the version of these kernel "
      "modules." },

    /* alias for backwards compatibility */
    { "no-kernel-module", NO_KERNEL_MODULES_OPTION, 0, NULL, NULL },

    { "no-kernel-modules", NO_KERNEL_MODULES_OPTION, 0, NULL,
      "Install everything but the kernel modules, and do not remove any "
      "existing, possibly conflicting, kernel modules.  This can be "
      "useful in some debug environments, or when installing the open kernel "
      "modules from source.  If you use this option, you "
      "must be careful to ensure that NVIDIA kernel modules matching "
      "this driver version are installed separately." },

    { "no-x-check", NO_X_CHECK_OPTION, 0, NULL,
      "Do not abort the installation if nvidia-installer detects that "
      "an X server is running.  Only under very rare circumstances should "
      "this option be used." },

    { "precompiled-kernel-interfaces-path",
      PRECOMPILED_KERNEL_INTERFACES_PATH_OPTION,
      NVGETOPT_STRING_ARGUMENT, NULL,
      "Before searching for a precompiled kernel interface in the "
      ".run file, search in the specified directory." },

    { "no-nouveau-check", 'z', 0, NULL,
      "Normally, nvidia-installer aborts installation if the nouveau kernel "
      "driver is in use.  Use this option to disable this check." },

    { "disable-nouveau", 'Z', NVGETOPT_IS_BOOLEAN, NULL,
      "nvidia-installer will attempt to disable the nouveau kernel driver "
      "by default, if it is in use during installation. Use "
      "'--no-disable-nouveau to prevent nvidia-installer from disabling "
      "nouveau by default."},

    { "run-nvidia-xconfig", 'X', 0, NULL,
      "nvidia-installer can optionally invoke the nvidia-xconfig utility.  "
      "This will update the system X configuration file so that the NVIDIA X "
      "driver is used.  The pre-existing X configuration file will be backed "
      "up.  At the end of installation, nvidia-installer will "
      "ask the user if they wish to run nvidia-xconfig; the default "
      "response is 'no'.  Use this option to make the default response "
      "'yes'.  This is useful with the '--no-questions' or '--silent' "
      "options, which assume the default values for all questions." },
    
    { "force-selinux", FORCE_SELINUX_OPTION, NVGETOPT_STRING_ARGUMENT, NULL,
      "Linux installations using SELinux (Security-Enhanced Linux) "
      "require that the security type of all shared libraries be set "
      "to 'shlib_t' or 'textrel_shlib_t', depending on the distribution. "
      "nvidia-installer will detect when to set the security type, "
      "and set it using chcon(1) on the shared libraries it installs.  "
      "If the execstack(8) system utility is present, nvidia-installer will "
      "use it to also clear the executable stack flag of the libraries.  "
      "Use this option to override nvidia-installer's detection of when "
      "to set the security type.  "
      "Valid values for &FORCE-SELINUX& are 'yes' (force setting of the "
      "security type), "
      "'no' (prevent setting of the security type), and 'default' "
      "(let nvidia-installer decide when to set the security type)." },

    { "selinux-chcon-type", SELINUX_CHCON_TYPE_OPTION,
      NVGETOPT_STRING_ARGUMENT | NVGETOPT_OPTION_APPLIES_TO_NVIDIA_UNINSTALL,
      NULL, "When SELinux support is enabled, nvidia-installer will try to "
      "determine which chcon argument to use by first trying "
      "'textrel_shlib_t', then 'texrel_shlib_t', then 'shlib_t'.  Use this "
      "option to override this detection logic." },

    { "no-sigwinch-workaround", NO_SIGWINCH_WORKAROUND_OPTION,
      NVGETOPT_OPTION_APPLIES_TO_NVIDIA_UNINSTALL, NULL,
      "Normally, nvidia-installer ignores the SIGWINCH signal before it "
      "forks to execute commands, e.g. to build the kernel module, and "
      "restores the SIGWINCH signal handler after the child process "
      "has terminated.  This option disables this behavior." },

    { "no-distro-scripts", NO_DISTRO_SCRIPTS_OPTION,
      NVGETOPT_OPTION_APPLIES_TO_NVIDIA_UNINSTALL, NULL,
      "Normally, nvidia-installer will run scripts from /usr/lib/nvidia before "
      "and after installing or uninstalling the driver.  Use this option to "
      "disable execution of these scripts." },

    { "no-opengl-files", NO_OPENGL_FILES_OPTION, 0, NULL,
      "Do not install any of the OpenGL-related driver files." },

    { "no-wine-files", NO_WINE_FILES_OPTION, 0, NULL,
      "Do not install any of the Wine driver files." },

    { "kernel-module-source-prefix", KERNEL_MODULE_SOURCE_PREFIX_OPTION, 
       NVGETOPT_STRING_ARGUMENT, NULL,
      "Specify a path where the source directory for the kernel module will "
      "be installed. Default: install source directory at /usr/src" },

    { "kernel-module-source-dir", KERNEL_MODULE_SOURCE_DIR_OPTION,
       NVGETOPT_STRING_ARGUMENT, NULL,
      "Specify the name of the directory where the kernel module sources will "
      "be installed. Default: directory name is \"nvidia-VERSION\""},

    { "no-kernel-module-source", NO_KERNEL_MODULE_SOURCE_OPTION, 0, NULL,
      "Skip installation of the kernel module source."},

    { "dkms", DKMS_OPTION, NVGETOPT_IS_BOOLEAN, NULL,
      "nvidia-installer can optionally register the NVIDIA kernel module "
      "sources, if installed, with DKMS, then build and install a kernel "
      "module using the DKMS-registered sources.  This will allow the DKMS "
      "infrastructure to automatically build a new kernel module when "
      "changing kernels.  During installation, if DKMS is detected, "
      "nvidia-installer will ask the user if they wish to register the "
      "module with DKMS; the default response is 'yes' unless the --no-dkms "
      "option is set, in which case the default response is 'no'." },

    { "module-signing-secret-key", MODULE_SIGNING_SECRET_KEY_OPTION, 
      NVGETOPT_STRING_ARGUMENT, NULL,
      "Specify a path to a private key to use for signing the NVIDIA kernel "
      "module. The corresponding public key must also be provided." },

    { "module-signing-public-key", MODULE_SIGNING_PUBLIC_KEY_OPTION, 
      NVGETOPT_STRING_ARGUMENT, NULL,
      "Specify a path to a public key to use for verifying the signature of "
      "the NVIDIA kernel module. The corresponding private key must also be "
      "provided." },

    { "module-signing-script", MODULE_SIGNING_SCRIPT_OPTION,
      NVGETOPT_STRING_ARGUMENT, NULL,
      "Specify a path to a program to use for signing the NVIDIA kernel "
      "module. The program will be called with the arguments: program-name "
      "<HASH> <PRIVATEKEY> <PUBLICKEY> <MODULE>; if the program returns an "
      "error status, it will be called again with the arguments: program-name "
      "<PRIVATEKEY> <PUBLICKEY> <MODULE>. Default: use the \"sign-file\" "
      "script in the kernel source directory." },

    { "module-signing-key-path", MODULE_SIGNING_KEY_PATH_OPTION,
      NVGETOPT_STRING_ARGUMENT, NULL,
      "Specify a path where signing keys generated by nvidia-installer will "
      "be installed. Default: install keys to '" DEFAULT_MODULE_SIGNING_KEY_PATH
      "'." },

    { "module-signing-hash", MODULE_SIGNING_HASH_OPTION,
      NVGETOPT_STRING_ARGUMENT, NULL,
      "Specify a cryptographic hash algorithm to use for signing kernel "
      "modules. This requires a module signing tool that allows explicit "
      "selection of the hash algorithm, and the hash algorithm name must "
      "be recognizable by the module signing tool. Default: select a hash "
      "algorithm automatically, based on the kernel's configuration." },

    { "module-signing-x509-hash", MODULE_SIGNING_X509_HASH_OPTION,
      NVGETOPT_STRING_ARGUMENT, NULL,
      "Specify a cryptographic hash algorithm to use for signing X.509 "
      "certificates generated by nvidia-installer. The hash algorithm "
      "name must be one of the message digest algorithms recognized by "
      "the x509(1) command." },

    { "no-check-for-alternate-installs", NO_CHECK_FOR_ALTERNATE_INSTALLS_OPTION,
      0, NULL,
      "Maintainers of alternate driver installation methods can report the "
      "presence and/or availability of an alternate driver installation to "
      "nvidia-installer. Setting this option skips the check for alternate "
      "driver installations." },

    { "no-unified-memory", NO_UVM_OPTION, 0, NULL,
      "Do not install the NVIDIA Unified Memory kernel module. This kernel "
      "module is required for CUDA on 64-bit systems, and if it is not "
      "installed, the CUDA driver and CUDA applications will not be able to "
      "run. The '--no-unified-memory' option should only be used to work "
      "around failures to build or install the Unified Memory kernel module on "
      "systems that do not need to run CUDA." },

    { "no-drm", NO_DRM_OPTION, 0, NULL,
      "Do not install the nvidia-drm kernel module. This kernel module "
      "provides several features, including X11 autoconfiguration, support for "
      "PRIME, and DRM-KMS. The latter is used to support modesetting on "
      "windowing systems that run independently of X11. The '--no-drm' option "
      "should only be used to work around failures to build or install the "
      "nvidia-drm kernel module on systems that do not need these features." },

    { "no-peermem", NO_PEERMEM_OPTION, 0, NULL,
      "Do not install the nvidia-peermem kernel module. This kernel module "
      "provides support for peer-to-peer memory sharing with Mellanox HCAs "
      "(Host Channel Adapters) via GPUDirect RDMA (Remote Direct Memory "
      "Access)." },

    { "concurrency-level", 'j', NVGETOPT_INTEGER_ARGUMENT, NULL,
      "Set the concurrency level for operations such as building the kernel "
      "module which may be parallelized on SMP systems. By default, this will "
      "be set to the number of detected CPUs, or to '1', if nvidia-installer "
      "fails to detect the number of CPUs. Systems with a large number of "
      "CPUs will have the default concurrency level limited to 32; setting "
      "a higher level on the command line will override this limit." },

    { "force-libglx-indirect", FORCE_LIBGLX_INDIRECT, 0, NULL,
      "Always install a libGLX_indirect.so.0 symlink, overwriting one if it "
      "exists." },
    { "no-libglx-indirect", NO_LIBGLX_INDIRECT, 0, NULL,
      "Do not install a libGLX_indirect.so.0 symlink." },

    { "install-libglvnd", INSTALL_LIBGLVND_OPTION, NVGETOPT_IS_BOOLEAN, NULL,
      "The installer will try to determine whether the libglvnd libraries are "
      "already available, and will install them if they're not. Use "
      "--install-libglvnd to always install the libglvnd libraries, "
      "overwriting any that already exist.  Use --no-install-libglvnd to "
      "exclude the libglvnd libraries, even if they appear to be missing." },

    { "glvnd-egl-config-path", GLVND_EGL_CONFIG_FILE_PATH_OPTION, NVGETOPT_STRING_ARGUMENT, NULL,
      "Install the EGL vendor library config file to this directory. If the "
      "libglvnd libraries are already present, then by default the installer "
      "will try to determine the path by running `pkg-config "
      "--variable=datadir libglvnd`. If that fails, then it will default to "
      DEFAULT_GLVND_EGL_JSON_PATH "."
    },

    { "egl-external-platform-config-path",
      EGL_EXTERNAL_PLATFORM_CONFIG_FILE_PATH_OPTION, NVGETOPT_STRING_ARGUMENT, NULL,
      "If the package includes an EGL external platform library, then install "
      "the EGL external platform library config file to this directory. "
      "Defaults to " DEFAULT_EGL_EXTERNAL_PLATFORM_JSON_PATH "."
    },

    { "override-file-type-destination",
      OVERRIDE_FILE_TYPE_DESTINATION_OPTION, NVGETOPT_STRING_ARGUMENT, NULL,
      "Override the default destination for a file type. This option takes an "
      "argument in the form of '<FILE_TYPE>:<destination>', where <FILE_TYPE> "
      "is a file type from the installer .manifest file, and <destination> is "
      "an absolute path to the directory where files of that type should be "
      "installed. This option may be given multiple times in order to override "
      "the destinations for multiple file types. Use of this option takes "
      "precedence over any other options that might otherwise influence the "
      "destination of the specified file type."
    },

    { "skip-depmod",
      SKIP_DEPMOD_OPTION, NVGETOPT_OPTION_APPLIES_TO_NVIDIA_UNINSTALL, NULL,
      "Don't run the depmod(1) utility after modifying kernel modules.  This "
      "should only be used in cases where depmod(1) will be run separately after "
      "running nvidia-installer."
    },

    { "systemd", SYSTEMD_OPTION, NVGETOPT_IS_BOOLEAN, NULL,
      "By default, the installer will install systemd unit files if systemctl "
      "is detected. Specifying --no-systemd will disable installation of "
      "systemd units." },

    { "systemd-unit-prefix",
      SYSTEMD_UNIT_PREFIX_OPTION, NVGETOPT_STRING_ARGUMENT, NULL,
      "The path to which systemd unit files should be installed. By default, "
      "the installer uses `pkg-config --variable=systemdsystemunitdir systemd` "
      "to determine the location to install systemd unit files, or "
      "'/usr/lib/systemd/system' if pkg-config is not available. Ignored if "
      "--no-systemd is specified." },

    { "systemd-sleep-prefix",
      SYSTEMD_SLEEP_PREFIX_OPTION, NVGETOPT_STRING_ARGUMENT, NULL,
      "The path to which systemd-sleep script files should be installed. By "
      "default, the installer uses `pkg-config --variable=systemdsleepdir "
      "systemd` to determine the location to install systemd-sleep script "
      "files, or '/usr/lib/systemd/system-sleep' if pkg-config is not "
      "available. Ignored if --no-systemd is specified." },

    { "systemd-sysconf-prefix",
      SYSTEMD_SYSCONF_PREFIX_OPTION, NVGETOPT_STRING_ARGUMENT, NULL,
      "The path to which systemd unit enable symlinks should be installed. By "
      "default, the installer uses `pkg-config "
      "--variable=systemdsystemconfdir systemd` to determine the location to "
      "install these symlinks, or '/etc/systemd/system' if pkg-config is not "
      "available. Ignored if --no-systemd is specified." },

    { "kernel-module-type", 'M',
      NVGETOPT_STRING_ARGUMENT, NULL,
      "The type of kernel modules to build and install. Valid values are "
      "\"open\" and \"proprietary\"."
    },

    { "kernel-module-build-directory", 'm',
      NVGETOPT_STRING_ARGUMENT, NULL,
      "Directly set the directory within the package from which to build the "
      "kernel modules. This option is deprecated; use \"--kernel-module-type\" "
      "instead."
    },

    { "print-recommended-kernel-module-type",
      PRINT_RECOMMENDED_MODULE_TYPE_OPTION,  0, NULL,
      "Print if \"open\" or \"proprietary\" modules should be used based on "
      "currently attached GPUs and exit. NOTE: A kernel module type may be "
      "recommended even if it is not included in this driver package."
    },

    { "allow-installation-with-running-driver",
      ALLOW_INSTALLATION_WITH_RUNNING_DRIVER_OPTION, NVGETOPT_IS_BOOLEAN, NULL,
      "Proceed with installation even if an NVIDIA driver is already installed "
      "and running."
    },

    { "rebuild-initramfs",
      REBUILD_INITRAMFS_OPTION, NVGETOPT_IS_BOOLEAN, NULL,
      "Rebuild the initramfs after installation is complete, regardless of the "
      "default action recommended by nvidia-installer.  --no-rebuild-initramfs "
      "skips rebuilding the initramfs after installation is complete.  These "
      "options are useful for non-interactive installations when a specific "
      "behavior is desired, regardless of what nvidia-installer would "
      "recommend by default in an interactive installation."
    },

    /* Orphaned options: These options were in the long_options table in
     * nvidia-installer.c but not in the help. */
    { "debug",                    'd', 0, NULL,NULL },
    { "help-args-only",           HELP_ARGS_ONLY_OPTION, 0, NULL, NULL },
    { "add-this-kernel",          ADD_THIS_KERNEL_OPTION, 0, NULL, NULL },
    { "rpm-file-list",            RPM_FILE_LIST_OPTION,
      NVGETOPT_STRING_ARGUMENT, NULL, NULL },
    { "no-rpms",                  NO_RPMS_OPTION, 0, NULL, NULL},
    { "advanced-options-args-only", ADVANCED_OPTIONS_ARGS_ONLY_OPTION, 0,
      NULL, NULL },

    /* Deprecated options: These options are no longer used, but
     * nvidia-installer will allow the user to set them anyway, for
     * backwards-compatibility purposes. */
    { "no-runlevel-check", NO_RUNLEVEL_CHECK_OPTION, 0, NULL, NULL },
    { "install-vdpau-wrapper", INSTALL_VDPAU_WRAPPER_OPTION, NVGETOPT_IS_BOOLEAN, NULL, NULL },
    { "no-network", 'N', 0, NULL, NULL },
    { "force-tls", FORCE_TLS_OPTION, NVGETOPT_STRING_ARGUMENT, NULL, NULL },
    { "force-tls-compat32", FORCE_TLS_COMPAT32_OPTION, NVGETOPT_STRING_ARGUMENT,
      NULL, NULL },
    { "glvnd-glx-client", GLVND_GLX_CLIENT_OPTION, NVGETOPT_IS_BOOLEAN, NULL, NULL },
    { "glvnd-egl-client", GLVND_EGL_CLIENT_OPTION, NVGETOPT_IS_BOOLEAN, NULL, NULL },
    { "no-cc-version-check", NO_CC_VERSION_CHECK_OPTION, 0, NULL, NULL },

    { NULL, 0, 0, NULL, NULL },
};

#endif /* __OPT_TABLE_H__ */
