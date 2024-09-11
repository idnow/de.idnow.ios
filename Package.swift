// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "IDnowSDK",
    platforms: [.iOS(.v11)],
    products: [
        .library(name: "IDnowSDK", targets: ["IDnowVideo"]),
        .library(name: "IDnowSDK-with-NFC", targets: ["IDnowVideo", "IDnowEID"]),
    ],
    targets: [
        .binaryTarget(name: "IDnowVideo", path: "idnow_vi.xcframework"),
        .binaryTarget(name: "IDnowEID", path: "eid/idnow_eid.xcframework"),
    ]
)
