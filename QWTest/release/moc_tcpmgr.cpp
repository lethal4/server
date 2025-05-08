/****************************************************************************
** Meta object code from reading C++ file 'tcpmgr.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tcpmgr.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpmgr.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASStcpMgrENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASStcpMgrENDCLASS = QtMocHelpers::stringData(
    "tcpMgr",
    "sig_con_success",
    "",
    "bsuccess",
    "sig_send_data",
    "ReqId",
    "reqId",
    "data",
    "sig_swich_chatdlg",
    "sig_login_failed",
    "sig_user_search",
    "std::shared_ptr<searchInfo>",
    "sig_friend_apply",
    "std::shared_ptr<AddFriendApply>",
    "sig_add_auth_friend",
    "std::shared_ptr<AuthInfo>",
    "sig_auth_rsp",
    "std::shared_ptr<AuthRsp>",
    "sig_text_chat_msg",
    "std::shared_ptr<TextChatMsg>",
    "msg",
    "slotTcpConnect",
    "ServerInfo",
    "slotSendData"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASStcpMgrENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   80,    2, 0x06,    1 /* Public */,
       4,    2,   83,    2, 0x06,    3 /* Public */,
       8,    0,   88,    2, 0x06,    6 /* Public */,
       9,    1,   89,    2, 0x06,    7 /* Public */,
      10,    1,   92,    2, 0x06,    9 /* Public */,
      12,    1,   95,    2, 0x06,   11 /* Public */,
      14,    1,   98,    2, 0x06,   13 /* Public */,
      16,    1,  101,    2, 0x06,   15 /* Public */,
      18,    1,  104,    2, 0x06,   17 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      21,    1,  107,    2, 0x0a,   19 /* Public */,
      23,    2,  110,    2, 0x0a,   21 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QByteArray,    6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void, 0x80000000 | 17,    2,
    QMetaType::Void, 0x80000000 | 19,   20,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 22,    2,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QByteArray,    6,    7,

       0        // eod
};

Q_CONSTINIT const QMetaObject tcpMgr::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASStcpMgrENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASStcpMgrENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASStcpMgrENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<tcpMgr, std::true_type>,
        // method 'sig_con_success'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'sig_send_data'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ReqId, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        // method 'sig_swich_chatdlg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sig_login_failed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'sig_user_search'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<searchInfo>, std::false_type>,
        // method 'sig_friend_apply'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<AddFriendApply>, std::false_type>,
        // method 'sig_add_auth_friend'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<AuthInfo>, std::false_type>,
        // method 'sig_auth_rsp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<AuthRsp>, std::false_type>,
        // method 'sig_text_chat_msg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<TextChatMsg>, std::false_type>,
        // method 'slotTcpConnect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ServerInfo, std::false_type>,
        // method 'slotSendData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ReqId, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>
    >,
    nullptr
} };

void tcpMgr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<tcpMgr *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sig_con_success((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->sig_send_data((*reinterpret_cast< std::add_pointer_t<ReqId>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 2: _t->sig_swich_chatdlg(); break;
        case 3: _t->sig_login_failed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->sig_user_search((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<searchInfo>>>(_a[1]))); break;
        case 5: _t->sig_friend_apply((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<AddFriendApply>>>(_a[1]))); break;
        case 6: _t->sig_add_auth_friend((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<AuthInfo>>>(_a[1]))); break;
        case 7: _t->sig_auth_rsp((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<AuthRsp>>>(_a[1]))); break;
        case 8: _t->sig_text_chat_msg((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<TextChatMsg>>>(_a[1]))); break;
        case 9: _t->slotTcpConnect((*reinterpret_cast< std::add_pointer_t<ServerInfo>>(_a[1]))); break;
        case 10: _t->slotSendData((*reinterpret_cast< std::add_pointer_t<ReqId>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (tcpMgr::*)(bool );
            if (_t _q_method = &tcpMgr::sig_con_success; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (tcpMgr::*)(ReqId , QByteArray );
            if (_t _q_method = &tcpMgr::sig_send_data; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (tcpMgr::*)();
            if (_t _q_method = &tcpMgr::sig_swich_chatdlg; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (tcpMgr::*)(int );
            if (_t _q_method = &tcpMgr::sig_login_failed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (tcpMgr::*)(std::shared_ptr<searchInfo> );
            if (_t _q_method = &tcpMgr::sig_user_search; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (tcpMgr::*)(std::shared_ptr<AddFriendApply> );
            if (_t _q_method = &tcpMgr::sig_friend_apply; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (tcpMgr::*)(std::shared_ptr<AuthInfo> );
            if (_t _q_method = &tcpMgr::sig_add_auth_friend; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (tcpMgr::*)(std::shared_ptr<AuthRsp> );
            if (_t _q_method = &tcpMgr::sig_auth_rsp; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (tcpMgr::*)(std::shared_ptr<TextChatMsg> );
            if (_t _q_method = &tcpMgr::sig_text_chat_msg; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject *tcpMgr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tcpMgr::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASStcpMgrENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "singleton<tcpMgr>"))
        return static_cast< singleton<tcpMgr>*>(this);
    if (!strcmp(_clname, "std::enable_shared_from_this<tcpMgr>"))
        return static_cast< std::enable_shared_from_this<tcpMgr>*>(this);
    return QObject::qt_metacast(_clname);
}

int tcpMgr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void tcpMgr::sig_con_success(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void tcpMgr::sig_send_data(ReqId _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void tcpMgr::sig_swich_chatdlg()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void tcpMgr::sig_login_failed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void tcpMgr::sig_user_search(std::shared_ptr<searchInfo> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void tcpMgr::sig_friend_apply(std::shared_ptr<AddFriendApply> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void tcpMgr::sig_add_auth_friend(std::shared_ptr<AuthInfo> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void tcpMgr::sig_auth_rsp(std::shared_ptr<AuthRsp> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void tcpMgr::sig_text_chat_msg(std::shared_ptr<TextChatMsg> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
