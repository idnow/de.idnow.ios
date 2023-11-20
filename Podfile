
target 'IDnow' do
  use_frameworks!
  pod 'IDnowSDK', '7.3.0'
  pod 'libPhoneNumber-iOS', :git => 'https://github.com/iziz/libPhoneNumber-iOS.git'
end

post_install do |installer|
  installer.generated_projects.each do |project|
    project.targets.each do |target|
        target.build_configurations.each do |config|
            config.build_settings['ONLY_ACTIVE_ARCH'] = 'NO'
         end
    end
  end
end
