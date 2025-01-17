#include "gtest/gtest.h"
#include "kafka_client.h"

TEST(test_kafka_producer_worker, create_producer) 
{   
    std::string broker_str = "localhost:9092";
    std::string topic = "test";
    kafka_clients::kafka_client *client = new kafka_clients::kafka_client();
    kafka_clients::kafka_producer_worker *worker;
    worker = client->create_producer(broker_str, topic);
    worker->init();
    worker->printCurrConf();
    std::string msg ="test";
    //Run this unit test without launching kafka broker will throw connection refused error
    worker->send(msg);
    worker->stop();
    free(worker);    
    delete client;
}
