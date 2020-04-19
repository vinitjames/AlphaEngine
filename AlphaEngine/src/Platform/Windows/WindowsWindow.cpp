#include "Aepch.h"
#include "WindowsWindow.h"
#include "AlphaEngine/Events/ApplicationEvent.h"
#include "AlphaEngine/Events/KeyEvent.h"
#include "AlphaEngine/Events/MouseEvent.h"

namespace AlphaEngine {
	static bool s_GLFWInitialized = false;
	static void ErrorCallback(int code, const char* msg) {
		AE_CORE_ERROR("GLFW Error ({0}) : {1}", code, msg);
	}
	Window* Window::Create(const WindowProps& props) {
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props){
		Init(props);
	}

	WindowsWindow::~WindowsWindow() {
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props) {
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		AE_CORE_INFO("Creating Window {0} {1} {2}", m_Data.Title, m_Data.Width, m_Data.Height);

		if (!s_GLFWInitialized) {
			int success = glfwInit();
			AE_CORE_ASSERT(success, "Could not Initialize GLFW!");
			glfwSetErrorCallback(ErrorCallback);
			s_GLFWInitialized = true;
		}


		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		if (!m_Window) {
			AE_CORE_ERROR("GLFW: Unable to Create Window");
			exit;
		}
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		//Set all relevant window Callbacks
		SetWindowCloseCallback();
		SetWindowSizeCallback();
		SetMouseButtonCallback();
		SetMouseMoveCallback();
		SetKeyCallback();
		SetMouseScrollCallback();

	}


	void WindowsWindow::SetWindowSizeCallback() {
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
			WindowsData* data = (WindowsData*)glfwGetWindowUserPointer(window);
			data->Height = height;
			data->Width = width;
			WindowResizeEvent event(width, height);
			data->EventCallback(event);
			});
	}

	void WindowsWindow::SetWindowCloseCallback() {
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
			WindowsData* data = (WindowsData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data->EventCallback(event);
			});
	}

	void WindowsWindow::SetKeyCallback() {
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowsData* data = (WindowsData*)glfwGetWindowUserPointer(window);
			switch (action) {

				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data->EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data->EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data->EventCallback(event);
					break;
				}
			}
		});
	}

	void WindowsWindow::SetMouseMoveCallback() {
		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos) {
			WindowsData* data = (WindowsData*)glfwGetWindowUserPointer(window);
			MouseMovedEvent event((float)xpos, (float)ypos);
			data->EventCallback(event);
		});
	}

	void WindowsWindow::SetMouseButtonCallback() {
		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
			WindowsData* data = (WindowsData*)glfwGetWindowUserPointer(window);
			switch (action) {

				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data->EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data->EventCallback(event);
					break;
				}
			}
		});
	}
	
	void WindowsWindow::SetMouseScrollCallback() {
		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset) {
			WindowsData* data = (WindowsData*)glfwGetWindowUserPointer(window);
			MouseScrolledEvent event((float)xoffset, (float)yoffset);
			data->EventCallback(event);
			});
	}

	void WindowsWindow::Shutdown() {
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(m_Window);

	}
	void WindowsWindow::SetVSync(bool enabled) {
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
		m_Data.Vsync = enabled;
	}

	bool WindowsWindow::IsVSync() const {
		return m_Data.Vsync;
	}

}