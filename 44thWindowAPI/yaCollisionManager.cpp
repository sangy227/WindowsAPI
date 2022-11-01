#include "yaCollisionManager.h"
#include "yaScene.h"
#include "yaSceneManager.h"
#include "yaGameObject.h"
#include "yaCollider.h"

namespace ya {

    WORD CollisionManager::mMatrix[_COLLIDER_LAYER] = {};
    std::map<UINT64, bool> CollisionManager::mCollisionInformation;


    //std::bitset<_COLLIDER_LAYER> CollisionManager::mMatrix2 = {};

    void CollisionManager::Tick()
    {
        Scene* playeScene = SceneManager::GetPlayScene();

        for (size_t row = 0; row < _COLLIDER_LAYER; row++)
        {
            for (size_t col = 0; col < _COLLIDER_LAYER; col++)
            {
                if (mMatrix[row] & (1 << col))
                {
                    //�浹 �� �Ǿ����� �ȵǾ������� �˻������ �Ѵ�.
                    LayerCollision(playeScene, (eColliderLayer)row, (eColliderLayer)col);
                }
            }
        }
    }
    void CollisionManager::SetLayer(eColliderLayer left, eColliderLayer right, bool value)
    {
        //������ ���ڸ� �� ��ū���ڸ� ����
        UINT row = 0;
        UINT col = 0;

        UINT iLeft = (UINT)left;
        UINT iRight = (UINT)right;

        if (iLeft < iRight)
        {
            row = (UINT)left;
            col = (UINT)right;
        }
        else
        {
            row = (UINT)right;
            col = (UINT)left;
        }

        if (value == true)
            mMatrix[row] |= (1 << col);
        else
            mMatrix[row] &= ~(1 << col);

        
    }

    void CollisionManager::LayerCollision(Scene* scene, eColliderLayer left, eColliderLayer right)
    {
        std::vector<GameObject*>& lefts = scene->GetGameObjects(left);
        std::vector<GameObject*>& rights = scene->GetGameObjects(right);

        for (auto leftObject : lefts)
        {
            Collider* leftCollider = leftObject->GetComponent<Collider>();
            if (leftCollider == nullptr)
                continue;

            for (auto rightObject : rights)
            {
                Collider* rightCollider = rightObject->GetComponent<Collider>();

                if (rightCollider == nullptr)
                    continue;

                if (leftObject == rightObject)
                    continue;

                ColliderCollision(leftCollider, rightCollider);
            }
        }
    }
    void CollisionManager::ColliderCollision(Collider* left, Collider* right)
    {
        //�� �浹ü�� Layer ��ȣ�� �ϴ� Ȯ�����ش�
        ColliderID id;
        id.left = left->GetID();
        id.right = right->GetID();

        std::map<UINT64, bool>::iterator iter
            = mCollisionInformation.find(id.ID);

        //�浹������ ���ٸ� �浹������ �������ش�.
        if (iter == mCollisionInformation.end())
        {
            mCollisionInformation.insert(std::make_pair(id.ID, false));
            iter = mCollisionInformation.find(id.ID);
        }


        if (Intersect(left, right))
        {
            //�浹

            if (iter->second == false)
            {
                //���� �ѹ� �浹
                

                //�浹�Լ��� ȣ���� �ָ� �ȴ�.
                left->OnCollisionEnter(right);
                right->OnCollisionEnter(left);

                iter->second == true;
            }
            else
            {
                //�浹 ���϶�
                left->OnCollisionStay(right);
                right->OnCollisionStay(left);
            }
            
        }
        else
        {
            //�浹x
            if (iter->second)
            {
                //�浹�ϰ� �������ö�
                left->OnCollisionExit(right);
                right->OnCollisionExit(left);

                iter->second == false;
            }

            // if (iter->second == false)

        }
    }
    bool CollisionManager::Intersect(Collider* left, Collider* right)
    {
        if (left->GetOwner()->IsDeath())
            return false;
        if (right->GetOwner()->IsDeath())
            return false;

        Vector2 leftPos = left->GetPos();
        Vector2 leftScale = left->GetScale();

        Vector2 rightPos = right->GetPos();
        Vector2 rightScale = right->GetScale();

        if (fabs(leftPos.x  - rightPos.x) < fabs(leftScale.x/2.0f + rightScale.x / 2.0f)
            && fabs(leftPos.y - rightPos.y) < fabs(leftScale.y / 2.0f + rightScale.y / 2.0f))
        {
            return true;
        }

        return false;
    }
}