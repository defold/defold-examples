#ifndef DMSDK_LOG_H
#define DMSDK_LOG_H

#include <stdint.h>

/**
 * Log severity
 */
enum dmLogSeverity
{
    DM_LOG_SEVERITY_DEBUG       = 0,//!< DM_LOG_SEVERITY_DEBUG
    DM_LOG_SEVERITY_USER_DEBUG  = 1,//!< DM_LOG_SEVERITY_USER_DEBUG
    DM_LOG_SEVERITY_INFO        = 2,//!< DM_LOG_SEVERITY_INFO
    DM_LOG_SEVERITY_WARNING     = 3,//!< DM_LOG_SEVERITY_WARNING
    DM_LOG_SEVERITY_ERROR       = 4,//!< DM_LOG_SEVERITY_ERROR
    DM_LOG_SEVERITY_FATAL       = 5,//!< DM_LOG_SEVERITY_FATAL
};

/**
 * dmLog, dmLogOnce functions for domain based logging
 * @param format Format string
 * @param args... Format args (variable arg list)
 *
 * Valid domain names are Debug, UserDebug, Info, Warning, Error, Fatal (ex. dmLogInfo or dmLogOnceInfo)
 *
 */

#ifdef DM_LOG_DISABLE

#define dmLogInfo(format, args...) do {} while(0);
#define dmLogWarning(format, args...) do {} while(0);
#define dmLogError(format, args...) do {} while(0);
#define dmLogFatal(format, args...) do {} while(0);

#else

#ifndef DLIB_LOG_DOMAIN
#define DLIB_LOG_DOMAIN "DEFAULT"
#ifdef __GNUC__
#warning "DLIB_LOG_DOMAIN is not defined"
#endif
#endif

#ifdef __GNUC__
void dmLogInternal(dmLogSeverity severity, const char* domain, const char* format, ...)
    __attribute__ ((format (printf, 3, 4)));
#else
void dmLogInternal(dmLogSeverity severity, const char* domain, const char* format, ...);
#endif

#ifdef _MSC_VER
#define dmLogDebug(format, ... ) dmLogInternal(DM_LOG_SEVERITY_DEBUG, DLIB_LOG_DOMAIN, format, __VA_ARGS__ );
#define dmLogUserDebug(format, ... ) dmLogInternal(DM_LOG_SEVERITY_USER_DEBUG, DLIB_LOG_DOMAIN, format, __VA_ARGS__ );
#define dmLogInfo(format, ... ) dmLogInternal(DM_LOG_SEVERITY_INFO, DLIB_LOG_DOMAIN, format, __VA_ARGS__ );
#define dmLogWarning(format, ... ) dmLogInternal(DM_LOG_SEVERITY_WARNING, DLIB_LOG_DOMAIN, format, __VA_ARGS__ );
#define dmLogError(format, ... ) dmLogInternal(DM_LOG_SEVERITY_ERROR, DLIB_LOG_DOMAIN, format, __VA_ARGS__ );
#define dmLogFatal(format, ... ) dmLogInternal(DM_LOG_SEVERITY_FATAL, DLIB_LOG_DOMAIN, format, __VA_ARGS__ );
#else
#define dmLogDebug(format, args...) dmLogInternal(DM_LOG_SEVERITY_DEBUG, DLIB_LOG_DOMAIN, format, ## args);
#define dmLogUserDebug(format, args...) dmLogInternal(DM_LOG_SEVERITY_USER_DEBUG, DLIB_LOG_DOMAIN, format, ## args);
#define dmLogInfo(format, args...) dmLogInternal(DM_LOG_SEVERITY_INFO, DLIB_LOG_DOMAIN, format, ## args);
#define dmLogWarning(format, args...) dmLogInternal(DM_LOG_SEVERITY_WARNING, DLIB_LOG_DOMAIN, format, ## args);
#define dmLogError(format, args...) dmLogInternal(DM_LOG_SEVERITY_ERROR, DLIB_LOG_DOMAIN, format, ## args);
#define dmLogFatal(format, args...) dmLogInternal(DM_LOG_SEVERITY_FATAL, DLIB_LOG_DOMAIN, format, ## args);
#endif

#define dmLogOnceIdentifier __dmLogOnce
#define __DM_LOG_PASTE(x, y) x ## y
#define DM_LOG_PASTE(x, y) __DM_LOG_PASTE(x, y)

#ifdef _MSC_VER
#define dmLogOnceInternal(method, format, ... )                     \
    {                                                               \
        static int DM_LOG_PASTE(dmLogOnceIdentifier, __LINE__) = 0; \
        if (DM_LOG_PASTE(dmLogOnceIdentifier, __LINE__) == 0)       \
        {                                                           \
            DM_LOG_PASTE(dmLogOnceIdentifier, __LINE__) = 1;        \
            method(format, __VA_ARGS__ );                           \
        }                                                           \
    }
#define dmLogOnceDebug(format, ... ) dmLogOnceInternal(dmLogDebug, format, __VA_ARGS__ )
#define dmLogOnceUserDebug(format, ... ) dmLogOnceInternal(dmLogUserDebug, format, __VA_ARGS__ )
#define dmLogOnceInfo(format, ... ) dmLogOnceInternal(dmLogInfo, format, __VA_ARGS__ )
#define dmLogOnceWarning(format, ... ) dmLogOnceInternal(dmLogWarning, format, __VA_ARGS__ )
#define dmLogOnceError(format, ... ) dmLogOnceInternal(dmLogError, format, __VA_ARGS__ )
#define dmLogOnceFatal(format, ... ) dmLogOnceCritical(dmLogFatal, format, __VA_ARGS__ )
#else
#define dmLogOnceInternal(method, format, args... )                 \
    {                                                               \
        static int DM_LOG_PASTE(dmLogOnceIdentifier, __LINE__) = 0; \
        if (DM_LOG_PASTE(dmLogOnceIdentifier, __LINE__) == 0)       \
        {                                                           \
            DM_LOG_PASTE(dmLogOnceIdentifier, __LINE__) = 1;        \
            method(format, ## args );                               \
        }                                                           \
    }
#define dmLogOnceDebug(format, args... ) dmLogOnceInternal(dmLogDebug, format, ## args )
#define dmLogOnceUserDebug(format, args... ) dmLogOnceInternal(dmLogUserDebug, format, ## args )
#define dmLogOnceInfo(format, args... ) dmLogOnceInternal(dmLogInfo, format, ## args )
#define dmLogOnceWarning(format, args... ) dmLogOnceInternal(dmLogWarning, format, ## args )
#define dmLogOnceError(format, args... ) dmLogOnceInternal(dmLogError, format, ## args )
#define dmLogOnceFatal(format, args... ) dmLogOnceCritical(dmLogFatal, format, ## args )
#endif

#endif

#endif // DMSDK_LOG_H
