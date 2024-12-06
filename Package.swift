// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "IDnowSDK",
    platforms: [.iOS(.v11)],
    products: [
        .library(
            name: "IDnowSDK",
            targets: ["IDnowSDK"]
        ),
    ],
    targets: [
        // Binary target for the actual framework, including resources
        .binaryTarget(
            name: "IDnowSDK",
            path: "vi/idnow_vi.xcframework",
            resources: [
                .process("vi/idnow_vi.xcframework/ios-arm64/idnow_vi.framework/IDnowImages.bundle"),
                .process("vi/idnow_vi.xcframework/ios-arm64/idnow_vi.framework/IDnowVideoIdentPlusImages.bundle")
            ]
        )
    ]
)