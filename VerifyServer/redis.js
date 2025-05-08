const config_module = require('./config')
const Redis = require('ioredis')

//创建redis客户端
const RedisCli = new Redis({
    host: config_module.redis_host,//redis主机
    port: config_module.redis_port,//端口
    password: config_module.redis_passwd,//密码
});

//监听
 RedisCli.on("error", function (err){
    console.log("RedisCli connect error");
    RedisCli.quit();//不需要考虑回收，js基于C++,全为引用，不需要回收.
 })

 /**
 * 根据key获取value
 * @param {*} key 
 * @returns 
 */
async function GetRedis(key) {//用await则函数必须声明为异步的async
    
    try{
        const result = await RedisCli.get(key)//get会返回一个promiss 只返回一个则不代表操作完成，需要等待其他完成，await作为等待
        if(result === null){
          console.log('result:','<'+result+'>', 'This key cannot be find...')
          return null
        }
        console.log('Result:','<'+result+'>','Get key success!...');
        return result
    }catch(error){
        console.log('GetRedis error is', error);
        return null
    }

  }

/**
 * 根据key查询redis中是否存在key
 * @param {*} key 
 * @returns 
 */
async function QueryRedis(key) {
    try{
        const result = await RedisCli.exists(key)//通过官方提供的exists来判断
        //  判断该值是否为空 如果为空返回null
        if (result === 0) {
          console.log('result:<','<'+result+'>','This key is null...');
          return null
        }
        console.log('Result:','<'+result+'>','With this value!...');
        return result
    }catch(error){
        console.log('QueryRedis error is', error);
        return null
    }

  }

/**
 * 设置key和value，并过期时间
 * @param {*} key 
 * @param {*} value 
 * @param {*} exptime 
 * @returns 
 */
async function SetRedisExpire(key,value, exptime){
    try{
        // 设置键和值
        await RedisCli.set(key,value)
        // 设置过期时间（以秒为单位）
        await RedisCli.expire(key, exptime);
        return true;
    }catch(error){
        console.log('SetRedisExpire error is', error);
        return false;
    }
}

/**
 * 退出函数
 */
function Quit(){
    RedisCli.quit();
}

module.exports = {GetRedis, QueryRedis, Quit, SetRedisExpire,}//node.js为单线程语言，不需要封装线程池多线程
//exports 抛出才可以给外部