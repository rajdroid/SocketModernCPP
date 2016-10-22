#include <string>

/** Contains general Error Types that might happen during
 *  socket creation or using socket
 */
enum class ErrorCodes {
    errConnectionTimeout,
    errUnknown
};

/** SocketExceptions class object is used for throwing exception
 *  when error occur during creation of socket or during using
 *  that socket. Error which might happen during operation are
 *  defined in enum class ErrorCodes
 */
class SocketExceptions
{
public:
    /** Constructor which take type ErrorCodes and set human friendly
     *  Exception description
     *  @param  errType
     *      Type of Error
     */
    SocketExceptions(ErrorCodes errType = ErrorCodes::errUnknown)
    {
        cException = errType;

        switch(errType)
        {
            case ErrorCodes::errConnectionTimeout:  SetExceptionString("Connection Timeout during making a connection");
                                                    break;
            case ErrorCodes::errUnknown:   SetExceptionString("Unknown type of error happened");
                            break;
        }
    }

    /** Copy Constructor which take another SockerException Object and
     *  create copy of that object
     *  @param  cSocketExcObj
     *      SocketException object from which to copy details
     */
    SocketExceptions(const SocketExceptions &cSocketExcObj)
    {
        cException = cSocketExcObj.cException;
        sExceptionString = cSocketExcObj.sExceptionString;
    }

    /** Return ErrorCode for which exception is happened
     *  @returns    cException
     *      Type of Error for which this Exception is defined
     */
    ErrorCodes getExceptionType()
    {
        return cException;
    }

    /** Return Exception string associated with the Exception
     *  @returns    sExceptionString
     *      String containing exception description
     */
    std::string getExceptionString()
    {
        return sExceptionString;
    }

private:
    ErrorCodes cException;          /**< Error type */
    std::string sExceptionString;   /**< String describing Exception */

    /** Set exception string and this function is for internal use
     *  it is not used by the users of this class
     *  @param  sErrorString
     *      string which contain description of error
     *  @returns
     *      void
     */
    void SetExceptionString(const std::string &sErrorString)
    {
        sExceptionString = sErrorString;
    }
};