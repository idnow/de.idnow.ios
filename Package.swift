// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "IDnowSDK",
    platforms: [.iOS(.v11)],
    products: [
        .library(
            name: "IDnowSDK",
            targets: ["IDnowSDK"]),
    ],
    targets: [
        .binaryTarget(
                            name: "IDnowSDK",
                            path: "vi/idnow_vi.xcframework"
                    )
    ]
)
