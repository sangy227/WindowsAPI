#pragma once
#include"Common.h"
#include "yaResource.h"

namespace ya {
	template <typename T>
	class Resources
	{

	public:
		typedef std::map<std::wstring, Resource*>::iterator ResourceIter;

		static T* Find(const std::wstring& key)
		{
			ResourceIter iter = mResources.find(key);

			//���ҽ��� �̹� map�ȿ� �����Ѵ�
			if (iter != mResources.end())
			{
				return dynamic_cast<T*>(iter->second);
			}
			return nullptr;
		
		}
		static T* Load(const std::wstring& key,const std::wstring& path)
		{
			T* resource = Find(key);
			//�ش� Ű�� �̹� �ε��Ȱ� ������ ���ҽ��� ��ȯ
			if (resource != nullptr)
				return resource;

			//���ҽ��� ����
			resource = new T();
			if (FAILED(resource->Load(path)))
			{
				MessageBox(nullptr, L"Image load Failed!!!", L"Error", MB_OK);
				return nullptr;
			}

			//???????? 10-25�� �ּ�ó���ϴϱ� �����
			//resource->Setkey(key);
			//resource->Setpath(path);

			mResources.insert(std::make_pair(key, resource));

			return dynamic_cast<T*>(resource);
		}

	private:
		static std::map<std::wstring, Resource*> mResources;
	};
	template <typename T>
	std::map<std::wstring, Resource*> Resources<T>::mResources;
}

