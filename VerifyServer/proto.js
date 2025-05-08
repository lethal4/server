const path = require("path")
const grpc = require("@grpc/grpc-js")
const protoLoader = require("@grpc/proto-loader")//等用于include

const PROTO_PATH = path.join(__dirname,"message.proto")
const packageDefinition = protoLoader.loadSync(PROTO_PATH, {KeepCase:true , longs:String , enums:String , defaults:true , oneofs:true})//oneofs

const protoDescriptor = grpc.loadPackageDefinition(packageDefinition)
const message_proto = protoDescriptor.message

module.exports = message_proto

