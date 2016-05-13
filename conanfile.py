from conans import ConanFile, ConfigureEnvironment
import os
from conans.tools import download, unzip, replace_in_file
from conans import CMake


class CapNProtoConan(ConanFile):
    name = "c-capnproto"
    version = "0.1"
    commit_sha = "a15accf4eb5824c10a3bf2e5e67f6b47abb4ca1e"
    ZIP_FOLDER_NAME = "c-capnproto-%s" % commit_sha
    generators = "cmake"
    settings = "os", "arch", "compiler", "build_type"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = "shared=False", "fPIC=True"
    exports = ["CMakeLists.txt"]
    url="http://github.com/lasote/conan-c-capnproto"
    license="MIT https://github.com/sandstorm-io/c-capnproto/blob/v0.1/LICENSE"
    requires="capnproto/0.5.3@lasote/stable"

    def config(self):
        del self.settings.compiler.libcxx
        if self.settings.os == "Windows":
            try:
                self.options.remove("fPIC")
            except: 
                pass
        
    def source(self):
        zip_name = "%s.zip" % self.commit_sha
        download("https://github.com/opensourcerouting/c-capnproto/archive/%s" % zip_name, zip_name)
        unzip(zip_name)
        os.unlink(zip_name)

    def build(self):
        cmake = CMake(self.settings)
        os.mkdir(os.path.join(self.ZIP_FOLDER_NAME, "_build"))
        cd_build = "cd %s/_build" % self.ZIP_FOLDER_NAME
        shared = "-DBUILD_SHARED_LIBS=ON" if self.options.shared else ""
        fpic = "-DFPIC=ON" if self.options.fPIC else ""
        cmake_1 = '%s && cmake ../../ %s %s %s' % (cd_build, cmake.command_line, shared, fpic)
        self.output.warn(cmake_1)
        self.run(cmake_1)
        cmake_2 = "%s && cmake --build . %s" % (cd_build, cmake.build_config)
        self.output.warn(cmake_2)
        self.run(cmake_2)

    def package(self):
        """ Define your conan structure: headers, libs, bins and data. After building your
            project, this method is called to create a defined structure:
        """
      
        self.copy(pattern="*.h", dst="include", src=self.ZIP_FOLDER_NAME,  keep_path=False)
         
        # Copying static and dynamic libs
        if self.settings.os == "Windows":
            if self.options.shared:
                self.copy(pattern="*.dll", dst="bin", src="%s/_build" % self.ZIP_FOLDER_NAME, keep_path=False)
            self.copy(pattern="*.lib", dst="lib", src="%s/_build" % self.ZIP_FOLDER_NAME, keep_path=False)
        else:
            if self.options.shared:
                if self.settings.os == "Macos":
                    self.copy(pattern="*.dylib", dst="lib", keep_path=False)
                else:
                    self.copy(pattern="*.so*", dst="lib", src=self.ZIP_FOLDER_NAME, keep_path=False)
            else:
                self.copy(pattern="*.a", dst="lib", src="%s/_build" % self.ZIP_FOLDER_NAME, keep_path=False)
                self.copy(pattern="*.a", dst="lib", src=self.ZIP_FOLDER_NAME, keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ['c_capnproto']

