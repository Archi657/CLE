#include <aws/core/Aws.h>
#include <aws/s3/S3Client.h>
#include <aws/s3/model/ListBucketsResult.h>
#include <aws/core/client/ClientConfiguration.h>
#include <iostream>

int main(int argc, char** argv) {
    // Initialize AWS SDK
    Aws::SDKOptions options;
    Aws::InitAPI(options);

    {
        // Configure for LocalStack
        Aws::Client::ClientConfiguration config;
        config.endpointOverride = "http://localhost:4566";
        config.scheme = Aws::Http::Scheme::HTTP;
        config.verifySSL = false;

        // Create S3 client with LocalStack configuration
        Aws::S3::S3Client s3_client(config);

        // List buckets
        auto outcome = s3_client.ListBuckets();

        if (outcome.IsSuccess()) {
            std::cout << "Successfully listed buckets:" << std::endl;
            const auto& buckets = outcome.GetResult().GetBuckets();
            std::cout << "Found " << buckets.size() << " buckets" << std::endl;
            
            for (const auto& bucket : buckets) {
                std::cout << "* " << bucket.GetName() << std::endl;
            }
        } else {
            std::cout << "Failed to list buckets: " << 
                outcome.GetError().GetMessage() << std::endl;
        }
    }

    // Clean up
    Aws::ShutdownAPI(options);
    return 0;
}