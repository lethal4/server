const grpc = require('@grpc/grpc-js');
const message_proto = require('./proto');
const const_module = require('./const');
const { v4: uuidv4} = require('uuid');
const emailModule = require('./email');
const redis_module = require('./redis');

async function GetVarifyCode(call, callback) {//async
    console.log("email is ", call.request.email);
    try{
        let query_res = await redis_module.GetRedis(const_module.code_prefix+call.request.email);//前缀+邮箱地址
        console.log("query_res is ", query_res);
        let uniqueId = query_res;
        
        if (!query_res) {
            console.error("Redis query failed for email:", call.request.email);
        }
        
        if(query_res == null)
        {
            uniqueId = uuidv4();
            if( uniqueId.length > 4)
            {
                uniqueId = uniqueId.substring(0,4);
            }
            let  bres = await redis_module.SetRedisExpire(const_module.code_prefix+call.request.email, uniqueId,300)
            if(!bres){
                
                console.error("Failed to set Redis key for email:", call.request.email);

                callback(null, { email: call.request.email,//grpc返回一个设置失败错误的json
                    error:const_module.Errors.RedisErr
                });
                return ;
            }
        }
       
        console.log("uniqueId is ", uniqueId);
        let text_str =  '验证码是'+ uniqueId +'请于四分钟内于APP中完成注册,否则验证码将会失效,'
        //发送邮件
        let mailOptions = {
            from: 'w2105424884@vip.qq.com',
            to: call.request.email,
            subject: 'QW注册验证码',
            text: text_str,
        };
    
        let send_res = await emailModule.SendMail(mailOptions);//await等待它完成 异步变同步
        console.log("send res is ", send_res);

        callback(null, { email:  call.request.email,
            error:const_module.Errors.Success
        }); 
        
 
    }catch(error){
        console.log("catch error is ", error);

        callback(null, { email:  call.request.email,
            error:const_module.Errors.Exception
        }); 
    }
     
}

function main() {
    var server = new grpc.Server();
    server.addService(message_proto.VarifyService.service, { GetVarifyCode: GetVarifyCode });
    server.bindAsync('127.0.0.1:50051', grpc.ServerCredentials.createInsecure(), (err, port) => {
        if (err) {
            console.error('Error binding server:', err);
            return;
        }
        console.log('gRPC server bound to port', port);
        
        console.log('gRPC server started');
    });
}

main();
